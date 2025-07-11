#include <stdio.h>
#include <stdlib.h>
#include "mpitest.h"
#include <math.h>

void bench_p2p(MPI_Comm comm, int src, int dst, void *buf, int size);
int bench_warmup(MPI_Comm comm, int dst, void *buf, int size);
double bench_send(int iter, MPI_Comm comm, int dst, void *buf, int size);
void bench_recv(MPI_Comm comm, int src, void *buf, int size);
#define WINDOW_SIZE 64
#define TAG 0
#define SYNC_TAG 100
#define MAX_BUFSIZE 5000000
#define NUM_REPEAT 20

int main(int argc, char** argv)
{
    MTestArgList *head;

    MTest_Init(NULL, NULL);

    int grank;
    int gsize;
    MPI_Comm_rank(MPI_COMM_WORLD, &grank);
    MPI_Comm_size(MPI_COMM_WORLD, &gsize);
    if (gsize < 2) {
        printf("! Test p2p_bw requires 2 processes !\n");
        return 1;
    }

    MPI_Comm comm = MPI_COMM_WORLD;

    void *buf;
    head = MTestArgListCreate(argc, argv);
    int send_rank = 0, recv_rank = 1;
    if (grank == send_rank) {
        mtest_mem_type_e send_memtype;
        int send_device;
        send_memtype = MTestArgListGetMemType(head, "sendmem");
        send_device = MTestArgListGetInt_with_default(head, "senddev", 0);
        MTestMalloc(MAX_BUFSIZE, send_memtype, NULL, &buf, send_device);
        MTestPrintfMsg(1, "Allocating buffer: memtype=%s, device=%d, size=%d\n", MTest_memtype_name(send_memtype), send_device, MAX_BUFSIZE);
    }
    if (grank == recv_rank) {
        mtest_mem_type_e recv_memtype;
        int recv_device;
        recv_memtype = MTestArgListGetMemType(head, "recvmem");
        recv_device = MTestArgListGetInt_with_default(head, "recvdev", 0);
        MTestMalloc(MAX_BUFSIZE, recv_memtype, NULL, &buf, recv_device);
        MTestPrintfMsg(1, "Allocating buffer: memtype=%s, device=%d, size=%d\n", MTest_memtype_name(recv_memtype), recv_device, MAX_BUFSIZE);
    }
    MTestArgListDestroy(head);
    if (!buf) {
        printf("! Failed to allocate buffer (size=%d)\n", MAX_BUFSIZE);
        return 1;
    }

    if (grank == 0) {
        printf("TEST p2p_bw:\n");
        printf("%12s %10s(us) %6s(us) %12s(MB/s)\n", "msgsize", "latency", "sigma", "bandwidth");
    }
    for (int size = 1; size < MAX_BUFSIZE; size *= 2) {
        bench_p2p(comm, 0, 1, buf, size);
    }
    if (grank == 0) {
        printf("\n");
    }

    MTest_Finalize(0);
    return 0;
}

void bench_p2p(MPI_Comm comm, int src, int dst, void *buf, int size)
{
    int iter;
    double tf_latency;

    int rank;
    MPI_Comm_rank(comm, &rank);

    if (rank == src) {
        iter = bench_warmup(comm, dst, buf, size);
        double sum1 = 0;
        double sum2 = 0;
        for (int i = 0; i<NUM_REPEAT; i++) {
            tf_latency = bench_send(iter, comm, dst, buf, size);
            tf_latency /= iter;
            sum1 += tf_latency;
            sum2 += tf_latency * tf_latency;
        }
        sum1 /= NUM_REPEAT;
        sum2 /= NUM_REPEAT;
        sum2 = sqrt(sum2 - sum1 * sum1);
        double tf_latency;
        double tf_sigma;
        double tf_bw;
        tf_latency = sum1 / (WINDOW_SIZE) * 1e6;
        tf_sigma = sum2 / (WINDOW_SIZE) * 1e6;
        tf_bw = size / tf_latency;
        printf("%12d %10.3f     %6.3f     %12.3f\n", size, tf_latency, tf_sigma, tf_bw);
        iter = 0;
        MPI_Send(&iter, 1, MPI_INT, dst, SYNC_TAG, comm);
    } else if (rank == dst) {
        bench_recv(comm, src, buf, size);
    }
}

int bench_warmup(MPI_Comm comm, int dst, void *buf, int size)
{
    int iter;
    double tf_dur;

    iter = 2;
    double last_dur = 1.0;
    int num_best = 0;
    while (num_best < 10) {
        tf_dur = bench_send(iter, comm, dst, buf, size);
        if (iter < (int) (iter * 0.001 / tf_dur)) {
            iter = (int) (iter * 0.001 / tf_dur);
            num_best = 0;
            continue;
        }
        if (tf_dur > last_dur) {
            num_best++;
        }
        last_dur = tf_dur;
    }
    return iter;
}

double bench_send(int iter, MPI_Comm comm, int dst, void *buf, int size)
{
    double tf_start;
    double tf_dur;

    MPI_Send(&iter, 1, MPI_INT, dst, SYNC_TAG, comm);

    tf_start = MPI_Wtime();
    for (int i = 0; i<iter; i++) {
        MPI_Request reqs[WINDOW_SIZE];
        for (int j = 0; j<WINDOW_SIZE; j++) {
            MPI_Isend(buf, size, MPI_CHAR, dst, TAG, comm, &reqs[j]);
        }
        MPI_Waitall(WINDOW_SIZE, reqs, MPI_STATUSES_IGNORE);
        MPI_Recv(NULL, 0, MPI_DATATYPE_NULL, dst, TAG, comm, MPI_STATUS_IGNORE);
    }
    tf_dur = MPI_Wtime() - tf_start;

    return tf_dur;
}

void bench_recv(MPI_Comm comm, int src, void *buf, int size)
{
    while (1) {
        int iter;
        MPI_Recv(&iter, 1, MPI_INT, src, SYNC_TAG, comm, MPI_STATUS_IGNORE);
        if (iter == 0) {
            break;
        }
        for (int i = 0; i<iter; i++) {
            MPI_Request reqs[WINDOW_SIZE];
            for (int j = 0; j<WINDOW_SIZE; j++) {
                MPI_Irecv(buf, size, MPI_CHAR, src, TAG, comm, &reqs[j]);
            }
            MPI_Waitall(WINDOW_SIZE, reqs, MPI_STATUSES_IGNORE);
            MPI_Send(NULL, 0, MPI_DATATYPE_NULL, src, TAG, comm);
        }
    }
}
