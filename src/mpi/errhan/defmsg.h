/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 *
 * This file automatically created by extracterrmsgs
 * DO NOT EDIT
 */

typedef struct msgpair {
        const unsigned int sentinal1;
        const char *short_name, *long_name; 
        const unsigned int sentinal2; } msgpair;

/* The names are in sorted order, allowing the use of a simple
  linear search or bisection algorithm to find the message corresponding to
  a particular message */
static const char short_gen0[] = "**UNKNOWN";
static const char long_gen0[]  = "Unknown error class";
static const char short_gen1[] = "**afinetinvalid";
static const char long_gen1[]  = "Network type AF_INET invalid in call to inet_pton";
static const char short_gen2[] = "**alloc_shar_mem";
static const char long_gen2[]  = "unable to allocate shared memory";
static const char short_gen3[] = "**allocmem";
static const char long_gen3[]  = "Unable to allocate memory for MPI_Alloc_mem";
static const char short_gen4[] = "**arg";
static const char long_gen4[]  = "Invalid argument";
static const char short_gen5[] = "**argarrayneg";
static const char long_gen5[]  = "Negative value in array ";
static const char short_gen6[] = "**argerrcode";
static const char long_gen6[]  = "Invalid error code";
static const char short_gen7[] = "**argneg";
static const char long_gen7[]  = "Invalid argument; must be non-negative";
static const char short_gen8[] = "**argnonpos";
static const char long_gen8[]  = "Invalid argument; must be positive";
static const char short_gen9[] = "**argrange";
static const char long_gen9[]  = "Argument is not within valid range";
static const char short_gen10[] = "**argstr_hostd";
static const char long_gen10[]  = "no space for the host description";
static const char short_gen11[] = "**argstr_missinghost";
static const char long_gen11[]  = "Missing hostname or invalid host/port description in business card";
static const char short_gen12[] = "**argstr_missingifname";
static const char long_gen12[]  = "Missing ifname or invalid host/port description in business card";
static const char short_gen13[] = "**argstr_missingport";
static const char long_gen13[]  = "Missing port or invalid host/port description in business card";
static const char short_gen14[] = "**argstr_no_port_name_tag";
static const char long_gen14[]  = "no port_name tag in MPI port.  Make sure that port was created with MPI_Open_port";
static const char short_gen15[] = "**argstr_port";
static const char long_gen15[]  = "no space for the listener port";
static const char short_gen16[] = "**argstr_port_name_tag";
static const char long_gen16[]  = "no space for port_name tag";
static const char short_gen17[] = "**argtoosmall";
static const char long_gen17[]  = "Invalid argument; value is too small";
static const char short_gen18[] = "**assert";
static const char long_gen18[]  = "Invalid assert argument";
static const char short_gen19[] = "**atexit_pmi_finalize";
static const char long_gen19[]  = " Registration of PMI finalize function in exit handler failed";
static const char short_gen20[] = "**attach_shar_mem";
static const char long_gen20[]  = "unable to attach to shared memory";
static const char short_gen21[] = "**attrsentinal";
static const char long_gen21[]  = "Internal fields in an attribute have been overwritten; possible errors in using the attribute value in user code.";
static const char short_gen22[] = "**badcase";
static const char long_gen22[]  = "INTERNAL ERROR: unexpected value in case statement";
static const char short_gen23[] = "**badgputype";
static const char long_gen23[]  = "Bad GPU type specified";
static const char short_gen24[] = "**badportrange";
static const char long_gen24[]  = "MPICH_PORT_RANGE - invalid range specified";
static const char short_gen25[] = "**base";
static const char long_gen25[]  = "Invalid base address";
static const char short_gen26[] = "**bind";
static const char long_gen26[]  = " Unable to bind socket to address";
static const char short_gen27[] = "**blcr_mod";
static const char long_gen27[]  = "BLCR kernel module not present";
static const char short_gen28[] = "**bsendbufsmall";
static const char long_gen28[]  = "Buffer size is smaller than MPI_BSEND_OVERHEAD";
static const char short_gen29[] = "**buf_inplace";
static const char long_gen29[]  = "buffer cannot be MPI_IN_PLACE";
static const char short_gen30[] = "**bufalias";
static const char long_gen30[]  = "Buffers must not be aliased";
static const char short_gen31[] = "**bufbsend";
static const char long_gen31[]  = "Insufficient space in Bsend buffer";
static const char short_gen32[] = "**bufexists";
static const char long_gen32[]  = "Buffer already attached with MPI_BUFFER_ATTACH.";
static const char short_gen33[] = "**buffer";
static const char long_gen33[]  = "Invalid buffer pointer";
static const char short_gen34[] = "**bufnull";
static const char long_gen34[]  = "Null buffer pointer";
static const char short_gen35[] = "**buscard";
static const char long_gen35[]  = "unable to create a business card";
static const char short_gen36[] = "**buscard_len";
static const char long_gen36[]  = "no space left in the business card to add a parameter";
static const char short_gen37[] = "**cancelinactive";
static const char long_gen37[]  = "Attempt to cancel an inactive persistent request";
static const char short_gen38[] = "**cancelunknown";
static const char long_gen38[]  = "Attempt to cancel an unknown type of request";
static const char short_gen39[] = "**cannotfreestream";
static const char long_gen39[]  = "The stream is still in use, cannot be freed.";
static const char short_gen40[] = "**cartcoordinvalid";
static const char long_gen40[]  = "Cartesian coordinate is invalid (not in range)";
static const char short_gen41[] = "**cartdim";
static const char long_gen41[]  = "Size of Cartesian grid is larger than the size of the communicator";
static const char short_gen42[] = "**ch3nostream";
static const char long_gen42[]  = "Stream is not supported in ch3.";
static const char short_gen43[] = "**ch3|badmsgtype";
static const char long_gen43[]  = "request contained an invalid message type";
static const char short_gen44[] = "**ch3|badreqtype";
static const char long_gen44[]  = "request contained an invalid request type";
static const char short_gen45[] = "**ch3|cancelreq";
static const char long_gen45[]  = "failure occurred while sending remote cancellation request packet";
static const char short_gen46[] = "**ch3|cancelresp";
static const char long_gen46[]  = "failure occurred while attempting to send cancel response packet";
static const char short_gen47[] = "**ch3|cancelrndv";
static const char long_gen47[]  = "failure occurred while performing local cancellation of a rendezvous message";
static const char short_gen48[] = "**ch3|ch3_init";
static const char long_gen48[]  = "channel initialization failed";
static const char short_gen49[] = "**ch3|close_progress";
static const char long_gen49[]  = "an error occurred while the device was waiting for all open connections to close";
static const char short_gen50[] = "**ch3|conn_parent";
static const char long_gen50[]  = "spawned process group was unable to connect back to the parent";
static const char short_gen51[] = "**ch3|conntimeout";
static const char long_gen51[]  = "Connection timed out";
static const char short_gen52[] = "**ch3|ctspkt";
static const char long_gen52[]  = "failure occurred while attempting to send CTS packet";
static const char short_gen53[] = "**ch3|eagermsg";
static const char long_gen53[]  = "failure occurred while attempting to send an eager message";
static const char short_gen54[] = "**ch3|get_parent_port";
static const char long_gen54[]  = "spawn process group was unable to obtain parent port name from the channel";
static const char short_gen55[] = "**ch3|loadrecviov";
static const char long_gen55[]  = "failure occurred while loading the receive I/O vector";
static const char short_gen56[] = "**ch3|loadsendiov";
static const char long_gen56[]  = "failure occurred while loading the send I/O vector";
static const char short_gen57[] = "**ch3|nopktcontainermem";
static const char long_gen57[]  = "failed to allocate memory for a packet reorder container";
static const char short_gen58[] = "**ch3|ooocancelreq";
static const char long_gen58[]  = "UNIMPLEMENTED: unable to process out-of-order cancellation requests";
static const char short_gen59[] = "**ch3|pktarraytoosmall";
static const char long_gen59[]  = " Size of the array of packet handlers is too small";
static const char short_gen60[] = "**ch3|pktordered";
static const char long_gen60[]  = "failure occurred while processing a reordered packet";
static const char short_gen61[] = "**ch3|portclose";
static const char long_gen61[]  = "Port is unexpectedly closed";
static const char short_gen62[] = "**ch3|postrecv";
static const char long_gen62[]  = "failure occurred while posting a receive for message data";
static const char short_gen63[] = "**ch3|rma_msg";
static const char long_gen63[]  = "RMA message operation failed";
static const char short_gen64[] = "**ch3|rmamsg";
static const char long_gen64[]  = "failure occurred while attempting to send an RMA message";
static const char short_gen65[] = "**ch3|rtspkt";
static const char long_gen65[]  = "failure occurred while attempting to send RTS packet";
static const char short_gen66[] = "**ch3|send_close_ack";
static const char long_gen66[]  = "an error occurred when the device attempted to acknowledge the closing of a connection";
static const char short_gen67[] = "**ch3|senddata";
static const char long_gen67[]  = "failure occurred while attempting to send message data";
static const char short_gen68[] = "**ch3|sock|accept";
static const char long_gen68[]  = "[ch3:sock] accepting a new connection failed";
static const char short_gen69[] = "**ch3|sock|addrinuse";
static const char long_gen69[]  = "[ch3:sock] tcp port already in use";
static const char short_gen70[] = "**ch3|sock|badhost";
static const char long_gen70[]  = "[ch3:soc] invalid host description";
static const char short_gen71[] = "**ch3|sock|badpacket";
static const char long_gen71[]  = "[ch3:sock] received packet of unknown type";
static const char short_gen72[] = "**ch3|sock|badsock";
static const char long_gen72[]  = "[ch3:sock] internal error - bad sock";
static const char short_gen73[] = "**ch3|sock|connalloc";
static const char long_gen73[]  = "[ch3:sock] unable to allocate an internal connection structure";
static const char short_gen74[] = "**ch3|sock|connclose";
static const char long_gen74[]  = "[ch3:sock] active connection unexpectedly closed";
static const char short_gen75[] = "**ch3|sock|connectionfailed";
static const char long_gen75[]  = "Connection failed for virtual channel";
static const char short_gen76[] = "**ch3|sock|connfailed";
static const char long_gen76[]  = "[ch3:sock] failed to connect to remote process";
static const char short_gen77[] = "**ch3|sock|connrefused";
static const char long_gen77[]  = "[ch3:sock] connection refused";
static const char short_gen78[] = "**ch3|sock|connterm";
static const char long_gen78[]  = "[ch3:sock] active connection unexpectedly terminated";
static const char short_gen79[] = "**ch3|sock|failure";
static const char long_gen79[]  = "[ch3:sock] unknown failure";
static const char short_gen80[] = "**ch3|sock|handle_sock_event";
static const char long_gen80[]  = "an error occurred while handling an event returned by MPIDI_CH3I_Sock_Wait()";
static const char short_gen81[] = "**ch3|sock|hostlookup";
static const char long_gen81[]  = "[ch3:sock] hostname lookup failed";
static const char short_gen82[] = "**ch3|sock|immedread";
static const char long_gen82[]  = "immediate read operation failed";
static const char short_gen83[] = "**ch3|sock|immedwrite";
static const char long_gen83[]  = "immediate write operation failed";
static const char short_gen84[] = "**ch3|sock|open_lrecv_data";
static const char long_gen84[]  = "[ch3:sock] failed to handle open lrecv data packet";
static const char short_gen85[] = "**ch3|sock|openlsend";
static const char long_gen85[]  = "[ch3:sock] failed to handle open lsend packet";
static const char short_gen86[] = "**ch3|sock|postconnect";
static const char long_gen86[]  = "[ch3:sock] post connect failed";
static const char short_gen87[] = "**ch3|sock|postread";
static const char long_gen87[]  = "attempt to post a read operation failed";
static const char short_gen88[] = "**ch3|sock|postwrite";
static const char long_gen88[]  = "attempt to post a write operation failed";
static const char short_gen89[] = "**ch3|sock|scconnaccept";
static const char long_gen89[]  = "[ch3:sock] failed to handle connection accept packet";
static const char short_gen90[] = "**ch3|sock|scopenresp";
static const char long_gen90[]  = "[ch3:sock] failed to handle open response packet";
static const char short_gen91[] = "**ch3|sock|writefailed";
static const char long_gen91[]  = "Write to socket failed";
static const char short_gen92[] = "**ch3|syncack";
static const char long_gen92[]  = "failure occurred while attempting to send eager synchronization packet";
static const char short_gen93[] = "**ch3|unhandled_connection_state";
static const char long_gen93[]  = "encountered an unexpected connection state";
static const char short_gen94[] = "**ch4nostream";
static const char long_gen94[]  = "No streams available. Configure --enable-thread-cs=per-vci and --with-ch4-max-vcis=# to enable streams.";
static const char short_gen95[] = "**ch4|badreqtype";
static const char long_gen95[]  = "request contained an invalid request type";
static const char short_gen96[] = "**ch4|badstartreq";
static const char long_gen96[]  = "start an invalid request kind";
static const char short_gen97[] = "**ch4|invalid_mt_model";
static const char long_gen97[]  = "Invalid multi-threading model";
static const char short_gen98[] = "**ch4|invalid_shm_posix_eager";
static const char long_gen98[]  = "Invalid shm posix eager module specified";
static const char short_gen99[] = "**ch4|partmismatchsize";
static const char long_gen99[]  = " Partitioned send and receive buﬀers are not identical in size";
static const char short_gen100[] = "**ch4|too_many_ranks";
static const char long_gen100[]  = "User requested number of ranks unsupported";
static const char short_gen101[] = "**ch4|too_small_cqdata";
static const char long_gen101[]  = " CQ data size is too small for enabling GPU pipelining";
static const char short_gen102[] = "**ckptpkt";
static const char long_gen102[]  = "Failed to send checkpoint marker packet";
static const char short_gen103[] = "**close";
static const char long_gen103[]  = "close of socket failed";
static const char short_gen104[] = "**closesocket";
static const char long_gen104[]  = "closesocket failed";
static const char short_gen105[] = "**cmadata";
static const char long_gen105[]  = "process_vm_readv bytes mismatch";
static const char short_gen106[] = "**cmaread";
static const char long_gen106[]  = "process_vm_readv failed";
static const char short_gen107[] = "**cmawrite";
static const char long_gen107[]  = "process_vm_writev failed";
static const char short_gen108[] = "**coll_fail";
static const char long_gen108[]  = "Failure during collective";
static const char short_gen109[] = "**collalgo";
static const char long_gen109[]  = "User set collective algorithm is not usable for the provided arguments";
static const char short_gen110[] = "**collective_size_mismatch";
static const char long_gen110[]  = "message sizes do not match across processes in the collective routine";
static const char short_gen111[] = "**comm";
static const char long_gen111[]  = "Invalid communicator";
static const char short_gen112[] = "**comm_connect_fail";
static const char long_gen112[]  = "Unable to establish connection to process";
static const char short_gen113[] = "**comm_fail";
static const char long_gen113[]  = "Communication error";
static const char short_gen114[] = "**comm_fail_conn";
static const char long_gen114[]  = "Communication error during connect sequence";
static const char short_gen115[] = "**commhasunmatched";
static const char long_gen115[]  = "Communicator being freed has unmatched message(s)";
static const char short_gen116[] = "**commnotintra";
static const char long_gen116[]  = "An intracommunicator is required but an intercommunicator was provided.";
static const char short_gen117[] = "**commnull";
static const char long_gen117[]  = "Null communicator";
static const char short_gen118[] = "**commperm";
static const char long_gen118[]  = "Cannot free permanent communicator";
static const char short_gen119[] = "**contentspredef";
static const char long_gen119[]  = "Named predefined datatypes are not permitted in MPI_Type_get_contents";
static const char short_gen120[] = "**conversion";
static const char long_gen120[]  = "An error occurred in a user-defined data conversion function";
static const char short_gen121[] = "**cookiepkt";
static const char long_gen121[]  = "failure occurred while attempting to send COOKIE packet";
static const char short_gen122[] = "**count";
static const char long_gen122[]  = "Invalid count";
static const char short_gen123[] = "**countneg";
static const char long_gen123[]  = "Negative count";
static const char short_gen124[] = "**ctspkt";
static const char long_gen124[]  = "failure occurred while attempting to send CTS packet";
static const char short_gen125[] = "**darrayblock";
static const char long_gen125[]  = "Value of m must be positive for block(m) distribution";
static const char short_gen126[] = "**darrayblock2";
static const char long_gen126[]  = "m * nprocs is less than array_size and is not valid for block(m) distribution (optional arguments: {m*nprocs}, {array_size} (int))";
static const char short_gen127[] = "**darraycyclic";
static const char long_gen127[]  = "Value of m must be positive for a cyclic(m) distribution";
static const char short_gen128[] = "**datarepextent";
static const char long_gen128[]  = "Invalid extent callback";
static const char short_gen129[] = "**datarepname";
static const char long_gen129[]  = "Invalid datarep name";
static const char short_gen130[] = "**datarepunsupported";
static const char long_gen130[]  = "Unsupported datarep passed to MPI_File_set_view ";
static const char short_gen131[] = "**datarepused";
static const char long_gen131[]  = "The requested datarep name has already been specified to MPI_REGISTER_DATAREP";
static const char short_gen132[] = "**detach_shar_mem";
static const char long_gen132[]  = "unable to detach shared memory";
static const char short_gen133[] = "**dev|pg_create";
static const char long_gen133[]  = "unable to create a new process group";
static const char short_gen134[] = "**dev|pg_finalize|list_not_empty";
static const char long_gen134[]  = "process group list was not empty";
static const char short_gen135[] = "**dev|pg_init";
static const char long_gen135[]  = "unable to initialize the process group management module";
static const char short_gen136[] = "**dev|pg_not_found";
static const char long_gen136[]  = "the specified process group object could not be located";
static const char short_gen137[] = "**dev|selfsenddeadlock";
static const char long_gen137[]  = "DEADLOCK: attempting to send a message to the local process without a prior matching receive";
static const char short_gen138[] = "**dev|vcrt_create";
static const char long_gen138[]  = "failed to a create VCRT";
static const char short_gen139[] = "**dims";
static const char long_gen139[]  = "Invalid dimension argument";
static const char short_gen140[] = "**dimsmany";
static const char long_gen140[]  = "Number of dimensions is too large ";
static const char short_gen141[] = "**dimspartition";
static const char long_gen141[]  = "Cannot partition nodes as requested ";
static const char short_gen142[] = "**dimszero";
static const char long_gen142[]  = "Communicator associated with zero-dimensional cartesian topology";
static const char short_gen143[] = "**dispunit";
static const char long_gen143[]  = "disp_unit argument is not positive integer";
static const char short_gen144[] = "**donepkt";
static const char long_gen144[]  = "failure occurred while attempting to send DONE packet";
static const char short_gen145[] = "**drconvnotsupported";
static const char long_gen145[]  = "Read and Write datarep conversions are currently not supported by MPI-IO";
static const char short_gen146[] = "**dtype";
static const char long_gen146[]  = "Invalid datatype";
static const char short_gen147[] = "**dtypecommit";
static const char long_gen147[]  = "Datatype has not been committed ";
static const char short_gen148[] = "**dtypemismatch";
static const char long_gen148[]  = "Receiving data with a datatype whose signature does not match that of the sending datatype.";
static const char short_gen149[] = "**dtypenull";
static const char long_gen149[]  = "Null datatype";
static const char short_gen150[] = "**dtypeperm";
static const char long_gen150[]  = "Cannot free permanent data type ";
static const char short_gen151[] = "**dupprocesses";
static const char long_gen151[]  = "Local and remote groups in MPI_Intercomm_create must not contain the same processes";
static const char short_gen152[] = "**dynamic_node_ids";
static const char long_gen152[]  = " Node information for dynamic processes currently is not implemented";
static const char short_gen153[] = "**eagain";
static const char long_gen153[]  = "Operation could not be issued (EAGAIN)";
static const char short_gen154[] = "**edgeoutrange";
static const char long_gen154[]  = "Edge index in graph topology is out of range";
static const char short_gen155[] = "**errclassref";
static const char long_gen155[]  = "Error class still in use";
static const char short_gen156[] = "**errcoderef";
static const char long_gen156[]  = "Error code still in use";
static const char short_gen157[] = "**errhandler";
static const char long_gen157[]  = "Invalid errhandler";
static const char short_gen158[] = "**errhandlernull";
static const char long_gen158[]  = "Null errhandler ";
static const char short_gen159[] = "**errhandnotfile";
static const char long_gen159[]  = "Error handler is not a file error handler";
static const char short_gen160[] = "**errhandnotsession";
static const char long_gen160[]  = "Error handler is not a session error handler";
static const char short_gen161[] = "**errhandnotwin";
static const char long_gen161[]  = "Error handler is not a win error handler";
static const char short_gen162[] = "**exceeded_connect_tries";
static const char long_gen162[]  = "Unable to establish connection to process";
static const char short_gen163[] = "**f90typecomplexnone";
static const char long_gen163[]  = " No complex type with the requested range and/or precision is available";
static const char short_gen164[] = "**f90typeintnone";
static const char long_gen164[]  = " No integer type with the requested range is available";
static const char short_gen165[] = "**f90typerealnone";
static const char long_gen165[]  = " No real type with the requested range and/or precision is available";
static const char short_gen166[] = "**f90typetoomany";
static const char long_gen166[]  = "Too many requests for unnamed, predefined f90 types";
static const char short_gen167[] = "**fail";
static const char long_gen167[]  = "";
static const char short_gen168[] = "**failure_pending";
static const char long_gen168[]  = "Request pending due to failure";
static const char short_gen169[] = "**file";
static const char long_gen169[]  = "Invalid MPI_File";
static const char short_gen170[] = "**fileaccess";
static const char long_gen170[]  = "Access denied to file";
static const char short_gen171[] = "**fileamode";
static const char long_gen171[]  = "Invalid amode value in MPI_File_open ";
static const char short_gen172[] = "**fileamodediff";
static const char long_gen172[]  = "amode must be the same on all processors";
static const char short_gen173[] = "**fileamodeone";
static const char long_gen173[]  = "Exactly one of MPI_MODE_RDONLY, MPI_MODE_WRONLY, or MPI_MODE_RDWR must be specified";
static const char short_gen174[] = "**fileamoderead";
static const char long_gen174[]  = "Cannot use MPI_MODE_CREATE or MPI_MODE_EXCL with MPI_MODE_RDONLY ";
static const char short_gen175[] = "**fileamodeseq";
static const char long_gen175[]  = "Cannot specify MPI_MODE_SEQUENTIAL with MPI_MODE_RDWR";
static const char short_gen176[] = "**fileexist";
static const char long_gen176[]  = "File exists";
static const char short_gen177[] = "**fileinuse";
static const char long_gen177[]  = "File in use by some process";
static const char short_gen178[] = "**filename";
static const char long_gen178[]  = "Invalid file name";
static const char short_gen179[] = "**filenamedir";
static const char long_gen179[]  = "Invalid or missing directory";
static const char short_gen180[] = "**filenamelong";
static const char long_gen180[]  = "Pathname too long";
static const char short_gen181[] = "**filenoexist";
static const char long_gen181[]  = "File does not exist";
static const char short_gen182[] = "**filenospace";
static const char long_gen182[]  = "Not enough space for file ";
static const char short_gen183[] = "**fileopunsupported";
static const char long_gen183[]  = "Unsupported file operation ";
static const char short_gen184[] = "**filequota";
static const char long_gen184[]  = "Quota exceeded for files";
static const char short_gen185[] = "**filerdonly";
static const char long_gen185[]  = "Read-only file or filesystem name";
static const char short_gen186[] = "**flag";
static const char long_gen186[]  = "invalid flag parameter";
static const char short_gen187[] = "**gethostbyname";
static const char long_gen187[]  = "gethostbyname failed";
static const char short_gen188[] = "**getsockname";
static const char long_gen188[]  = "getsockname failed";
static const char short_gen189[] = "**gpu_enqueue_noncontig";
static const char long_gen189[]  = "Non-contig datatype not supported due to missing TLS.";
static const char short_gen190[] = "**gpu_finalize";
static const char long_gen190[]  = " gpu_finalize failed";
static const char short_gen191[] = "**gpu_get_buffer_info";
static const char long_gen191[]  = " gpu_get_buffer_info failed";
static const char short_gen192[] = "**gpu_get_dev_count";
static const char long_gen192[]  = " gpu_get_dev_count failed";
static const char short_gen193[] = "**gpu_init";
static const char long_gen193[]  = " gpu_init failed";
static const char short_gen194[] = "**gpu_ipc_handle_create";
static const char long_gen194[]  = " gpu_ipc_handle_create failed";
static const char short_gen195[] = "**gpu_ipc_handle_map";
static const char long_gen195[]  = " gpu_ipc_handle_map failed";
static const char short_gen196[] = "**gpu_ipc_handle_unmap";
static const char long_gen196[]  = " gpu_ipc_handle_unmap failed";
static const char short_gen197[] = "**gpu_pipeline_packed";
static const char long_gen197[]  = " GPU pipelining does not support non-contiguous data types";
static const char short_gen198[] = "**gpu_query_ptr";
static const char long_gen198[]  = " gpu_query_pointer_attr failed";
static const char short_gen199[] = "**graphnnodes";
static const char long_gen199[]  = "Number of graph nodes exceeds size of communicator.";
static const char short_gen200[] = "**group";
static const char long_gen200[]  = "Invalid group";
static const char short_gen201[] = "**groupnotincomm";
static const char long_gen201[]  = "Specified group is not within the communicator";
static const char short_gen202[] = "**groupnull";
static const char long_gen202[]  = "Null group";
static const char short_gen203[] = "**groupperm";
static const char long_gen203[]  = "Cannot free permanent group";
static const char short_gen204[] = "**hcoll_wrong_arg";
static const char long_gen204[]  = "Error in hcolrte api: wrong null argument";
static const char short_gen205[] = "**iface_notfound";
static const char long_gen205[]  = "The network interface specified in MPIR_CVAR_CH3_NETWORK_IFACE was not found.";
static const char short_gen206[] = "**ifname_and_hostname";
static const char long_gen206[]  = "Only one of MPIR_CVAR_CH3_INTERFACE_HOSTNAME and MPIR_CVAR_CH3_NETWORK_IFACE environment variables are allowed, but both were set.";
static const char short_gen207[] = "**ifnameinvalid";
static const char long_gen207[]  = "Interface name was invalid in call to inet_pton";
static const char short_gen208[] = "**indexneg";
static const char long_gen208[]  = "Index value in graph topology must be nonnegative";
static const char short_gen209[] = "**indexnonmonotone";
static const char long_gen209[]  = "Index values in graph topology must be monotone nondecreasing";
static const char short_gen210[] = "**info";
static const char long_gen210[]  = "Invalid MPI_Info";
static const char short_gen211[] = "**infoenv";
static const char long_gen211[]  = "MPI_INFO_ENV is read-only";
static const char short_gen212[] = "**infohexinvalid";
static const char long_gen212[]  = "MPI_Info key value is invalid";
static const char short_gen213[] = "**infokey";
static const char long_gen213[]  = "Invalid key for MPI_Info ";
static const char short_gen214[] = "**infokeyempty";
static const char long_gen214[]  = "Empty or blank key ";
static const char short_gen215[] = "**infokeylong";
static const char long_gen215[]  = "Key is too long";
static const char short_gen216[] = "**infokeynull";
static const char long_gen216[]  = "Null key";
static const char short_gen217[] = "**infonkey";
static const char long_gen217[]  = "Requested nth key does not exist";
static const char short_gen218[] = "**infonokey";
static const char long_gen218[]  = "MPI_Info key is not defined ";
static const char short_gen219[] = "**infonoteq";
static const char long_gen219[]  = "MPI_Info key value are not consistent for all processes";
static const char short_gen220[] = "**infonull";
static const char long_gen220[]  = "Null MPI_Info ";
static const char short_gen221[] = "**infoval";
static const char long_gen221[]  = "Invalid MPI_Info value ";
static const char short_gen222[] = "**infovallong";
static const char long_gen222[]  = "Value is too long ";
static const char short_gen223[] = "**init_buscard";
static const char long_gen223[]  = "failed to get my business card";
static const char short_gen224[] = "**init_progress";
static const char long_gen224[]  = "progress_init failed";
static const char short_gen225[] = "**init_vcrt";
static const char long_gen225[]  = "failed to create VCRT";
static const char short_gen226[] = "**initialized";
static const char long_gen226[]  = "MPI not initialized. Call MPI_Init or MPI_Init_thread first";
static const char short_gen227[] = "**inittwice";
static const char long_gen227[]  = "Cannot call MPI_INIT or MPI_INIT_THREAD more than once";
static const char short_gen228[] = "**instatus";
static const char long_gen228[]  = "See the MPI_ERROR field in MPI_Status for the error code";
static const char short_gen229[] = "**intern";
static const char long_gen229[]  = "Internal MPI error!";
static const char short_gen230[] = "**invalid_handle";
static const char long_gen230[]  = "invalid handle";
static const char short_gen231[] = "**invalid_netmod";
static const char long_gen231[]  = "Invalid netmod specified";
static const char short_gen232[] = "**invalid_refcount";
static const char long_gen232[]  = "invalid reference count";
static const char short_gen233[] = "**invaliderrclass";
static const char long_gen233[]  = "Invalid error class given";
static const char short_gen234[] = "**invaliderrcode";
static const char long_gen234[]  = "Invalid error code given";
static const char short_gen235[] = "**invalidgpustream";
static const char long_gen235[]  = "Info hint 'type' is set, but info hint 'value' is invalid.";
static const char short_gen236[] = "**invalidmembind";
static const char long_gen236[]  = " Invalid bind object identifier.";
static const char short_gen237[] = "**invalidpkt";
static const char long_gen237[]  = " Invalid packet type";
static const char short_gen238[] = "**io";
static const char long_gen238[]  = "Other I/O error ";
static const char short_gen239[] = "**ioRMWrdwr";
static const char long_gen239[]  = "Must open file with MPI_MODE_RDWR for read-modify-write";
static const char short_gen240[] = "**ioagnomatch";
static const char long_gen240[]  = "No aggregators match";
static const char short_gen241[] = "**ioamodeseq";
static const char long_gen241[]  = "Cannot use this function when the file is opened with amode MPI_MODE_SEQUENTIAL ";
static const char short_gen242[] = "**iobadcount";
static const char long_gen242[]  = "Invalid count argument";
static const char short_gen243[] = "**iobaddisp";
static const char long_gen243[]  = "Invalid displacement argument";
static const char short_gen244[] = "**iobadfh";
static const char long_gen244[]  = "Invalid file handle";
static const char short_gen245[] = "**iobadoffset";
static const char long_gen245[]  = "Invalid offset argument";
static const char short_gen246[] = "**iobadoverlap";
static const char long_gen246[]  = " write voilates monotonically non-decreasing";
static const char short_gen247[] = "**iobadsize";
static const char long_gen247[]  = "Invalid size argument";
static const char short_gen248[] = "**iobadwhence";
static const char long_gen248[]  = "Invalid whence argument";
static const char short_gen249[] = "**iodatarepnomem";
static const char long_gen249[]  = "User must allocate memory for datarep";
static const char short_gen250[] = "**iodispifseq";
static const char long_gen250[]  = "disp must be set to MPI_DISPLACEMENT_CURRENT since file was opened with MPI_MODE_SEQUENTIAL";
static const char short_gen251[] = "**ioetype";
static const char long_gen251[]  = "Only an integral number of etypes can be accessed";
static const char short_gen252[] = "**iofiletype";
static const char long_gen252[]  = "Filetype must be constructed out of one or more etypes";
static const char short_gen253[] = "**iofstypeunsupported";
static const char long_gen253[]  = "Specified filesystem is not available";
static const char short_gen254[] = "**ioneedrd";
static const char long_gen254[]  = "Read access is required to this file";
static const char short_gen255[] = "**ionegoffset";
static const char long_gen255[]  = "Negative offset argument";
static const char short_gen256[] = "**iopreallocrdwr";
static const char long_gen256[]  = "Must open file with MPI_MODE_RDWR to preallocate disk space";
static const char short_gen257[] = "**iordonly";
static const char long_gen257[]  = "Cannot write to a file opened with amode MPI_MODE_RDONLY";
static const char short_gen258[] = "**iorsrc";
static const char long_gen258[]  = "Unable to read from the file as part of a strided read operation";
static const char short_gen259[] = "**iosequnsupported";
static const char long_gen259[]  = "MPI_MODE_SEQUENTIAL not supported on this file system";
static const char short_gen260[] = "**iosharedfailed";
static const char long_gen260[]  = "Could not access shared file pointer";
static const char short_gen261[] = "**iosharedunsupported";
static const char long_gen261[]  = "Shared file pointers not supported";
static const char short_gen262[] = "**iosplitcoll";
static const char long_gen262[]  = "Only one active split collective I/O operation is allowed per file handle";
static const char short_gen263[] = "**iosplitcollnone";
static const char long_gen263[]  = "No split collective I/O operation is active";
static const char short_gen264[] = "**iowronly";
static const char long_gen264[]  = "Cannot read from a file opened with amode MPI_MODE_WRONLY";
static const char short_gen265[] = "**iowsrc";
static const char long_gen265[]  = "Unable to read from the file as part of a strided write operation";
static const char short_gen266[] = "**iowswc";
static const char long_gen266[]  = "Unable to write to the file as part of a strided write operation";
static const char short_gen267[] = "**join_portname";
static const char long_gen267[]  = "local and remote port names are the same";
static const char short_gen268[] = "**join_recv";
static const char long_gen268[]  = "recv from the socket failed";
static const char short_gen269[] = "**join_send";
static const char long_gen269[]  = "send on the socket failed";
static const char short_gen270[] = "**keyval";
static const char long_gen270[]  = "Invalid keyval";
static const char short_gen271[] = "**keyvalinvalid";
static const char long_gen271[]  = "Attribute key was MPI_KEYVAL_INVALID";
static const char short_gen272[] = "**keyvalobj";
static const char long_gen272[]  = "Keyval was not defined for the supplied object";
static const char short_gen273[] = "**listen";
static const char long_gen273[]  = "listen failed";
static const char short_gen274[] = "**locktype";
static const char long_gen274[]  = "Invalid locktype argument";
static const char short_gen275[] = "**memcpyalias";
static const char long_gen275[]  = "memcpy arguments alias each other";
static const char short_gen276[] = "**missinggpustream";
static const char long_gen276[]  = "Info hint 'type' is set, but info hint 'value' is missing.";
static const char short_gen277[] = "**mpi_abort";
static const char long_gen277[]  = "MPI_Abort failed";
static const char short_gen278[] = "**mpi_accumulate";
static const char long_gen278[]  = "MPI_Accumulate failed";
static const char short_gen279[] = "**mpi_accumulate_c";
static const char long_gen279[]  = "MPI_Accumulate_c failed";
static const char short_gen280[] = "**mpi_add_error_class";
static const char long_gen280[]  = "MPI_Add_error_class failed";
static const char short_gen281[] = "**mpi_add_error_code";
static const char long_gen281[]  = "MPI_Add_error_code failed";
static const char short_gen282[] = "**mpi_add_error_string";
static const char long_gen282[]  = "MPI_Add_error_string failed";
static const char short_gen283[] = "**mpi_allgather";
static const char long_gen283[]  = "MPI_Allgather failed";
static const char short_gen284[] = "**mpi_allgather_c";
static const char long_gen284[]  = "MPI_Allgather_c failed";
static const char short_gen285[] = "**mpi_allgather_init";
static const char long_gen285[]  = "MPI_Allgather_init failed";
static const char short_gen286[] = "**mpi_allgather_init_c";
static const char long_gen286[]  = "MPI_Allgather_init_c failed";
static const char short_gen287[] = "**mpi_allgatherv";
static const char long_gen287[]  = "MPI_Allgatherv failed";
static const char short_gen288[] = "**mpi_allgatherv_c";
static const char long_gen288[]  = "MPI_Allgatherv_c failed";
static const char short_gen289[] = "**mpi_allgatherv_init";
static const char long_gen289[]  = "MPI_Allgatherv_init failed";
static const char short_gen290[] = "**mpi_allgatherv_init_c";
static const char long_gen290[]  = "MPI_Allgatherv_init_c failed";
static const char short_gen291[] = "**mpi_alloc_mem";
static const char long_gen291[]  = "MPI_Alloc_mem failed";
static const char short_gen292[] = "**mpi_allreduce";
static const char long_gen292[]  = "MPI_Allreduce failed";
static const char short_gen293[] = "**mpi_allreduce_c";
static const char long_gen293[]  = "MPI_Allreduce_c failed";
static const char short_gen294[] = "**mpi_allreduce_init";
static const char long_gen294[]  = "MPI_Allreduce_init failed";
static const char short_gen295[] = "**mpi_allreduce_init_c";
static const char long_gen295[]  = "MPI_Allreduce_init_c failed";
static const char short_gen296[] = "**mpi_alltoall";
static const char long_gen296[]  = "MPI_Alltoall failed";
static const char short_gen297[] = "**mpi_alltoall_c";
static const char long_gen297[]  = "MPI_Alltoall_c failed";
static const char short_gen298[] = "**mpi_alltoall_init";
static const char long_gen298[]  = "MPI_Alltoall_init failed";
static const char short_gen299[] = "**mpi_alltoall_init_c";
static const char long_gen299[]  = "MPI_Alltoall_init_c failed";
static const char short_gen300[] = "**mpi_alltoallv";
static const char long_gen300[]  = "MPI_Alltoallv failed";
static const char short_gen301[] = "**mpi_alltoallv_c";
static const char long_gen301[]  = "MPI_Alltoallv_c failed";
static const char short_gen302[] = "**mpi_alltoallv_init";
static const char long_gen302[]  = "MPI_Alltoallv_init failed";
static const char short_gen303[] = "**mpi_alltoallv_init_c";
static const char long_gen303[]  = "MPI_Alltoallv_init_c failed";
static const char short_gen304[] = "**mpi_alltoallw";
static const char long_gen304[]  = "MPI_Alltoallw failed";
static const char short_gen305[] = "**mpi_alltoallw_c";
static const char long_gen305[]  = "MPI_Alltoallw_c failed";
static const char short_gen306[] = "**mpi_alltoallw_init";
static const char long_gen306[]  = "MPI_Alltoallw_init failed";
static const char short_gen307[] = "**mpi_alltoallw_init_c";
static const char long_gen307[]  = "MPI_Alltoallw_init_c failed";
static const char short_gen308[] = "**mpi_barrier";
static const char long_gen308[]  = "MPI_Barrier failed";
static const char short_gen309[] = "**mpi_barrier_init";
static const char long_gen309[]  = "MPI_Barrier_init failed";
static const char short_gen310[] = "**mpi_bcast";
static const char long_gen310[]  = "MPI_Bcast failed";
static const char short_gen311[] = "**mpi_bcast_c";
static const char long_gen311[]  = "MPI_Bcast_c failed";
static const char short_gen312[] = "**mpi_bcast_init";
static const char long_gen312[]  = "MPI_Bcast_init failed";
static const char short_gen313[] = "**mpi_bcast_init_c";
static const char long_gen313[]  = "MPI_Bcast_init_c failed";
static const char short_gen314[] = "**mpi_bsend";
static const char long_gen314[]  = "MPI_Bsend failed";
static const char short_gen315[] = "**mpi_bsend_c";
static const char long_gen315[]  = "MPI_Bsend_c failed";
static const char short_gen316[] = "**mpi_bsend_init";
static const char long_gen316[]  = "MPI_Bsend_init failed";
static const char short_gen317[] = "**mpi_bsend_init_c";
static const char long_gen317[]  = "MPI_Bsend_init_c failed";
static const char short_gen318[] = "**mpi_buffer_attach";
static const char long_gen318[]  = "MPI_Buffer_attach failed";
static const char short_gen319[] = "**mpi_buffer_attach_c";
static const char long_gen319[]  = "MPI_Buffer_attach_c failed";
static const char short_gen320[] = "**mpi_buffer_detach";
static const char long_gen320[]  = "MPI_Buffer_detach failed";
static const char short_gen321[] = "**mpi_buffer_detach_c";
static const char long_gen321[]  = "MPI_Buffer_detach_c failed";
static const char short_gen322[] = "**mpi_buffer_flush";
static const char long_gen322[]  = "MPI_Buffer_flush failed";
static const char short_gen323[] = "**mpi_buffer_iflush";
static const char long_gen323[]  = "MPI_Buffer_iflush failed";
static const char short_gen324[] = "**mpi_cancel";
static const char long_gen324[]  = "MPI_Cancel failed";
static const char short_gen325[] = "**mpi_cart_coords";
static const char long_gen325[]  = "MPI_Cart_coords failed";
static const char short_gen326[] = "**mpi_cart_create";
static const char long_gen326[]  = "MPI_Cart_create failed";
static const char short_gen327[] = "**mpi_cart_get";
static const char long_gen327[]  = "MPI_Cart_get failed";
static const char short_gen328[] = "**mpi_cart_map";
static const char long_gen328[]  = "MPI_Cart_map failed";
static const char short_gen329[] = "**mpi_cart_rank";
static const char long_gen329[]  = "MPI_Cart_rank failed";
static const char short_gen330[] = "**mpi_cart_shift";
static const char long_gen330[]  = "MPI_Cart_shift failed";
static const char short_gen331[] = "**mpi_cart_sub";
static const char long_gen331[]  = "MPI_Cart_sub failed";
static const char short_gen332[] = "**mpi_cartdim_get";
static const char long_gen332[]  = "MPI_Cartdim_get failed";
static const char short_gen333[] = "**mpi_close_port";
static const char long_gen333[]  = "MPI_Close_port failed";
static const char short_gen334[] = "**mpi_comm_accept";
static const char long_gen334[]  = "MPI_Comm_accept failed";
static const char short_gen335[] = "**mpi_comm_attach_buffer";
static const char long_gen335[]  = "MPI_Comm_attach_buffer failed";
static const char short_gen336[] = "**mpi_comm_attach_buffer_c";
static const char long_gen336[]  = "MPI_Comm_attach_buffer_c failed";
static const char short_gen337[] = "**mpi_comm_call_errhandler";
static const char long_gen337[]  = "MPI_Comm_call_errhandler failed";
static const char short_gen338[] = "**mpi_comm_compare";
static const char long_gen338[]  = "MPI_Comm_compare failed";
static const char short_gen339[] = "**mpi_comm_connect";
static const char long_gen339[]  = "MPI_Comm_connect failed";
static const char short_gen340[] = "**mpi_comm_create";
static const char long_gen340[]  = "MPI_Comm_create failed";
static const char short_gen341[] = "**mpi_comm_create_errhandler";
static const char long_gen341[]  = "MPI_Comm_create_errhandler failed";
static const char short_gen342[] = "**mpi_comm_create_from_group";
static const char long_gen342[]  = "MPI_Comm_create_from_group failed";
static const char short_gen343[] = "**mpi_comm_create_group";
static const char long_gen343[]  = "MPI_Comm_create_group failed";
static const char short_gen344[] = "**mpi_comm_create_keyval";
static const char long_gen344[]  = "MPI_Comm_create_keyval failed";
static const char short_gen345[] = "**mpi_comm_delete_attr";
static const char long_gen345[]  = "MPI_Comm_delete_attr failed";
static const char short_gen346[] = "**mpi_comm_detach_buffer";
static const char long_gen346[]  = "MPI_Comm_detach_buffer failed";
static const char short_gen347[] = "**mpi_comm_detach_buffer_c";
static const char long_gen347[]  = "MPI_Comm_detach_buffer_c failed";
static const char short_gen348[] = "**mpi_comm_disconnect";
static const char long_gen348[]  = "MPI_Comm_disconnect failed";
static const char short_gen349[] = "**mpi_comm_dup";
static const char long_gen349[]  = "MPI_Comm_dup failed";
static const char short_gen350[] = "**mpi_comm_dup_with_info";
static const char long_gen350[]  = "MPI_Comm_dup_with_info failed";
static const char short_gen351[] = "**mpi_comm_flush_buffer";
static const char long_gen351[]  = "MPI_Comm_flush_buffer failed";
static const char short_gen352[] = "**mpi_comm_free";
static const char long_gen352[]  = "MPI_Comm_free failed";
static const char short_gen353[] = "**mpi_comm_free_keyval";
static const char long_gen353[]  = "MPI_Comm_free_keyval failed";
static const char short_gen354[] = "**mpi_comm_get_attr";
static const char long_gen354[]  = "MPI_Comm_get_attr failed";
static const char short_gen355[] = "**mpi_comm_get_errhandler";
static const char long_gen355[]  = "MPI_Comm_get_errhandler failed";
static const char short_gen356[] = "**mpi_comm_get_info";
static const char long_gen356[]  = "MPI_Comm_get_info failed";
static const char short_gen357[] = "**mpi_comm_get_name";
static const char long_gen357[]  = "MPI_Comm_get_name failed";
static const char short_gen358[] = "**mpi_comm_get_parent";
static const char long_gen358[]  = "MPI_Comm_get_parent failed";
static const char short_gen359[] = "**mpi_comm_group";
static const char long_gen359[]  = "MPI_Comm_group failed";
static const char short_gen360[] = "**mpi_comm_idup";
static const char long_gen360[]  = "MPI_Comm_idup failed";
static const char short_gen361[] = "**mpi_comm_idup_with_info";
static const char long_gen361[]  = "MPI_Comm_idup_with_info failed";
static const char short_gen362[] = "**mpi_comm_iflush_buffer";
static const char long_gen362[]  = "MPI_Comm_iflush_buffer failed";
static const char short_gen363[] = "**mpi_comm_join";
static const char long_gen363[]  = "MPI_Comm_join failed";
static const char short_gen364[] = "**mpi_comm_rank";
static const char long_gen364[]  = "MPI_Comm_rank failed";
static const char short_gen365[] = "**mpi_comm_remote_group";
static const char long_gen365[]  = "MPI_Comm_remote_group failed";
static const char short_gen366[] = "**mpi_comm_remote_size";
static const char long_gen366[]  = "MPI_Comm_remote_size failed";
static const char short_gen367[] = "**mpi_comm_set_attr";
static const char long_gen367[]  = "MPI_Comm_set_attr failed";
static const char short_gen368[] = "**mpi_comm_set_errhandler";
static const char long_gen368[]  = "MPI_Comm_set_errhandler failed";
static const char short_gen369[] = "**mpi_comm_set_info";
static const char long_gen369[]  = "MPI_Comm_set_info failed";
static const char short_gen370[] = "**mpi_comm_set_name";
static const char long_gen370[]  = "MPI_Comm_set_name failed";
static const char short_gen371[] = "**mpi_comm_size";
static const char long_gen371[]  = "MPI_Comm_size failed";
static const char short_gen372[] = "**mpi_comm_spawn";
static const char long_gen372[]  = "MPI_Comm_spawn failed";
static const char short_gen373[] = "**mpi_comm_spawn_multiple";
static const char long_gen373[]  = "MPI_Comm_spawn_multiple failed";
static const char short_gen374[] = "**mpi_comm_split";
static const char long_gen374[]  = "MPI_Comm_split failed";
static const char short_gen375[] = "**mpi_comm_split_type";
static const char long_gen375[]  = "MPI_Comm_split_type failed";
static const char short_gen376[] = "**mpi_comm_test_inter";
static const char long_gen376[]  = "MPI_Comm_test_inter failed";
static const char short_gen377[] = "**mpi_compare_and_swap";
static const char long_gen377[]  = "MPI_Compare_and_swap failed";
static const char short_gen378[] = "**mpi_dims_create";
static const char long_gen378[]  = "MPI_Dims_create failed";
static const char short_gen379[] = "**mpi_dist_graph_create";
static const char long_gen379[]  = "MPI_Dist_graph_create failed";
static const char short_gen380[] = "**mpi_dist_graph_create_adjacent";
static const char long_gen380[]  = "MPI_Dist_graph_create_adjacent failed";
static const char short_gen381[] = "**mpi_dist_graph_neighbors";
static const char long_gen381[]  = "MPI_Dist_graph_neighbors failed";
static const char short_gen382[] = "**mpi_dist_graph_neighbors_count";
static const char long_gen382[]  = "MPI_Dist_graph_neighbors_count failed";
static const char short_gen383[] = "**mpi_errhandler_free";
static const char long_gen383[]  = "MPI_Errhandler_free failed";
static const char short_gen384[] = "**mpi_error_class";
static const char long_gen384[]  = "MPI_Error_class failed";
static const char short_gen385[] = "**mpi_error_string";
static const char long_gen385[]  = "MPI_Error_string failed";
static const char short_gen386[] = "**mpi_exscan";
static const char long_gen386[]  = "MPI_Exscan failed";
static const char short_gen387[] = "**mpi_exscan_c";
static const char long_gen387[]  = "MPI_Exscan_c failed";
static const char short_gen388[] = "**mpi_exscan_init";
static const char long_gen388[]  = "MPI_Exscan_init failed";
static const char short_gen389[] = "**mpi_exscan_init_c";
static const char long_gen389[]  = "MPI_Exscan_init_c failed";
static const char short_gen390[] = "**mpi_fetch_and_op";
static const char long_gen390[]  = "MPI_Fetch_and_op failed";
static const char short_gen391[] = "**mpi_file_call_errhandler";
static const char long_gen391[]  = "MPI_File_call_errhandler failed";
static const char short_gen392[] = "**mpi_file_create_errhandler";
static const char long_gen392[]  = "MPI_File_create_errhandler failed";
static const char short_gen393[] = "**mpi_file_get_errhandler";
static const char long_gen393[]  = "MPI_File_get_errhandler failed";
static const char short_gen394[] = "**mpi_file_set_errhandler";
static const char long_gen394[]  = "MPI_File_set_errhandler failed";
static const char short_gen395[] = "**mpi_finalize";
static const char long_gen395[]  = "MPI_Finalize failed";
static const char short_gen396[] = "**mpi_finalized";
static const char long_gen396[]  = "MPI_Finalized failed";
static const char short_gen397[] = "**mpi_free_mem";
static const char long_gen397[]  = "MPI_Free_mem failed";
static const char short_gen398[] = "**mpi_gather";
static const char long_gen398[]  = "MPI_Gather failed";
static const char short_gen399[] = "**mpi_gather_c";
static const char long_gen399[]  = "MPI_Gather_c failed";
static const char short_gen400[] = "**mpi_gather_init";
static const char long_gen400[]  = "MPI_Gather_init failed";
static const char short_gen401[] = "**mpi_gather_init_c";
static const char long_gen401[]  = "MPI_Gather_init_c failed";
static const char short_gen402[] = "**mpi_gatherv";
static const char long_gen402[]  = "MPI_Gatherv failed";
static const char short_gen403[] = "**mpi_gatherv_c";
static const char long_gen403[]  = "MPI_Gatherv_c failed";
static const char short_gen404[] = "**mpi_gatherv_init";
static const char long_gen404[]  = "MPI_Gatherv_init failed";
static const char short_gen405[] = "**mpi_gatherv_init_c";
static const char long_gen405[]  = "MPI_Gatherv_init_c failed";
static const char short_gen406[] = "**mpi_get";
static const char long_gen406[]  = "MPI_Get failed";
static const char short_gen407[] = "**mpi_get_accumulate";
static const char long_gen407[]  = "MPI_Get_accumulate failed";
static const char short_gen408[] = "**mpi_get_accumulate_c";
static const char long_gen408[]  = "MPI_Get_accumulate_c failed";
static const char short_gen409[] = "**mpi_get_address";
static const char long_gen409[]  = "MPI_Get_address failed";
static const char short_gen410[] = "**mpi_get_c";
static const char long_gen410[]  = "MPI_Get_c failed";
static const char short_gen411[] = "**mpi_get_count";
static const char long_gen411[]  = "MPI_Get_count failed";
static const char short_gen412[] = "**mpi_get_count_c";
static const char long_gen412[]  = "MPI_Get_count_c failed";
static const char short_gen413[] = "**mpi_get_elements";
static const char long_gen413[]  = "MPI_Get_elements failed";
static const char short_gen414[] = "**mpi_get_elements_c";
static const char long_gen414[]  = "MPI_Get_elements_c failed";
static const char short_gen415[] = "**mpi_get_elements_x";
static const char long_gen415[]  = "MPI_Get_elements_x failed";
static const char short_gen416[] = "**mpi_get_hw_resource_info";
static const char long_gen416[]  = "MPI_Get_hw_resource_info failed";
static const char short_gen417[] = "**mpi_get_library_version";
static const char long_gen417[]  = "MPI_Get_library_version failed";
static const char short_gen418[] = "**mpi_get_processor_name";
static const char long_gen418[]  = "MPI_Get_processor_name failed";
static const char short_gen419[] = "**mpi_get_version";
static const char long_gen419[]  = "MPI_Get_version failed";
static const char short_gen420[] = "**mpi_graph_create";
static const char long_gen420[]  = "MPI_Graph_create failed";
static const char short_gen421[] = "**mpi_graph_get";
static const char long_gen421[]  = "MPI_Graph_get failed";
static const char short_gen422[] = "**mpi_graph_map";
static const char long_gen422[]  = "MPI_Graph_map failed";
static const char short_gen423[] = "**mpi_graph_neighbors";
static const char long_gen423[]  = "MPI_Graph_neighbors failed";
static const char short_gen424[] = "**mpi_graph_neighbors_count";
static const char long_gen424[]  = "MPI_Graph_neighbors_count failed";
static const char short_gen425[] = "**mpi_graphdims_get";
static const char long_gen425[]  = "MPI_Graphdims_get failed";
static const char short_gen426[] = "**mpi_grequest_complete";
static const char long_gen426[]  = "MPI_Grequest_complete failed";
static const char short_gen427[] = "**mpi_grequest_start";
static const char long_gen427[]  = "MPI_Grequest_start failed";
static const char short_gen428[] = "**mpi_group_compare";
static const char long_gen428[]  = "MPI_Group_compare failed";
static const char short_gen429[] = "**mpi_group_difference";
static const char long_gen429[]  = "MPI_Group_difference failed";
static const char short_gen430[] = "**mpi_group_excl";
static const char long_gen430[]  = "MPI_Group_excl failed";
static const char short_gen431[] = "**mpi_group_free";
static const char long_gen431[]  = "MPI_Group_free failed";
static const char short_gen432[] = "**mpi_group_from_session_pset";
static const char long_gen432[]  = "MPI_Group_from_session_pset failed";
static const char short_gen433[] = "**mpi_group_incl";
static const char long_gen433[]  = "MPI_Group_incl failed";
static const char short_gen434[] = "**mpi_group_intersection";
static const char long_gen434[]  = "MPI_Group_intersection failed";
static const char short_gen435[] = "**mpi_group_range_excl";
static const char long_gen435[]  = "MPI_Group_range_excl failed";
static const char short_gen436[] = "**mpi_group_range_incl";
static const char long_gen436[]  = "MPI_Group_range_incl failed";
static const char short_gen437[] = "**mpi_group_rank";
static const char long_gen437[]  = "MPI_Group_rank failed";
static const char short_gen438[] = "**mpi_group_size";
static const char long_gen438[]  = "MPI_Group_size failed";
static const char short_gen439[] = "**mpi_group_translate_ranks";
static const char long_gen439[]  = "MPI_Group_translate_ranks failed";
static const char short_gen440[] = "**mpi_group_union";
static const char long_gen440[]  = "MPI_Group_union failed";
static const char short_gen441[] = "**mpi_iallgather";
static const char long_gen441[]  = "MPI_Iallgather failed";
static const char short_gen442[] = "**mpi_iallgather_c";
static const char long_gen442[]  = "MPI_Iallgather_c failed";
static const char short_gen443[] = "**mpi_iallgatherv";
static const char long_gen443[]  = "MPI_Iallgatherv failed";
static const char short_gen444[] = "**mpi_iallgatherv_c";
static const char long_gen444[]  = "MPI_Iallgatherv_c failed";
static const char short_gen445[] = "**mpi_iallreduce";
static const char long_gen445[]  = "MPI_Iallreduce failed";
static const char short_gen446[] = "**mpi_iallreduce_c";
static const char long_gen446[]  = "MPI_Iallreduce_c failed";
static const char short_gen447[] = "**mpi_ialltoall";
static const char long_gen447[]  = "MPI_Ialltoall failed";
static const char short_gen448[] = "**mpi_ialltoall_c";
static const char long_gen448[]  = "MPI_Ialltoall_c failed";
static const char short_gen449[] = "**mpi_ialltoallv";
static const char long_gen449[]  = "MPI_Ialltoallv failed";
static const char short_gen450[] = "**mpi_ialltoallv_c";
static const char long_gen450[]  = "MPI_Ialltoallv_c failed";
static const char short_gen451[] = "**mpi_ialltoallw";
static const char long_gen451[]  = "MPI_Ialltoallw failed";
static const char short_gen452[] = "**mpi_ialltoallw_c";
static const char long_gen452[]  = "MPI_Ialltoallw_c failed";
static const char short_gen453[] = "**mpi_ibarrier";
static const char long_gen453[]  = "MPI_Ibarrier failed";
static const char short_gen454[] = "**mpi_ibcast";
static const char long_gen454[]  = "MPI_Ibcast failed";
static const char short_gen455[] = "**mpi_ibcast_c";
static const char long_gen455[]  = "MPI_Ibcast_c failed";
static const char short_gen456[] = "**mpi_ibsend";
static const char long_gen456[]  = "MPI_Ibsend failed";
static const char short_gen457[] = "**mpi_ibsend_c";
static const char long_gen457[]  = "MPI_Ibsend_c failed";
static const char short_gen458[] = "**mpi_iexscan";
static const char long_gen458[]  = "MPI_Iexscan failed";
static const char short_gen459[] = "**mpi_iexscan_c";
static const char long_gen459[]  = "MPI_Iexscan_c failed";
static const char short_gen460[] = "**mpi_igather";
static const char long_gen460[]  = "MPI_Igather failed";
static const char short_gen461[] = "**mpi_igather_c";
static const char long_gen461[]  = "MPI_Igather_c failed";
static const char short_gen462[] = "**mpi_igatherv";
static const char long_gen462[]  = "MPI_Igatherv failed";
static const char short_gen463[] = "**mpi_igatherv_c";
static const char long_gen463[]  = "MPI_Igatherv_c failed";
static const char short_gen464[] = "**mpi_improbe";
static const char long_gen464[]  = "MPI_Improbe failed";
static const char short_gen465[] = "**mpi_imrecv";
static const char long_gen465[]  = "MPI_Imrecv failed";
static const char short_gen466[] = "**mpi_imrecv_c";
static const char long_gen466[]  = "MPI_Imrecv_c failed";
static const char short_gen467[] = "**mpi_ineighbor_allgather";
static const char long_gen467[]  = "MPI_Ineighbor_allgather failed";
static const char short_gen468[] = "**mpi_ineighbor_allgather_c";
static const char long_gen468[]  = "MPI_Ineighbor_allgather_c failed";
static const char short_gen469[] = "**mpi_ineighbor_allgatherv";
static const char long_gen469[]  = "MPI_Ineighbor_allgatherv failed";
static const char short_gen470[] = "**mpi_ineighbor_allgatherv_c";
static const char long_gen470[]  = "MPI_Ineighbor_allgatherv_c failed";
static const char short_gen471[] = "**mpi_ineighbor_alltoall";
static const char long_gen471[]  = "MPI_Ineighbor_alltoall failed";
static const char short_gen472[] = "**mpi_ineighbor_alltoall_c";
static const char long_gen472[]  = "MPI_Ineighbor_alltoall_c failed";
static const char short_gen473[] = "**mpi_ineighbor_alltoallv";
static const char long_gen473[]  = "MPI_Ineighbor_alltoallv failed";
static const char short_gen474[] = "**mpi_ineighbor_alltoallv_c";
static const char long_gen474[]  = "MPI_Ineighbor_alltoallv_c failed";
static const char short_gen475[] = "**mpi_ineighbor_alltoallw";
static const char long_gen475[]  = "MPI_Ineighbor_alltoallw failed";
static const char short_gen476[] = "**mpi_ineighbor_alltoallw_c";
static const char long_gen476[]  = "MPI_Ineighbor_alltoallw_c failed";
static const char short_gen477[] = "**mpi_info_create";
static const char long_gen477[]  = "MPI_Info_create failed";
static const char short_gen478[] = "**mpi_info_create_env";
static const char long_gen478[]  = "MPI_Info_create_env failed";
static const char short_gen479[] = "**mpi_info_delete";
static const char long_gen479[]  = "MPI_Info_delete failed";
static const char short_gen480[] = "**mpi_info_dup";
static const char long_gen480[]  = "MPI_Info_dup failed";
static const char short_gen481[] = "**mpi_info_free";
static const char long_gen481[]  = "MPI_Info_free failed";
static const char short_gen482[] = "**mpi_info_get";
static const char long_gen482[]  = "MPI_Info_get failed";
static const char short_gen483[] = "**mpi_info_get_nkeys";
static const char long_gen483[]  = "MPI_Info_get_nkeys failed";
static const char short_gen484[] = "**mpi_info_get_nthkey";
static const char long_gen484[]  = "MPI_Info_get_nthkey failed";
static const char short_gen485[] = "**mpi_info_get_string";
static const char long_gen485[]  = "MPI_Info_get_string failed";
static const char short_gen486[] = "**mpi_info_get_valuelen";
static const char long_gen486[]  = "MPI_Info_get_valuelen failed";
static const char short_gen487[] = "**mpi_info_set";
static const char long_gen487[]  = "MPI_Info_set failed";
static const char short_gen488[] = "**mpi_init";
static const char long_gen488[]  = "MPI_Init failed";
static const char short_gen489[] = "**mpi_init_thread";
static const char long_gen489[]  = "MPI_Init_thread failed";
static const char short_gen490[] = "**mpi_initialized";
static const char long_gen490[]  = "MPI_Initialized failed";
static const char short_gen491[] = "**mpi_intercomm_create";
static const char long_gen491[]  = "MPI_Intercomm_create failed";
static const char short_gen492[] = "**mpi_intercomm_create_from_groups";
static const char long_gen492[]  = "MPI_Intercomm_create_from_groups failed";
static const char short_gen493[] = "**mpi_intercomm_merge";
static const char long_gen493[]  = "MPI_Intercomm_merge failed";
static const char short_gen494[] = "**mpi_iprobe";
static const char long_gen494[]  = "MPI_Iprobe failed";
static const char short_gen495[] = "**mpi_irecv";
static const char long_gen495[]  = "MPI_Irecv failed";
static const char short_gen496[] = "**mpi_irecv_c";
static const char long_gen496[]  = "MPI_Irecv_c failed";
static const char short_gen497[] = "**mpi_ireduce";
static const char long_gen497[]  = "MPI_Ireduce failed";
static const char short_gen498[] = "**mpi_ireduce_c";
static const char long_gen498[]  = "MPI_Ireduce_c failed";
static const char short_gen499[] = "**mpi_ireduce_scatter";
static const char long_gen499[]  = "MPI_Ireduce_scatter failed";
static const char short_gen500[] = "**mpi_ireduce_scatter_block";
static const char long_gen500[]  = "MPI_Ireduce_scatter_block failed";
static const char short_gen501[] = "**mpi_ireduce_scatter_block_c";
static const char long_gen501[]  = "MPI_Ireduce_scatter_block_c failed";
static const char short_gen502[] = "**mpi_ireduce_scatter_c";
static const char long_gen502[]  = "MPI_Ireduce_scatter_c failed";
static const char short_gen503[] = "**mpi_irsend";
static const char long_gen503[]  = "MPI_Irsend failed";
static const char short_gen504[] = "**mpi_irsend_c";
static const char long_gen504[]  = "MPI_Irsend_c failed";
static const char short_gen505[] = "**mpi_is_thread_main";
static const char long_gen505[]  = "MPI_Is_thread_main failed";
static const char short_gen506[] = "**mpi_iscan";
static const char long_gen506[]  = "MPI_Iscan failed";
static const char short_gen507[] = "**mpi_iscan_c";
static const char long_gen507[]  = "MPI_Iscan_c failed";
static const char short_gen508[] = "**mpi_iscatter";
static const char long_gen508[]  = "MPI_Iscatter failed";
static const char short_gen509[] = "**mpi_iscatter_c";
static const char long_gen509[]  = "MPI_Iscatter_c failed";
static const char short_gen510[] = "**mpi_iscatterv";
static const char long_gen510[]  = "MPI_Iscatterv failed";
static const char short_gen511[] = "**mpi_iscatterv_c";
static const char long_gen511[]  = "MPI_Iscatterv_c failed";
static const char short_gen512[] = "**mpi_isend";
static const char long_gen512[]  = "MPI_Isend failed";
static const char short_gen513[] = "**mpi_isend_c";
static const char long_gen513[]  = "MPI_Isend_c failed";
static const char short_gen514[] = "**mpi_isendrecv";
static const char long_gen514[]  = "MPI_Isendrecv failed";
static const char short_gen515[] = "**mpi_isendrecv_c";
static const char long_gen515[]  = "MPI_Isendrecv_c failed";
static const char short_gen516[] = "**mpi_isendrecv_replace";
static const char long_gen516[]  = "MPI_Isendrecv_replace failed";
static const char short_gen517[] = "**mpi_isendrecv_replace_c";
static const char long_gen517[]  = "MPI_Isendrecv_replace_c failed";
static const char short_gen518[] = "**mpi_issend";
static const char long_gen518[]  = "MPI_Issend failed";
static const char short_gen519[] = "**mpi_issend_c";
static const char long_gen519[]  = "MPI_Issend_c failed";
static const char short_gen520[] = "**mpi_lookup_name";
static const char long_gen520[]  = "MPI_Lookup_name failed";
static const char short_gen521[] = "**mpi_mprobe";
static const char long_gen521[]  = "MPI_Mprobe failed";
static const char short_gen522[] = "**mpi_mrecv";
static const char long_gen522[]  = "MPI_Mrecv failed";
static const char short_gen523[] = "**mpi_mrecv_c";
static const char long_gen523[]  = "MPI_Mrecv_c failed";
static const char short_gen524[] = "**mpi_neighbor_allgather";
static const char long_gen524[]  = "MPI_Neighbor_allgather failed";
static const char short_gen525[] = "**mpi_neighbor_allgather_c";
static const char long_gen525[]  = "MPI_Neighbor_allgather_c failed";
static const char short_gen526[] = "**mpi_neighbor_allgather_init";
static const char long_gen526[]  = "MPI_Neighbor_allgather_init failed";
static const char short_gen527[] = "**mpi_neighbor_allgather_init_c";
static const char long_gen527[]  = "MPI_Neighbor_allgather_init_c failed";
static const char short_gen528[] = "**mpi_neighbor_allgatherv";
static const char long_gen528[]  = "MPI_Neighbor_allgatherv failed";
static const char short_gen529[] = "**mpi_neighbor_allgatherv_c";
static const char long_gen529[]  = "MPI_Neighbor_allgatherv_c failed";
static const char short_gen530[] = "**mpi_neighbor_allgatherv_init";
static const char long_gen530[]  = "MPI_Neighbor_allgatherv_init failed";
static const char short_gen531[] = "**mpi_neighbor_allgatherv_init_c";
static const char long_gen531[]  = "MPI_Neighbor_allgatherv_init_c failed";
static const char short_gen532[] = "**mpi_neighbor_alltoall";
static const char long_gen532[]  = "MPI_Neighbor_alltoall failed";
static const char short_gen533[] = "**mpi_neighbor_alltoall_c";
static const char long_gen533[]  = "MPI_Neighbor_alltoall_c failed";
static const char short_gen534[] = "**mpi_neighbor_alltoall_init";
static const char long_gen534[]  = "MPI_Neighbor_alltoall_init failed";
static const char short_gen535[] = "**mpi_neighbor_alltoall_init_c";
static const char long_gen535[]  = "MPI_Neighbor_alltoall_init_c failed";
static const char short_gen536[] = "**mpi_neighbor_alltoallv";
static const char long_gen536[]  = "MPI_Neighbor_alltoallv failed";
static const char short_gen537[] = "**mpi_neighbor_alltoallv_c";
static const char long_gen537[]  = "MPI_Neighbor_alltoallv_c failed";
static const char short_gen538[] = "**mpi_neighbor_alltoallv_init";
static const char long_gen538[]  = "MPI_Neighbor_alltoallv_init failed";
static const char short_gen539[] = "**mpi_neighbor_alltoallv_init_c";
static const char long_gen539[]  = "MPI_Neighbor_alltoallv_init_c failed";
static const char short_gen540[] = "**mpi_neighbor_alltoallw";
static const char long_gen540[]  = "MPI_Neighbor_alltoallw failed";
static const char short_gen541[] = "**mpi_neighbor_alltoallw_c";
static const char long_gen541[]  = "MPI_Neighbor_alltoallw_c failed";
static const char short_gen542[] = "**mpi_neighbor_alltoallw_init";
static const char long_gen542[]  = "MPI_Neighbor_alltoallw_init failed";
static const char short_gen543[] = "**mpi_neighbor_alltoallw_init_c";
static const char long_gen543[]  = "MPI_Neighbor_alltoallw_init_c failed";
static const char short_gen544[] = "**mpi_op_commutative";
static const char long_gen544[]  = "MPI_Op_commutative failed";
static const char short_gen545[] = "**mpi_op_create";
static const char long_gen545[]  = "MPI_Op_create failed";
static const char short_gen546[] = "**mpi_op_create_c";
static const char long_gen546[]  = "MPI_Op_create_c failed";
static const char short_gen547[] = "**mpi_op_free";
static const char long_gen547[]  = "MPI_Op_free failed";
static const char short_gen548[] = "**mpi_open_port";
static const char long_gen548[]  = "MPI_Open_port failed";
static const char short_gen549[] = "**mpi_pack";
static const char long_gen549[]  = "MPI_Pack failed";
static const char short_gen550[] = "**mpi_pack_c";
static const char long_gen550[]  = "MPI_Pack_c failed";
static const char short_gen551[] = "**mpi_pack_external";
static const char long_gen551[]  = "MPI_Pack_external failed";
static const char short_gen552[] = "**mpi_pack_external_c";
static const char long_gen552[]  = "MPI_Pack_external_c failed";
static const char short_gen553[] = "**mpi_pack_external_size";
static const char long_gen553[]  = "MPI_Pack_external_size failed";
static const char short_gen554[] = "**mpi_pack_external_size_c";
static const char long_gen554[]  = "MPI_Pack_external_size_c failed";
static const char short_gen555[] = "**mpi_pack_size";
static const char long_gen555[]  = "MPI_Pack_size failed";
static const char short_gen556[] = "**mpi_pack_size_c";
static const char long_gen556[]  = "MPI_Pack_size_c failed";
static const char short_gen557[] = "**mpi_parrived";
static const char long_gen557[]  = "MPI_Parrived failed";
static const char short_gen558[] = "**mpi_pready";
static const char long_gen558[]  = "MPI_Pready failed";
static const char short_gen559[] = "**mpi_pready_list";
static const char long_gen559[]  = "MPI_Pready_list failed";
static const char short_gen560[] = "**mpi_pready_range";
static const char long_gen560[]  = "MPI_Pready_range failed";
static const char short_gen561[] = "**mpi_precv_init";
static const char long_gen561[]  = "MPI_Precv_init failed";
static const char short_gen562[] = "**mpi_probe";
static const char long_gen562[]  = "MPI_Probe failed";
static const char short_gen563[] = "**mpi_psend_init";
static const char long_gen563[]  = "MPI_Psend_init failed";
static const char short_gen564[] = "**mpi_publish_name";
static const char long_gen564[]  = "MPI_Publish_name failed";
static const char short_gen565[] = "**mpi_put";
static const char long_gen565[]  = "MPI_Put failed";
static const char short_gen566[] = "**mpi_put_c";
static const char long_gen566[]  = "MPI_Put_c failed";
static const char short_gen567[] = "**mpi_query_thread";
static const char long_gen567[]  = "MPI_Query_thread failed";
static const char short_gen568[] = "**mpi_raccumulate";
static const char long_gen568[]  = "MPI_Raccumulate failed";
static const char short_gen569[] = "**mpi_raccumulate_c";
static const char long_gen569[]  = "MPI_Raccumulate_c failed";
static const char short_gen570[] = "**mpi_recv";
static const char long_gen570[]  = "MPI_Recv failed";
static const char short_gen571[] = "**mpi_recv_c";
static const char long_gen571[]  = "MPI_Recv_c failed";
static const char short_gen572[] = "**mpi_recv_init";
static const char long_gen572[]  = "MPI_Recv_init failed";
static const char short_gen573[] = "**mpi_recv_init_c";
static const char long_gen573[]  = "MPI_Recv_init_c failed";
static const char short_gen574[] = "**mpi_reduce";
static const char long_gen574[]  = "MPI_Reduce failed";
static const char short_gen575[] = "**mpi_reduce_c";
static const char long_gen575[]  = "MPI_Reduce_c failed";
static const char short_gen576[] = "**mpi_reduce_init";
static const char long_gen576[]  = "MPI_Reduce_init failed";
static const char short_gen577[] = "**mpi_reduce_init_c";
static const char long_gen577[]  = "MPI_Reduce_init_c failed";
static const char short_gen578[] = "**mpi_reduce_local";
static const char long_gen578[]  = "MPI_Reduce_local failed";
static const char short_gen579[] = "**mpi_reduce_local_c";
static const char long_gen579[]  = "MPI_Reduce_local_c failed";
static const char short_gen580[] = "**mpi_reduce_scatter";
static const char long_gen580[]  = "MPI_Reduce_scatter failed";
static const char short_gen581[] = "**mpi_reduce_scatter_block";
static const char long_gen581[]  = "MPI_Reduce_scatter_block failed";
static const char short_gen582[] = "**mpi_reduce_scatter_block_c";
static const char long_gen582[]  = "MPI_Reduce_scatter_block_c failed";
static const char short_gen583[] = "**mpi_reduce_scatter_block_init";
static const char long_gen583[]  = "MPI_Reduce_scatter_block_init failed";
static const char short_gen584[] = "**mpi_reduce_scatter_block_init_c";
static const char long_gen584[]  = "MPI_Reduce_scatter_block_init_c failed";
static const char short_gen585[] = "**mpi_reduce_scatter_c";
static const char long_gen585[]  = "MPI_Reduce_scatter_c failed";
static const char short_gen586[] = "**mpi_reduce_scatter_init";
static const char long_gen586[]  = "MPI_Reduce_scatter_init failed";
static const char short_gen587[] = "**mpi_reduce_scatter_init_c";
static const char long_gen587[]  = "MPI_Reduce_scatter_init_c failed";
static const char short_gen588[] = "**mpi_remove_error_class";
static const char long_gen588[]  = "MPI_Remove_error_class failed";
static const char short_gen589[] = "**mpi_remove_error_code";
static const char long_gen589[]  = "MPI_Remove_error_code failed";
static const char short_gen590[] = "**mpi_remove_error_string";
static const char long_gen590[]  = "MPI_Remove_error_string failed";
static const char short_gen591[] = "**mpi_request_free";
static const char long_gen591[]  = "MPI_Request_free failed";
static const char short_gen592[] = "**mpi_request_get_status";
static const char long_gen592[]  = "MPI_Request_get_status failed";
static const char short_gen593[] = "**mpi_request_get_status_all";
static const char long_gen593[]  = "MPI_Request_get_status_all failed";
static const char short_gen594[] = "**mpi_request_get_status_any";
static const char long_gen594[]  = "MPI_Request_get_status_any failed";
static const char short_gen595[] = "**mpi_request_get_status_some";
static const char long_gen595[]  = "MPI_Request_get_status_some failed";
static const char short_gen596[] = "**mpi_rget";
static const char long_gen596[]  = "MPI_Rget failed";
static const char short_gen597[] = "**mpi_rget_accumulate";
static const char long_gen597[]  = "MPI_Rget_accumulate failed";
static const char short_gen598[] = "**mpi_rget_accumulate_c";
static const char long_gen598[]  = "MPI_Rget_accumulate_c failed";
static const char short_gen599[] = "**mpi_rget_c";
static const char long_gen599[]  = "MPI_Rget_c failed";
static const char short_gen600[] = "**mpi_rput";
static const char long_gen600[]  = "MPI_Rput failed";
static const char short_gen601[] = "**mpi_rput_c";
static const char long_gen601[]  = "MPI_Rput_c failed";
static const char short_gen602[] = "**mpi_rsend";
static const char long_gen602[]  = "MPI_Rsend failed";
static const char short_gen603[] = "**mpi_rsend_c";
static const char long_gen603[]  = "MPI_Rsend_c failed";
static const char short_gen604[] = "**mpi_rsend_init";
static const char long_gen604[]  = "MPI_Rsend_init failed";
static const char short_gen605[] = "**mpi_rsend_init_c";
static const char long_gen605[]  = "MPI_Rsend_init_c failed";
static const char short_gen606[] = "**mpi_scan";
static const char long_gen606[]  = "MPI_Scan failed";
static const char short_gen607[] = "**mpi_scan_c";
static const char long_gen607[]  = "MPI_Scan_c failed";
static const char short_gen608[] = "**mpi_scan_init";
static const char long_gen608[]  = "MPI_Scan_init failed";
static const char short_gen609[] = "**mpi_scan_init_c";
static const char long_gen609[]  = "MPI_Scan_init_c failed";
static const char short_gen610[] = "**mpi_scatter";
static const char long_gen610[]  = "MPI_Scatter failed";
static const char short_gen611[] = "**mpi_scatter_c";
static const char long_gen611[]  = "MPI_Scatter_c failed";
static const char short_gen612[] = "**mpi_scatter_init";
static const char long_gen612[]  = "MPI_Scatter_init failed";
static const char short_gen613[] = "**mpi_scatter_init_c";
static const char long_gen613[]  = "MPI_Scatter_init_c failed";
static const char short_gen614[] = "**mpi_scatterv";
static const char long_gen614[]  = "MPI_Scatterv failed";
static const char short_gen615[] = "**mpi_scatterv_c";
static const char long_gen615[]  = "MPI_Scatterv_c failed";
static const char short_gen616[] = "**mpi_scatterv_init";
static const char long_gen616[]  = "MPI_Scatterv_init failed";
static const char short_gen617[] = "**mpi_scatterv_init_c";
static const char long_gen617[]  = "MPI_Scatterv_init_c failed";
static const char short_gen618[] = "**mpi_send";
static const char long_gen618[]  = "MPI_Send failed";
static const char short_gen619[] = "**mpi_send_c";
static const char long_gen619[]  = "MPI_Send_c failed";
static const char short_gen620[] = "**mpi_send_init";
static const char long_gen620[]  = "MPI_Send_init failed";
static const char short_gen621[] = "**mpi_send_init_c";
static const char long_gen621[]  = "MPI_Send_init_c failed";
static const char short_gen622[] = "**mpi_sendrecv";
static const char long_gen622[]  = "MPI_Sendrecv failed";
static const char short_gen623[] = "**mpi_sendrecv_c";
static const char long_gen623[]  = "MPI_Sendrecv_c failed";
static const char short_gen624[] = "**mpi_sendrecv_replace";
static const char long_gen624[]  = "MPI_Sendrecv_replace failed";
static const char short_gen625[] = "**mpi_sendrecv_replace_c";
static const char long_gen625[]  = "MPI_Sendrecv_replace_c failed";
static const char short_gen626[] = "**mpi_session_attach_buffer";
static const char long_gen626[]  = "MPI_Session_attach_buffer failed";
static const char short_gen627[] = "**mpi_session_attach_buffer_c";
static const char long_gen627[]  = "MPI_Session_attach_buffer_c failed";
static const char short_gen628[] = "**mpi_session_call_errhandler";
static const char long_gen628[]  = "MPI_Session_call_errhandler failed";
static const char short_gen629[] = "**mpi_session_create_errhandler";
static const char long_gen629[]  = "MPI_Session_create_errhandler failed";
static const char short_gen630[] = "**mpi_session_detach_buffer";
static const char long_gen630[]  = "MPI_Session_detach_buffer failed";
static const char short_gen631[] = "**mpi_session_detach_buffer_c";
static const char long_gen631[]  = "MPI_Session_detach_buffer_c failed";
static const char short_gen632[] = "**mpi_session_finalize";
static const char long_gen632[]  = "MPI_Session_finalize failed";
static const char short_gen633[] = "**mpi_session_flush_buffer";
static const char long_gen633[]  = "MPI_Session_flush_buffer failed";
static const char short_gen634[] = "**mpi_session_get_errhandler";
static const char long_gen634[]  = "MPI_Session_get_errhandler failed";
static const char short_gen635[] = "**mpi_session_get_info";
static const char long_gen635[]  = "MPI_Session_get_info failed";
static const char short_gen636[] = "**mpi_session_get_nth_pset";
static const char long_gen636[]  = "MPI_Session_get_nth_pset failed";
static const char short_gen637[] = "**mpi_session_get_num_psets";
static const char long_gen637[]  = "MPI_Session_get_num_psets failed";
static const char short_gen638[] = "**mpi_session_get_pset_info";
static const char long_gen638[]  = "MPI_Session_get_pset_info failed";
static const char short_gen639[] = "**mpi_session_iflush_buffer";
static const char long_gen639[]  = "MPI_Session_iflush_buffer failed";
static const char short_gen640[] = "**mpi_session_init";
static const char long_gen640[]  = "MPI_Session_init failed";
static const char short_gen641[] = "**mpi_session_set_errhandler";
static const char long_gen641[]  = "MPI_Session_set_errhandler failed";
static const char short_gen642[] = "**mpi_ssend";
static const char long_gen642[]  = "MPI_Ssend failed";
static const char short_gen643[] = "**mpi_ssend_c";
static const char long_gen643[]  = "MPI_Ssend_c failed";
static const char short_gen644[] = "**mpi_ssend_init";
static const char long_gen644[]  = "MPI_Ssend_init failed";
static const char short_gen645[] = "**mpi_ssend_init_c";
static const char long_gen645[]  = "MPI_Ssend_init_c failed";
static const char short_gen646[] = "**mpi_start";
static const char long_gen646[]  = "MPI_Start failed";
static const char short_gen647[] = "**mpi_startall";
static const char long_gen647[]  = "MPI_Startall failed";
static const char short_gen648[] = "**mpi_status_c2f";
static const char long_gen648[]  = "MPI_Status_c2f failed";
static const char short_gen649[] = "**mpi_status_c2f08";
static const char long_gen649[]  = "MPI_Status_c2f08 failed";
static const char short_gen650[] = "**mpi_status_f082c";
static const char long_gen650[]  = "MPI_Status_f082c failed";
static const char short_gen651[] = "**mpi_status_f082f";
static const char long_gen651[]  = "MPI_Status_f082f failed";
static const char short_gen652[] = "**mpi_status_f2c";
static const char long_gen652[]  = "MPI_Status_f2c failed";
static const char short_gen653[] = "**mpi_status_f2f08";
static const char long_gen653[]  = "MPI_Status_f2f08 failed";
static const char short_gen654[] = "**mpi_status_set_cancelled";
static const char long_gen654[]  = "MPI_Status_set_cancelled failed";
static const char short_gen655[] = "**mpi_status_set_elements";
static const char long_gen655[]  = "MPI_Status_set_elements failed";
static const char short_gen656[] = "**mpi_status_set_elements_c";
static const char long_gen656[]  = "MPI_Status_set_elements_c failed";
static const char short_gen657[] = "**mpi_status_set_elements_x";
static const char long_gen657[]  = "MPI_Status_set_elements_x failed";
static const char short_gen658[] = "**mpi_test";
static const char long_gen658[]  = "MPI_Test failed";
static const char short_gen659[] = "**mpi_test_cancelled";
static const char long_gen659[]  = "MPI_Test_cancelled failed";
static const char short_gen660[] = "**mpi_testall";
static const char long_gen660[]  = "MPI_Testall failed";
static const char short_gen661[] = "**mpi_testany";
static const char long_gen661[]  = "MPI_Testany failed";
static const char short_gen662[] = "**mpi_testsome";
static const char long_gen662[]  = "MPI_Testsome failed";
static const char short_gen663[] = "**mpi_topo_test";
static const char long_gen663[]  = "MPI_Topo_test failed";
static const char short_gen664[] = "**mpi_type_commit";
static const char long_gen664[]  = "MPI_Type_commit failed";
static const char short_gen665[] = "**mpi_type_contiguous";
static const char long_gen665[]  = "MPI_Type_contiguous failed";
static const char short_gen666[] = "**mpi_type_contiguous_c";
static const char long_gen666[]  = "MPI_Type_contiguous_c failed";
static const char short_gen667[] = "**mpi_type_create_darray";
static const char long_gen667[]  = "MPI_Type_create_darray failed";
static const char short_gen668[] = "**mpi_type_create_darray_c";
static const char long_gen668[]  = "MPI_Type_create_darray_c failed";
static const char short_gen669[] = "**mpi_type_create_f90_complex";
static const char long_gen669[]  = "MPI_Type_create_f90_complex failed";
static const char short_gen670[] = "**mpi_type_create_f90_integer";
static const char long_gen670[]  = "MPI_Type_create_f90_integer failed";
static const char short_gen671[] = "**mpi_type_create_f90_real";
static const char long_gen671[]  = "MPI_Type_create_f90_real failed";
static const char short_gen672[] = "**mpi_type_create_hindexed";
static const char long_gen672[]  = "MPI_Type_create_hindexed failed";
static const char short_gen673[] = "**mpi_type_create_hindexed_block";
static const char long_gen673[]  = "MPI_Type_create_hindexed_block failed";
static const char short_gen674[] = "**mpi_type_create_hindexed_block_c";
static const char long_gen674[]  = "MPI_Type_create_hindexed_block_c failed";
static const char short_gen675[] = "**mpi_type_create_hindexed_c";
static const char long_gen675[]  = "MPI_Type_create_hindexed_c failed";
static const char short_gen676[] = "**mpi_type_create_hvector";
static const char long_gen676[]  = "MPI_Type_create_hvector failed";
static const char short_gen677[] = "**mpi_type_create_hvector_c";
static const char long_gen677[]  = "MPI_Type_create_hvector_c failed";
static const char short_gen678[] = "**mpi_type_create_indexed_block";
static const char long_gen678[]  = "MPI_Type_create_indexed_block failed";
static const char short_gen679[] = "**mpi_type_create_indexed_block_c";
static const char long_gen679[]  = "MPI_Type_create_indexed_block_c failed";
static const char short_gen680[] = "**mpi_type_create_keyval";
static const char long_gen680[]  = "MPI_Type_create_keyval failed";
static const char short_gen681[] = "**mpi_type_create_resized";
static const char long_gen681[]  = "MPI_Type_create_resized failed";
static const char short_gen682[] = "**mpi_type_create_resized_c";
static const char long_gen682[]  = "MPI_Type_create_resized_c failed";
static const char short_gen683[] = "**mpi_type_create_struct";
static const char long_gen683[]  = "MPI_Type_create_struct failed";
static const char short_gen684[] = "**mpi_type_create_struct_c";
static const char long_gen684[]  = "MPI_Type_create_struct_c failed";
static const char short_gen685[] = "**mpi_type_create_subarray";
static const char long_gen685[]  = "MPI_Type_create_subarray failed";
static const char short_gen686[] = "**mpi_type_create_subarray_c";
static const char long_gen686[]  = "MPI_Type_create_subarray_c failed";
static const char short_gen687[] = "**mpi_type_delete_attr";
static const char long_gen687[]  = "MPI_Type_delete_attr failed";
static const char short_gen688[] = "**mpi_type_dup";
static const char long_gen688[]  = "MPI_Type_dup failed";
static const char short_gen689[] = "**mpi_type_extent";
static const char long_gen689[]  = "MPI_Type_extent failed";
static const char short_gen690[] = "**mpi_type_free";
static const char long_gen690[]  = "MPI_Type_free failed";
static const char short_gen691[] = "**mpi_type_free_keyval";
static const char long_gen691[]  = "MPI_Type_free_keyval failed";
static const char short_gen692[] = "**mpi_type_get_attr";
static const char long_gen692[]  = "MPI_Type_get_attr failed";
static const char short_gen693[] = "**mpi_type_get_contents";
static const char long_gen693[]  = "MPI_Type_get_contents failed";
static const char short_gen694[] = "**mpi_type_get_contents_c";
static const char long_gen694[]  = "MPI_Type_get_contents_c failed";
static const char short_gen695[] = "**mpi_type_get_envelope";
static const char long_gen695[]  = "MPI_Type_get_envelope failed";
static const char short_gen696[] = "**mpi_type_get_envelope_c";
static const char long_gen696[]  = "MPI_Type_get_envelope_c failed";
static const char short_gen697[] = "**mpi_type_get_extent";
static const char long_gen697[]  = "MPI_Type_get_extent failed";
static const char short_gen698[] = "**mpi_type_get_extent_c";
static const char long_gen698[]  = "MPI_Type_get_extent_c failed";
static const char short_gen699[] = "**mpi_type_get_extent_x";
static const char long_gen699[]  = "MPI_Type_get_extent_x failed";
static const char short_gen700[] = "**mpi_type_get_name";
static const char long_gen700[]  = "MPI_Type_get_name failed";
static const char short_gen701[] = "**mpi_type_get_true_extent";
static const char long_gen701[]  = "MPI_Type_get_true_extent failed";
static const char short_gen702[] = "**mpi_type_get_true_extent_c";
static const char long_gen702[]  = "MPI_Type_get_true_extent_c failed";
static const char short_gen703[] = "**mpi_type_get_true_extent_x";
static const char long_gen703[]  = "MPI_Type_get_true_extent_x failed";
static const char short_gen704[] = "**mpi_type_get_value_index";
static const char long_gen704[]  = "MPI_Type_get_value_index failed";
static const char short_gen705[] = "**mpi_type_indexed";
static const char long_gen705[]  = "MPI_Type_indexed failed";
static const char short_gen706[] = "**mpi_type_indexed_c";
static const char long_gen706[]  = "MPI_Type_indexed_c failed";
static const char short_gen707[] = "**mpi_type_lb";
static const char long_gen707[]  = "MPI_Type_lb failed";
static const char short_gen708[] = "**mpi_type_match_size";
static const char long_gen708[]  = "MPI_Type_match_size failed";
static const char short_gen709[] = "**mpi_type_set_attr";
static const char long_gen709[]  = "MPI_Type_set_attr failed";
static const char short_gen710[] = "**mpi_type_set_name";
static const char long_gen710[]  = "MPI_Type_set_name failed";
static const char short_gen711[] = "**mpi_type_size";
static const char long_gen711[]  = "MPI_Type_size failed";
static const char short_gen712[] = "**mpi_type_size_c";
static const char long_gen712[]  = "MPI_Type_size_c failed";
static const char short_gen713[] = "**mpi_type_size_x";
static const char long_gen713[]  = "MPI_Type_size_x failed";
static const char short_gen714[] = "**mpi_type_ub";
static const char long_gen714[]  = "MPI_Type_ub failed";
static const char short_gen715[] = "**mpi_type_vector";
static const char long_gen715[]  = "MPI_Type_vector failed";
static const char short_gen716[] = "**mpi_type_vector_c";
static const char long_gen716[]  = "MPI_Type_vector_c failed";
static const char short_gen717[] = "**mpi_unpack";
static const char long_gen717[]  = "MPI_Unpack failed";
static const char short_gen718[] = "**mpi_unpack_c";
static const char long_gen718[]  = "MPI_Unpack_c failed";
static const char short_gen719[] = "**mpi_unpack_external";
static const char long_gen719[]  = "MPI_Unpack_external failed";
static const char short_gen720[] = "**mpi_unpack_external_c";
static const char long_gen720[]  = "MPI_Unpack_external_c failed";
static const char short_gen721[] = "**mpi_unpublish_name";
static const char long_gen721[]  = "MPI_Unpublish_name failed";
static const char short_gen722[] = "**mpi_wait";
static const char long_gen722[]  = "MPI_Wait failed";
static const char short_gen723[] = "**mpi_waitall";
static const char long_gen723[]  = "MPI_Waitall failed";
static const char short_gen724[] = "**mpi_waitany";
static const char long_gen724[]  = "MPI_Waitany failed";
static const char short_gen725[] = "**mpi_waitsome";
static const char long_gen725[]  = "MPI_Waitsome failed";
static const char short_gen726[] = "**mpi_win_allocate";
static const char long_gen726[]  = "MPI_Win_allocate failed";
static const char short_gen727[] = "**mpi_win_allocate_c";
static const char long_gen727[]  = "MPI_Win_allocate_c failed";
static const char short_gen728[] = "**mpi_win_allocate_shared";
static const char long_gen728[]  = "MPI_Win_allocate_shared failed";
static const char short_gen729[] = "**mpi_win_allocate_shared_c";
static const char long_gen729[]  = "MPI_Win_allocate_shared_c failed";
static const char short_gen730[] = "**mpi_win_attach";
static const char long_gen730[]  = "MPI_Win_attach failed";
static const char short_gen731[] = "**mpi_win_call_errhandler";
static const char long_gen731[]  = "MPI_Win_call_errhandler failed";
static const char short_gen732[] = "**mpi_win_complete";
static const char long_gen732[]  = "MPI_Win_complete failed";
static const char short_gen733[] = "**mpi_win_create";
static const char long_gen733[]  = "MPI_Win_create failed";
static const char short_gen734[] = "**mpi_win_create_c";
static const char long_gen734[]  = "MPI_Win_create_c failed";
static const char short_gen735[] = "**mpi_win_create_dynamic";
static const char long_gen735[]  = "MPI_Win_create_dynamic failed";
static const char short_gen736[] = "**mpi_win_create_errhandler";
static const char long_gen736[]  = "MPI_Win_create_errhandler failed";
static const char short_gen737[] = "**mpi_win_create_keyval";
static const char long_gen737[]  = "MPI_Win_create_keyval failed";
static const char short_gen738[] = "**mpi_win_delete_attr";
static const char long_gen738[]  = "MPI_Win_delete_attr failed";
static const char short_gen739[] = "**mpi_win_detach";
static const char long_gen739[]  = "MPI_Win_detach failed";
static const char short_gen740[] = "**mpi_win_fence";
static const char long_gen740[]  = "MPI_Win_fence failed";
static const char short_gen741[] = "**mpi_win_flush";
static const char long_gen741[]  = "MPI_Win_flush failed";
static const char short_gen742[] = "**mpi_win_flush_all";
static const char long_gen742[]  = "MPI_Win_flush_all failed";
static const char short_gen743[] = "**mpi_win_flush_local";
static const char long_gen743[]  = "MPI_Win_flush_local failed";
static const char short_gen744[] = "**mpi_win_flush_local_all";
static const char long_gen744[]  = "MPI_Win_flush_local_all failed";
static const char short_gen745[] = "**mpi_win_free";
static const char long_gen745[]  = "MPI_Win_free failed";
static const char short_gen746[] = "**mpi_win_free_keyval";
static const char long_gen746[]  = "MPI_Win_free_keyval failed";
static const char short_gen747[] = "**mpi_win_get_attr";
static const char long_gen747[]  = "MPI_Win_get_attr failed";
static const char short_gen748[] = "**mpi_win_get_errhandler";
static const char long_gen748[]  = "MPI_Win_get_errhandler failed";
static const char short_gen749[] = "**mpi_win_get_group";
static const char long_gen749[]  = "MPI_Win_get_group failed";
static const char short_gen750[] = "**mpi_win_get_info";
static const char long_gen750[]  = "MPI_Win_get_info failed";
static const char short_gen751[] = "**mpi_win_get_name";
static const char long_gen751[]  = "MPI_Win_get_name failed";
static const char short_gen752[] = "**mpi_win_lock";
static const char long_gen752[]  = "MPI_Win_lock failed";
static const char short_gen753[] = "**mpi_win_lock_all";
static const char long_gen753[]  = "MPI_Win_lock_all failed";
static const char short_gen754[] = "**mpi_win_post";
static const char long_gen754[]  = "MPI_Win_post failed";
static const char short_gen755[] = "**mpi_win_set_attr";
static const char long_gen755[]  = "MPI_Win_set_attr failed";
static const char short_gen756[] = "**mpi_win_set_errhandler";
static const char long_gen756[]  = "MPI_Win_set_errhandler failed";
static const char short_gen757[] = "**mpi_win_set_info";
static const char long_gen757[]  = "MPI_Win_set_info failed";
static const char short_gen758[] = "**mpi_win_set_name";
static const char long_gen758[]  = "MPI_Win_set_name failed";
static const char short_gen759[] = "**mpi_win_shared_query";
static const char long_gen759[]  = "MPI_Win_shared_query failed";
static const char short_gen760[] = "**mpi_win_shared_query_c";
static const char long_gen760[]  = "MPI_Win_shared_query_c failed";
static const char short_gen761[] = "**mpi_win_start";
static const char long_gen761[]  = "MPI_Win_start failed";
static const char short_gen762[] = "**mpi_win_sync";
static const char long_gen762[]  = "MPI_Win_sync failed";
static const char short_gen763[] = "**mpi_win_test";
static const char long_gen763[]  = "MPI_Win_test failed";
static const char short_gen764[] = "**mpi_win_unlock";
static const char long_gen764[]  = "MPI_Win_unlock failed";
static const char short_gen765[] = "**mpi_win_unlock_all";
static const char long_gen765[]  = "MPI_Win_unlock_all failed";
static const char short_gen766[] = "**mpi_win_wait";
static const char long_gen766[]  = "MPI_Win_wait failed";
static const char short_gen767[] = "**mpix_allreduce_enqueue";
static const char long_gen767[]  = "MPIX_Allreduce_enqueue failed";
static const char short_gen768[] = "**mpix_allreduce_enqueue_c";
static const char long_gen768[]  = "MPIX_Allreduce_enqueue_c failed";
static const char short_gen769[] = "**mpix_async_spawn";
static const char long_gen769[]  = "MPIX_Async_spawn failed";
static const char short_gen770[] = "**mpix_async_start";
static const char long_gen770[]  = "MPIX_Async_start failed";
static const char short_gen771[] = "**mpix_comm_agree";
static const char long_gen771[]  = "MPIX_Comm_agree failed";
static const char short_gen772[] = "**mpix_comm_create_errhandler_x";
static const char long_gen772[]  = "MPIX_Comm_create_errhandler_x failed";
static const char short_gen773[] = "**mpix_comm_failure_ack";
static const char long_gen773[]  = "MPIX_Comm_failure_ack failed";
static const char short_gen774[] = "**mpix_comm_failure_get_acked";
static const char long_gen774[]  = "MPIX_Comm_failure_get_acked failed";
static const char short_gen775[] = "**mpix_comm_get_failed";
static const char long_gen775[]  = "MPIX_Comm_get_failed failed";
static const char short_gen776[] = "**mpix_comm_get_stream";
static const char long_gen776[]  = "MPIX_Comm_get_stream failed";
static const char short_gen777[] = "**mpix_comm_revoke";
static const char long_gen777[]  = "MPIX_Comm_revoke failed";
static const char short_gen778[] = "**mpix_comm_shrink";
static const char long_gen778[]  = "MPIX_Comm_shrink failed";
static const char short_gen779[] = "**mpix_comm_test_threadcomm";
static const char long_gen779[]  = "MPIX_Comm_test_threadcomm failed";
static const char short_gen780[] = "**mpix_file_create_errhandler_x";
static const char long_gen780[]  = "MPIX_File_create_errhandler_x failed";
static const char short_gen781[] = "**mpix_gpu_query_support";
static const char long_gen781[]  = "MPIX_GPU_query_support failed";
static const char short_gen782[] = "**mpix_grequest_class_allocate";
static const char long_gen782[]  = "MPIX_Grequest_class_allocate failed";
static const char short_gen783[] = "**mpix_grequest_class_create";
static const char long_gen783[]  = "MPIX_Grequest_class_create failed";
static const char short_gen784[] = "**mpix_grequest_start";
static const char long_gen784[]  = "MPIX_Grequest_start failed";
static const char short_gen785[] = "**mpix_info_set_hex";
static const char long_gen785[]  = "MPIX_Info_set_hex failed";
static const char short_gen786[] = "**mpix_irecv_enqueue";
static const char long_gen786[]  = "MPIX_Irecv_enqueue failed";
static const char short_gen787[] = "**mpix_irecv_enqueue_c";
static const char long_gen787[]  = "MPIX_Irecv_enqueue_c failed";
static const char short_gen788[] = "**mpix_isend_enqueue";
static const char long_gen788[]  = "MPIX_Isend_enqueue failed";
static const char short_gen789[] = "**mpix_isend_enqueue_c";
static const char long_gen789[]  = "MPIX_Isend_enqueue_c failed";
static const char short_gen790[] = "**mpix_op_create_x";
static const char long_gen790[]  = "MPIX_Op_create_x failed";
static const char short_gen791[] = "**mpix_recv_enqueue";
static const char long_gen791[]  = "MPIX_Recv_enqueue failed";
static const char short_gen792[] = "**mpix_recv_enqueue_c";
static const char long_gen792[]  = "MPIX_Recv_enqueue_c failed";
static const char short_gen793[] = "**mpix_send_enqueue";
static const char long_gen793[]  = "MPIX_Send_enqueue failed";
static const char short_gen794[] = "**mpix_send_enqueue_c";
static const char long_gen794[]  = "MPIX_Send_enqueue_c failed";
static const char short_gen795[] = "**mpix_session_create_errhandler_x";
static const char long_gen795[]  = "MPIX_Session_create_errhandler_x failed";
static const char short_gen796[] = "**mpix_start_progress_thread";
static const char long_gen796[]  = "MPIX_Start_progress_thread failed";
static const char short_gen797[] = "**mpix_stop_progress_thread";
static const char long_gen797[]  = "MPIX_Stop_progress_thread failed";
static const char short_gen798[] = "**mpix_stream_comm_create";
static const char long_gen798[]  = "MPIX_Stream_comm_create failed";
static const char short_gen799[] = "**mpix_stream_comm_create_multiplex";
static const char long_gen799[]  = "MPIX_Stream_comm_create_multiplex failed";
static const char short_gen800[] = "**mpix_stream_create";
static const char long_gen800[]  = "MPIX_Stream_create failed";
static const char short_gen801[] = "**mpix_stream_free";
static const char long_gen801[]  = "MPIX_Stream_free failed";
static const char short_gen802[] = "**mpix_stream_irecv";
static const char long_gen802[]  = "MPIX_Stream_irecv failed";
static const char short_gen803[] = "**mpix_stream_irecv_c";
static const char long_gen803[]  = "MPIX_Stream_irecv_c failed";
static const char short_gen804[] = "**mpix_stream_isend";
static const char long_gen804[]  = "MPIX_Stream_isend failed";
static const char short_gen805[] = "**mpix_stream_isend_c";
static const char long_gen805[]  = "MPIX_Stream_isend_c failed";
static const char short_gen806[] = "**mpix_stream_progress";
static const char long_gen806[]  = "MPIX_Stream_progress failed";
static const char short_gen807[] = "**mpix_stream_recv";
static const char long_gen807[]  = "MPIX_Stream_recv failed";
static const char short_gen808[] = "**mpix_stream_recv_c";
static const char long_gen808[]  = "MPIX_Stream_recv_c failed";
static const char short_gen809[] = "**mpix_stream_send";
static const char long_gen809[]  = "MPIX_Stream_send failed";
static const char short_gen810[] = "**mpix_stream_send_c";
static const char long_gen810[]  = "MPIX_Stream_send_c failed";
static const char short_gen811[] = "**mpix_threadcomm_finish";
static const char long_gen811[]  = "MPIX_Threadcomm_finish failed";
static const char short_gen812[] = "**mpix_threadcomm_free";
static const char long_gen812[]  = "MPIX_Threadcomm_free failed";
static const char short_gen813[] = "**mpix_threadcomm_init";
static const char long_gen813[]  = "MPIX_Threadcomm_init failed";
static const char short_gen814[] = "**mpix_threadcomm_start";
static const char long_gen814[]  = "MPIX_Threadcomm_start failed";
static const char short_gen815[] = "**mpix_type_iov";
static const char long_gen815[]  = "MPIX_Type_iov failed";
static const char short_gen816[] = "**mpix_type_iov_len";
static const char long_gen816[]  = "MPIX_Type_iov_len failed";
static const char short_gen817[] = "**mpix_wait_enqueue";
static const char long_gen817[]  = "MPIX_Wait_enqueue failed";
static const char short_gen818[] = "**mpix_waitall_enqueue";
static const char long_gen818[]  = "MPIX_Waitall_enqueue failed";
static const char short_gen819[] = "**mpix_win_create_errhandler_x";
static const char long_gen819[]  = "MPIX_Win_create_errhandler_x failed";
static const char short_gen820[] = "**mpl_gavl_create";
static const char long_gen820[]  = " mpl_gavl_create failed";
static const char short_gen821[] = "**mpl_gavl_delete_range";
static const char long_gen821[]  = " mpl_gavl_delete_range failed";
static const char short_gen822[] = "**mpl_gavl_delete_start_addr";
static const char long_gen822[]  = " mpl_gavl_delete_start_addr failed";
static const char short_gen823[] = "**mpl_gavl_insert";
static const char long_gen823[]  = " mpl_gavl_insert failed";
static const char short_gen824[] = "**mpl_gavl_search";
static const char long_gen824[]  = " mpl_gavl_search failed";
static const char short_gen825[] = "**mpl_gpu_fast_memcpy";
static const char long_gen825[]  = "  MPL_gpu_fast_memcpy failed";
static const char short_gen826[] = "**mpl_gpu_get_dev_id_from_attr";
static const char long_gen826[]  = " MPL_gpu_get_dev_id_from_attr failed";
static const char short_gen827[] = "**mpl_gpu_imemcpy";
static const char long_gen827[]  = " MPL_gpu_imemcpy failed";
static const char short_gen828[] = "**mpl_gpu_test";
static const char long_gen828[]  = " MPL_gpu_test failed";
static const char short_gen829[] = "**mpl_ze_init_device_fds";
static const char long_gen829[]  = " mpl_ze_init_device_fds failed";
static const char short_gen830[] = "**namepubfile";
static const char long_gen830[]  = "Unable to publish service name";
static const char short_gen831[] = "**namepubnotfound";
static const char long_gen831[]  = "Lookup failed for service name";
static const char short_gen832[] = "**namepubnotpub";
static const char long_gen832[]  = "Publish failed for service name";
static const char short_gen833[] = "**nameservice";
static const char long_gen833[]  = "Invalid service name (see MPI_Publish_name)";
static const char short_gen834[] = "**need_get_contents_c";
static const char long_gen834[]  = "use MPI_Type_get_contents_c to query large count datatype";
static const char short_gen835[] = "**need_get_envelope_c";
static const char long_gen835[]  = "use MPI_Type_get_envelope_c to query large count datatype";
static const char short_gen836[] = "**netloc_endpoint_mismatch";
static const char long_gen836[]  = "Netloc topology does not contain the node";
static const char short_gen837[] = "**netloc_topo_load";
static const char long_gen837[]  = "Error loading netloc topology";
static const char short_gen838[] = "**noConnInfoToString";
static const char long_gen838[]  = "No ConnInfoToString routine defined for this process group";
static const char short_gen839[] = "**noerrclasses";
static const char long_gen839[]  = "No more user-defined error classes";
static const char short_gen840[] = "**noerrcodes";
static const char long_gen840[]  = "No more user-defined error codes";
static const char short_gen841[] = "**nofence";
static const char long_gen841[]  = " invalid Gentran fence";
static const char short_gen842[] = "**nomem";
static const char long_gen842[]  = "Out of memory";
static const char short_gen843[] = "**nomem2";
static const char long_gen843[]  = "Unable to allocate memory (probably out of memory)";
static const char short_gen844[] = "**nomembind";
static const char long_gen844[]  = " hwloc_set_area_membind() is not available";
static const char short_gen845[] = "**nomemreq";
static const char long_gen845[]  = "failure occurred while allocating memory for a request object";
static const char short_gen846[] = "**nonamepub";
static const char long_gen846[]  = "No name publishing service available";
static const char short_gen847[] = "**nosupport";
static const char long_gen847[]  = " Algorithm selected is not supported. Please choose another algorithm";
static const char short_gen848[] = "**notcarttopo";
static const char long_gen848[]  = "No Cartesian topology associated with this communicator";
static const char short_gen849[] = "**notcstatignore";
static const char long_gen849[]  = "MPI_STATUS_IGNORE cannot be passed to MPI_Status_c2f()";
static const char short_gen850[] = "**notdistgraphtopo";
static const char long_gen850[]  = "No Distributed Graph topology associated with this communicator";
static const char short_gen851[] = "**notfstatignore";
static const char long_gen851[]  = "MPI_STATUS_IGNORE cannot be passed to MPI_Status_f2c()";
static const char short_gen852[] = "**notgenreq";
static const char long_gen852[]  = "Attempt to complete a request with MPI_GREQUEST_COMPLETE that was not started with MPI_GREQUEST_START";
static const char short_gen853[] = "**notgpustream";
static const char long_gen853[]  = "The communicator does not have a local gpu stream attached.";
static const char short_gen854[] = "**notgraphtopo";
static const char long_gen854[]  = "No Graph topology associated with this communicator";
static const char short_gen855[] = "**notimpl";
static const char long_gen855[]  = "Function not implemented";
static const char short_gen856[] = "**notopology";
static const char long_gen856[]  = "No topology associated with this communicator";
static const char short_gen857[] = "**notsame";
static const char long_gen857[]  = "Inconsistent arguments to collective routine ";
static const char short_gen858[] = "**null_buff_ptr";
static const char long_gen858[]  = "Error in hcolrte api: buffer pointer is NULL for non DTE_ZERO INLINE data representation";
static const char short_gen859[] = "**nullptr";
static const char long_gen859[]  = "Null pointer";
static const char short_gen860[] = "**nullptrtype";
static const char long_gen860[]  = "Null pointer";
static const char short_gen861[] = "**nullvertex";
static const char long_gen861[]  = "  Gentran vertex is NULL";
static const char short_gen862[] = "**ofi_no_prov";
static const char long_gen862[]  = "No valid libfabric provider";
static const char short_gen863[] = "**ofi_num_nics";
static const char long_gen863[]  = "OFI has a different number of nics available on different notes";
static const char short_gen864[] = "**ofi_provider_mismatch";
static const char long_gen864[]  = "OFI Provider name does not match configure-time provider name";
static const char short_gen865[] = "**ofid_atomicto";
static const char long_gen865[]  = "OFI call atomicto failed";
static const char short_gen866[] = "**ofid_avclose";
static const char long_gen866[]  = "OFI call avclose failed";
static const char short_gen867[] = "**ofid_avlookup";
static const char long_gen867[]  = "OFI call avlookup failed";
static const char short_gen868[] = "**ofid_avmap";
static const char long_gen868[]  = "OFI call avmap failed";
static const char short_gen869[] = "**ofid_avopen";
static const char long_gen869[]  = "OFI call avopen failed";
static const char short_gen870[] = "**ofid_bind";
static const char long_gen870[]  = "OFI call bind failed";
static const char short_gen871[] = "**ofid_cancel";
static const char long_gen871[]  = "OFI cancel failed";
static const char short_gen872[] = "**ofid_cntr_open";
static const char long_gen872[]  = "OFI Counter open failed";
static const char short_gen873[] = "**ofid_cntr_wait";
static const char long_gen873[]  = "OFI Counter wait failed";
static const char short_gen874[] = "**ofid_cntrclose";
static const char long_gen874[]  = "OFI call cntrclose failed";
static const char short_gen875[] = "**ofid_control";
static const char long_gen875[]  = "OFI call control failed";
static const char short_gen876[] = "**ofid_cqclose";
static const char long_gen876[]  = "OFI call cqclose failed";
static const char short_gen877[] = "**ofid_domainclose";
static const char long_gen877[]  = "OFI call domainclose failed";
static const char short_gen878[] = "**ofid_enable_trigger";
static const char long_gen878[]  = "OFI triggered ops enable failed";
static const char short_gen879[] = "**ofid_ep";
static const char long_gen879[]  = "OFI call ep failed";
static const char short_gen880[] = "**ofid_ep_enable";
static const char long_gen880[]  = "OFI call ep_enable failed";
static const char short_gen881[] = "**ofid_epclose";
static const char long_gen881[]  = "OFI call epclose failed";
static const char short_gen882[] = "**ofid_fabric";
static const char long_gen882[]  = "OFI call fabric failed";
static const char short_gen883[] = "**ofid_fabricclose";
static const char long_gen883[]  = "OFI call fabricclose failed";
static const char short_gen884[] = "**ofid_fi_close";
static const char long_gen884[]  = "OFI call fi_close failed";
static const char short_gen885[] = "**ofid_getinfo";
static const char long_gen885[]  = "OFI call getinfo failed";
static const char short_gen886[] = "**ofid_getname";
static const char long_gen886[]  = "OFI call getname failed";
static const char short_gen887[] = "**ofid_inject";
static const char long_gen887[]  = "OFI call inject failed";
static const char short_gen888[] = "**ofid_issue_trigger";
static const char long_gen888[]  = "OFI triggered ops issue failed";
static const char short_gen889[] = "**ofid_mr_bind";
static const char long_gen889[]  = "OFI call mr_bind failed";
static const char short_gen890[] = "**ofid_mr_enable";
static const char long_gen890[]  = "OFI call mr_enable failed";
static const char short_gen891[] = "**ofid_mr_key";
static const char long_gen891[]  = "OFI MR key invalid";
static const char short_gen892[] = "**ofid_mr_reg";
static const char long_gen892[]  = "OFI call mr_reg failed";
static const char short_gen893[] = "**ofid_mr_regattr";
static const char long_gen893[]  = "OFI call mr_regattr failed";
static const char short_gen894[] = "**ofid_mr_unreg";
static const char long_gen894[]  = "OFI call mr_unreg failed";
static const char short_gen895[] = "**ofid_opencq";
static const char long_gen895[]  = "OFI call opencq failed";
static const char short_gen896[] = "**ofid_openct";
static const char long_gen896[]  = "OFI call openct failed";
static const char short_gen897[] = "**ofid_opendomain";
static const char long_gen897[]  = "OFI call opendomain failed";
static const char short_gen898[] = "**ofid_poll";
static const char long_gen898[]  = "OFI poll failed";
static const char short_gen899[] = "**ofid_prepost";
static const char long_gen899[]  = "OFI call prepost failed";
static const char short_gen900[] = "**ofid_rdma_atomicto";
static const char long_gen900[]  = "OFI call rdma_atomicto failed";
static const char short_gen901[] = "**ofid_rdma_inject_write";
static const char long_gen901[]  = "OFI call rdma_inject_write failed";
static const char short_gen902[] = "**ofid_rdma_readfrom";
static const char long_gen902[]  = "OFI call rdma_readfrom failed";
static const char short_gen903[] = "**ofid_rdma_write";
static const char long_gen903[]  = "OFI call rdma_write failed";
static const char short_gen904[] = "**ofid_send";
static const char long_gen904[]  = "OFI call send failed";
static const char short_gen905[] = "**ofid_setopt";
static const char long_gen905[]  = "OFI call setopt failed";
static const char short_gen906[] = "**ofid_stx_ctx_close";
static const char long_gen906[]  = "OFI call stx_ctx_close failed";
static const char short_gen907[] = "**ofid_tinject";
static const char long_gen907[]  = "OFI call tinject failed";
static const char short_gen908[] = "**ofid_tinjectdata";
static const char long_gen908[]  = "OFI call tinjectdata failed";
static const char short_gen909[] = "**ofid_trecv";
static const char long_gen909[]  = "OFI call trecv failed";
static const char short_gen910[] = "**ofid_trecvmsg";
static const char long_gen910[]  = "OFI call trecvmsg failed";
static const char short_gen911[] = "**ofid_trecvsync";
static const char long_gen911[]  = "OFI call trecvsync failed";
static const char short_gen912[] = "**ofid_tsend";
static const char long_gen912[]  = "OFI call tsend failed";
static const char short_gen913[] = "**ofid_tsenddata";
static const char long_gen913[]  = "OFI call tsenddata failed";
static const char short_gen914[] = "**ofid_tsendv";
static const char long_gen914[]  = "OFI call tsendv failed";
static const char short_gen915[] = "**op";
static const char long_gen915[]  = "Invalid MPI_Op";
static const char short_gen916[] = "**opencolltuningfile";
static const char long_gen916[]  = " Unable to open collective tuning file";
static const char short_gen917[] = "**openportfailed";
static const char long_gen917[]  = "Unable to establish a port";
static const char short_gen918[] = "**opnotallowed";
static const char long_gen918[]  = "MPI_Op operation is not allowed in this routine";
static const char short_gen919[] = "**opnotpredefined";
static const char long_gen919[]  = "only predefined ops are valid";
static const char short_gen920[] = "**opnull";
static const char long_gen920[]  = "Null MPI_Op";
static const char short_gen921[] = "**opundefined";
static const char long_gen921[]  = "MPI_Op operation not defined for this datatype ";
static const char short_gen922[] = "**oremote_fail";
static const char long_gen922[]  = "open failed on a remote node";
static const char short_gen923[] = "**other";
static const char long_gen923[]  = "Other MPI error";
static const char short_gen924[] = "**outofstream";
static const char long_gen924[]  = "No streams available. Use MPIR_CVAR_CH4_RESERVE_VCIS to reserve the number of streams can be allocated.";
static const char short_gen925[] = "**parse_thread_affinity";
static const char long_gen925[]  = "Failed to parse async thread affinity string";
static const char short_gen926[] = "**partitioninvalid";
static const char long_gen926[]  = " Invalid partition";
static const char short_gen927[] = "**pending";
static const char long_gen927[]  = "Pending request (no error)";
static const char short_gen928[] = "**permattr";
static const char long_gen928[]  = "Cannot set permanent attribute";
static const char short_gen929[] = "**permop";
static const char long_gen929[]  = "Cannot free permanent MPI_Op ";
static const char short_gen930[] = "**pglookup";
static const char long_gen930[]  = "unable to find the process group structure";
static const char short_gen931[] = "**pmi_spawn_multiple";
static const char long_gen931[]  = "PMI_Spawn_multiple failed";
static const char short_gen932[] = "**pmix_load_topo";
static const char long_gen932[]  = " PMIx_Load_topology failed";
static const char short_gen933[] = "**pmix_unknown_topo";
static const char long_gen933[]  = " PMIx_Load_topology returns unknown topology";
static const char short_gen934[] = "**poll";
static const char long_gen934[]  = "poll of socket fds failed";
static const char short_gen935[] = "**port";
static const char long_gen935[]  = "Invalid port";
static const char short_gen936[] = "**portexist";
static const char long_gen936[]  = "Named port does not exist";
static const char short_gen937[] = "**predeferrclass";
static const char long_gen937[]  = "Predefined error class given";
static const char short_gen938[] = "**predeferrcode";
static const char long_gen938[]  = "Predefined error code given";
static const char short_gen939[] = "**proc_aborted";
static const char long_gen939[]  = "Process was aborted";
static const char short_gen940[] = "**proc_failed";
static const char long_gen940[]  = "Process failed";
static const char short_gen941[] = "**procnamefailed";
static const char long_gen941[]  = "Failed to get processor name";
static const char short_gen942[] = "**progress_sock_wait";
static const char long_gen942[]  = "sock_wait failed";
static const char short_gen943[] = "**progresshookstoomany";
static const char long_gen943[]  = " too many progress hooks are registered";
static const char short_gen944[] = "**psetinvalidn";
static const char long_gen944[]  = "Invalid pset number";
static const char short_gen945[] = "**psetinvalidname";
static const char long_gen945[]  = "Invalid pset name";
static const char short_gen946[] = "**pthread_mutex";
static const char long_gen946[]  = "pthread mutex routine failed";
static const char short_gen947[] = "**putenv";
static const char long_gen947[]  = "putenv failed";
static const char short_gen948[] = "**qmpi_invalid_name";
static const char long_gen948[]  = " tool name is invalid";
static const char short_gen949[] = "**rangedup";
static const char long_gen949[]  = "The range array specifies duplicate entries";
static const char short_gen950[] = "**rangeendinvalid";
static const char long_gen950[]  = "Some element of a range array is either negative or too large";
static const char short_gen951[] = "**rangestartinvalid";
static const char long_gen951[]  = "Some element of a range array is either negative or too large";
static const char short_gen952[] = "**rank";
static const char long_gen952[]  = "Invalid rank";
static const char short_gen953[] = "**rankarray";
static const char long_gen953[]  = "Invalid rank in rank array";
static const char short_gen954[] = "**rankdup";
static const char long_gen954[]  = "Duplicate ranks in rank array ";
static const char short_gen955[] = "**ranklocal";
static const char long_gen955[]  = "Error specifying local_leader ";
static const char short_gen956[] = "**rankremote";
static const char long_gen956[]  = "Error specifying remote_leader ";
static const char short_gen957[] = "**ranksdistinct";
static const char long_gen957[]  = "Local and remote leaders must be different processes";
static const char short_gen958[] = "**read";
static const char long_gen958[]  = "read from socket failed";
static const char short_gen959[] = "**read_file";
static const char long_gen959[]  = "Failed to read from file";
static const char short_gen960[] = "**recv";
static const char long_gen960[]  = "recv failed";
static const char short_gen961[] = "**recvbuf_inplace";
static const char long_gen961[]  = "recvbuf cannot be MPI_IN_PLACE";
static const char short_gen962[] = "**recvmsg";
static const char long_gen962[]  = "recvmsg failed";
static const char short_gen963[] = "**remove_shar_mem";
static const char long_gen963[]  = "unable to remove shared memory";
static const char short_gen964[] = "**reqnotmsg";
static const char long_gen964[]  = " Invalid MPI_Message (MPI_Request passed)";
static const char short_gen965[] = "**request";
static const char long_gen965[]  = "Invalid MPI_Request";
static const char short_gen966[] = "**request_invalid_kind";
static const char long_gen966[]  = "The supplied request was invalid";
static const char short_gen967[] = "**requestinvalidparrived";
static const char long_gen967[]  = " Invalid or inactive partitioned receive request passed to MPI_Parrived.";
static const char short_gen968[] = "**requestinvalidpready";
static const char long_gen968[]  = " Invalid or inactive partitioned send request passed to MPI_Pready, MPI_Pready_range or MPI_Pready_list.";
static const char short_gen969[] = "**requestinvalidstart";
static const char long_gen969[]  = "Request is neither persistent nor partitioned in MPI_Start or MPI_Startall.";
static const char short_gen970[] = "**requestnull";
static const char long_gen970[]  = "Null MPI_Request ";
static const char short_gen971[] = "**requestpartactive";
static const char long_gen971[]  = "Partitioned request passed to MPI_Start or MPI_Startall is already active.";
static const char short_gen972[] = "**requestpersistactive";
static const char long_gen972[]  = "Persistent request passed to MPI_Start or MPI_Startall is already active.";
static const char short_gen973[] = "**revoked";
static const char long_gen973[]  = "Communication object revoked";
static const char short_gen974[] = "**rmaattach";
static const char long_gen974[]  = "Memory cannot be attached";
static const char short_gen975[] = "**rmaconflict";
static const char long_gen975[]  = "Conflicting accesses to window ";
static const char short_gen976[] = "**rmadisp";
static const char long_gen976[]  = "Invalid displacement argument in RMA call ";
static const char short_gen977[] = "**rmaflavor";
static const char long_gen977[]  = "Incorrect window flavor";
static const char short_gen978[] = "**rmarange";
static const char long_gen978[]  = "Target memory is not contained within the window";
static const char short_gen979[] = "**rmashared";
static const char long_gen979[]  = "Memory cannot be shared";
static const char short_gen980[] = "**rmasize";
static const char long_gen980[]  = "Invalid size argument in RMA call";
static const char short_gen981[] = "**rmasync";
static const char long_gen981[]  = "Wrong synchronization of RMA calls ";
static const char short_gen982[] = "**rmatypenotatomic";
static const char long_gen982[]  = " Datatype not permitted for atomic operations";
static const char short_gen983[] = "**root";
static const char long_gen983[]  = "Invalid root";
static const char short_gen984[] = "**rsendnomatch";
static const char long_gen984[]  = "Ready send had no matching receive ";
static const char short_gen985[] = "**rtspkt";
static const char long_gen985[]  = "failure occurred while attempting to send RTS packet";
static const char short_gen986[] = "**sem_destroy";
static const char long_gen986[]  = "sem_destroy() failed";
static const char short_gen987[] = "**sem_init";
static const char long_gen987[]  = "sem_init() failed";
static const char short_gen988[] = "**sem_post";
static const char long_gen988[]  = "sem_post() failed";
static const char short_gen989[] = "**sem_wait";
static const char long_gen989[]  = "sem_wait() failed";
static const char short_gen990[] = "**sendbuf_inplace";
static const char long_gen990[]  = "sendbuf cannot be MPI_IN_PLACE";
static const char short_gen991[] = "**sendmsg";
static const char long_gen991[]  = "sendmsg failed";
static const char short_gen992[] = "**servicename";
static const char long_gen992[]  = "Attempt to lookup an unknown service name ";
static const char short_gen993[] = "**session";
static const char long_gen993[]  = "Invalid MPI_Session handle";
static const char short_gen994[] = "**sessioninuse";
static const char long_gen994[]  = "MPI_Session is referenced and cannot be released";
static const char short_gen995[] = "**sessionnull";
static const char long_gen995[]  = " NULL MPI_Session";
static const char short_gen996[] = "**set_thread_affinity";
static const char long_gen996[]  = "Failed to set the async thread affinity";
static const char short_gen997[] = "**signal";
static const char long_gen997[]  = "signal() failed";
static const char short_gen998[] = "**snprintf";
static const char long_gen998[]  = "snprintf returned an invalid number";
static const char short_gen999[] = "**sock_accept";
static const char long_gen999[]  = "accept of socket fd failed";
static const char short_gen1000[] = "**sock_close";
static const char long_gen1000[]  = " unable to close a socket";
static const char short_gen1001[] = "**sock_closed";
static const char long_gen1001[]  = "socket closed";
static const char short_gen1002[] = "**sock_connect";
static const char long_gen1002[]  = "connect failed";
static const char short_gen1003[] = "**sock_create";
static const char long_gen1003[]  = "unable to create a socket";
static const char short_gen1004[] = "**sock_gethost";
static const char long_gen1004[]  = "gethostname failed";
static const char short_gen1005[] = "**sock_post_close";
static const char long_gen1005[]  = "posting a close of the socket failed";
static const char short_gen1006[] = "**sock_unlink";
static const char long_gen1006[]  = "unlinking socket fd failed";
static const char short_gen1007[] = "**sockaddrfailed";
static const char long_gen1007[]  = " MPL_get_sockaddr failed";
static const char short_gen1008[] = "**sock|badbuf";
static const char long_gen1008[]  = "the supplied buffer contains invalid memory";
static const char short_gen1009[] = "**sock|badhandle";
static const char long_gen1009[]  = "sock contains an invalid handle";
static const char short_gen1010[] = "**sock|badhdbuf";
static const char long_gen1010[]  = "a memory fault occurred while accessing the host description string";
static const char short_gen1011[] = "**sock|badhdlen";
static const char long_gen1011[]  = "host description string to small to store description";
static const char short_gen1012[] = "**sock|badhdmax";
static const char long_gen1012[]  = "the length of the host description string must be non-negative";
static const char short_gen1013[] = "**sock|badiovn";
static const char long_gen1013[]  = "size of iov is invalid";
static const char short_gen1014[] = "**sock|badlen";
static const char long_gen1014[]  = "bad length parameter(s)";
static const char short_gen1015[] = "**sock|badport";
static const char long_gen1015[]  = "port number is out of range";
static const char short_gen1016[] = "**sock|badsock";
static const char long_gen1016[]  = "supplied sock is corrupt";
static const char short_gen1017[] = "**sock|closing";
static const char long_gen1017[]  = "sock is in the process of being closed locally";
static const char short_gen1018[] = "**sock|closing_already";
static const char long_gen1018[]  = "a close operation is already posted";
static const char short_gen1019[] = "**sock|connclosed";
static const char long_gen1019[]  = "connection closed by peer";
static const char short_gen1020[] = "**sock|connfailed";
static const char long_gen1020[]  = "connection failure";
static const char short_gen1021[] = "**sock|connrefused";
static const char long_gen1021[]  = "connection refused";
static const char short_gen1022[] = "**sock|listener_bad_sock";
static const char long_gen1022[]  = "supplied sock is not a listener";
static const char short_gen1023[] = "**sock|listener_bad_state";
static const char long_gen1023[]  = "supplied listener sock is in a bad state";
static const char short_gen1024[] = "**sock|listener_read";
static const char long_gen1024[]  = "read operation not allowed on a listener";
static const char short_gen1025[] = "**sock|listener_write";
static const char long_gen1025[]  = "write operation not allowed on a listener";
static const char short_gen1026[] = "**sock|nosock";
static const char long_gen1026[]  = "no new sock was available to accept";
static const char short_gen1027[] = "**sock|notconnected";
static const char long_gen1027[]  = "sock is not connected";
static const char short_gen1028[] = "**sock|oserror";
static const char long_gen1028[]  = "unexpected operating system error";
static const char short_gen1029[] = "**sock|osnomem";
static const char long_gen1029[]  = "operating system routine failed due to lack of memory";
static const char short_gen1030[] = "**sock|poll|accept";
static const char long_gen1030[]  = "accept failed to acquire a new socket";
static const char short_gen1031[] = "**sock|poll|bind";
static const char long_gen1031[]  = "unable to bind socket to port";
static const char short_gen1032[] = "**sock|poll|eqfail";
static const char long_gen1032[]  = "fatal error: failed to enqueue an event; event was lost";
static const char short_gen1033[] = "**sock|poll|eqmalloc";
static const char long_gen1033[]  = "MPL_malloc failed to allocate memory for an event queue structure";
static const char short_gen1034[] = "**sock|poll|listen";
static const char long_gen1034[]  = "listen() failed";
static const char short_gen1035[] = "**sock|poll|nodelay";
static const char long_gen1035[]  = "unable to set TCP no delay attribute on socket";
static const char short_gen1036[] = "**sock|poll|nonblock";
static const char long_gen1036[]  = "unable to set socket to nonblocking";
static const char short_gen1037[] = "**sock|poll|pipe";
static const char long_gen1037[]  = "unable to allocate pipe to wakeup a blocking poll()";
static const char short_gen1038[] = "**sock|poll|pipenonblock";
static const char long_gen1038[]  = "unable to set wakeup pipe to nonblocking";
static const char short_gen1039[] = "**sock|poll|reuseaddr";
static const char long_gen1039[]  = "unable to set reuseaddr attribute on socket";
static const char short_gen1040[] = "**sock|poll|setrcvbufsz";
static const char long_gen1040[]  = " unable to set the receive socket buffer size";
static const char short_gen1041[] = "**sock|poll|setsndbufsz";
static const char long_gen1041[]  = " unable to set the send socket buffer size";
static const char short_gen1042[] = "**sock|poll|socket";
static const char long_gen1042[]  = "unable to obtain new socket";
static const char short_gen1043[] = "**sock|poll|unhandledstate";
static const char long_gen1043[]  = "encountered an unexpected state";
static const char short_gen1044[] = "**sock|poll|unhandledtype";
static const char long_gen1044[]  = "encountered an unexpected sock type";
static const char short_gen1045[] = "**sock|reads";
static const char long_gen1045[]  = "attempt to perform multiple simultaneous reads";
static const char short_gen1046[] = "**sock|setalloc";
static const char long_gen1046[]  = "unable to allocate a new sock set object";
static const char short_gen1047[] = "**sock|sockalloc";
static const char long_gen1047[]  = "unable to allocate a new sock object";
static const char short_gen1048[] = "**sock|uninit";
static const char long_gen1048[]  = "Sock library has not been initialized";
static const char short_gen1049[] = "**sock|writes";
static const char long_gen1049[]  = "attempt to perform multiple simultaneous writes";
static const char short_gen1050[] = "**spawn";
static const char long_gen1050[]  = "Error in spawn call";
static const char short_gen1051[] = "**splittype";
static const char long_gen1051[]  = "Invalid split_type argument";
static const char short_gen1052[] = "**storageorder";
static const char long_gen1052[]  = "Invalid storage order";
static const char short_gen1053[] = "**streamcomm_dstidx";
static const char long_gen1053[]  = "The destination stream index exceeds the number of streams.";
static const char short_gen1054[] = "**streamcomm_notmult";
static const char long_gen1054[]  = "The communicator is not a multiplex stream communicator.";
static const char short_gen1055[] = "**streamcomm_srcidx";
static const char long_gen1055[]  = "The source stream index exceeds the number of streams.";
static const char short_gen1056[] = "**stride";
static const char long_gen1056[]  = "Range does not terminate";
static const char short_gen1057[] = "**stridezero";
static const char long_gen1057[]  = "Zero stride is invalid";
static const char short_gen1058[] = "**success";
static const char long_gen1058[]  = "No MPI error";
static const char short_gen1059[] = "**tag";
static const char long_gen1059[]  = "Invalid tag";
static const char short_gen1060[] = "**tcp_cleanup_fail";
static const char long_gen1060[]  = "Error while cleaning up failed connection";
static const char short_gen1061[] = "**thread_level";
static const char long_gen1061[]  = " Invalid thread level";
static const char short_gen1062[] = "**timeout";
static const char long_gen1062[]  = "Operation timed out";
static const char short_gen1063[] = "**tmpvc_connect_fail";
static const char long_gen1063[]  = "Failure during connection protocol";
static const char short_gen1064[] = "**too_big_for_input";
static const char long_gen1064[]  = "The input is too big for internal routines";
static const char short_gen1065[] = "**toomanycomm";
static const char long_gen1065[]  = "Too many communicators";
static const char short_gen1066[] = "**toomanycommfrag";
static const char long_gen1066[]  = " Cannot allocate context ID because of fragmentation";
static const char short_gen1067[] = "**toomanynbc";
static const char long_gen1067[]  = " too many outstanding nonblocking collectives detected";
static const char short_gen1068[] = "**topology";
static const char long_gen1068[]  = "Invalid topology";
static const char short_gen1069[] = "**topotoolarge";
static const char long_gen1069[]  = "Topology size is greater than communicator size";
static const char short_gen1070[] = "**treetype";
static const char long_gen1070[]  = " Invalid tree type used for initializing Tree algorithms";
static const char short_gen1071[] = "**truncate";
static const char long_gen1071[]  = "Message truncated";
static const char short_gen1072[] = "**typeinitbadmem";
static const char long_gen1072[]  = "builtin datatype handle references invalid memory";
static const char short_gen1073[] = "**typematchnoclass";
static const char long_gen1073[]  = "The value of typeclass is not one of MPI_TYPECLASS_REAL, MPI_TYPECLASS_INTEGER, or MPI_TYPECLASS_COMPLEX";
static const char short_gen1074[] = "**typematchsize";
static const char long_gen1074[]  = "No MPI datatype available for the given typeclass and size";
static const char short_gen1075[] = "**typenotpredefined";
static const char long_gen1075[]  = " Datatype must be predefined";
static const char short_gen1076[] = "**ucx_nm_rq_error";
static const char long_gen1076[]  = " return failed request in UCX netmod";
static const char short_gen1077[] = "**ucx_nm_status";
static const char long_gen1077[]  = " ucx function returned with failed status";
static const char short_gen1078[] = "**unknown";
static const char long_gen1078[]  = "Unknown error.  Please file a bug report.";
static const char short_gen1079[] = "**unknowngpid";
static const char long_gen1079[]  = "Internal MPI error: Unknown gpid";
static const char short_gen1080[] = "**unsupporteddatarep";
static const char long_gen1080[]  = "Only native data representation currently supported";
static const char short_gen1081[] = "**unweightedboth";
static const char long_gen1081[]  = "Must specify MPI_UNWEIGHTED for both or neither weight arguments";
static const char short_gen1082[] = "**user";
static const char long_gen1082[]  = "user defined function returned an error code";
static const char short_gen1083[] = "**valuetoolarge";
static const char long_gen1083[]  = "Value is too large to store";
static const char short_gen1084[] = "**vc_in_error_state";
static const char long_gen1084[]  = "Connection is in error state";
static const char short_gen1085[] = "**win";
static const char long_gen1085[]  = "Invalid MPI_Win";
static const char short_gen1086[] = "**winInvalidOp";
static const char long_gen1086[]  = " Invalid RMA operation";
static const char short_gen1087[] = "**winallocnotshared";
static const char long_gen1087[]  = "processes are not in the same shared memory domain";
static const char short_gen1088[] = "**windows_mutex";
static const char long_gen1088[]  = "Windows mutex routine failed";
static const char short_gen1089[] = "**winflavor";
static const char long_gen1089[]  = " Window flavor is not compatible with the given operation";
static const char short_gen1090[] = "**winnoprogress";
static const char long_gen1090[]  = " Detected an error while in progress wait for RMA messages";
static const char short_gen1091[] = "**winnull";
static const char long_gen1091[]  = "Null MPI_Win";
static const char short_gen1092[] = "**write";
static const char long_gen1092[]  = "write failed";
static const char short_gen1093[] = "**writev";
static const char long_gen1093[]  = "writev failed";
static const char short_gen1094[] = "**xpmem_attach";
static const char long_gen1094[]  = " xpmem_attach failed";
static const char short_gen1095[] = "**xpmem_get";
static const char long_gen1095[]  = " xpmem_get failed";
static const char short_gen1096[] = "**xpmem_make";
static const char long_gen1096[]  = " xpmem_make failed";
static const char short_gen1097[] = "**xpmem_release";
static const char long_gen1097[]  = " xpmem_release failed";
static const char short_gen1098[] = "**xpmem_remove";
static const char long_gen1098[]  = " xpmem_remove failed";
static const char short_gen1099[] = "**xpmem_segid";
static const char long_gen1099[]  = " xpmem remote segid is unset";
static const char short_gen1100[] = "**xpmem_segtree_init";
static const char long_gen1100[]  = " xpmem_segtree_init failed";
static const char short_gen1101[] = "**yaksa";
static const char long_gen1101[]  = "Yaksa library returned an error";

static const int generic_msgs_len = 1102;
static const msgpair generic_err_msgs[] = {
    { 0xacebad03, short_gen0, long_gen0, 0xcb0bfa11 },
    { 0xacebad03, short_gen1, long_gen1, 0xcb0bfa11 },
    { 0xacebad03, short_gen2, long_gen2, 0xcb0bfa11 },
    { 0xacebad03, short_gen3, long_gen3, 0xcb0bfa11 },
    { 0xacebad03, short_gen4, long_gen4, 0xcb0bfa11 },
    { 0xacebad03, short_gen5, long_gen5, 0xcb0bfa11 },
    { 0xacebad03, short_gen6, long_gen6, 0xcb0bfa11 },
    { 0xacebad03, short_gen7, long_gen7, 0xcb0bfa11 },
    { 0xacebad03, short_gen8, long_gen8, 0xcb0bfa11 },
    { 0xacebad03, short_gen9, long_gen9, 0xcb0bfa11 },
    { 0xacebad03, short_gen10, long_gen10, 0xcb0bfa11 },
    { 0xacebad03, short_gen11, long_gen11, 0xcb0bfa11 },
    { 0xacebad03, short_gen12, long_gen12, 0xcb0bfa11 },
    { 0xacebad03, short_gen13, long_gen13, 0xcb0bfa11 },
    { 0xacebad03, short_gen14, long_gen14, 0xcb0bfa11 },
    { 0xacebad03, short_gen15, long_gen15, 0xcb0bfa11 },
    { 0xacebad03, short_gen16, long_gen16, 0xcb0bfa11 },
    { 0xacebad03, short_gen17, long_gen17, 0xcb0bfa11 },
    { 0xacebad03, short_gen18, long_gen18, 0xcb0bfa11 },
    { 0xacebad03, short_gen19, long_gen19, 0xcb0bfa11 },
    { 0xacebad03, short_gen20, long_gen20, 0xcb0bfa11 },
    { 0xacebad03, short_gen21, long_gen21, 0xcb0bfa11 },
    { 0xacebad03, short_gen22, long_gen22, 0xcb0bfa11 },
    { 0xacebad03, short_gen23, long_gen23, 0xcb0bfa11 },
    { 0xacebad03, short_gen24, long_gen24, 0xcb0bfa11 },
    { 0xacebad03, short_gen25, long_gen25, 0xcb0bfa11 },
    { 0xacebad03, short_gen26, long_gen26, 0xcb0bfa11 },
    { 0xacebad03, short_gen27, long_gen27, 0xcb0bfa11 },
    { 0xacebad03, short_gen28, long_gen28, 0xcb0bfa11 },
    { 0xacebad03, short_gen29, long_gen29, 0xcb0bfa11 },
    { 0xacebad03, short_gen30, long_gen30, 0xcb0bfa11 },
    { 0xacebad03, short_gen31, long_gen31, 0xcb0bfa11 },
    { 0xacebad03, short_gen32, long_gen32, 0xcb0bfa11 },
    { 0xacebad03, short_gen33, long_gen33, 0xcb0bfa11 },
    { 0xacebad03, short_gen34, long_gen34, 0xcb0bfa11 },
    { 0xacebad03, short_gen35, long_gen35, 0xcb0bfa11 },
    { 0xacebad03, short_gen36, long_gen36, 0xcb0bfa11 },
    { 0xacebad03, short_gen37, long_gen37, 0xcb0bfa11 },
    { 0xacebad03, short_gen38, long_gen38, 0xcb0bfa11 },
    { 0xacebad03, short_gen39, long_gen39, 0xcb0bfa11 },
    { 0xacebad03, short_gen40, long_gen40, 0xcb0bfa11 },
    { 0xacebad03, short_gen41, long_gen41, 0xcb0bfa11 },
    { 0xacebad03, short_gen42, long_gen42, 0xcb0bfa11 },
    { 0xacebad03, short_gen43, long_gen43, 0xcb0bfa11 },
    { 0xacebad03, short_gen44, long_gen44, 0xcb0bfa11 },
    { 0xacebad03, short_gen45, long_gen45, 0xcb0bfa11 },
    { 0xacebad03, short_gen46, long_gen46, 0xcb0bfa11 },
    { 0xacebad03, short_gen47, long_gen47, 0xcb0bfa11 },
    { 0xacebad03, short_gen48, long_gen48, 0xcb0bfa11 },
    { 0xacebad03, short_gen49, long_gen49, 0xcb0bfa11 },
    { 0xacebad03, short_gen50, long_gen50, 0xcb0bfa11 },
    { 0xacebad03, short_gen51, long_gen51, 0xcb0bfa11 },
    { 0xacebad03, short_gen52, long_gen52, 0xcb0bfa11 },
    { 0xacebad03, short_gen53, long_gen53, 0xcb0bfa11 },
    { 0xacebad03, short_gen54, long_gen54, 0xcb0bfa11 },
    { 0xacebad03, short_gen55, long_gen55, 0xcb0bfa11 },
    { 0xacebad03, short_gen56, long_gen56, 0xcb0bfa11 },
    { 0xacebad03, short_gen57, long_gen57, 0xcb0bfa11 },
    { 0xacebad03, short_gen58, long_gen58, 0xcb0bfa11 },
    { 0xacebad03, short_gen59, long_gen59, 0xcb0bfa11 },
    { 0xacebad03, short_gen60, long_gen60, 0xcb0bfa11 },
    { 0xacebad03, short_gen61, long_gen61, 0xcb0bfa11 },
    { 0xacebad03, short_gen62, long_gen62, 0xcb0bfa11 },
    { 0xacebad03, short_gen63, long_gen63, 0xcb0bfa11 },
    { 0xacebad03, short_gen64, long_gen64, 0xcb0bfa11 },
    { 0xacebad03, short_gen65, long_gen65, 0xcb0bfa11 },
    { 0xacebad03, short_gen66, long_gen66, 0xcb0bfa11 },
    { 0xacebad03, short_gen67, long_gen67, 0xcb0bfa11 },
    { 0xacebad03, short_gen68, long_gen68, 0xcb0bfa11 },
    { 0xacebad03, short_gen69, long_gen69, 0xcb0bfa11 },
    { 0xacebad03, short_gen70, long_gen70, 0xcb0bfa11 },
    { 0xacebad03, short_gen71, long_gen71, 0xcb0bfa11 },
    { 0xacebad03, short_gen72, long_gen72, 0xcb0bfa11 },
    { 0xacebad03, short_gen73, long_gen73, 0xcb0bfa11 },
    { 0xacebad03, short_gen74, long_gen74, 0xcb0bfa11 },
    { 0xacebad03, short_gen75, long_gen75, 0xcb0bfa11 },
    { 0xacebad03, short_gen76, long_gen76, 0xcb0bfa11 },
    { 0xacebad03, short_gen77, long_gen77, 0xcb0bfa11 },
    { 0xacebad03, short_gen78, long_gen78, 0xcb0bfa11 },
    { 0xacebad03, short_gen79, long_gen79, 0xcb0bfa11 },
    { 0xacebad03, short_gen80, long_gen80, 0xcb0bfa11 },
    { 0xacebad03, short_gen81, long_gen81, 0xcb0bfa11 },
    { 0xacebad03, short_gen82, long_gen82, 0xcb0bfa11 },
    { 0xacebad03, short_gen83, long_gen83, 0xcb0bfa11 },
    { 0xacebad03, short_gen84, long_gen84, 0xcb0bfa11 },
    { 0xacebad03, short_gen85, long_gen85, 0xcb0bfa11 },
    { 0xacebad03, short_gen86, long_gen86, 0xcb0bfa11 },
    { 0xacebad03, short_gen87, long_gen87, 0xcb0bfa11 },
    { 0xacebad03, short_gen88, long_gen88, 0xcb0bfa11 },
    { 0xacebad03, short_gen89, long_gen89, 0xcb0bfa11 },
    { 0xacebad03, short_gen90, long_gen90, 0xcb0bfa11 },
    { 0xacebad03, short_gen91, long_gen91, 0xcb0bfa11 },
    { 0xacebad03, short_gen92, long_gen92, 0xcb0bfa11 },
    { 0xacebad03, short_gen93, long_gen93, 0xcb0bfa11 },
    { 0xacebad03, short_gen94, long_gen94, 0xcb0bfa11 },
    { 0xacebad03, short_gen95, long_gen95, 0xcb0bfa11 },
    { 0xacebad03, short_gen96, long_gen96, 0xcb0bfa11 },
    { 0xacebad03, short_gen97, long_gen97, 0xcb0bfa11 },
    { 0xacebad03, short_gen98, long_gen98, 0xcb0bfa11 },
    { 0xacebad03, short_gen99, long_gen99, 0xcb0bfa11 },
    { 0xacebad03, short_gen100, long_gen100, 0xcb0bfa11 },
    { 0xacebad03, short_gen101, long_gen101, 0xcb0bfa11 },
    { 0xacebad03, short_gen102, long_gen102, 0xcb0bfa11 },
    { 0xacebad03, short_gen103, long_gen103, 0xcb0bfa11 },
    { 0xacebad03, short_gen104, long_gen104, 0xcb0bfa11 },
    { 0xacebad03, short_gen105, long_gen105, 0xcb0bfa11 },
    { 0xacebad03, short_gen106, long_gen106, 0xcb0bfa11 },
    { 0xacebad03, short_gen107, long_gen107, 0xcb0bfa11 },
    { 0xacebad03, short_gen108, long_gen108, 0xcb0bfa11 },
    { 0xacebad03, short_gen109, long_gen109, 0xcb0bfa11 },
    { 0xacebad03, short_gen110, long_gen110, 0xcb0bfa11 },
    { 0xacebad03, short_gen111, long_gen111, 0xcb0bfa11 },
    { 0xacebad03, short_gen112, long_gen112, 0xcb0bfa11 },
    { 0xacebad03, short_gen113, long_gen113, 0xcb0bfa11 },
    { 0xacebad03, short_gen114, long_gen114, 0xcb0bfa11 },
    { 0xacebad03, short_gen115, long_gen115, 0xcb0bfa11 },
    { 0xacebad03, short_gen116, long_gen116, 0xcb0bfa11 },
    { 0xacebad03, short_gen117, long_gen117, 0xcb0bfa11 },
    { 0xacebad03, short_gen118, long_gen118, 0xcb0bfa11 },
    { 0xacebad03, short_gen119, long_gen119, 0xcb0bfa11 },
    { 0xacebad03, short_gen120, long_gen120, 0xcb0bfa11 },
    { 0xacebad03, short_gen121, long_gen121, 0xcb0bfa11 },
    { 0xacebad03, short_gen122, long_gen122, 0xcb0bfa11 },
    { 0xacebad03, short_gen123, long_gen123, 0xcb0bfa11 },
    { 0xacebad03, short_gen124, long_gen124, 0xcb0bfa11 },
    { 0xacebad03, short_gen125, long_gen125, 0xcb0bfa11 },
    { 0xacebad03, short_gen126, long_gen126, 0xcb0bfa11 },
    { 0xacebad03, short_gen127, long_gen127, 0xcb0bfa11 },
    { 0xacebad03, short_gen128, long_gen128, 0xcb0bfa11 },
    { 0xacebad03, short_gen129, long_gen129, 0xcb0bfa11 },
    { 0xacebad03, short_gen130, long_gen130, 0xcb0bfa11 },
    { 0xacebad03, short_gen131, long_gen131, 0xcb0bfa11 },
    { 0xacebad03, short_gen132, long_gen132, 0xcb0bfa11 },
    { 0xacebad03, short_gen133, long_gen133, 0xcb0bfa11 },
    { 0xacebad03, short_gen134, long_gen134, 0xcb0bfa11 },
    { 0xacebad03, short_gen135, long_gen135, 0xcb0bfa11 },
    { 0xacebad03, short_gen136, long_gen136, 0xcb0bfa11 },
    { 0xacebad03, short_gen137, long_gen137, 0xcb0bfa11 },
    { 0xacebad03, short_gen138, long_gen138, 0xcb0bfa11 },
    { 0xacebad03, short_gen139, long_gen139, 0xcb0bfa11 },
    { 0xacebad03, short_gen140, long_gen140, 0xcb0bfa11 },
    { 0xacebad03, short_gen141, long_gen141, 0xcb0bfa11 },
    { 0xacebad03, short_gen142, long_gen142, 0xcb0bfa11 },
    { 0xacebad03, short_gen143, long_gen143, 0xcb0bfa11 },
    { 0xacebad03, short_gen144, long_gen144, 0xcb0bfa11 },
    { 0xacebad03, short_gen145, long_gen145, 0xcb0bfa11 },
    { 0xacebad03, short_gen146, long_gen146, 0xcb0bfa11 },
    { 0xacebad03, short_gen147, long_gen147, 0xcb0bfa11 },
    { 0xacebad03, short_gen148, long_gen148, 0xcb0bfa11 },
    { 0xacebad03, short_gen149, long_gen149, 0xcb0bfa11 },
    { 0xacebad03, short_gen150, long_gen150, 0xcb0bfa11 },
    { 0xacebad03, short_gen151, long_gen151, 0xcb0bfa11 },
    { 0xacebad03, short_gen152, long_gen152, 0xcb0bfa11 },
    { 0xacebad03, short_gen153, long_gen153, 0xcb0bfa11 },
    { 0xacebad03, short_gen154, long_gen154, 0xcb0bfa11 },
    { 0xacebad03, short_gen155, long_gen155, 0xcb0bfa11 },
    { 0xacebad03, short_gen156, long_gen156, 0xcb0bfa11 },
    { 0xacebad03, short_gen157, long_gen157, 0xcb0bfa11 },
    { 0xacebad03, short_gen158, long_gen158, 0xcb0bfa11 },
    { 0xacebad03, short_gen159, long_gen159, 0xcb0bfa11 },
    { 0xacebad03, short_gen160, long_gen160, 0xcb0bfa11 },
    { 0xacebad03, short_gen161, long_gen161, 0xcb0bfa11 },
    { 0xacebad03, short_gen162, long_gen162, 0xcb0bfa11 },
    { 0xacebad03, short_gen163, long_gen163, 0xcb0bfa11 },
    { 0xacebad03, short_gen164, long_gen164, 0xcb0bfa11 },
    { 0xacebad03, short_gen165, long_gen165, 0xcb0bfa11 },
    { 0xacebad03, short_gen166, long_gen166, 0xcb0bfa11 },
    { 0xacebad03, short_gen167, long_gen167, 0xcb0bfa11 },
    { 0xacebad03, short_gen168, long_gen168, 0xcb0bfa11 },
    { 0xacebad03, short_gen169, long_gen169, 0xcb0bfa11 },
    { 0xacebad03, short_gen170, long_gen170, 0xcb0bfa11 },
    { 0xacebad03, short_gen171, long_gen171, 0xcb0bfa11 },
    { 0xacebad03, short_gen172, long_gen172, 0xcb0bfa11 },
    { 0xacebad03, short_gen173, long_gen173, 0xcb0bfa11 },
    { 0xacebad03, short_gen174, long_gen174, 0xcb0bfa11 },
    { 0xacebad03, short_gen175, long_gen175, 0xcb0bfa11 },
    { 0xacebad03, short_gen176, long_gen176, 0xcb0bfa11 },
    { 0xacebad03, short_gen177, long_gen177, 0xcb0bfa11 },
    { 0xacebad03, short_gen178, long_gen178, 0xcb0bfa11 },
    { 0xacebad03, short_gen179, long_gen179, 0xcb0bfa11 },
    { 0xacebad03, short_gen180, long_gen180, 0xcb0bfa11 },
    { 0xacebad03, short_gen181, long_gen181, 0xcb0bfa11 },
    { 0xacebad03, short_gen182, long_gen182, 0xcb0bfa11 },
    { 0xacebad03, short_gen183, long_gen183, 0xcb0bfa11 },
    { 0xacebad03, short_gen184, long_gen184, 0xcb0bfa11 },
    { 0xacebad03, short_gen185, long_gen185, 0xcb0bfa11 },
    { 0xacebad03, short_gen186, long_gen186, 0xcb0bfa11 },
    { 0xacebad03, short_gen187, long_gen187, 0xcb0bfa11 },
    { 0xacebad03, short_gen188, long_gen188, 0xcb0bfa11 },
    { 0xacebad03, short_gen189, long_gen189, 0xcb0bfa11 },
    { 0xacebad03, short_gen190, long_gen190, 0xcb0bfa11 },
    { 0xacebad03, short_gen191, long_gen191, 0xcb0bfa11 },
    { 0xacebad03, short_gen192, long_gen192, 0xcb0bfa11 },
    { 0xacebad03, short_gen193, long_gen193, 0xcb0bfa11 },
    { 0xacebad03, short_gen194, long_gen194, 0xcb0bfa11 },
    { 0xacebad03, short_gen195, long_gen195, 0xcb0bfa11 },
    { 0xacebad03, short_gen196, long_gen196, 0xcb0bfa11 },
    { 0xacebad03, short_gen197, long_gen197, 0xcb0bfa11 },
    { 0xacebad03, short_gen198, long_gen198, 0xcb0bfa11 },
    { 0xacebad03, short_gen199, long_gen199, 0xcb0bfa11 },
    { 0xacebad03, short_gen200, long_gen200, 0xcb0bfa11 },
    { 0xacebad03, short_gen201, long_gen201, 0xcb0bfa11 },
    { 0xacebad03, short_gen202, long_gen202, 0xcb0bfa11 },
    { 0xacebad03, short_gen203, long_gen203, 0xcb0bfa11 },
    { 0xacebad03, short_gen204, long_gen204, 0xcb0bfa11 },
    { 0xacebad03, short_gen205, long_gen205, 0xcb0bfa11 },
    { 0xacebad03, short_gen206, long_gen206, 0xcb0bfa11 },
    { 0xacebad03, short_gen207, long_gen207, 0xcb0bfa11 },
    { 0xacebad03, short_gen208, long_gen208, 0xcb0bfa11 },
    { 0xacebad03, short_gen209, long_gen209, 0xcb0bfa11 },
    { 0xacebad03, short_gen210, long_gen210, 0xcb0bfa11 },
    { 0xacebad03, short_gen211, long_gen211, 0xcb0bfa11 },
    { 0xacebad03, short_gen212, long_gen212, 0xcb0bfa11 },
    { 0xacebad03, short_gen213, long_gen213, 0xcb0bfa11 },
    { 0xacebad03, short_gen214, long_gen214, 0xcb0bfa11 },
    { 0xacebad03, short_gen215, long_gen215, 0xcb0bfa11 },
    { 0xacebad03, short_gen216, long_gen216, 0xcb0bfa11 },
    { 0xacebad03, short_gen217, long_gen217, 0xcb0bfa11 },
    { 0xacebad03, short_gen218, long_gen218, 0xcb0bfa11 },
    { 0xacebad03, short_gen219, long_gen219, 0xcb0bfa11 },
    { 0xacebad03, short_gen220, long_gen220, 0xcb0bfa11 },
    { 0xacebad03, short_gen221, long_gen221, 0xcb0bfa11 },
    { 0xacebad03, short_gen222, long_gen222, 0xcb0bfa11 },
    { 0xacebad03, short_gen223, long_gen223, 0xcb0bfa11 },
    { 0xacebad03, short_gen224, long_gen224, 0xcb0bfa11 },
    { 0xacebad03, short_gen225, long_gen225, 0xcb0bfa11 },
    { 0xacebad03, short_gen226, long_gen226, 0xcb0bfa11 },
    { 0xacebad03, short_gen227, long_gen227, 0xcb0bfa11 },
    { 0xacebad03, short_gen228, long_gen228, 0xcb0bfa11 },
    { 0xacebad03, short_gen229, long_gen229, 0xcb0bfa11 },
    { 0xacebad03, short_gen230, long_gen230, 0xcb0bfa11 },
    { 0xacebad03, short_gen231, long_gen231, 0xcb0bfa11 },
    { 0xacebad03, short_gen232, long_gen232, 0xcb0bfa11 },
    { 0xacebad03, short_gen233, long_gen233, 0xcb0bfa11 },
    { 0xacebad03, short_gen234, long_gen234, 0xcb0bfa11 },
    { 0xacebad03, short_gen235, long_gen235, 0xcb0bfa11 },
    { 0xacebad03, short_gen236, long_gen236, 0xcb0bfa11 },
    { 0xacebad03, short_gen237, long_gen237, 0xcb0bfa11 },
    { 0xacebad03, short_gen238, long_gen238, 0xcb0bfa11 },
    { 0xacebad03, short_gen239, long_gen239, 0xcb0bfa11 },
    { 0xacebad03, short_gen240, long_gen240, 0xcb0bfa11 },
    { 0xacebad03, short_gen241, long_gen241, 0xcb0bfa11 },
    { 0xacebad03, short_gen242, long_gen242, 0xcb0bfa11 },
    { 0xacebad03, short_gen243, long_gen243, 0xcb0bfa11 },
    { 0xacebad03, short_gen244, long_gen244, 0xcb0bfa11 },
    { 0xacebad03, short_gen245, long_gen245, 0xcb0bfa11 },
    { 0xacebad03, short_gen246, long_gen246, 0xcb0bfa11 },
    { 0xacebad03, short_gen247, long_gen247, 0xcb0bfa11 },
    { 0xacebad03, short_gen248, long_gen248, 0xcb0bfa11 },
    { 0xacebad03, short_gen249, long_gen249, 0xcb0bfa11 },
    { 0xacebad03, short_gen250, long_gen250, 0xcb0bfa11 },
    { 0xacebad03, short_gen251, long_gen251, 0xcb0bfa11 },
    { 0xacebad03, short_gen252, long_gen252, 0xcb0bfa11 },
    { 0xacebad03, short_gen253, long_gen253, 0xcb0bfa11 },
    { 0xacebad03, short_gen254, long_gen254, 0xcb0bfa11 },
    { 0xacebad03, short_gen255, long_gen255, 0xcb0bfa11 },
    { 0xacebad03, short_gen256, long_gen256, 0xcb0bfa11 },
    { 0xacebad03, short_gen257, long_gen257, 0xcb0bfa11 },
    { 0xacebad03, short_gen258, long_gen258, 0xcb0bfa11 },
    { 0xacebad03, short_gen259, long_gen259, 0xcb0bfa11 },
    { 0xacebad03, short_gen260, long_gen260, 0xcb0bfa11 },
    { 0xacebad03, short_gen261, long_gen261, 0xcb0bfa11 },
    { 0xacebad03, short_gen262, long_gen262, 0xcb0bfa11 },
    { 0xacebad03, short_gen263, long_gen263, 0xcb0bfa11 },
    { 0xacebad03, short_gen264, long_gen264, 0xcb0bfa11 },
    { 0xacebad03, short_gen265, long_gen265, 0xcb0bfa11 },
    { 0xacebad03, short_gen266, long_gen266, 0xcb0bfa11 },
    { 0xacebad03, short_gen267, long_gen267, 0xcb0bfa11 },
    { 0xacebad03, short_gen268, long_gen268, 0xcb0bfa11 },
    { 0xacebad03, short_gen269, long_gen269, 0xcb0bfa11 },
    { 0xacebad03, short_gen270, long_gen270, 0xcb0bfa11 },
    { 0xacebad03, short_gen271, long_gen271, 0xcb0bfa11 },
    { 0xacebad03, short_gen272, long_gen272, 0xcb0bfa11 },
    { 0xacebad03, short_gen273, long_gen273, 0xcb0bfa11 },
    { 0xacebad03, short_gen274, long_gen274, 0xcb0bfa11 },
    { 0xacebad03, short_gen275, long_gen275, 0xcb0bfa11 },
    { 0xacebad03, short_gen276, long_gen276, 0xcb0bfa11 },
    { 0xacebad03, short_gen277, long_gen277, 0xcb0bfa11 },
    { 0xacebad03, short_gen278, long_gen278, 0xcb0bfa11 },
    { 0xacebad03, short_gen279, long_gen279, 0xcb0bfa11 },
    { 0xacebad03, short_gen280, long_gen280, 0xcb0bfa11 },
    { 0xacebad03, short_gen281, long_gen281, 0xcb0bfa11 },
    { 0xacebad03, short_gen282, long_gen282, 0xcb0bfa11 },
    { 0xacebad03, short_gen283, long_gen283, 0xcb0bfa11 },
    { 0xacebad03, short_gen284, long_gen284, 0xcb0bfa11 },
    { 0xacebad03, short_gen285, long_gen285, 0xcb0bfa11 },
    { 0xacebad03, short_gen286, long_gen286, 0xcb0bfa11 },
    { 0xacebad03, short_gen287, long_gen287, 0xcb0bfa11 },
    { 0xacebad03, short_gen288, long_gen288, 0xcb0bfa11 },
    { 0xacebad03, short_gen289, long_gen289, 0xcb0bfa11 },
    { 0xacebad03, short_gen290, long_gen290, 0xcb0bfa11 },
    { 0xacebad03, short_gen291, long_gen291, 0xcb0bfa11 },
    { 0xacebad03, short_gen292, long_gen292, 0xcb0bfa11 },
    { 0xacebad03, short_gen293, long_gen293, 0xcb0bfa11 },
    { 0xacebad03, short_gen294, long_gen294, 0xcb0bfa11 },
    { 0xacebad03, short_gen295, long_gen295, 0xcb0bfa11 },
    { 0xacebad03, short_gen296, long_gen296, 0xcb0bfa11 },
    { 0xacebad03, short_gen297, long_gen297, 0xcb0bfa11 },
    { 0xacebad03, short_gen298, long_gen298, 0xcb0bfa11 },
    { 0xacebad03, short_gen299, long_gen299, 0xcb0bfa11 },
    { 0xacebad03, short_gen300, long_gen300, 0xcb0bfa11 },
    { 0xacebad03, short_gen301, long_gen301, 0xcb0bfa11 },
    { 0xacebad03, short_gen302, long_gen302, 0xcb0bfa11 },
    { 0xacebad03, short_gen303, long_gen303, 0xcb0bfa11 },
    { 0xacebad03, short_gen304, long_gen304, 0xcb0bfa11 },
    { 0xacebad03, short_gen305, long_gen305, 0xcb0bfa11 },
    { 0xacebad03, short_gen306, long_gen306, 0xcb0bfa11 },
    { 0xacebad03, short_gen307, long_gen307, 0xcb0bfa11 },
    { 0xacebad03, short_gen308, long_gen308, 0xcb0bfa11 },
    { 0xacebad03, short_gen309, long_gen309, 0xcb0bfa11 },
    { 0xacebad03, short_gen310, long_gen310, 0xcb0bfa11 },
    { 0xacebad03, short_gen311, long_gen311, 0xcb0bfa11 },
    { 0xacebad03, short_gen312, long_gen312, 0xcb0bfa11 },
    { 0xacebad03, short_gen313, long_gen313, 0xcb0bfa11 },
    { 0xacebad03, short_gen314, long_gen314, 0xcb0bfa11 },
    { 0xacebad03, short_gen315, long_gen315, 0xcb0bfa11 },
    { 0xacebad03, short_gen316, long_gen316, 0xcb0bfa11 },
    { 0xacebad03, short_gen317, long_gen317, 0xcb0bfa11 },
    { 0xacebad03, short_gen318, long_gen318, 0xcb0bfa11 },
    { 0xacebad03, short_gen319, long_gen319, 0xcb0bfa11 },
    { 0xacebad03, short_gen320, long_gen320, 0xcb0bfa11 },
    { 0xacebad03, short_gen321, long_gen321, 0xcb0bfa11 },
    { 0xacebad03, short_gen322, long_gen322, 0xcb0bfa11 },
    { 0xacebad03, short_gen323, long_gen323, 0xcb0bfa11 },
    { 0xacebad03, short_gen324, long_gen324, 0xcb0bfa11 },
    { 0xacebad03, short_gen325, long_gen325, 0xcb0bfa11 },
    { 0xacebad03, short_gen326, long_gen326, 0xcb0bfa11 },
    { 0xacebad03, short_gen327, long_gen327, 0xcb0bfa11 },
    { 0xacebad03, short_gen328, long_gen328, 0xcb0bfa11 },
    { 0xacebad03, short_gen329, long_gen329, 0xcb0bfa11 },
    { 0xacebad03, short_gen330, long_gen330, 0xcb0bfa11 },
    { 0xacebad03, short_gen331, long_gen331, 0xcb0bfa11 },
    { 0xacebad03, short_gen332, long_gen332, 0xcb0bfa11 },
    { 0xacebad03, short_gen333, long_gen333, 0xcb0bfa11 },
    { 0xacebad03, short_gen334, long_gen334, 0xcb0bfa11 },
    { 0xacebad03, short_gen335, long_gen335, 0xcb0bfa11 },
    { 0xacebad03, short_gen336, long_gen336, 0xcb0bfa11 },
    { 0xacebad03, short_gen337, long_gen337, 0xcb0bfa11 },
    { 0xacebad03, short_gen338, long_gen338, 0xcb0bfa11 },
    { 0xacebad03, short_gen339, long_gen339, 0xcb0bfa11 },
    { 0xacebad03, short_gen340, long_gen340, 0xcb0bfa11 },
    { 0xacebad03, short_gen341, long_gen341, 0xcb0bfa11 },
    { 0xacebad03, short_gen342, long_gen342, 0xcb0bfa11 },
    { 0xacebad03, short_gen343, long_gen343, 0xcb0bfa11 },
    { 0xacebad03, short_gen344, long_gen344, 0xcb0bfa11 },
    { 0xacebad03, short_gen345, long_gen345, 0xcb0bfa11 },
    { 0xacebad03, short_gen346, long_gen346, 0xcb0bfa11 },
    { 0xacebad03, short_gen347, long_gen347, 0xcb0bfa11 },
    { 0xacebad03, short_gen348, long_gen348, 0xcb0bfa11 },
    { 0xacebad03, short_gen349, long_gen349, 0xcb0bfa11 },
    { 0xacebad03, short_gen350, long_gen350, 0xcb0bfa11 },
    { 0xacebad03, short_gen351, long_gen351, 0xcb0bfa11 },
    { 0xacebad03, short_gen352, long_gen352, 0xcb0bfa11 },
    { 0xacebad03, short_gen353, long_gen353, 0xcb0bfa11 },
    { 0xacebad03, short_gen354, long_gen354, 0xcb0bfa11 },
    { 0xacebad03, short_gen355, long_gen355, 0xcb0bfa11 },
    { 0xacebad03, short_gen356, long_gen356, 0xcb0bfa11 },
    { 0xacebad03, short_gen357, long_gen357, 0xcb0bfa11 },
    { 0xacebad03, short_gen358, long_gen358, 0xcb0bfa11 },
    { 0xacebad03, short_gen359, long_gen359, 0xcb0bfa11 },
    { 0xacebad03, short_gen360, long_gen360, 0xcb0bfa11 },
    { 0xacebad03, short_gen361, long_gen361, 0xcb0bfa11 },
    { 0xacebad03, short_gen362, long_gen362, 0xcb0bfa11 },
    { 0xacebad03, short_gen363, long_gen363, 0xcb0bfa11 },
    { 0xacebad03, short_gen364, long_gen364, 0xcb0bfa11 },
    { 0xacebad03, short_gen365, long_gen365, 0xcb0bfa11 },
    { 0xacebad03, short_gen366, long_gen366, 0xcb0bfa11 },
    { 0xacebad03, short_gen367, long_gen367, 0xcb0bfa11 },
    { 0xacebad03, short_gen368, long_gen368, 0xcb0bfa11 },
    { 0xacebad03, short_gen369, long_gen369, 0xcb0bfa11 },
    { 0xacebad03, short_gen370, long_gen370, 0xcb0bfa11 },
    { 0xacebad03, short_gen371, long_gen371, 0xcb0bfa11 },
    { 0xacebad03, short_gen372, long_gen372, 0xcb0bfa11 },
    { 0xacebad03, short_gen373, long_gen373, 0xcb0bfa11 },
    { 0xacebad03, short_gen374, long_gen374, 0xcb0bfa11 },
    { 0xacebad03, short_gen375, long_gen375, 0xcb0bfa11 },
    { 0xacebad03, short_gen376, long_gen376, 0xcb0bfa11 },
    { 0xacebad03, short_gen377, long_gen377, 0xcb0bfa11 },
    { 0xacebad03, short_gen378, long_gen378, 0xcb0bfa11 },
    { 0xacebad03, short_gen379, long_gen379, 0xcb0bfa11 },
    { 0xacebad03, short_gen380, long_gen380, 0xcb0bfa11 },
    { 0xacebad03, short_gen381, long_gen381, 0xcb0bfa11 },
    { 0xacebad03, short_gen382, long_gen382, 0xcb0bfa11 },
    { 0xacebad03, short_gen383, long_gen383, 0xcb0bfa11 },
    { 0xacebad03, short_gen384, long_gen384, 0xcb0bfa11 },
    { 0xacebad03, short_gen385, long_gen385, 0xcb0bfa11 },
    { 0xacebad03, short_gen386, long_gen386, 0xcb0bfa11 },
    { 0xacebad03, short_gen387, long_gen387, 0xcb0bfa11 },
    { 0xacebad03, short_gen388, long_gen388, 0xcb0bfa11 },
    { 0xacebad03, short_gen389, long_gen389, 0xcb0bfa11 },
    { 0xacebad03, short_gen390, long_gen390, 0xcb0bfa11 },
    { 0xacebad03, short_gen391, long_gen391, 0xcb0bfa11 },
    { 0xacebad03, short_gen392, long_gen392, 0xcb0bfa11 },
    { 0xacebad03, short_gen393, long_gen393, 0xcb0bfa11 },
    { 0xacebad03, short_gen394, long_gen394, 0xcb0bfa11 },
    { 0xacebad03, short_gen395, long_gen395, 0xcb0bfa11 },
    { 0xacebad03, short_gen396, long_gen396, 0xcb0bfa11 },
    { 0xacebad03, short_gen397, long_gen397, 0xcb0bfa11 },
    { 0xacebad03, short_gen398, long_gen398, 0xcb0bfa11 },
    { 0xacebad03, short_gen399, long_gen399, 0xcb0bfa11 },
    { 0xacebad03, short_gen400, long_gen400, 0xcb0bfa11 },
    { 0xacebad03, short_gen401, long_gen401, 0xcb0bfa11 },
    { 0xacebad03, short_gen402, long_gen402, 0xcb0bfa11 },
    { 0xacebad03, short_gen403, long_gen403, 0xcb0bfa11 },
    { 0xacebad03, short_gen404, long_gen404, 0xcb0bfa11 },
    { 0xacebad03, short_gen405, long_gen405, 0xcb0bfa11 },
    { 0xacebad03, short_gen406, long_gen406, 0xcb0bfa11 },
    { 0xacebad03, short_gen407, long_gen407, 0xcb0bfa11 },
    { 0xacebad03, short_gen408, long_gen408, 0xcb0bfa11 },
    { 0xacebad03, short_gen409, long_gen409, 0xcb0bfa11 },
    { 0xacebad03, short_gen410, long_gen410, 0xcb0bfa11 },
    { 0xacebad03, short_gen411, long_gen411, 0xcb0bfa11 },
    { 0xacebad03, short_gen412, long_gen412, 0xcb0bfa11 },
    { 0xacebad03, short_gen413, long_gen413, 0xcb0bfa11 },
    { 0xacebad03, short_gen414, long_gen414, 0xcb0bfa11 },
    { 0xacebad03, short_gen415, long_gen415, 0xcb0bfa11 },
    { 0xacebad03, short_gen416, long_gen416, 0xcb0bfa11 },
    { 0xacebad03, short_gen417, long_gen417, 0xcb0bfa11 },
    { 0xacebad03, short_gen418, long_gen418, 0xcb0bfa11 },
    { 0xacebad03, short_gen419, long_gen419, 0xcb0bfa11 },
    { 0xacebad03, short_gen420, long_gen420, 0xcb0bfa11 },
    { 0xacebad03, short_gen421, long_gen421, 0xcb0bfa11 },
    { 0xacebad03, short_gen422, long_gen422, 0xcb0bfa11 },
    { 0xacebad03, short_gen423, long_gen423, 0xcb0bfa11 },
    { 0xacebad03, short_gen424, long_gen424, 0xcb0bfa11 },
    { 0xacebad03, short_gen425, long_gen425, 0xcb0bfa11 },
    { 0xacebad03, short_gen426, long_gen426, 0xcb0bfa11 },
    { 0xacebad03, short_gen427, long_gen427, 0xcb0bfa11 },
    { 0xacebad03, short_gen428, long_gen428, 0xcb0bfa11 },
    { 0xacebad03, short_gen429, long_gen429, 0xcb0bfa11 },
    { 0xacebad03, short_gen430, long_gen430, 0xcb0bfa11 },
    { 0xacebad03, short_gen431, long_gen431, 0xcb0bfa11 },
    { 0xacebad03, short_gen432, long_gen432, 0xcb0bfa11 },
    { 0xacebad03, short_gen433, long_gen433, 0xcb0bfa11 },
    { 0xacebad03, short_gen434, long_gen434, 0xcb0bfa11 },
    { 0xacebad03, short_gen435, long_gen435, 0xcb0bfa11 },
    { 0xacebad03, short_gen436, long_gen436, 0xcb0bfa11 },
    { 0xacebad03, short_gen437, long_gen437, 0xcb0bfa11 },
    { 0xacebad03, short_gen438, long_gen438, 0xcb0bfa11 },
    { 0xacebad03, short_gen439, long_gen439, 0xcb0bfa11 },
    { 0xacebad03, short_gen440, long_gen440, 0xcb0bfa11 },
    { 0xacebad03, short_gen441, long_gen441, 0xcb0bfa11 },
    { 0xacebad03, short_gen442, long_gen442, 0xcb0bfa11 },
    { 0xacebad03, short_gen443, long_gen443, 0xcb0bfa11 },
    { 0xacebad03, short_gen444, long_gen444, 0xcb0bfa11 },
    { 0xacebad03, short_gen445, long_gen445, 0xcb0bfa11 },
    { 0xacebad03, short_gen446, long_gen446, 0xcb0bfa11 },
    { 0xacebad03, short_gen447, long_gen447, 0xcb0bfa11 },
    { 0xacebad03, short_gen448, long_gen448, 0xcb0bfa11 },
    { 0xacebad03, short_gen449, long_gen449, 0xcb0bfa11 },
    { 0xacebad03, short_gen450, long_gen450, 0xcb0bfa11 },
    { 0xacebad03, short_gen451, long_gen451, 0xcb0bfa11 },
    { 0xacebad03, short_gen452, long_gen452, 0xcb0bfa11 },
    { 0xacebad03, short_gen453, long_gen453, 0xcb0bfa11 },
    { 0xacebad03, short_gen454, long_gen454, 0xcb0bfa11 },
    { 0xacebad03, short_gen455, long_gen455, 0xcb0bfa11 },
    { 0xacebad03, short_gen456, long_gen456, 0xcb0bfa11 },
    { 0xacebad03, short_gen457, long_gen457, 0xcb0bfa11 },
    { 0xacebad03, short_gen458, long_gen458, 0xcb0bfa11 },
    { 0xacebad03, short_gen459, long_gen459, 0xcb0bfa11 },
    { 0xacebad03, short_gen460, long_gen460, 0xcb0bfa11 },
    { 0xacebad03, short_gen461, long_gen461, 0xcb0bfa11 },
    { 0xacebad03, short_gen462, long_gen462, 0xcb0bfa11 },
    { 0xacebad03, short_gen463, long_gen463, 0xcb0bfa11 },
    { 0xacebad03, short_gen464, long_gen464, 0xcb0bfa11 },
    { 0xacebad03, short_gen465, long_gen465, 0xcb0bfa11 },
    { 0xacebad03, short_gen466, long_gen466, 0xcb0bfa11 },
    { 0xacebad03, short_gen467, long_gen467, 0xcb0bfa11 },
    { 0xacebad03, short_gen468, long_gen468, 0xcb0bfa11 },
    { 0xacebad03, short_gen469, long_gen469, 0xcb0bfa11 },
    { 0xacebad03, short_gen470, long_gen470, 0xcb0bfa11 },
    { 0xacebad03, short_gen471, long_gen471, 0xcb0bfa11 },
    { 0xacebad03, short_gen472, long_gen472, 0xcb0bfa11 },
    { 0xacebad03, short_gen473, long_gen473, 0xcb0bfa11 },
    { 0xacebad03, short_gen474, long_gen474, 0xcb0bfa11 },
    { 0xacebad03, short_gen475, long_gen475, 0xcb0bfa11 },
    { 0xacebad03, short_gen476, long_gen476, 0xcb0bfa11 },
    { 0xacebad03, short_gen477, long_gen477, 0xcb0bfa11 },
    { 0xacebad03, short_gen478, long_gen478, 0xcb0bfa11 },
    { 0xacebad03, short_gen479, long_gen479, 0xcb0bfa11 },
    { 0xacebad03, short_gen480, long_gen480, 0xcb0bfa11 },
    { 0xacebad03, short_gen481, long_gen481, 0xcb0bfa11 },
    { 0xacebad03, short_gen482, long_gen482, 0xcb0bfa11 },
    { 0xacebad03, short_gen483, long_gen483, 0xcb0bfa11 },
    { 0xacebad03, short_gen484, long_gen484, 0xcb0bfa11 },
    { 0xacebad03, short_gen485, long_gen485, 0xcb0bfa11 },
    { 0xacebad03, short_gen486, long_gen486, 0xcb0bfa11 },
    { 0xacebad03, short_gen487, long_gen487, 0xcb0bfa11 },
    { 0xacebad03, short_gen488, long_gen488, 0xcb0bfa11 },
    { 0xacebad03, short_gen489, long_gen489, 0xcb0bfa11 },
    { 0xacebad03, short_gen490, long_gen490, 0xcb0bfa11 },
    { 0xacebad03, short_gen491, long_gen491, 0xcb0bfa11 },
    { 0xacebad03, short_gen492, long_gen492, 0xcb0bfa11 },
    { 0xacebad03, short_gen493, long_gen493, 0xcb0bfa11 },
    { 0xacebad03, short_gen494, long_gen494, 0xcb0bfa11 },
    { 0xacebad03, short_gen495, long_gen495, 0xcb0bfa11 },
    { 0xacebad03, short_gen496, long_gen496, 0xcb0bfa11 },
    { 0xacebad03, short_gen497, long_gen497, 0xcb0bfa11 },
    { 0xacebad03, short_gen498, long_gen498, 0xcb0bfa11 },
    { 0xacebad03, short_gen499, long_gen499, 0xcb0bfa11 },
    { 0xacebad03, short_gen500, long_gen500, 0xcb0bfa11 },
    { 0xacebad03, short_gen501, long_gen501, 0xcb0bfa11 },
    { 0xacebad03, short_gen502, long_gen502, 0xcb0bfa11 },
    { 0xacebad03, short_gen503, long_gen503, 0xcb0bfa11 },
    { 0xacebad03, short_gen504, long_gen504, 0xcb0bfa11 },
    { 0xacebad03, short_gen505, long_gen505, 0xcb0bfa11 },
    { 0xacebad03, short_gen506, long_gen506, 0xcb0bfa11 },
    { 0xacebad03, short_gen507, long_gen507, 0xcb0bfa11 },
    { 0xacebad03, short_gen508, long_gen508, 0xcb0bfa11 },
    { 0xacebad03, short_gen509, long_gen509, 0xcb0bfa11 },
    { 0xacebad03, short_gen510, long_gen510, 0xcb0bfa11 },
    { 0xacebad03, short_gen511, long_gen511, 0xcb0bfa11 },
    { 0xacebad03, short_gen512, long_gen512, 0xcb0bfa11 },
    { 0xacebad03, short_gen513, long_gen513, 0xcb0bfa11 },
    { 0xacebad03, short_gen514, long_gen514, 0xcb0bfa11 },
    { 0xacebad03, short_gen515, long_gen515, 0xcb0bfa11 },
    { 0xacebad03, short_gen516, long_gen516, 0xcb0bfa11 },
    { 0xacebad03, short_gen517, long_gen517, 0xcb0bfa11 },
    { 0xacebad03, short_gen518, long_gen518, 0xcb0bfa11 },
    { 0xacebad03, short_gen519, long_gen519, 0xcb0bfa11 },
    { 0xacebad03, short_gen520, long_gen520, 0xcb0bfa11 },
    { 0xacebad03, short_gen521, long_gen521, 0xcb0bfa11 },
    { 0xacebad03, short_gen522, long_gen522, 0xcb0bfa11 },
    { 0xacebad03, short_gen523, long_gen523, 0xcb0bfa11 },
    { 0xacebad03, short_gen524, long_gen524, 0xcb0bfa11 },
    { 0xacebad03, short_gen525, long_gen525, 0xcb0bfa11 },
    { 0xacebad03, short_gen526, long_gen526, 0xcb0bfa11 },
    { 0xacebad03, short_gen527, long_gen527, 0xcb0bfa11 },
    { 0xacebad03, short_gen528, long_gen528, 0xcb0bfa11 },
    { 0xacebad03, short_gen529, long_gen529, 0xcb0bfa11 },
    { 0xacebad03, short_gen530, long_gen530, 0xcb0bfa11 },
    { 0xacebad03, short_gen531, long_gen531, 0xcb0bfa11 },
    { 0xacebad03, short_gen532, long_gen532, 0xcb0bfa11 },
    { 0xacebad03, short_gen533, long_gen533, 0xcb0bfa11 },
    { 0xacebad03, short_gen534, long_gen534, 0xcb0bfa11 },
    { 0xacebad03, short_gen535, long_gen535, 0xcb0bfa11 },
    { 0xacebad03, short_gen536, long_gen536, 0xcb0bfa11 },
    { 0xacebad03, short_gen537, long_gen537, 0xcb0bfa11 },
    { 0xacebad03, short_gen538, long_gen538, 0xcb0bfa11 },
    { 0xacebad03, short_gen539, long_gen539, 0xcb0bfa11 },
    { 0xacebad03, short_gen540, long_gen540, 0xcb0bfa11 },
    { 0xacebad03, short_gen541, long_gen541, 0xcb0bfa11 },
    { 0xacebad03, short_gen542, long_gen542, 0xcb0bfa11 },
    { 0xacebad03, short_gen543, long_gen543, 0xcb0bfa11 },
    { 0xacebad03, short_gen544, long_gen544, 0xcb0bfa11 },
    { 0xacebad03, short_gen545, long_gen545, 0xcb0bfa11 },
    { 0xacebad03, short_gen546, long_gen546, 0xcb0bfa11 },
    { 0xacebad03, short_gen547, long_gen547, 0xcb0bfa11 },
    { 0xacebad03, short_gen548, long_gen548, 0xcb0bfa11 },
    { 0xacebad03, short_gen549, long_gen549, 0xcb0bfa11 },
    { 0xacebad03, short_gen550, long_gen550, 0xcb0bfa11 },
    { 0xacebad03, short_gen551, long_gen551, 0xcb0bfa11 },
    { 0xacebad03, short_gen552, long_gen552, 0xcb0bfa11 },
    { 0xacebad03, short_gen553, long_gen553, 0xcb0bfa11 },
    { 0xacebad03, short_gen554, long_gen554, 0xcb0bfa11 },
    { 0xacebad03, short_gen555, long_gen555, 0xcb0bfa11 },
    { 0xacebad03, short_gen556, long_gen556, 0xcb0bfa11 },
    { 0xacebad03, short_gen557, long_gen557, 0xcb0bfa11 },
    { 0xacebad03, short_gen558, long_gen558, 0xcb0bfa11 },
    { 0xacebad03, short_gen559, long_gen559, 0xcb0bfa11 },
    { 0xacebad03, short_gen560, long_gen560, 0xcb0bfa11 },
    { 0xacebad03, short_gen561, long_gen561, 0xcb0bfa11 },
    { 0xacebad03, short_gen562, long_gen562, 0xcb0bfa11 },
    { 0xacebad03, short_gen563, long_gen563, 0xcb0bfa11 },
    { 0xacebad03, short_gen564, long_gen564, 0xcb0bfa11 },
    { 0xacebad03, short_gen565, long_gen565, 0xcb0bfa11 },
    { 0xacebad03, short_gen566, long_gen566, 0xcb0bfa11 },
    { 0xacebad03, short_gen567, long_gen567, 0xcb0bfa11 },
    { 0xacebad03, short_gen568, long_gen568, 0xcb0bfa11 },
    { 0xacebad03, short_gen569, long_gen569, 0xcb0bfa11 },
    { 0xacebad03, short_gen570, long_gen570, 0xcb0bfa11 },
    { 0xacebad03, short_gen571, long_gen571, 0xcb0bfa11 },
    { 0xacebad03, short_gen572, long_gen572, 0xcb0bfa11 },
    { 0xacebad03, short_gen573, long_gen573, 0xcb0bfa11 },
    { 0xacebad03, short_gen574, long_gen574, 0xcb0bfa11 },
    { 0xacebad03, short_gen575, long_gen575, 0xcb0bfa11 },
    { 0xacebad03, short_gen576, long_gen576, 0xcb0bfa11 },
    { 0xacebad03, short_gen577, long_gen577, 0xcb0bfa11 },
    { 0xacebad03, short_gen578, long_gen578, 0xcb0bfa11 },
    { 0xacebad03, short_gen579, long_gen579, 0xcb0bfa11 },
    { 0xacebad03, short_gen580, long_gen580, 0xcb0bfa11 },
    { 0xacebad03, short_gen581, long_gen581, 0xcb0bfa11 },
    { 0xacebad03, short_gen582, long_gen582, 0xcb0bfa11 },
    { 0xacebad03, short_gen583, long_gen583, 0xcb0bfa11 },
    { 0xacebad03, short_gen584, long_gen584, 0xcb0bfa11 },
    { 0xacebad03, short_gen585, long_gen585, 0xcb0bfa11 },
    { 0xacebad03, short_gen586, long_gen586, 0xcb0bfa11 },
    { 0xacebad03, short_gen587, long_gen587, 0xcb0bfa11 },
    { 0xacebad03, short_gen588, long_gen588, 0xcb0bfa11 },
    { 0xacebad03, short_gen589, long_gen589, 0xcb0bfa11 },
    { 0xacebad03, short_gen590, long_gen590, 0xcb0bfa11 },
    { 0xacebad03, short_gen591, long_gen591, 0xcb0bfa11 },
    { 0xacebad03, short_gen592, long_gen592, 0xcb0bfa11 },
    { 0xacebad03, short_gen593, long_gen593, 0xcb0bfa11 },
    { 0xacebad03, short_gen594, long_gen594, 0xcb0bfa11 },
    { 0xacebad03, short_gen595, long_gen595, 0xcb0bfa11 },
    { 0xacebad03, short_gen596, long_gen596, 0xcb0bfa11 },
    { 0xacebad03, short_gen597, long_gen597, 0xcb0bfa11 },
    { 0xacebad03, short_gen598, long_gen598, 0xcb0bfa11 },
    { 0xacebad03, short_gen599, long_gen599, 0xcb0bfa11 },
    { 0xacebad03, short_gen600, long_gen600, 0xcb0bfa11 },
    { 0xacebad03, short_gen601, long_gen601, 0xcb0bfa11 },
    { 0xacebad03, short_gen602, long_gen602, 0xcb0bfa11 },
    { 0xacebad03, short_gen603, long_gen603, 0xcb0bfa11 },
    { 0xacebad03, short_gen604, long_gen604, 0xcb0bfa11 },
    { 0xacebad03, short_gen605, long_gen605, 0xcb0bfa11 },
    { 0xacebad03, short_gen606, long_gen606, 0xcb0bfa11 },
    { 0xacebad03, short_gen607, long_gen607, 0xcb0bfa11 },
    { 0xacebad03, short_gen608, long_gen608, 0xcb0bfa11 },
    { 0xacebad03, short_gen609, long_gen609, 0xcb0bfa11 },
    { 0xacebad03, short_gen610, long_gen610, 0xcb0bfa11 },
    { 0xacebad03, short_gen611, long_gen611, 0xcb0bfa11 },
    { 0xacebad03, short_gen612, long_gen612, 0xcb0bfa11 },
    { 0xacebad03, short_gen613, long_gen613, 0xcb0bfa11 },
    { 0xacebad03, short_gen614, long_gen614, 0xcb0bfa11 },
    { 0xacebad03, short_gen615, long_gen615, 0xcb0bfa11 },
    { 0xacebad03, short_gen616, long_gen616, 0xcb0bfa11 },
    { 0xacebad03, short_gen617, long_gen617, 0xcb0bfa11 },
    { 0xacebad03, short_gen618, long_gen618, 0xcb0bfa11 },
    { 0xacebad03, short_gen619, long_gen619, 0xcb0bfa11 },
    { 0xacebad03, short_gen620, long_gen620, 0xcb0bfa11 },
    { 0xacebad03, short_gen621, long_gen621, 0xcb0bfa11 },
    { 0xacebad03, short_gen622, long_gen622, 0xcb0bfa11 },
    { 0xacebad03, short_gen623, long_gen623, 0xcb0bfa11 },
    { 0xacebad03, short_gen624, long_gen624, 0xcb0bfa11 },
    { 0xacebad03, short_gen625, long_gen625, 0xcb0bfa11 },
    { 0xacebad03, short_gen626, long_gen626, 0xcb0bfa11 },
    { 0xacebad03, short_gen627, long_gen627, 0xcb0bfa11 },
    { 0xacebad03, short_gen628, long_gen628, 0xcb0bfa11 },
    { 0xacebad03, short_gen629, long_gen629, 0xcb0bfa11 },
    { 0xacebad03, short_gen630, long_gen630, 0xcb0bfa11 },
    { 0xacebad03, short_gen631, long_gen631, 0xcb0bfa11 },
    { 0xacebad03, short_gen632, long_gen632, 0xcb0bfa11 },
    { 0xacebad03, short_gen633, long_gen633, 0xcb0bfa11 },
    { 0xacebad03, short_gen634, long_gen634, 0xcb0bfa11 },
    { 0xacebad03, short_gen635, long_gen635, 0xcb0bfa11 },
    { 0xacebad03, short_gen636, long_gen636, 0xcb0bfa11 },
    { 0xacebad03, short_gen637, long_gen637, 0xcb0bfa11 },
    { 0xacebad03, short_gen638, long_gen638, 0xcb0bfa11 },
    { 0xacebad03, short_gen639, long_gen639, 0xcb0bfa11 },
    { 0xacebad03, short_gen640, long_gen640, 0xcb0bfa11 },
    { 0xacebad03, short_gen641, long_gen641, 0xcb0bfa11 },
    { 0xacebad03, short_gen642, long_gen642, 0xcb0bfa11 },
    { 0xacebad03, short_gen643, long_gen643, 0xcb0bfa11 },
    { 0xacebad03, short_gen644, long_gen644, 0xcb0bfa11 },
    { 0xacebad03, short_gen645, long_gen645, 0xcb0bfa11 },
    { 0xacebad03, short_gen646, long_gen646, 0xcb0bfa11 },
    { 0xacebad03, short_gen647, long_gen647, 0xcb0bfa11 },
    { 0xacebad03, short_gen648, long_gen648, 0xcb0bfa11 },
    { 0xacebad03, short_gen649, long_gen649, 0xcb0bfa11 },
    { 0xacebad03, short_gen650, long_gen650, 0xcb0bfa11 },
    { 0xacebad03, short_gen651, long_gen651, 0xcb0bfa11 },
    { 0xacebad03, short_gen652, long_gen652, 0xcb0bfa11 },
    { 0xacebad03, short_gen653, long_gen653, 0xcb0bfa11 },
    { 0xacebad03, short_gen654, long_gen654, 0xcb0bfa11 },
    { 0xacebad03, short_gen655, long_gen655, 0xcb0bfa11 },
    { 0xacebad03, short_gen656, long_gen656, 0xcb0bfa11 },
    { 0xacebad03, short_gen657, long_gen657, 0xcb0bfa11 },
    { 0xacebad03, short_gen658, long_gen658, 0xcb0bfa11 },
    { 0xacebad03, short_gen659, long_gen659, 0xcb0bfa11 },
    { 0xacebad03, short_gen660, long_gen660, 0xcb0bfa11 },
    { 0xacebad03, short_gen661, long_gen661, 0xcb0bfa11 },
    { 0xacebad03, short_gen662, long_gen662, 0xcb0bfa11 },
    { 0xacebad03, short_gen663, long_gen663, 0xcb0bfa11 },
    { 0xacebad03, short_gen664, long_gen664, 0xcb0bfa11 },
    { 0xacebad03, short_gen665, long_gen665, 0xcb0bfa11 },
    { 0xacebad03, short_gen666, long_gen666, 0xcb0bfa11 },
    { 0xacebad03, short_gen667, long_gen667, 0xcb0bfa11 },
    { 0xacebad03, short_gen668, long_gen668, 0xcb0bfa11 },
    { 0xacebad03, short_gen669, long_gen669, 0xcb0bfa11 },
    { 0xacebad03, short_gen670, long_gen670, 0xcb0bfa11 },
    { 0xacebad03, short_gen671, long_gen671, 0xcb0bfa11 },
    { 0xacebad03, short_gen672, long_gen672, 0xcb0bfa11 },
    { 0xacebad03, short_gen673, long_gen673, 0xcb0bfa11 },
    { 0xacebad03, short_gen674, long_gen674, 0xcb0bfa11 },
    { 0xacebad03, short_gen675, long_gen675, 0xcb0bfa11 },
    { 0xacebad03, short_gen676, long_gen676, 0xcb0bfa11 },
    { 0xacebad03, short_gen677, long_gen677, 0xcb0bfa11 },
    { 0xacebad03, short_gen678, long_gen678, 0xcb0bfa11 },
    { 0xacebad03, short_gen679, long_gen679, 0xcb0bfa11 },
    { 0xacebad03, short_gen680, long_gen680, 0xcb0bfa11 },
    { 0xacebad03, short_gen681, long_gen681, 0xcb0bfa11 },
    { 0xacebad03, short_gen682, long_gen682, 0xcb0bfa11 },
    { 0xacebad03, short_gen683, long_gen683, 0xcb0bfa11 },
    { 0xacebad03, short_gen684, long_gen684, 0xcb0bfa11 },
    { 0xacebad03, short_gen685, long_gen685, 0xcb0bfa11 },
    { 0xacebad03, short_gen686, long_gen686, 0xcb0bfa11 },
    { 0xacebad03, short_gen687, long_gen687, 0xcb0bfa11 },
    { 0xacebad03, short_gen688, long_gen688, 0xcb0bfa11 },
    { 0xacebad03, short_gen689, long_gen689, 0xcb0bfa11 },
    { 0xacebad03, short_gen690, long_gen690, 0xcb0bfa11 },
    { 0xacebad03, short_gen691, long_gen691, 0xcb0bfa11 },
    { 0xacebad03, short_gen692, long_gen692, 0xcb0bfa11 },
    { 0xacebad03, short_gen693, long_gen693, 0xcb0bfa11 },
    { 0xacebad03, short_gen694, long_gen694, 0xcb0bfa11 },
    { 0xacebad03, short_gen695, long_gen695, 0xcb0bfa11 },
    { 0xacebad03, short_gen696, long_gen696, 0xcb0bfa11 },
    { 0xacebad03, short_gen697, long_gen697, 0xcb0bfa11 },
    { 0xacebad03, short_gen698, long_gen698, 0xcb0bfa11 },
    { 0xacebad03, short_gen699, long_gen699, 0xcb0bfa11 },
    { 0xacebad03, short_gen700, long_gen700, 0xcb0bfa11 },
    { 0xacebad03, short_gen701, long_gen701, 0xcb0bfa11 },
    { 0xacebad03, short_gen702, long_gen702, 0xcb0bfa11 },
    { 0xacebad03, short_gen703, long_gen703, 0xcb0bfa11 },
    { 0xacebad03, short_gen704, long_gen704, 0xcb0bfa11 },
    { 0xacebad03, short_gen705, long_gen705, 0xcb0bfa11 },
    { 0xacebad03, short_gen706, long_gen706, 0xcb0bfa11 },
    { 0xacebad03, short_gen707, long_gen707, 0xcb0bfa11 },
    { 0xacebad03, short_gen708, long_gen708, 0xcb0bfa11 },
    { 0xacebad03, short_gen709, long_gen709, 0xcb0bfa11 },
    { 0xacebad03, short_gen710, long_gen710, 0xcb0bfa11 },
    { 0xacebad03, short_gen711, long_gen711, 0xcb0bfa11 },
    { 0xacebad03, short_gen712, long_gen712, 0xcb0bfa11 },
    { 0xacebad03, short_gen713, long_gen713, 0xcb0bfa11 },
    { 0xacebad03, short_gen714, long_gen714, 0xcb0bfa11 },
    { 0xacebad03, short_gen715, long_gen715, 0xcb0bfa11 },
    { 0xacebad03, short_gen716, long_gen716, 0xcb0bfa11 },
    { 0xacebad03, short_gen717, long_gen717, 0xcb0bfa11 },
    { 0xacebad03, short_gen718, long_gen718, 0xcb0bfa11 },
    { 0xacebad03, short_gen719, long_gen719, 0xcb0bfa11 },
    { 0xacebad03, short_gen720, long_gen720, 0xcb0bfa11 },
    { 0xacebad03, short_gen721, long_gen721, 0xcb0bfa11 },
    { 0xacebad03, short_gen722, long_gen722, 0xcb0bfa11 },
    { 0xacebad03, short_gen723, long_gen723, 0xcb0bfa11 },
    { 0xacebad03, short_gen724, long_gen724, 0xcb0bfa11 },
    { 0xacebad03, short_gen725, long_gen725, 0xcb0bfa11 },
    { 0xacebad03, short_gen726, long_gen726, 0xcb0bfa11 },
    { 0xacebad03, short_gen727, long_gen727, 0xcb0bfa11 },
    { 0xacebad03, short_gen728, long_gen728, 0xcb0bfa11 },
    { 0xacebad03, short_gen729, long_gen729, 0xcb0bfa11 },
    { 0xacebad03, short_gen730, long_gen730, 0xcb0bfa11 },
    { 0xacebad03, short_gen731, long_gen731, 0xcb0bfa11 },
    { 0xacebad03, short_gen732, long_gen732, 0xcb0bfa11 },
    { 0xacebad03, short_gen733, long_gen733, 0xcb0bfa11 },
    { 0xacebad03, short_gen734, long_gen734, 0xcb0bfa11 },
    { 0xacebad03, short_gen735, long_gen735, 0xcb0bfa11 },
    { 0xacebad03, short_gen736, long_gen736, 0xcb0bfa11 },
    { 0xacebad03, short_gen737, long_gen737, 0xcb0bfa11 },
    { 0xacebad03, short_gen738, long_gen738, 0xcb0bfa11 },
    { 0xacebad03, short_gen739, long_gen739, 0xcb0bfa11 },
    { 0xacebad03, short_gen740, long_gen740, 0xcb0bfa11 },
    { 0xacebad03, short_gen741, long_gen741, 0xcb0bfa11 },
    { 0xacebad03, short_gen742, long_gen742, 0xcb0bfa11 },
    { 0xacebad03, short_gen743, long_gen743, 0xcb0bfa11 },
    { 0xacebad03, short_gen744, long_gen744, 0xcb0bfa11 },
    { 0xacebad03, short_gen745, long_gen745, 0xcb0bfa11 },
    { 0xacebad03, short_gen746, long_gen746, 0xcb0bfa11 },
    { 0xacebad03, short_gen747, long_gen747, 0xcb0bfa11 },
    { 0xacebad03, short_gen748, long_gen748, 0xcb0bfa11 },
    { 0xacebad03, short_gen749, long_gen749, 0xcb0bfa11 },
    { 0xacebad03, short_gen750, long_gen750, 0xcb0bfa11 },
    { 0xacebad03, short_gen751, long_gen751, 0xcb0bfa11 },
    { 0xacebad03, short_gen752, long_gen752, 0xcb0bfa11 },
    { 0xacebad03, short_gen753, long_gen753, 0xcb0bfa11 },
    { 0xacebad03, short_gen754, long_gen754, 0xcb0bfa11 },
    { 0xacebad03, short_gen755, long_gen755, 0xcb0bfa11 },
    { 0xacebad03, short_gen756, long_gen756, 0xcb0bfa11 },
    { 0xacebad03, short_gen757, long_gen757, 0xcb0bfa11 },
    { 0xacebad03, short_gen758, long_gen758, 0xcb0bfa11 },
    { 0xacebad03, short_gen759, long_gen759, 0xcb0bfa11 },
    { 0xacebad03, short_gen760, long_gen760, 0xcb0bfa11 },
    { 0xacebad03, short_gen761, long_gen761, 0xcb0bfa11 },
    { 0xacebad03, short_gen762, long_gen762, 0xcb0bfa11 },
    { 0xacebad03, short_gen763, long_gen763, 0xcb0bfa11 },
    { 0xacebad03, short_gen764, long_gen764, 0xcb0bfa11 },
    { 0xacebad03, short_gen765, long_gen765, 0xcb0bfa11 },
    { 0xacebad03, short_gen766, long_gen766, 0xcb0bfa11 },
    { 0xacebad03, short_gen767, long_gen767, 0xcb0bfa11 },
    { 0xacebad03, short_gen768, long_gen768, 0xcb0bfa11 },
    { 0xacebad03, short_gen769, long_gen769, 0xcb0bfa11 },
    { 0xacebad03, short_gen770, long_gen770, 0xcb0bfa11 },
    { 0xacebad03, short_gen771, long_gen771, 0xcb0bfa11 },
    { 0xacebad03, short_gen772, long_gen772, 0xcb0bfa11 },
    { 0xacebad03, short_gen773, long_gen773, 0xcb0bfa11 },
    { 0xacebad03, short_gen774, long_gen774, 0xcb0bfa11 },
    { 0xacebad03, short_gen775, long_gen775, 0xcb0bfa11 },
    { 0xacebad03, short_gen776, long_gen776, 0xcb0bfa11 },
    { 0xacebad03, short_gen777, long_gen777, 0xcb0bfa11 },
    { 0xacebad03, short_gen778, long_gen778, 0xcb0bfa11 },
    { 0xacebad03, short_gen779, long_gen779, 0xcb0bfa11 },
    { 0xacebad03, short_gen780, long_gen780, 0xcb0bfa11 },
    { 0xacebad03, short_gen781, long_gen781, 0xcb0bfa11 },
    { 0xacebad03, short_gen782, long_gen782, 0xcb0bfa11 },
    { 0xacebad03, short_gen783, long_gen783, 0xcb0bfa11 },
    { 0xacebad03, short_gen784, long_gen784, 0xcb0bfa11 },
    { 0xacebad03, short_gen785, long_gen785, 0xcb0bfa11 },
    { 0xacebad03, short_gen786, long_gen786, 0xcb0bfa11 },
    { 0xacebad03, short_gen787, long_gen787, 0xcb0bfa11 },
    { 0xacebad03, short_gen788, long_gen788, 0xcb0bfa11 },
    { 0xacebad03, short_gen789, long_gen789, 0xcb0bfa11 },
    { 0xacebad03, short_gen790, long_gen790, 0xcb0bfa11 },
    { 0xacebad03, short_gen791, long_gen791, 0xcb0bfa11 },
    { 0xacebad03, short_gen792, long_gen792, 0xcb0bfa11 },
    { 0xacebad03, short_gen793, long_gen793, 0xcb0bfa11 },
    { 0xacebad03, short_gen794, long_gen794, 0xcb0bfa11 },
    { 0xacebad03, short_gen795, long_gen795, 0xcb0bfa11 },
    { 0xacebad03, short_gen796, long_gen796, 0xcb0bfa11 },
    { 0xacebad03, short_gen797, long_gen797, 0xcb0bfa11 },
    { 0xacebad03, short_gen798, long_gen798, 0xcb0bfa11 },
    { 0xacebad03, short_gen799, long_gen799, 0xcb0bfa11 },
    { 0xacebad03, short_gen800, long_gen800, 0xcb0bfa11 },
    { 0xacebad03, short_gen801, long_gen801, 0xcb0bfa11 },
    { 0xacebad03, short_gen802, long_gen802, 0xcb0bfa11 },
    { 0xacebad03, short_gen803, long_gen803, 0xcb0bfa11 },
    { 0xacebad03, short_gen804, long_gen804, 0xcb0bfa11 },
    { 0xacebad03, short_gen805, long_gen805, 0xcb0bfa11 },
    { 0xacebad03, short_gen806, long_gen806, 0xcb0bfa11 },
    { 0xacebad03, short_gen807, long_gen807, 0xcb0bfa11 },
    { 0xacebad03, short_gen808, long_gen808, 0xcb0bfa11 },
    { 0xacebad03, short_gen809, long_gen809, 0xcb0bfa11 },
    { 0xacebad03, short_gen810, long_gen810, 0xcb0bfa11 },
    { 0xacebad03, short_gen811, long_gen811, 0xcb0bfa11 },
    { 0xacebad03, short_gen812, long_gen812, 0xcb0bfa11 },
    { 0xacebad03, short_gen813, long_gen813, 0xcb0bfa11 },
    { 0xacebad03, short_gen814, long_gen814, 0xcb0bfa11 },
    { 0xacebad03, short_gen815, long_gen815, 0xcb0bfa11 },
    { 0xacebad03, short_gen816, long_gen816, 0xcb0bfa11 },
    { 0xacebad03, short_gen817, long_gen817, 0xcb0bfa11 },
    { 0xacebad03, short_gen818, long_gen818, 0xcb0bfa11 },
    { 0xacebad03, short_gen819, long_gen819, 0xcb0bfa11 },
    { 0xacebad03, short_gen820, long_gen820, 0xcb0bfa11 },
    { 0xacebad03, short_gen821, long_gen821, 0xcb0bfa11 },
    { 0xacebad03, short_gen822, long_gen822, 0xcb0bfa11 },
    { 0xacebad03, short_gen823, long_gen823, 0xcb0bfa11 },
    { 0xacebad03, short_gen824, long_gen824, 0xcb0bfa11 },
    { 0xacebad03, short_gen825, long_gen825, 0xcb0bfa11 },
    { 0xacebad03, short_gen826, long_gen826, 0xcb0bfa11 },
    { 0xacebad03, short_gen827, long_gen827, 0xcb0bfa11 },
    { 0xacebad03, short_gen828, long_gen828, 0xcb0bfa11 },
    { 0xacebad03, short_gen829, long_gen829, 0xcb0bfa11 },
    { 0xacebad03, short_gen830, long_gen830, 0xcb0bfa11 },
    { 0xacebad03, short_gen831, long_gen831, 0xcb0bfa11 },
    { 0xacebad03, short_gen832, long_gen832, 0xcb0bfa11 },
    { 0xacebad03, short_gen833, long_gen833, 0xcb0bfa11 },
    { 0xacebad03, short_gen834, long_gen834, 0xcb0bfa11 },
    { 0xacebad03, short_gen835, long_gen835, 0xcb0bfa11 },
    { 0xacebad03, short_gen836, long_gen836, 0xcb0bfa11 },
    { 0xacebad03, short_gen837, long_gen837, 0xcb0bfa11 },
    { 0xacebad03, short_gen838, long_gen838, 0xcb0bfa11 },
    { 0xacebad03, short_gen839, long_gen839, 0xcb0bfa11 },
    { 0xacebad03, short_gen840, long_gen840, 0xcb0bfa11 },
    { 0xacebad03, short_gen841, long_gen841, 0xcb0bfa11 },
    { 0xacebad03, short_gen842, long_gen842, 0xcb0bfa11 },
    { 0xacebad03, short_gen843, long_gen843, 0xcb0bfa11 },
    { 0xacebad03, short_gen844, long_gen844, 0xcb0bfa11 },
    { 0xacebad03, short_gen845, long_gen845, 0xcb0bfa11 },
    { 0xacebad03, short_gen846, long_gen846, 0xcb0bfa11 },
    { 0xacebad03, short_gen847, long_gen847, 0xcb0bfa11 },
    { 0xacebad03, short_gen848, long_gen848, 0xcb0bfa11 },
    { 0xacebad03, short_gen849, long_gen849, 0xcb0bfa11 },
    { 0xacebad03, short_gen850, long_gen850, 0xcb0bfa11 },
    { 0xacebad03, short_gen851, long_gen851, 0xcb0bfa11 },
    { 0xacebad03, short_gen852, long_gen852, 0xcb0bfa11 },
    { 0xacebad03, short_gen853, long_gen853, 0xcb0bfa11 },
    { 0xacebad03, short_gen854, long_gen854, 0xcb0bfa11 },
    { 0xacebad03, short_gen855, long_gen855, 0xcb0bfa11 },
    { 0xacebad03, short_gen856, long_gen856, 0xcb0bfa11 },
    { 0xacebad03, short_gen857, long_gen857, 0xcb0bfa11 },
    { 0xacebad03, short_gen858, long_gen858, 0xcb0bfa11 },
    { 0xacebad03, short_gen859, long_gen859, 0xcb0bfa11 },
    { 0xacebad03, short_gen860, long_gen860, 0xcb0bfa11 },
    { 0xacebad03, short_gen861, long_gen861, 0xcb0bfa11 },
    { 0xacebad03, short_gen862, long_gen862, 0xcb0bfa11 },
    { 0xacebad03, short_gen863, long_gen863, 0xcb0bfa11 },
    { 0xacebad03, short_gen864, long_gen864, 0xcb0bfa11 },
    { 0xacebad03, short_gen865, long_gen865, 0xcb0bfa11 },
    { 0xacebad03, short_gen866, long_gen866, 0xcb0bfa11 },
    { 0xacebad03, short_gen867, long_gen867, 0xcb0bfa11 },
    { 0xacebad03, short_gen868, long_gen868, 0xcb0bfa11 },
    { 0xacebad03, short_gen869, long_gen869, 0xcb0bfa11 },
    { 0xacebad03, short_gen870, long_gen870, 0xcb0bfa11 },
    { 0xacebad03, short_gen871, long_gen871, 0xcb0bfa11 },
    { 0xacebad03, short_gen872, long_gen872, 0xcb0bfa11 },
    { 0xacebad03, short_gen873, long_gen873, 0xcb0bfa11 },
    { 0xacebad03, short_gen874, long_gen874, 0xcb0bfa11 },
    { 0xacebad03, short_gen875, long_gen875, 0xcb0bfa11 },
    { 0xacebad03, short_gen876, long_gen876, 0xcb0bfa11 },
    { 0xacebad03, short_gen877, long_gen877, 0xcb0bfa11 },
    { 0xacebad03, short_gen878, long_gen878, 0xcb0bfa11 },
    { 0xacebad03, short_gen879, long_gen879, 0xcb0bfa11 },
    { 0xacebad03, short_gen880, long_gen880, 0xcb0bfa11 },
    { 0xacebad03, short_gen881, long_gen881, 0xcb0bfa11 },
    { 0xacebad03, short_gen882, long_gen882, 0xcb0bfa11 },
    { 0xacebad03, short_gen883, long_gen883, 0xcb0bfa11 },
    { 0xacebad03, short_gen884, long_gen884, 0xcb0bfa11 },
    { 0xacebad03, short_gen885, long_gen885, 0xcb0bfa11 },
    { 0xacebad03, short_gen886, long_gen886, 0xcb0bfa11 },
    { 0xacebad03, short_gen887, long_gen887, 0xcb0bfa11 },
    { 0xacebad03, short_gen888, long_gen888, 0xcb0bfa11 },
    { 0xacebad03, short_gen889, long_gen889, 0xcb0bfa11 },
    { 0xacebad03, short_gen890, long_gen890, 0xcb0bfa11 },
    { 0xacebad03, short_gen891, long_gen891, 0xcb0bfa11 },
    { 0xacebad03, short_gen892, long_gen892, 0xcb0bfa11 },
    { 0xacebad03, short_gen893, long_gen893, 0xcb0bfa11 },
    { 0xacebad03, short_gen894, long_gen894, 0xcb0bfa11 },
    { 0xacebad03, short_gen895, long_gen895, 0xcb0bfa11 },
    { 0xacebad03, short_gen896, long_gen896, 0xcb0bfa11 },
    { 0xacebad03, short_gen897, long_gen897, 0xcb0bfa11 },
    { 0xacebad03, short_gen898, long_gen898, 0xcb0bfa11 },
    { 0xacebad03, short_gen899, long_gen899, 0xcb0bfa11 },
    { 0xacebad03, short_gen900, long_gen900, 0xcb0bfa11 },
    { 0xacebad03, short_gen901, long_gen901, 0xcb0bfa11 },
    { 0xacebad03, short_gen902, long_gen902, 0xcb0bfa11 },
    { 0xacebad03, short_gen903, long_gen903, 0xcb0bfa11 },
    { 0xacebad03, short_gen904, long_gen904, 0xcb0bfa11 },
    { 0xacebad03, short_gen905, long_gen905, 0xcb0bfa11 },
    { 0xacebad03, short_gen906, long_gen906, 0xcb0bfa11 },
    { 0xacebad03, short_gen907, long_gen907, 0xcb0bfa11 },
    { 0xacebad03, short_gen908, long_gen908, 0xcb0bfa11 },
    { 0xacebad03, short_gen909, long_gen909, 0xcb0bfa11 },
    { 0xacebad03, short_gen910, long_gen910, 0xcb0bfa11 },
    { 0xacebad03, short_gen911, long_gen911, 0xcb0bfa11 },
    { 0xacebad03, short_gen912, long_gen912, 0xcb0bfa11 },
    { 0xacebad03, short_gen913, long_gen913, 0xcb0bfa11 },
    { 0xacebad03, short_gen914, long_gen914, 0xcb0bfa11 },
    { 0xacebad03, short_gen915, long_gen915, 0xcb0bfa11 },
    { 0xacebad03, short_gen916, long_gen916, 0xcb0bfa11 },
    { 0xacebad03, short_gen917, long_gen917, 0xcb0bfa11 },
    { 0xacebad03, short_gen918, long_gen918, 0xcb0bfa11 },
    { 0xacebad03, short_gen919, long_gen919, 0xcb0bfa11 },
    { 0xacebad03, short_gen920, long_gen920, 0xcb0bfa11 },
    { 0xacebad03, short_gen921, long_gen921, 0xcb0bfa11 },
    { 0xacebad03, short_gen922, long_gen922, 0xcb0bfa11 },
    { 0xacebad03, short_gen923, long_gen923, 0xcb0bfa11 },
    { 0xacebad03, short_gen924, long_gen924, 0xcb0bfa11 },
    { 0xacebad03, short_gen925, long_gen925, 0xcb0bfa11 },
    { 0xacebad03, short_gen926, long_gen926, 0xcb0bfa11 },
    { 0xacebad03, short_gen927, long_gen927, 0xcb0bfa11 },
    { 0xacebad03, short_gen928, long_gen928, 0xcb0bfa11 },
    { 0xacebad03, short_gen929, long_gen929, 0xcb0bfa11 },
    { 0xacebad03, short_gen930, long_gen930, 0xcb0bfa11 },
    { 0xacebad03, short_gen931, long_gen931, 0xcb0bfa11 },
    { 0xacebad03, short_gen932, long_gen932, 0xcb0bfa11 },
    { 0xacebad03, short_gen933, long_gen933, 0xcb0bfa11 },
    { 0xacebad03, short_gen934, long_gen934, 0xcb0bfa11 },
    { 0xacebad03, short_gen935, long_gen935, 0xcb0bfa11 },
    { 0xacebad03, short_gen936, long_gen936, 0xcb0bfa11 },
    { 0xacebad03, short_gen937, long_gen937, 0xcb0bfa11 },
    { 0xacebad03, short_gen938, long_gen938, 0xcb0bfa11 },
    { 0xacebad03, short_gen939, long_gen939, 0xcb0bfa11 },
    { 0xacebad03, short_gen940, long_gen940, 0xcb0bfa11 },
    { 0xacebad03, short_gen941, long_gen941, 0xcb0bfa11 },
    { 0xacebad03, short_gen942, long_gen942, 0xcb0bfa11 },
    { 0xacebad03, short_gen943, long_gen943, 0xcb0bfa11 },
    { 0xacebad03, short_gen944, long_gen944, 0xcb0bfa11 },
    { 0xacebad03, short_gen945, long_gen945, 0xcb0bfa11 },
    { 0xacebad03, short_gen946, long_gen946, 0xcb0bfa11 },
    { 0xacebad03, short_gen947, long_gen947, 0xcb0bfa11 },
    { 0xacebad03, short_gen948, long_gen948, 0xcb0bfa11 },
    { 0xacebad03, short_gen949, long_gen949, 0xcb0bfa11 },
    { 0xacebad03, short_gen950, long_gen950, 0xcb0bfa11 },
    { 0xacebad03, short_gen951, long_gen951, 0xcb0bfa11 },
    { 0xacebad03, short_gen952, long_gen952, 0xcb0bfa11 },
    { 0xacebad03, short_gen953, long_gen953, 0xcb0bfa11 },
    { 0xacebad03, short_gen954, long_gen954, 0xcb0bfa11 },
    { 0xacebad03, short_gen955, long_gen955, 0xcb0bfa11 },
    { 0xacebad03, short_gen956, long_gen956, 0xcb0bfa11 },
    { 0xacebad03, short_gen957, long_gen957, 0xcb0bfa11 },
    { 0xacebad03, short_gen958, long_gen958, 0xcb0bfa11 },
    { 0xacebad03, short_gen959, long_gen959, 0xcb0bfa11 },
    { 0xacebad03, short_gen960, long_gen960, 0xcb0bfa11 },
    { 0xacebad03, short_gen961, long_gen961, 0xcb0bfa11 },
    { 0xacebad03, short_gen962, long_gen962, 0xcb0bfa11 },
    { 0xacebad03, short_gen963, long_gen963, 0xcb0bfa11 },
    { 0xacebad03, short_gen964, long_gen964, 0xcb0bfa11 },
    { 0xacebad03, short_gen965, long_gen965, 0xcb0bfa11 },
    { 0xacebad03, short_gen966, long_gen966, 0xcb0bfa11 },
    { 0xacebad03, short_gen967, long_gen967, 0xcb0bfa11 },
    { 0xacebad03, short_gen968, long_gen968, 0xcb0bfa11 },
    { 0xacebad03, short_gen969, long_gen969, 0xcb0bfa11 },
    { 0xacebad03, short_gen970, long_gen970, 0xcb0bfa11 },
    { 0xacebad03, short_gen971, long_gen971, 0xcb0bfa11 },
    { 0xacebad03, short_gen972, long_gen972, 0xcb0bfa11 },
    { 0xacebad03, short_gen973, long_gen973, 0xcb0bfa11 },
    { 0xacebad03, short_gen974, long_gen974, 0xcb0bfa11 },
    { 0xacebad03, short_gen975, long_gen975, 0xcb0bfa11 },
    { 0xacebad03, short_gen976, long_gen976, 0xcb0bfa11 },
    { 0xacebad03, short_gen977, long_gen977, 0xcb0bfa11 },
    { 0xacebad03, short_gen978, long_gen978, 0xcb0bfa11 },
    { 0xacebad03, short_gen979, long_gen979, 0xcb0bfa11 },
    { 0xacebad03, short_gen980, long_gen980, 0xcb0bfa11 },
    { 0xacebad03, short_gen981, long_gen981, 0xcb0bfa11 },
    { 0xacebad03, short_gen982, long_gen982, 0xcb0bfa11 },
    { 0xacebad03, short_gen983, long_gen983, 0xcb0bfa11 },
    { 0xacebad03, short_gen984, long_gen984, 0xcb0bfa11 },
    { 0xacebad03, short_gen985, long_gen985, 0xcb0bfa11 },
    { 0xacebad03, short_gen986, long_gen986, 0xcb0bfa11 },
    { 0xacebad03, short_gen987, long_gen987, 0xcb0bfa11 },
    { 0xacebad03, short_gen988, long_gen988, 0xcb0bfa11 },
    { 0xacebad03, short_gen989, long_gen989, 0xcb0bfa11 },
    { 0xacebad03, short_gen990, long_gen990, 0xcb0bfa11 },
    { 0xacebad03, short_gen991, long_gen991, 0xcb0bfa11 },
    { 0xacebad03, short_gen992, long_gen992, 0xcb0bfa11 },
    { 0xacebad03, short_gen993, long_gen993, 0xcb0bfa11 },
    { 0xacebad03, short_gen994, long_gen994, 0xcb0bfa11 },
    { 0xacebad03, short_gen995, long_gen995, 0xcb0bfa11 },
    { 0xacebad03, short_gen996, long_gen996, 0xcb0bfa11 },
    { 0xacebad03, short_gen997, long_gen997, 0xcb0bfa11 },
    { 0xacebad03, short_gen998, long_gen998, 0xcb0bfa11 },
    { 0xacebad03, short_gen999, long_gen999, 0xcb0bfa11 },
    { 0xacebad03, short_gen1000, long_gen1000, 0xcb0bfa11 },
    { 0xacebad03, short_gen1001, long_gen1001, 0xcb0bfa11 },
    { 0xacebad03, short_gen1002, long_gen1002, 0xcb0bfa11 },
    { 0xacebad03, short_gen1003, long_gen1003, 0xcb0bfa11 },
    { 0xacebad03, short_gen1004, long_gen1004, 0xcb0bfa11 },
    { 0xacebad03, short_gen1005, long_gen1005, 0xcb0bfa11 },
    { 0xacebad03, short_gen1006, long_gen1006, 0xcb0bfa11 },
    { 0xacebad03, short_gen1007, long_gen1007, 0xcb0bfa11 },
    { 0xacebad03, short_gen1008, long_gen1008, 0xcb0bfa11 },
    { 0xacebad03, short_gen1009, long_gen1009, 0xcb0bfa11 },
    { 0xacebad03, short_gen1010, long_gen1010, 0xcb0bfa11 },
    { 0xacebad03, short_gen1011, long_gen1011, 0xcb0bfa11 },
    { 0xacebad03, short_gen1012, long_gen1012, 0xcb0bfa11 },
    { 0xacebad03, short_gen1013, long_gen1013, 0xcb0bfa11 },
    { 0xacebad03, short_gen1014, long_gen1014, 0xcb0bfa11 },
    { 0xacebad03, short_gen1015, long_gen1015, 0xcb0bfa11 },
    { 0xacebad03, short_gen1016, long_gen1016, 0xcb0bfa11 },
    { 0xacebad03, short_gen1017, long_gen1017, 0xcb0bfa11 },
    { 0xacebad03, short_gen1018, long_gen1018, 0xcb0bfa11 },
    { 0xacebad03, short_gen1019, long_gen1019, 0xcb0bfa11 },
    { 0xacebad03, short_gen1020, long_gen1020, 0xcb0bfa11 },
    { 0xacebad03, short_gen1021, long_gen1021, 0xcb0bfa11 },
    { 0xacebad03, short_gen1022, long_gen1022, 0xcb0bfa11 },
    { 0xacebad03, short_gen1023, long_gen1023, 0xcb0bfa11 },
    { 0xacebad03, short_gen1024, long_gen1024, 0xcb0bfa11 },
    { 0xacebad03, short_gen1025, long_gen1025, 0xcb0bfa11 },
    { 0xacebad03, short_gen1026, long_gen1026, 0xcb0bfa11 },
    { 0xacebad03, short_gen1027, long_gen1027, 0xcb0bfa11 },
    { 0xacebad03, short_gen1028, long_gen1028, 0xcb0bfa11 },
    { 0xacebad03, short_gen1029, long_gen1029, 0xcb0bfa11 },
    { 0xacebad03, short_gen1030, long_gen1030, 0xcb0bfa11 },
    { 0xacebad03, short_gen1031, long_gen1031, 0xcb0bfa11 },
    { 0xacebad03, short_gen1032, long_gen1032, 0xcb0bfa11 },
    { 0xacebad03, short_gen1033, long_gen1033, 0xcb0bfa11 },
    { 0xacebad03, short_gen1034, long_gen1034, 0xcb0bfa11 },
    { 0xacebad03, short_gen1035, long_gen1035, 0xcb0bfa11 },
    { 0xacebad03, short_gen1036, long_gen1036, 0xcb0bfa11 },
    { 0xacebad03, short_gen1037, long_gen1037, 0xcb0bfa11 },
    { 0xacebad03, short_gen1038, long_gen1038, 0xcb0bfa11 },
    { 0xacebad03, short_gen1039, long_gen1039, 0xcb0bfa11 },
    { 0xacebad03, short_gen1040, long_gen1040, 0xcb0bfa11 },
    { 0xacebad03, short_gen1041, long_gen1041, 0xcb0bfa11 },
    { 0xacebad03, short_gen1042, long_gen1042, 0xcb0bfa11 },
    { 0xacebad03, short_gen1043, long_gen1043, 0xcb0bfa11 },
    { 0xacebad03, short_gen1044, long_gen1044, 0xcb0bfa11 },
    { 0xacebad03, short_gen1045, long_gen1045, 0xcb0bfa11 },
    { 0xacebad03, short_gen1046, long_gen1046, 0xcb0bfa11 },
    { 0xacebad03, short_gen1047, long_gen1047, 0xcb0bfa11 },
    { 0xacebad03, short_gen1048, long_gen1048, 0xcb0bfa11 },
    { 0xacebad03, short_gen1049, long_gen1049, 0xcb0bfa11 },
    { 0xacebad03, short_gen1050, long_gen1050, 0xcb0bfa11 },
    { 0xacebad03, short_gen1051, long_gen1051, 0xcb0bfa11 },
    { 0xacebad03, short_gen1052, long_gen1052, 0xcb0bfa11 },
    { 0xacebad03, short_gen1053, long_gen1053, 0xcb0bfa11 },
    { 0xacebad03, short_gen1054, long_gen1054, 0xcb0bfa11 },
    { 0xacebad03, short_gen1055, long_gen1055, 0xcb0bfa11 },
    { 0xacebad03, short_gen1056, long_gen1056, 0xcb0bfa11 },
    { 0xacebad03, short_gen1057, long_gen1057, 0xcb0bfa11 },
    { 0xacebad03, short_gen1058, long_gen1058, 0xcb0bfa11 },
    { 0xacebad03, short_gen1059, long_gen1059, 0xcb0bfa11 },
    { 0xacebad03, short_gen1060, long_gen1060, 0xcb0bfa11 },
    { 0xacebad03, short_gen1061, long_gen1061, 0xcb0bfa11 },
    { 0xacebad03, short_gen1062, long_gen1062, 0xcb0bfa11 },
    { 0xacebad03, short_gen1063, long_gen1063, 0xcb0bfa11 },
    { 0xacebad03, short_gen1064, long_gen1064, 0xcb0bfa11 },
    { 0xacebad03, short_gen1065, long_gen1065, 0xcb0bfa11 },
    { 0xacebad03, short_gen1066, long_gen1066, 0xcb0bfa11 },
    { 0xacebad03, short_gen1067, long_gen1067, 0xcb0bfa11 },
    { 0xacebad03, short_gen1068, long_gen1068, 0xcb0bfa11 },
    { 0xacebad03, short_gen1069, long_gen1069, 0xcb0bfa11 },
    { 0xacebad03, short_gen1070, long_gen1070, 0xcb0bfa11 },
    { 0xacebad03, short_gen1071, long_gen1071, 0xcb0bfa11 },
    { 0xacebad03, short_gen1072, long_gen1072, 0xcb0bfa11 },
    { 0xacebad03, short_gen1073, long_gen1073, 0xcb0bfa11 },
    { 0xacebad03, short_gen1074, long_gen1074, 0xcb0bfa11 },
    { 0xacebad03, short_gen1075, long_gen1075, 0xcb0bfa11 },
    { 0xacebad03, short_gen1076, long_gen1076, 0xcb0bfa11 },
    { 0xacebad03, short_gen1077, long_gen1077, 0xcb0bfa11 },
    { 0xacebad03, short_gen1078, long_gen1078, 0xcb0bfa11 },
    { 0xacebad03, short_gen1079, long_gen1079, 0xcb0bfa11 },
    { 0xacebad03, short_gen1080, long_gen1080, 0xcb0bfa11 },
    { 0xacebad03, short_gen1081, long_gen1081, 0xcb0bfa11 },
    { 0xacebad03, short_gen1082, long_gen1082, 0xcb0bfa11 },
    { 0xacebad03, short_gen1083, long_gen1083, 0xcb0bfa11 },
    { 0xacebad03, short_gen1084, long_gen1084, 0xcb0bfa11 },
    { 0xacebad03, short_gen1085, long_gen1085, 0xcb0bfa11 },
    { 0xacebad03, short_gen1086, long_gen1086, 0xcb0bfa11 },
    { 0xacebad03, short_gen1087, long_gen1087, 0xcb0bfa11 },
    { 0xacebad03, short_gen1088, long_gen1088, 0xcb0bfa11 },
    { 0xacebad03, short_gen1089, long_gen1089, 0xcb0bfa11 },
    { 0xacebad03, short_gen1090, long_gen1090, 0xcb0bfa11 },
    { 0xacebad03, short_gen1091, long_gen1091, 0xcb0bfa11 },
    { 0xacebad03, short_gen1092, long_gen1092, 0xcb0bfa11 },
    { 0xacebad03, short_gen1093, long_gen1093, 0xcb0bfa11 },
    { 0xacebad03, short_gen1094, long_gen1094, 0xcb0bfa11 },
    { 0xacebad03, short_gen1095, long_gen1095, 0xcb0bfa11 },
    { 0xacebad03, short_gen1096, long_gen1096, 0xcb0bfa11 },
    { 0xacebad03, short_gen1097, long_gen1097, 0xcb0bfa11 },
    { 0xacebad03, short_gen1098, long_gen1098, 0xcb0bfa11 },
    { 0xacebad03, short_gen1099, long_gen1099, 0xcb0bfa11 },
    { 0xacebad03, short_gen1100, long_gen1100, 0xcb0bfa11 },
    { 0xacebad03, short_gen1101, long_gen1101, 0xcb0bfa11 }
};
static const char short_spc0[] = "**arg %s";
static const char long_spc0[]  = "Invalid argument %s";
static const char short_spc1[] = "**argarrayneg %s %d %d";
static const char long_spc1[]  = "Negative value in array %s[%d] (value is %d)";
static const char short_spc2[] = "**argerrcode %d";
static const char long_spc2[]  = "Invalid error code %d";
static const char short_spc3[] = "**argneg %s %d";
static const char long_spc3[]  = "Invalid value for %s, must be non-negative but is %d";
static const char short_spc4[] = "**argnonpos %s %d";
static const char long_spc4[]  = "Invalid value for %s; must be positive but is %d";
static const char short_spc5[] = "**argrange %s %d %d";
static const char long_spc5[]  = "Argument %s has value %d but must be within [0,%d]";
static const char short_spc6[] = "**argtoosmall %s %d %d";
static const char long_spc6[]  = "Invalid argument for %s: value is %d but must be at least %d";
static const char short_spc7[] = "**assert %d";
static const char long_spc7[]  = "Invalid assert argument (%d)";
static const char short_spc8[] = "**atexit_pmi_finalize %d";
static const char long_spc8[]  = " Registration of PMI finalize function in exit handler failed with %d";
static const char short_spc9[] = "**badcase %d";
static const char long_spc9[]  = "INTERNAL ERROR: unexpected value in case statement (value=%d)";
static const char short_spc10[] = "**bind %s %d";
static const char long_spc10[]  = " Unable to bind socket to address, %s (errno %d)";
static const char short_spc11[] = "**bsendbufsmall %d %d";
static const char long_spc11[]  = "Buffer size of %d is smaller than MPI_BSEND_OVERHEAD (%d)";
static const char short_spc12[] = "**buf_inplace %s";
static const char long_spc12[]  = "buffer '%s' cannot be MPI_IN_PLACE";
static const char short_spc13[] = "**bufbsend %d %d";
static const char long_spc13[]  = "Insufficient space in Bsend buffer; requested %d; total buffer size is %d";
static const char short_spc14[] = "**cartcoordinvalid %d %d %d";
static const char long_spc14[]  = "Cartesian coordinate for the %d coordinate is %d but must be between 0 and %d";
static const char short_spc15[] = "**cartdim %d %d";
static const char long_spc15[]  = "Size of the communicator (%d) is smaller than the size of the Cartesian topology (%d)";
static const char short_spc16[] = "**ch3|badmsgtype %d";
static const char long_spc16[]  = "request contained an invalid message type (%d)";
static const char short_spc17[] = "**ch3|badreqtype %d";
static const char long_spc17[]  = "request contained an invalid request type (%d)";
static const char short_spc18[] = "**ch3|conn_parent %s";
static const char long_spc18[]  = "spawned process group was unable to connect back to the parent on port <%s>";
static const char short_spc19[] = "**ch3|conntimeout %d";
static const char long_spc19[]  = "Connection timed out in %d seconds";
static const char short_spc20[] = "**ch3|postrecv %s";
static const char long_spc20[]  = "failure occurred while posting a receive for message data (%s)";
static const char short_spc21[] = "**ch3|sock|badhost %s %d %s";
static const char long_spc21[]  = "[ch3:sock] invalid host description, %s:%d (%s)";
static const char short_spc22[] = "**ch3|sock|badpacket %d";
static const char long_spc22[]  = "[ch3:sock] received packet of unknown type (%d)";
static const char short_spc23[] = "**ch3|sock|connrefused %s %d %s";
static const char long_spc23[]  = "[ch3:sock] failed to connect to process %s:%d (%s)";
static const char short_spc24[] = "**ch3|sock|failure %d";
static const char long_spc24[]  = "[ch3:sock] unknown failure, sock_errno=%d";
static const char short_spc25[] = "**ch3|sock|postconnect %d %d %s";
static const char long_spc25[]  = "[ch3:sock] rank %d unable to connect to rank %d using business card <%s>";
static const char short_spc26[] = "**ch3|sock|writefailed %d";
static const char long_spc26[]  = "Write to socket failed with code %d";
static const char short_spc27[] = "**ch3|unhandled_connection_state %p %d";
static const char long_spc27[]  = "encountered an unexpected connection state (vc=%p, state=%d)";
static const char short_spc28[] = "**ch4|badreqtype %d";
static const char long_spc28[]  = "request contained an invalid request type (%d)";
static const char short_spc29[] = "**ch4|badstartreq %d";
static const char long_spc29[]  = "start an invalid request kind (%d)";
static const char short_spc30[] = "**ch4|invalid_mt_model %s";
static const char long_spc30[]  = "Invalid multi-threading model (%s)";
static const char short_spc31[] = "**ch4|invalid_shm_posix_eager %s";
static const char long_spc31[]  = "Invalid shm posix eager module specified (%s)";
static const char short_spc32[] = "**ch4|partmismatchsize %d %d";
static const char long_spc32[]  = " Partitioned send and receive buﬀers are not identical in size; %d bytes received but receive buffer size is %d";
static const char short_spc33[] = "**close %s";
static const char long_spc33[]  = "close of socket failed - %s";
static const char short_spc34[] = "**closesocket %s %d";
static const char long_spc34[]  = "closesocket failed, %s (errno %d)";
static const char short_spc35[] = "**cmadata %d %d";
static const char long_spc35[]  = "process_vm_readv bytes mismatch, got %d, expect %d";
static const char short_spc36[] = "**cmaread %d";
static const char long_spc36[]  = "process_vm_readv failed (errno %d)";
static const char short_spc37[] = "**cmawrite %d";
static const char long_spc37[]  = "process_vm_writev failed (errno %d)";
static const char short_spc38[] = "**collective_size_mismatch %d %d";
static const char long_spc38[]  = "message sizes do not match across processes in the collective routine: Received %d but expected %d";
static const char short_spc39[] = "**comm_fail %d";
static const char long_spc39[]  = "Communication error with rank %d";
static const char short_spc40[] = "**comm_fail %d %s";
static const char long_spc40[]  = "Communication error with rank %d: %s";
static const char short_spc41[] = "**comm_fail_conn %s %s";
static const char long_spc41[]  = "Communication error during connect sequence (state=%s): %s";
static const char short_spc42[] = "**commhasunmatched %x %d";
static const char long_spc42[]  = "Communicator (handle=%x) being freed has %d unmatched message(s)";
static const char short_spc43[] = "**commperm %s";
static const char long_spc43[]  = "Cannot free permanent communicator %s";
static const char short_spc44[] = "**countneg %d";
static const char long_spc44[]  = "Negative count, value is %d";
static const char short_spc45[] = "**darrayblock %d";
static const char long_spc45[]  = "Value of m in block(m) distribution is %d must must be positive";
static const char short_spc46[] = "**darrayblock2 %d %d";
static const char long_spc46[]  = "m * nprocs is %d but must equal the array size %d and is not valid for block(m) distribution";
static const char short_spc47[] = "**darraycyclic %d";
static const char long_spc47[]  = "Value of m is %d but must be positive for a cyclic(m) distribution";
static const char short_spc48[] = "**datarepused %s";
static const char long_spc48[]  = "The requested datarep name %s has already been specified to MPI_REGISTER_DATAREP";
static const char short_spc49[] = "**dev|pg_not_found %p";
static const char long_spc49[]  = "the specified process group object could not be located (pg=%p)";
static const char short_spc50[] = "**dev|vcrt_create %s";
static const char long_spc50[]  = "failed to create VCRT for %s";
static const char short_spc51[] = "**dimsmany %d %d";
static const char long_spc51[]  = "Number of dimensions %d is too large (maximum is %d)";
static const char short_spc52[] = "**dispunit %d";
static const char long_spc52[]  = "disp_unit argument is not positive integer (value is %d)";
static const char short_spc53[] = "**dtypenull %s";
static const char long_spc53[]  = "Datatype for argument %s is a null datatype";
static const char short_spc54[] = "**dupprocesses %d";
static const char long_spc54[]  = "Local and remote groups in MPI_Intercomm_create must not contain the same processes; both contain process %d";
static const char short_spc55[] = "**edgeoutrange %d %d %d";
static const char long_spc55[]  = "Edge index edges[%d] is %d but must be nonnegative and less than %d";
static const char short_spc56[] = "**errclassref %x %d";
static const char long_spc56[]  = "Error class %x still in use (ref_count = %d)";
static const char short_spc57[] = "**errcoderef %x %d";
static const char long_spc57[]  = "Error code %x still in use (ref_count = %d)";
static const char short_spc58[] = "**exceeded_connect_tries %d";
static const char long_spc58[]  = "Unable to establish connection to rank %d";
static const char short_spc59[] = "**f90typecomplexnone %d %d";
static const char long_spc59[]  = " No complex type with both %d digits of precision and an exponent range of %d is available";
static const char short_spc60[] = "**f90typeintnone %d";
static const char long_spc60[]  = " No integer type with %d digits of range is available";
static const char short_spc61[] = "**f90typerealnone %d %d";
static const char long_spc61[]  = " No real type with both %d digits of precision and an exponent range of %d is available";
static const char short_spc62[] = "**fail %s %d";
static const char long_spc62[]  = "%s (errno %d)";
static const char short_spc63[] = "**fileaccess %s";
static const char long_spc63[]  = "Access denied to file %s";
static const char short_spc64[] = "**filename %s";
static const char long_spc64[]  = "Invalid file name %s";
static const char short_spc65[] = "**filenamedir %s";
static const char long_spc65[]  = "Invalid or missing directory %s";
static const char short_spc66[] = "**filenamelong %s %d";
static const char long_spc66[]  = "Pathname %s too long (%d characters)";
static const char short_spc67[] = "**filenoexist %s";
static const char long_spc67[]  = "File %s does not exist";
static const char short_spc68[] = "**flag %d";
static const char long_spc68[]  = "invalid flag parameter (flag = %d)";
static const char short_spc69[] = "**gethostbyname %s %d";
static const char long_spc69[]  = "gethostbyname failed, %s (errno %d)";
static const char short_spc70[] = "**getsockname %s";
static const char long_spc70[]  = "getsockname failed - %s";
static const char short_spc71[] = "**groupnotincomm %d";
static const char long_spc71[]  = "Rank %d of the specified group is not a member of this communicator";
static const char short_spc72[] = "**hcoll_wrong_arg %p %d";
static const char long_spc72[]  = "Error in hcolrte api: wrong null argument (ec_h.handle = %p, ec_h.rank = %d)";
static const char short_spc73[] = "**iface_notfound %s";
static const char long_spc73[]  = "The network interface, \"%s\", specified in MPIR_CVAR_CH3_NETWORK_IFACE was not found.";
static const char short_spc74[] = "**indexneg %d %d";
static const char long_spc74[]  = "Index value for index[%d] is %d but must be nonnegative";
static const char short_spc75[] = "**indexnonmonotone %d %d %d";
static const char long_spc75[]  = "Index values in graph topology must be monotone nondecreasing but index[%d] is %d but the next index value is %d";
static const char short_spc76[] = "**infonkey %d %d";
static const char long_spc76[]  = "Requested key %d but this MPI_Info only has %d keys";
static const char short_spc77[] = "**infonokey %s";
static const char long_spc77[]  = "MPI_Info key %s is not defined ";
static const char short_spc78[] = "**infonoteq %s";
static const char long_spc78[]  = "MPI_Info value with key %s is not consistent for all processes";
static const char short_spc79[] = "**intern %s";
static const char long_spc79[]  = "Internal MPI error!  %s";
static const char short_spc80[] = "**invalid_handle %d";
static const char long_spc80[]  = "invalid handle (%d)";
static const char short_spc81[] = "**invalid_netmod %s";
static const char long_spc81[]  = "Invalid netmod specified (%s)";
static const char short_spc82[] = "**invalid_refcount %d";
static const char long_spc82[]  = "invalid reference count (%d)";
static const char short_spc83[] = "**invalidmembind %d";
static const char long_spc83[]  = " cannot bind memory to object (%d). A memory object id was expected but a non-memory object id was passed instead";
static const char short_spc84[] = "**invalidpkt %d";
static const char long_spc84[]  = " Invalid packet type (%d)";
static const char short_spc85[] = "**io %s";
static const char long_spc85[]  = "Other I/O error %s";
static const char short_spc86[] = "**join_portname %s %s";
static const char long_spc86[]  = "local %s, remote %s";
static const char short_spc87[] = "**join_recv %d";
static const char long_spc87[]  = "recv from the socket failed (errno %d)";
static const char short_spc88[] = "**join_send %d";
static const char long_spc88[]  = "send on the socket failed (errno %d)";
static const char short_spc89[] = "**keyvalobj %s";
static const char long_spc89[]  = "Keyval was not defined for %s objects";
static const char short_spc90[] = "**listen %s %d";
static const char long_spc90[]  = "listen failed, %s (errno %d)";
static const char short_spc91[] = "**locktype %d";
static const char long_spc91[]  = "Invalid locktype argument (%d)";
static const char short_spc92[] = "**memcpyalias %p %p %L";
static const char long_spc92[]  = "memcpy arguments alias each other, dst=%p src=%p len=%L";
static const char short_spc93[] = "**mpi_abort %C %d";
static const char long_spc93[]  = "MPI_Abort(%C, errorcode=%d) failed";
static const char short_spc94[] = "**mpi_accumulate %p %d %D %d %L %d %D %O %W";
static const char long_spc94[]  = "MPI_Accumulate(origin_addr=%p, origin_count=%d, %D, target_rank=%d, target_disp=%L, target_count=%d, %D, %O, %W) failed";
static const char short_spc95[] = "**mpi_accumulate_c %p %c %D %d %L %c %D %O %W";
static const char long_spc95[]  = "MPI_Accumulate_c(origin_addr=%p, origin_count=%c, %D, target_rank=%d, target_disp=%L, target_count=%c, %D, %O, %W) failed";
static const char short_spc96[] = "**mpi_add_error_class %p";
static const char long_spc96[]  = "MPI_Add_error_class(errorclass=%p) failed";
static const char short_spc97[] = "**mpi_add_error_code %d %p";
static const char long_spc97[]  = "MPI_Add_error_code(errorclass=%d, errorcode=%p) failed";
static const char short_spc98[] = "**mpi_add_error_string %d %s";
static const char long_spc98[]  = "MPI_Add_error_string(errorcode=%d, string=%s) failed";
static const char short_spc99[] = "**mpi_allgather %p %d %D %p %d %D %C";
static const char long_spc99[]  = "MPI_Allgather(sendbuf=%p, sendcount=%d, %D, recvbuf=%p, recvcount=%d, %D, %C) failed";
static const char short_spc100[] = "**mpi_allgather_c %p %c %D %p %c %D %C";
static const char long_spc100[]  = "MPI_Allgather_c(sendbuf=%p, sendcount=%c, %D, recvbuf=%p, recvcount=%c, %D, %C) failed";
static const char short_spc101[] = "**mpi_allgather_init %p %d %D %p %d %D %C %I %p";
static const char long_spc101[]  = "MPI_Allgather_init(sendbuf=%p, sendcount=%d, %D, recvbuf=%p, recvcount=%d, %D, %C, %I, request=%p) failed";
static const char short_spc102[] = "**mpi_allgather_init_c %p %c %D %p %c %D %C %I %p";
static const char long_spc102[]  = "MPI_Allgather_init_c(sendbuf=%p, sendcount=%c, %D, recvbuf=%p, recvcount=%c, %D, %C, %I, request=%p) failed";
static const char short_spc103[] = "**mpi_allgatherv %p %d %D %p %p %p %D %C";
static const char long_spc103[]  = "MPI_Allgatherv(sendbuf=%p, sendcount=%d, %D, recvbuf=%p, recvcounts=%p, displs=%p, %D, %C) failed";
static const char short_spc104[] = "**mpi_allgatherv_c %p %c %D %p %p %p %D %C";
static const char long_spc104[]  = "MPI_Allgatherv_c(sendbuf=%p, sendcount=%c, %D, recvbuf=%p, recvcounts=%p, displs=%p, %D, %C) failed";
static const char short_spc105[] = "**mpi_allgatherv_init %p %d %D %p %p %p %D %C %I %p";
static const char long_spc105[]  = "MPI_Allgatherv_init(sendbuf=%p, sendcount=%d, %D, recvbuf=%p, recvcounts=%p, displs=%p, %D, %C, %I, request=%p) failed";
static const char short_spc106[] = "**mpi_allgatherv_init_c %p %c %D %p %p %p %D %C %I %p";
static const char long_spc106[]  = "MPI_Allgatherv_init_c(sendbuf=%p, sendcount=%c, %D, recvbuf=%p, recvcounts=%p, displs=%p, %D, %C, %I, request=%p) failed";
static const char short_spc107[] = "**mpi_alloc_mem %L %I %p";
static const char long_spc107[]  = "MPI_Alloc_mem(size=%L, %I, baseptr=%p) failed";
static const char short_spc108[] = "**mpi_allreduce %p %p %d %D %O %C";
static const char long_spc108[]  = "MPI_Allreduce(sendbuf=%p, recvbuf=%p, count=%d, %D, %O, %C) failed";
static const char short_spc109[] = "**mpi_allreduce_c %p %p %c %D %O %C";
static const char long_spc109[]  = "MPI_Allreduce_c(sendbuf=%p, recvbuf=%p, count=%c, %D, %O, %C) failed";
static const char short_spc110[] = "**mpi_allreduce_init %p %p %d %D %O %C %I %p";
static const char long_spc110[]  = "MPI_Allreduce_init(sendbuf=%p, recvbuf=%p, count=%d, %D, %O, %C, %I, request=%p) failed";
static const char short_spc111[] = "**mpi_allreduce_init_c %p %p %c %D %O %C %I %p";
static const char long_spc111[]  = "MPI_Allreduce_init_c(sendbuf=%p, recvbuf=%p, count=%c, %D, %O, %C, %I, request=%p) failed";
static const char short_spc112[] = "**mpi_alltoall %p %d %D %p %d %D %C";
static const char long_spc112[]  = "MPI_Alltoall(sendbuf=%p, sendcount=%d, %D, recvbuf=%p, recvcount=%d, %D, %C) failed";
static const char short_spc113[] = "**mpi_alltoall_c %p %c %D %p %c %D %C";
static const char long_spc113[]  = "MPI_Alltoall_c(sendbuf=%p, sendcount=%c, %D, recvbuf=%p, recvcount=%c, %D, %C) failed";
static const char short_spc114[] = "**mpi_alltoall_init %p %d %D %p %d %D %C %I %p";
static const char long_spc114[]  = "MPI_Alltoall_init(sendbuf=%p, sendcount=%d, %D, recvbuf=%p, recvcount=%d, %D, %C, %I, request=%p) failed";
static const char short_spc115[] = "**mpi_alltoall_init_c %p %c %D %p %c %D %C %I %p";
static const char long_spc115[]  = "MPI_Alltoall_init_c(sendbuf=%p, sendcount=%c, %D, recvbuf=%p, recvcount=%c, %D, %C, %I, request=%p) failed";
static const char short_spc116[] = "**mpi_alltoallv %p %p %p %D %p %p %p %D %C";
static const char long_spc116[]  = "MPI_Alltoallv(sendbuf=%p, sendcounts=%p, sdispls=%p, %D, recvbuf=%p, recvcounts=%p, rdispls=%p, %D, %C) failed";
static const char short_spc117[] = "**mpi_alltoallv_c %p %p %p %D %p %p %p %D %C";
static const char long_spc117[]  = "MPI_Alltoallv_c(sendbuf=%p, sendcounts=%p, sdispls=%p, %D, recvbuf=%p, recvcounts=%p, rdispls=%p, %D, %C) failed";
static const char short_spc118[] = "**mpi_alltoallv_init %p %p %p %D %p %p %p %D %C %I %p";
static const char long_spc118[]  = "MPI_Alltoallv_init(sendbuf=%p, sendcounts=%p, sdispls=%p, %D, recvbuf=%p, recvcounts=%p, rdispls=%p, %D, %C, %I, request=%p) failed";
static const char short_spc119[] = "**mpi_alltoallv_init_c %p %p %p %D %p %p %p %D %C %I %p";
static const char long_spc119[]  = "MPI_Alltoallv_init_c(sendbuf=%p, sendcounts=%p, sdispls=%p, %D, recvbuf=%p, recvcounts=%p, rdispls=%p, %D, %C, %I, request=%p) failed";
static const char short_spc120[] = "**mpi_alltoallw %p %p %p %p %p %p %p %p %C";
static const char long_spc120[]  = "MPI_Alltoallw(sendbuf=%p, sendcounts=%p, sdispls=%p, sendtypes=%p, recvbuf=%p, recvcounts=%p, rdispls=%p, recvtypes=%p, %C) failed";
static const char short_spc121[] = "**mpi_alltoallw_c %p %p %p %p %p %p %p %p %C";
static const char long_spc121[]  = "MPI_Alltoallw_c(sendbuf=%p, sendcounts=%p, sdispls=%p, sendtypes=%p, recvbuf=%p, recvcounts=%p, rdispls=%p, recvtypes=%p, %C) failed";
static const char short_spc122[] = "**mpi_alltoallw_init %p %p %p %p %p %p %p %p %C %I %p";
static const char long_spc122[]  = "MPI_Alltoallw_init(sendbuf=%p, sendcounts=%p, sdispls=%p, sendtypes=%p, recvbuf=%p, recvcounts=%p, rdispls=%p, recvtypes=%p, %C, %I, request=%p) failed";
static const char short_spc123[] = "**mpi_alltoallw_init_c %p %p %p %p %p %p %p %p %C %I %p";
static const char long_spc123[]  = "MPI_Alltoallw_init_c(sendbuf=%p, sendcounts=%p, sdispls=%p, sendtypes=%p, recvbuf=%p, recvcounts=%p, rdispls=%p, recvtypes=%p, %C, %I, request=%p) failed";
static const char short_spc124[] = "**mpi_barrier %C";
static const char long_spc124[]  = "MPI_Barrier(%C) failed";
static const char short_spc125[] = "**mpi_barrier_init %C %I %p";
static const char long_spc125[]  = "MPI_Barrier_init(%C, %I, request=%p) failed";
static const char short_spc126[] = "**mpi_bcast %p %d %D %i %C";
static const char long_spc126[]  = "MPI_Bcast(buffer=%p, count=%d, %D, %i, %C) failed";
static const char short_spc127[] = "**mpi_bcast_c %p %c %D %i %C";
static const char long_spc127[]  = "MPI_Bcast_c(buffer=%p, count=%c, %D, %i, %C) failed";
static const char short_spc128[] = "**mpi_bcast_init %p %d %D %i %C %I %p";
static const char long_spc128[]  = "MPI_Bcast_init(buffer=%p, count=%d, %D, %i, %C, %I, request=%p) failed";
static const char short_spc129[] = "**mpi_bcast_init_c %p %c %D %i %C %I %p";
static const char long_spc129[]  = "MPI_Bcast_init_c(buffer=%p, count=%c, %D, %i, %C, %I, request=%p) failed";
static const char short_spc130[] = "**mpi_bsend %p %d %D %i %t %C";
static const char long_spc130[]  = "MPI_Bsend(buf=%p, count=%d, %D, %i, %t, %C) failed";
static const char short_spc131[] = "**mpi_bsend_c %p %c %D %i %t %C";
static const char long_spc131[]  = "MPI_Bsend_c(buf=%p, count=%c, %D, %i, %t, %C) failed";
static const char short_spc132[] = "**mpi_bsend_init %p %d %D %i %t %C %p";
static const char long_spc132[]  = "MPI_Bsend_init(buf=%p, count=%d, %D, %i, %t, %C, request=%p) failed";
static const char short_spc133[] = "**mpi_bsend_init_c %p %c %D %i %t %C %p";
static const char long_spc133[]  = "MPI_Bsend_init_c(buf=%p, count=%c, %D, %i, %t, %C, request=%p) failed";
static const char short_spc134[] = "**mpi_buffer_attach %p %d";
static const char long_spc134[]  = "MPI_Buffer_attach(buffer=%p, size=%d) failed";
static const char short_spc135[] = "**mpi_buffer_attach_c %p %c";
static const char long_spc135[]  = "MPI_Buffer_attach_c(buffer=%p, size=%c) failed";
static const char short_spc136[] = "**mpi_buffer_detach %p %p";
static const char long_spc136[]  = "MPI_Buffer_detach(buffer_addr=%p, size=%p) failed";
static const char short_spc137[] = "**mpi_buffer_detach_c %p %p";
static const char long_spc137[]  = "MPI_Buffer_detach_c(buffer_addr=%p, size=%p) failed";
static const char short_spc138[] = "**mpi_buffer_iflush %p";
static const char long_spc138[]  = "MPI_Buffer_iflush(request=%p) failed";
static const char short_spc139[] = "**mpi_cancel %p";
static const char long_spc139[]  = "MPI_Cancel(request=%p) failed";
static const char short_spc140[] = "**mpi_cart_coords %C %i %d %p";
static const char long_spc140[]  = "MPI_Cart_coords(%C, %i, maxdims=%d, coords=%p) failed";
static const char short_spc141[] = "**mpi_cart_create %C %d %p %p %d %p";
static const char long_spc141[]  = "MPI_Cart_create(%C, ndims=%d, dims=%p, periods=%p, reorder=%d, comm_cart=%p) failed";
static const char short_spc142[] = "**mpi_cart_get %C %d %p %p %p";
static const char long_spc142[]  = "MPI_Cart_get(%C, maxdims=%d, dims=%p, periods=%p, coords=%p) failed";
static const char short_spc143[] = "**mpi_cart_map %C %d %p %p %p";
static const char long_spc143[]  = "MPI_Cart_map(%C, ndims=%d, dims=%p, periods=%p, newrank=%p) failed";
static const char short_spc144[] = "**mpi_cart_rank %C %p %p";
static const char long_spc144[]  = "MPI_Cart_rank(%C, coords=%p, rank=%p) failed";
static const char short_spc145[] = "**mpi_cart_shift %C %d %d %p %p";
static const char long_spc145[]  = "MPI_Cart_shift(%C, direction=%d, disp=%d, rank_source=%p, rank_dest=%p) failed";
static const char short_spc146[] = "**mpi_cart_sub %C %p %p";
static const char long_spc146[]  = "MPI_Cart_sub(%C, remain_dims=%p, newcomm=%p) failed";
static const char short_spc147[] = "**mpi_cartdim_get %C %p";
static const char long_spc147[]  = "MPI_Cartdim_get(%C, ndims=%p) failed";
static const char short_spc148[] = "**mpi_close_port %s";
static const char long_spc148[]  = "MPI_Close_port(port_name=%s) failed";
static const char short_spc149[] = "**mpi_comm_accept %s %I %i %C %p";
static const char long_spc149[]  = "MPI_Comm_accept(port_name=%s, %I, %i, %C, newcomm=%p) failed";
static const char short_spc150[] = "**mpi_comm_attach_buffer %C %p %d";
static const char long_spc150[]  = "MPI_Comm_attach_buffer(%C, buffer=%p, size=%d) failed";
static const char short_spc151[] = "**mpi_comm_attach_buffer_c %C %p %c";
static const char long_spc151[]  = "MPI_Comm_attach_buffer_c(%C, buffer=%p, size=%c) failed";
static const char short_spc152[] = "**mpi_comm_call_errhandler %C %d";
static const char long_spc152[]  = "MPI_Comm_call_errhandler(%C, errorcode=%d) failed";
static const char short_spc153[] = "**mpi_comm_compare %C %C %p";
static const char long_spc153[]  = "MPI_Comm_compare(%C, %C, result=%p) failed";
static const char short_spc154[] = "**mpi_comm_connect %s %I %i %C %p";
static const char long_spc154[]  = "MPI_Comm_connect(port_name=%s, %I, %i, %C, newcomm=%p) failed";
static const char short_spc155[] = "**mpi_comm_create %C %G %p";
static const char long_spc155[]  = "MPI_Comm_create(%C, %G, newcomm=%p) failed";
static const char short_spc156[] = "**mpi_comm_create_errhandler %p %p";
static const char long_spc156[]  = "MPI_Comm_create_errhandler(comm_errhandler_fn=%p, errhandler=%p) failed";
static const char short_spc157[] = "**mpi_comm_create_from_group %G %s %I %E %p";
static const char long_spc157[]  = "MPI_Comm_create_from_group(%G, stringtag=%s, %I, %E, newcomm=%p) failed";
static const char short_spc158[] = "**mpi_comm_create_group %C %G %t %p";
static const char long_spc158[]  = "MPI_Comm_create_group(%C, %G, %t, newcomm=%p) failed";
static const char short_spc159[] = "**mpi_comm_create_keyval %p %p %p %p";
static const char long_spc159[]  = "MPI_Comm_create_keyval(comm_copy_attr_fn=%p, comm_delete_attr_fn=%p, comm_keyval=%p, extra_state=%p) failed";
static const char short_spc160[] = "**mpi_comm_delete_attr %C %K";
static const char long_spc160[]  = "MPI_Comm_delete_attr(%C, %K) failed";
static const char short_spc161[] = "**mpi_comm_detach_buffer %C %p %p";
static const char long_spc161[]  = "MPI_Comm_detach_buffer(%C, buffer_addr=%p, size=%p) failed";
static const char short_spc162[] = "**mpi_comm_detach_buffer_c %C %p %p";
static const char long_spc162[]  = "MPI_Comm_detach_buffer_c(%C, buffer_addr=%p, size=%p) failed";
static const char short_spc163[] = "**mpi_comm_disconnect %p";
static const char long_spc163[]  = "MPI_Comm_disconnect(comm=%p) failed";
static const char short_spc164[] = "**mpi_comm_dup %C %p";
static const char long_spc164[]  = "MPI_Comm_dup(%C, newcomm=%p) failed";
static const char short_spc165[] = "**mpi_comm_dup_with_info %C %I %p";
static const char long_spc165[]  = "MPI_Comm_dup_with_info(%C, %I, newcomm=%p) failed";
static const char short_spc166[] = "**mpi_comm_flush_buffer %C";
static const char long_spc166[]  = "MPI_Comm_flush_buffer(%C) failed";
static const char short_spc167[] = "**mpi_comm_free %p";
static const char long_spc167[]  = "MPI_Comm_free(comm=%p) failed";
static const char short_spc168[] = "**mpi_comm_free_keyval %p";
static const char long_spc168[]  = "MPI_Comm_free_keyval(comm_keyval=%p) failed";
static const char short_spc169[] = "**mpi_comm_get_attr %C %K %p %p";
static const char long_spc169[]  = "MPI_Comm_get_attr(%C, %K, attribute_val=%p, flag=%p) failed";
static const char short_spc170[] = "**mpi_comm_get_errhandler %C %p";
static const char long_spc170[]  = "MPI_Comm_get_errhandler(%C, errhandler=%p) failed";
static const char short_spc171[] = "**mpi_comm_get_info %C %p";
static const char long_spc171[]  = "MPI_Comm_get_info(%C, info_used=%p) failed";
static const char short_spc172[] = "**mpi_comm_get_name %C %p %p";
static const char long_spc172[]  = "MPI_Comm_get_name(%C, comm_name=%p, resultlen=%p) failed";
static const char short_spc173[] = "**mpi_comm_get_parent %p";
static const char long_spc173[]  = "MPI_Comm_get_parent(parent=%p) failed";
static const char short_spc174[] = "**mpi_comm_group %C %p";
static const char long_spc174[]  = "MPI_Comm_group(%C, group=%p) failed";
static const char short_spc175[] = "**mpi_comm_idup %C %p %p";
static const char long_spc175[]  = "MPI_Comm_idup(%C, newcomm=%p, request=%p) failed";
static const char short_spc176[] = "**mpi_comm_idup_with_info %C %I %p %p";
static const char long_spc176[]  = "MPI_Comm_idup_with_info(%C, %I, newcomm=%p, request=%p) failed";
static const char short_spc177[] = "**mpi_comm_iflush_buffer %C %p";
static const char long_spc177[]  = "MPI_Comm_iflush_buffer(%C, request=%p) failed";
static const char short_spc178[] = "**mpi_comm_join %d %p";
static const char long_spc178[]  = "MPI_Comm_join(fd=%d, intercomm=%p) failed";
static const char short_spc179[] = "**mpi_comm_rank %C %p";
static const char long_spc179[]  = "MPI_Comm_rank(%C, rank=%p) failed";
static const char short_spc180[] = "**mpi_comm_remote_group %C %p";
static const char long_spc180[]  = "MPI_Comm_remote_group(%C, group=%p) failed";
static const char short_spc181[] = "**mpi_comm_remote_size %C %p";
static const char long_spc181[]  = "MPI_Comm_remote_size(%C, size=%p) failed";
static const char short_spc182[] = "**mpi_comm_set_attr %C %K %p";
static const char long_spc182[]  = "MPI_Comm_set_attr(%C, %K, attribute_val=%p) failed";
static const char short_spc183[] = "**mpi_comm_set_errhandler %C %E";
static const char long_spc183[]  = "MPI_Comm_set_errhandler(%C, %E) failed";
static const char short_spc184[] = "**mpi_comm_set_info %C %I";
static const char long_spc184[]  = "MPI_Comm_set_info(%C, %I) failed";
static const char short_spc185[] = "**mpi_comm_set_name %C %s";
static const char long_spc185[]  = "MPI_Comm_set_name(%C, comm_name=%s) failed";
static const char short_spc186[] = "**mpi_comm_size %C %p";
static const char long_spc186[]  = "MPI_Comm_size(%C, size=%p) failed";
static const char short_spc187[] = "**mpi_comm_spawn %s %p %d %I %i %C %p %p";
static const char long_spc187[]  = "MPI_Comm_spawn(command=%s, argv=%p, maxprocs=%d, %I, %i, %C, intercomm=%p, array_of_errcodes=%p) failed";
static const char short_spc188[] = "**mpi_comm_spawn_multiple %d %p %p %p %p %i %C %p %p";
static const char long_spc188[]  = "MPI_Comm_spawn_multiple(count=%d, array_of_commands=%p, array_of_argv=%p, array_of_maxprocs=%p, array_of_info=%p, %i, %C, intercomm=%p, array_of_errcodes=%p) failed";
static const char short_spc189[] = "**mpi_comm_split %C %d %d %p";
static const char long_spc189[]  = "MPI_Comm_split(%C, color=%d, key=%d, newcomm=%p) failed";
static const char short_spc190[] = "**mpi_comm_split_type %C %d %d %I %p";
static const char long_spc190[]  = "MPI_Comm_split_type(%C, split_type=%d, key=%d, %I, newcomm=%p) failed";
static const char short_spc191[] = "**mpi_comm_test_inter %C %p";
static const char long_spc191[]  = "MPI_Comm_test_inter(%C, flag=%p) failed";
static const char short_spc192[] = "**mpi_compare_and_swap %p %p %p %D %d %L %W";
static const char long_spc192[]  = "MPI_Compare_and_swap(origin_addr=%p, compare_addr=%p, result_addr=%p, %D, target_rank=%d, target_disp=%L, %W) failed";
static const char short_spc193[] = "**mpi_dims_create %d %d %p";
static const char long_spc193[]  = "MPI_Dims_create(nnodes=%d, ndims=%d, dims=%p) failed";
static const char short_spc194[] = "**mpi_dist_graph_create %C %d %p %p %p %p %I %d %p";
static const char long_spc194[]  = "MPI_Dist_graph_create(%C, n=%d, sources=%p, degrees=%p, destinations=%p, weights=%p, %I, reorder=%d, comm_dist_graph=%p) failed";
static const char short_spc195[] = "**mpi_dist_graph_create_adjacent %C %d %p %p %d %p %p %I %d %p";
static const char long_spc195[]  = "MPI_Dist_graph_create_adjacent(%C, indegree=%d, sources=%p, sourceweights=%p, outdegree=%d, destinations=%p, destweights=%p, %I, reorder=%d, comm_dist_graph=%p) failed";
static const char short_spc196[] = "**mpi_dist_graph_neighbors %C %d %p %p %d %p %p";
static const char long_spc196[]  = "MPI_Dist_graph_neighbors(%C, maxindegree=%d, sources=%p, sourceweights=%p, maxoutdegree=%d, destinations=%p, destweights=%p) failed";
static const char short_spc197[] = "**mpi_dist_graph_neighbors_count %C %p %p %p";
static const char long_spc197[]  = "MPI_Dist_graph_neighbors_count(%C, indegree=%p, outdegree=%p, weighted=%p) failed";
static const char short_spc198[] = "**mpi_errhandler_free %p";
static const char long_spc198[]  = "MPI_Errhandler_free(errhandler=%p) failed";
static const char short_spc199[] = "**mpi_error_class %d %p";
static const char long_spc199[]  = "MPI_Error_class(errorcode=%d, errorclass=%p) failed";
static const char short_spc200[] = "**mpi_error_string %d %p %p";
static const char long_spc200[]  = "MPI_Error_string(errorcode=%d, string=%p, resultlen=%p) failed";
static const char short_spc201[] = "**mpi_exscan %p %p %d %D %O %C";
static const char long_spc201[]  = "MPI_Exscan(sendbuf=%p, recvbuf=%p, count=%d, %D, %O, %C) failed";
static const char short_spc202[] = "**mpi_exscan_c %p %p %c %D %O %C";
static const char long_spc202[]  = "MPI_Exscan_c(sendbuf=%p, recvbuf=%p, count=%c, %D, %O, %C) failed";
static const char short_spc203[] = "**mpi_exscan_init %p %p %d %D %O %C %I %p";
static const char long_spc203[]  = "MPI_Exscan_init(sendbuf=%p, recvbuf=%p, count=%d, %D, %O, %C, %I, request=%p) failed";
static const char short_spc204[] = "**mpi_exscan_init_c %p %p %c %D %O %C %I %p";
static const char long_spc204[]  = "MPI_Exscan_init_c(sendbuf=%p, recvbuf=%p, count=%c, %D, %O, %C, %I, request=%p) failed";
static const char short_spc205[] = "**mpi_fetch_and_op %p %p %D %d %L %O %W";
static const char long_spc205[]  = "MPI_Fetch_and_op(origin_addr=%p, result_addr=%p, %D, target_rank=%d, target_disp=%L, %O, %W) failed";
static const char short_spc206[] = "**mpi_file_call_errhandler %F %d";
static const char long_spc206[]  = "MPI_File_call_errhandler(%F, errorcode=%d) failed";
static const char short_spc207[] = "**mpi_file_create_errhandler %p %p";
static const char long_spc207[]  = "MPI_File_create_errhandler(file_errhandler_fn=%p, errhandler=%p) failed";
static const char short_spc208[] = "**mpi_file_get_errhandler %F %p";
static const char long_spc208[]  = "MPI_File_get_errhandler(%F, errhandler=%p) failed";
static const char short_spc209[] = "**mpi_file_set_errhandler %F %E";
static const char long_spc209[]  = "MPI_File_set_errhandler(%F, %E) failed";
static const char short_spc210[] = "**mpi_finalized %p";
static const char long_spc210[]  = "MPI_Finalized(flag=%p) failed";
static const char short_spc211[] = "**mpi_free_mem %p";
static const char long_spc211[]  = "MPI_Free_mem(base=%p) failed";
static const char short_spc212[] = "**mpi_gather %p %d %D %p %d %D %i %C";
static const char long_spc212[]  = "MPI_Gather(sendbuf=%p, sendcount=%d, %D, recvbuf=%p, recvcount=%d, %D, %i, %C) failed";
static const char short_spc213[] = "**mpi_gather_c %p %c %D %p %c %D %i %C";
static const char long_spc213[]  = "MPI_Gather_c(sendbuf=%p, sendcount=%c, %D, recvbuf=%p, recvcount=%c, %D, %i, %C) failed";
static const char short_spc214[] = "**mpi_gather_init %p %d %D %p %d %D %i %C %I %p";
static const char long_spc214[]  = "MPI_Gather_init(sendbuf=%p, sendcount=%d, %D, recvbuf=%p, recvcount=%d, %D, %i, %C, %I, request=%p) failed";
static const char short_spc215[] = "**mpi_gather_init_c %p %c %D %p %c %D %i %C %I %p";
static const char long_spc215[]  = "MPI_Gather_init_c(sendbuf=%p, sendcount=%c, %D, recvbuf=%p, recvcount=%c, %D, %i, %C, %I, request=%p) failed";
static const char short_spc216[] = "**mpi_gatherv %p %d %D %p %p %p %D %i %C";
static const char long_spc216[]  = "MPI_Gatherv(sendbuf=%p, sendcount=%d, %D, recvbuf=%p, recvcounts=%p, displs=%p, %D, %i, %C) failed";
static const char short_spc217[] = "**mpi_gatherv_c %p %c %D %p %p %p %D %i %C";
static const char long_spc217[]  = "MPI_Gatherv_c(sendbuf=%p, sendcount=%c, %D, recvbuf=%p, recvcounts=%p, displs=%p, %D, %i, %C) failed";
static const char short_spc218[] = "**mpi_gatherv_init %p %d %D %p %p %p %D %i %C %I %p";
static const char long_spc218[]  = "MPI_Gatherv_init(sendbuf=%p, sendcount=%d, %D, recvbuf=%p, recvcounts=%p, displs=%p, %D, %i, %C, %I, request=%p) failed";
static const char short_spc219[] = "**mpi_gatherv_init_c %p %c %D %p %p %p %D %i %C %I %p";
static const char long_spc219[]  = "MPI_Gatherv_init_c(sendbuf=%p, sendcount=%c, %D, recvbuf=%p, recvcounts=%p, displs=%p, %D, %i, %C, %I, request=%p) failed";
static const char short_spc220[] = "**mpi_get %p %d %D %d %L %d %D %W";
static const char long_spc220[]  = "MPI_Get(origin_addr=%p, origin_count=%d, %D, target_rank=%d, target_disp=%L, target_count=%d, %D, %W) failed";
static const char short_spc221[] = "**mpi_get_accumulate %p %d %D %p %d %D %d %L %d %D %O %W";
static const char long_spc221[]  = "MPI_Get_accumulate(origin_addr=%p, origin_count=%d, %D, result_addr=%p, result_count=%d, %D, target_rank=%d, target_disp=%L, target_count=%d, %D, %O, %W) failed";
static const char short_spc222[] = "**mpi_get_accumulate_c %p %c %D %p %c %D %d %L %c %D %O %W";
static const char long_spc222[]  = "MPI_Get_accumulate_c(origin_addr=%p, origin_count=%c, %D, result_addr=%p, result_count=%c, %D, target_rank=%d, target_disp=%L, target_count=%c, %D, %O, %W) failed";
static const char short_spc223[] = "**mpi_get_address %p %p";
static const char long_spc223[]  = "MPI_Get_address(location=%p, address=%p) failed";
static const char short_spc224[] = "**mpi_get_c %p %c %D %d %L %c %D %W";
static const char long_spc224[]  = "MPI_Get_c(origin_addr=%p, origin_count=%c, %D, target_rank=%d, target_disp=%L, target_count=%c, %D, %W) failed";
static const char short_spc225[] = "**mpi_get_count %p %D %p";
static const char long_spc225[]  = "MPI_Get_count(status=%p, %D, count=%p) failed";
static const char short_spc226[] = "**mpi_get_count_c %p %D %p";
static const char long_spc226[]  = "MPI_Get_count_c(status=%p, %D, count=%p) failed";
static const char short_spc227[] = "**mpi_get_elements %p %D %p";
static const char long_spc227[]  = "MPI_Get_elements(status=%p, %D, count=%p) failed";
static const char short_spc228[] = "**mpi_get_elements_c %p %D %p";
static const char long_spc228[]  = "MPI_Get_elements_c(status=%p, %D, count=%p) failed";
static const char short_spc229[] = "**mpi_get_elements_x %p %D %p";
static const char long_spc229[]  = "MPI_Get_elements_x(status=%p, %D, count=%p) failed";
static const char short_spc230[] = "**mpi_get_hw_resource_info %p";
static const char long_spc230[]  = "MPI_Get_hw_resource_info(hw_info=%p) failed";
static const char short_spc231[] = "**mpi_get_library_version %p %p";
static const char long_spc231[]  = "MPI_Get_library_version(version=%p, resultlen=%p) failed";
static const char short_spc232[] = "**mpi_get_processor_name %p %p";
static const char long_spc232[]  = "MPI_Get_processor_name(name=%p, resultlen=%p) failed";
static const char short_spc233[] = "**mpi_get_version %p %p";
static const char long_spc233[]  = "MPI_Get_version(version=%p, subversion=%p) failed";
static const char short_spc234[] = "**mpi_graph_create %C %d %p %p %d %p";
static const char long_spc234[]  = "MPI_Graph_create(%C, nnodes=%d, indx=%p, edges=%p, reorder=%d, comm_graph=%p) failed";
static const char short_spc235[] = "**mpi_graph_get %C %d %d %p %p";
static const char long_spc235[]  = "MPI_Graph_get(%C, maxindex=%d, maxedges=%d, indx=%p, edges=%p) failed";
static const char short_spc236[] = "**mpi_graph_map %C %d %p %p %p";
static const char long_spc236[]  = "MPI_Graph_map(%C, nnodes=%d, indx=%p, edges=%p, newrank=%p) failed";
static const char short_spc237[] = "**mpi_graph_neighbors %C %i %d %p";
static const char long_spc237[]  = "MPI_Graph_neighbors(%C, %i, maxneighbors=%d, neighbors=%p) failed";
static const char short_spc238[] = "**mpi_graph_neighbors_count %C %i %p";
static const char long_spc238[]  = "MPI_Graph_neighbors_count(%C, %i, nneighbors=%p) failed";
static const char short_spc239[] = "**mpi_graphdims_get %C %p %p";
static const char long_spc239[]  = "MPI_Graphdims_get(%C, nnodes=%p, nedges=%p) failed";
static const char short_spc240[] = "**mpi_grequest_complete %R";
static const char long_spc240[]  = "MPI_Grequest_complete(%R) failed";
static const char short_spc241[] = "**mpi_grequest_start %p %p %p %p %p";
static const char long_spc241[]  = "MPI_Grequest_start(query_fn=%p, free_fn=%p, cancel_fn=%p, extra_state=%p, request=%p) failed";
static const char short_spc242[] = "**mpi_group_compare %G %G %p";
static const char long_spc242[]  = "MPI_Group_compare(%G, %G, result=%p) failed";
static const char short_spc243[] = "**mpi_group_difference %G %G %p";
static const char long_spc243[]  = "MPI_Group_difference(%G, %G, newgroup=%p) failed";
static const char short_spc244[] = "**mpi_group_excl %G %d %p %p";
static const char long_spc244[]  = "MPI_Group_excl(%G, n=%d, ranks=%p, newgroup=%p) failed";
static const char short_spc245[] = "**mpi_group_free %p";
static const char long_spc245[]  = "MPI_Group_free(group=%p) failed";
static const char short_spc246[] = "**mpi_group_from_session_pset %S %s %p";
static const char long_spc246[]  = "MPI_Group_from_session_pset(%S, pset_name=%s, newgroup=%p) failed";
static const char short_spc247[] = "**mpi_group_incl %G %d %p %p";
static const char long_spc247[]  = "MPI_Group_incl(%G, n=%d, ranks=%p, newgroup=%p) failed";
static const char short_spc248[] = "**mpi_group_intersection %G %G %p";
static const char long_spc248[]  = "MPI_Group_intersection(%G, %G, newgroup=%p) failed";
static const char short_spc249[] = "**mpi_group_range_excl %G %d %p %p";
static const char long_spc249[]  = "MPI_Group_range_excl(%G, n=%d, ranges=%p, newgroup=%p) failed";
static const char short_spc250[] = "**mpi_group_range_incl %G %d %p %p";
static const char long_spc250[]  = "MPI_Group_range_incl(%G, n=%d, ranges=%p, newgroup=%p) failed";
static const char short_spc251[] = "**mpi_group_rank %G %p";
static const char long_spc251[]  = "MPI_Group_rank(%G, rank=%p) failed";
static const char short_spc252[] = "**mpi_group_size %G %p";
static const char long_spc252[]  = "MPI_Group_size(%G, size=%p) failed";
static const char short_spc253[] = "**mpi_group_translate_ranks %G %d %p %G %p";
static const char long_spc253[]  = "MPI_Group_translate_ranks(%G, n=%d, ranks1=%p, %G, ranks2=%p) failed";
static const char short_spc254[] = "**mpi_group_union %G %G %p";
static const char long_spc254[]  = "MPI_Group_union(%G, %G, newgroup=%p) failed";
static const char short_spc255[] = "**mpi_iallgather %p %d %D %p %d %D %C %p";
static const char long_spc255[]  = "MPI_Iallgather(sendbuf=%p, sendcount=%d, %D, recvbuf=%p, recvcount=%d, %D, %C, request=%p) failed";
static const char short_spc256[] = "**mpi_iallgather_c %p %c %D %p %c %D %C %p";
static const char long_spc256[]  = "MPI_Iallgather_c(sendbuf=%p, sendcount=%c, %D, recvbuf=%p, recvcount=%c, %D, %C, request=%p) failed";
static const char short_spc257[] = "**mpi_iallgatherv %p %d %D %p %p %p %D %C %p";
static const char long_spc257[]  = "MPI_Iallgatherv(sendbuf=%p, sendcount=%d, %D, recvbuf=%p, recvcounts=%p, displs=%p, %D, %C, request=%p) failed";
static const char short_spc258[] = "**mpi_iallgatherv_c %p %c %D %p %p %p %D %C %p";
static const char long_spc258[]  = "MPI_Iallgatherv_c(sendbuf=%p, sendcount=%c, %D, recvbuf=%p, recvcounts=%p, displs=%p, %D, %C, request=%p) failed";
static const char short_spc259[] = "**mpi_iallreduce %p %p %d %D %O %C %p";
static const char long_spc259[]  = "MPI_Iallreduce(sendbuf=%p, recvbuf=%p, count=%d, %D, %O, %C, request=%p) failed";
static const char short_spc260[] = "**mpi_iallreduce_c %p %p %c %D %O %C %p";
static const char long_spc260[]  = "MPI_Iallreduce_c(sendbuf=%p, recvbuf=%p, count=%c, %D, %O, %C, request=%p) failed";
static const char short_spc261[] = "**mpi_ialltoall %p %d %D %p %d %D %C %p";
static const char long_spc261[]  = "MPI_Ialltoall(sendbuf=%p, sendcount=%d, %D, recvbuf=%p, recvcount=%d, %D, %C, request=%p) failed";
static const char short_spc262[] = "**mpi_ialltoall_c %p %c %D %p %c %D %C %p";
static const char long_spc262[]  = "MPI_Ialltoall_c(sendbuf=%p, sendcount=%c, %D, recvbuf=%p, recvcount=%c, %D, %C, request=%p) failed";
static const char short_spc263[] = "**mpi_ialltoallv %p %p %p %D %p %p %p %D %C %p";
static const char long_spc263[]  = "MPI_Ialltoallv(sendbuf=%p, sendcounts=%p, sdispls=%p, %D, recvbuf=%p, recvcounts=%p, rdispls=%p, %D, %C, request=%p) failed";
static const char short_spc264[] = "**mpi_ialltoallv_c %p %p %p %D %p %p %p %D %C %p";
static const char long_spc264[]  = "MPI_Ialltoallv_c(sendbuf=%p, sendcounts=%p, sdispls=%p, %D, recvbuf=%p, recvcounts=%p, rdispls=%p, %D, %C, request=%p) failed";
static const char short_spc265[] = "**mpi_ialltoallw %p %p %p %p %p %p %p %p %C %p";
static const char long_spc265[]  = "MPI_Ialltoallw(sendbuf=%p, sendcounts=%p, sdispls=%p, sendtypes=%p, recvbuf=%p, recvcounts=%p, rdispls=%p, recvtypes=%p, %C, request=%p) failed";
static const char short_spc266[] = "**mpi_ialltoallw_c %p %p %p %p %p %p %p %p %C %p";
static const char long_spc266[]  = "MPI_Ialltoallw_c(sendbuf=%p, sendcounts=%p, sdispls=%p, sendtypes=%p, recvbuf=%p, recvcounts=%p, rdispls=%p, recvtypes=%p, %C, request=%p) failed";
static const char short_spc267[] = "**mpi_ibarrier %C %p";
static const char long_spc267[]  = "MPI_Ibarrier(%C, request=%p) failed";
static const char short_spc268[] = "**mpi_ibcast %p %d %D %i %C %p";
static const char long_spc268[]  = "MPI_Ibcast(buffer=%p, count=%d, %D, %i, %C, request=%p) failed";
static const char short_spc269[] = "**mpi_ibcast_c %p %c %D %i %C %p";
static const char long_spc269[]  = "MPI_Ibcast_c(buffer=%p, count=%c, %D, %i, %C, request=%p) failed";
static const char short_spc270[] = "**mpi_ibsend %p %d %D %i %t %C %p";
static const char long_spc270[]  = "MPI_Ibsend(buf=%p, count=%d, %D, %i, %t, %C, request=%p) failed";
static const char short_spc271[] = "**mpi_ibsend_c %p %c %D %i %t %C %p";
static const char long_spc271[]  = "MPI_Ibsend_c(buf=%p, count=%c, %D, %i, %t, %C, request=%p) failed";
static const char short_spc272[] = "**mpi_iexscan %p %p %d %D %O %C %p";
static const char long_spc272[]  = "MPI_Iexscan(sendbuf=%p, recvbuf=%p, count=%d, %D, %O, %C, request=%p) failed";
static const char short_spc273[] = "**mpi_iexscan_c %p %p %c %D %O %C %p";
static const char long_spc273[]  = "MPI_Iexscan_c(sendbuf=%p, recvbuf=%p, count=%c, %D, %O, %C, request=%p) failed";
static const char short_spc274[] = "**mpi_igather %p %d %D %p %d %D %i %C %p";
static const char long_spc274[]  = "MPI_Igather(sendbuf=%p, sendcount=%d, %D, recvbuf=%p, recvcount=%d, %D, %i, %C, request=%p) failed";
static const char short_spc275[] = "**mpi_igather_c %p %c %D %p %c %D %i %C %p";
static const char long_spc275[]  = "MPI_Igather_c(sendbuf=%p, sendcount=%c, %D, recvbuf=%p, recvcount=%c, %D, %i, %C, request=%p) failed";
static const char short_spc276[] = "**mpi_igatherv %p %d %D %p %p %p %D %i %C %p";
static const char long_spc276[]  = "MPI_Igatherv(sendbuf=%p, sendcount=%d, %D, recvbuf=%p, recvcounts=%p, displs=%p, %D, %i, %C, request=%p) failed";
static const char short_spc277[] = "**mpi_igatherv_c %p %c %D %p %p %p %D %i %C %p";
static const char long_spc277[]  = "MPI_Igatherv_c(sendbuf=%p, sendcount=%c, %D, recvbuf=%p, recvcounts=%p, displs=%p, %D, %i, %C, request=%p) failed";
static const char short_spc278[] = "**mpi_improbe %i %t %C %p %p %p";
static const char long_spc278[]  = "MPI_Improbe(%i, %t, %C, flag=%p, message=%p, status=%p) failed";
static const char short_spc279[] = "**mpi_imrecv %p %d %D %p %p";
static const char long_spc279[]  = "MPI_Imrecv(buf=%p, count=%d, %D, message=%p, request=%p) failed";
static const char short_spc280[] = "**mpi_imrecv_c %p %c %D %p %p";
static const char long_spc280[]  = "MPI_Imrecv_c(buf=%p, count=%c, %D, message=%p, request=%p) failed";
static const char short_spc281[] = "**mpi_ineighbor_allgather %p %d %D %p %d %D %C %p";
static const char long_spc281[]  = "MPI_Ineighbor_allgather(sendbuf=%p, sendcount=%d, %D, recvbuf=%p, recvcount=%d, %D, %C, request=%p) failed";
static const char short_spc282[] = "**mpi_ineighbor_allgather_c %p %c %D %p %c %D %C %p";
static const char long_spc282[]  = "MPI_Ineighbor_allgather_c(sendbuf=%p, sendcount=%c, %D, recvbuf=%p, recvcount=%c, %D, %C, request=%p) failed";
static const char short_spc283[] = "**mpi_ineighbor_allgatherv %p %d %D %p %p %p %D %C %p";
static const char long_spc283[]  = "MPI_Ineighbor_allgatherv(sendbuf=%p, sendcount=%d, %D, recvbuf=%p, recvcounts=%p, displs=%p, %D, %C, request=%p) failed";
static const char short_spc284[] = "**mpi_ineighbor_allgatherv_c %p %c %D %p %p %p %D %C %p";
static const char long_spc284[]  = "MPI_Ineighbor_allgatherv_c(sendbuf=%p, sendcount=%c, %D, recvbuf=%p, recvcounts=%p, displs=%p, %D, %C, request=%p) failed";
static const char short_spc285[] = "**mpi_ineighbor_alltoall %p %d %D %p %d %D %C %p";
static const char long_spc285[]  = "MPI_Ineighbor_alltoall(sendbuf=%p, sendcount=%d, %D, recvbuf=%p, recvcount=%d, %D, %C, request=%p) failed";
static const char short_spc286[] = "**mpi_ineighbor_alltoall_c %p %c %D %p %c %D %C %p";
static const char long_spc286[]  = "MPI_Ineighbor_alltoall_c(sendbuf=%p, sendcount=%c, %D, recvbuf=%p, recvcount=%c, %D, %C, request=%p) failed";
static const char short_spc287[] = "**mpi_ineighbor_alltoallv %p %p %p %D %p %p %p %D %C %p";
static const char long_spc287[]  = "MPI_Ineighbor_alltoallv(sendbuf=%p, sendcounts=%p, sdispls=%p, %D, recvbuf=%p, recvcounts=%p, rdispls=%p, %D, %C, request=%p) failed";
static const char short_spc288[] = "**mpi_ineighbor_alltoallv_c %p %p %p %D %p %p %p %D %C %p";
static const char long_spc288[]  = "MPI_Ineighbor_alltoallv_c(sendbuf=%p, sendcounts=%p, sdispls=%p, %D, recvbuf=%p, recvcounts=%p, rdispls=%p, %D, %C, request=%p) failed";
static const char short_spc289[] = "**mpi_ineighbor_alltoallw %p %p %p %p %p %p %p %p %C %p";
static const char long_spc289[]  = "MPI_Ineighbor_alltoallw(sendbuf=%p, sendcounts=%p, sdispls=%p, sendtypes=%p, recvbuf=%p, recvcounts=%p, rdispls=%p, recvtypes=%p, %C, request=%p) failed";
static const char short_spc290[] = "**mpi_ineighbor_alltoallw_c %p %p %p %p %p %p %p %p %C %p";
static const char long_spc290[]  = "MPI_Ineighbor_alltoallw_c(sendbuf=%p, sendcounts=%p, sdispls=%p, sendtypes=%p, recvbuf=%p, recvcounts=%p, rdispls=%p, recvtypes=%p, %C, request=%p) failed";
static const char short_spc291[] = "**mpi_info_create %p";
static const char long_spc291[]  = "MPI_Info_create(info=%p) failed";
static const char short_spc292[] = "**mpi_info_create_env %p %p %p";
static const char long_spc292[]  = "MPI_Info_create_env(argc=%p, argv=%p, info=%p) failed";
static const char short_spc293[] = "**mpi_info_delete %I %s";
static const char long_spc293[]  = "MPI_Info_delete(%I, key=%s) failed";
static const char short_spc294[] = "**mpi_info_dup %I %p";
static const char long_spc294[]  = "MPI_Info_dup(%I, newinfo=%p) failed";
static const char short_spc295[] = "**mpi_info_free %p";
static const char long_spc295[]  = "MPI_Info_free(info=%p) failed";
static const char short_spc296[] = "**mpi_info_get %I %s %d %p %p";
static const char long_spc296[]  = "MPI_Info_get(%I, key=%s, valuelen=%d, value=%p, flag=%p) failed";
static const char short_spc297[] = "**mpi_info_get_nkeys %I %p";
static const char long_spc297[]  = "MPI_Info_get_nkeys(%I, nkeys=%p) failed";
static const char short_spc298[] = "**mpi_info_get_nthkey %I %d %p";
static const char long_spc298[]  = "MPI_Info_get_nthkey(%I, n=%d, key=%p) failed";
static const char short_spc299[] = "**mpi_info_get_string %I %s %p %p %p";
static const char long_spc299[]  = "MPI_Info_get_string(%I, key=%s, buflen=%p, value=%p, flag=%p) failed";
static const char short_spc300[] = "**mpi_info_get_valuelen %I %s %p %p";
static const char long_spc300[]  = "MPI_Info_get_valuelen(%I, key=%s, valuelen=%p, flag=%p) failed";
static const char short_spc301[] = "**mpi_info_set %I %s %s";
static const char long_spc301[]  = "MPI_Info_set(%I, key=%s, value=%s) failed";
static const char short_spc302[] = "**mpi_init %p %p";
static const char long_spc302[]  = "MPI_Init(argc=%p, argv=%p) failed";
static const char short_spc303[] = "**mpi_init_thread %p %p %d %p";
static const char long_spc303[]  = "MPI_Init_thread(argc=%p, argv=%p, required=%d, provided=%p) failed";
static const char short_spc304[] = "**mpi_initialized %p";
static const char long_spc304[]  = "MPI_Initialized(flag=%p) failed";
static const char short_spc305[] = "**mpi_intercomm_create %C %i %C %i %t %p";
static const char long_spc305[]  = "MPI_Intercomm_create(%C, %i, %C, %i, %t, newintercomm=%p) failed";
static const char short_spc306[] = "**mpi_intercomm_create_from_groups %G %i %G %i %s %I %E %p";
static const char long_spc306[]  = "MPI_Intercomm_create_from_groups(%G, %i, %G, %i, stringtag=%s, %I, %E, newintercomm=%p) failed";
static const char short_spc307[] = "**mpi_intercomm_merge %C %d %p";
static const char long_spc307[]  = "MPI_Intercomm_merge(%C, high=%d, newintracomm=%p) failed";
static const char short_spc308[] = "**mpi_iprobe %i %t %C %p %p";
static const char long_spc308[]  = "MPI_Iprobe(%i, %t, %C, flag=%p, status=%p) failed";
static const char short_spc309[] = "**mpi_irecv %p %d %D %i %t %C %p";
static const char long_spc309[]  = "MPI_Irecv(buf=%p, count=%d, %D, %i, %t, %C, request=%p) failed";
static const char short_spc310[] = "**mpi_irecv_c %p %c %D %i %t %C %p";
static const char long_spc310[]  = "MPI_Irecv_c(buf=%p, count=%c, %D, %i, %t, %C, request=%p) failed";
static const char short_spc311[] = "**mpi_ireduce %p %p %d %D %O %i %C %p";
static const char long_spc311[]  = "MPI_Ireduce(sendbuf=%p, recvbuf=%p, count=%d, %D, %O, %i, %C, request=%p) failed";
static const char short_spc312[] = "**mpi_ireduce_c %p %p %c %D %O %i %C %p";
static const char long_spc312[]  = "MPI_Ireduce_c(sendbuf=%p, recvbuf=%p, count=%c, %D, %O, %i, %C, request=%p) failed";
static const char short_spc313[] = "**mpi_ireduce_scatter %p %p %p %D %O %C %p";
static const char long_spc313[]  = "MPI_Ireduce_scatter(sendbuf=%p, recvbuf=%p, recvcounts=%p, %D, %O, %C, request=%p) failed";
static const char short_spc314[] = "**mpi_ireduce_scatter_block %p %p %d %D %O %C %p";
static const char long_spc314[]  = "MPI_Ireduce_scatter_block(sendbuf=%p, recvbuf=%p, recvcount=%d, %D, %O, %C, request=%p) failed";
static const char short_spc315[] = "**mpi_ireduce_scatter_block_c %p %p %c %D %O %C %p";
static const char long_spc315[]  = "MPI_Ireduce_scatter_block_c(sendbuf=%p, recvbuf=%p, recvcount=%c, %D, %O, %C, request=%p) failed";
static const char short_spc316[] = "**mpi_ireduce_scatter_c %p %p %p %D %O %C %p";
static const char long_spc316[]  = "MPI_Ireduce_scatter_c(sendbuf=%p, recvbuf=%p, recvcounts=%p, %D, %O, %C, request=%p) failed";
static const char short_spc317[] = "**mpi_irsend %p %d %D %i %t %C %p";
static const char long_spc317[]  = "MPI_Irsend(buf=%p, count=%d, %D, %i, %t, %C, request=%p) failed";
static const char short_spc318[] = "**mpi_irsend_c %p %c %D %i %t %C %p";
static const char long_spc318[]  = "MPI_Irsend_c(buf=%p, count=%c, %D, %i, %t, %C, request=%p) failed";
static const char short_spc319[] = "**mpi_is_thread_main %p";
static const char long_spc319[]  = "MPI_Is_thread_main(flag=%p) failed";
static const char short_spc320[] = "**mpi_iscan %p %p %d %D %O %C %p";
static const char long_spc320[]  = "MPI_Iscan(sendbuf=%p, recvbuf=%p, count=%d, %D, %O, %C, request=%p) failed";
static const char short_spc321[] = "**mpi_iscan_c %p %p %c %D %O %C %p";
static const char long_spc321[]  = "MPI_Iscan_c(sendbuf=%p, recvbuf=%p, count=%c, %D, %O, %C, request=%p) failed";
static const char short_spc322[] = "**mpi_iscatter %p %d %D %p %d %D %i %C %p";
static const char long_spc322[]  = "MPI_Iscatter(sendbuf=%p, sendcount=%d, %D, recvbuf=%p, recvcount=%d, %D, %i, %C, request=%p) failed";
static const char short_spc323[] = "**mpi_iscatter_c %p %c %D %p %c %D %i %C %p";
static const char long_spc323[]  = "MPI_Iscatter_c(sendbuf=%p, sendcount=%c, %D, recvbuf=%p, recvcount=%c, %D, %i, %C, request=%p) failed";
static const char short_spc324[] = "**mpi_iscatterv %p %p %p %D %p %d %D %i %C %p";
static const char long_spc324[]  = "MPI_Iscatterv(sendbuf=%p, sendcounts=%p, displs=%p, %D, recvbuf=%p, recvcount=%d, %D, %i, %C, request=%p) failed";
static const char short_spc325[] = "**mpi_iscatterv_c %p %p %p %D %p %c %D %i %C %p";
static const char long_spc325[]  = "MPI_Iscatterv_c(sendbuf=%p, sendcounts=%p, displs=%p, %D, recvbuf=%p, recvcount=%c, %D, %i, %C, request=%p) failed";
static const char short_spc326[] = "**mpi_isend %p %d %D %i %t %C %p";
static const char long_spc326[]  = "MPI_Isend(buf=%p, count=%d, %D, %i, %t, %C, request=%p) failed";
static const char short_spc327[] = "**mpi_isend_c %p %c %D %i %t %C %p";
static const char long_spc327[]  = "MPI_Isend_c(buf=%p, count=%c, %D, %i, %t, %C, request=%p) failed";
static const char short_spc328[] = "**mpi_isendrecv %p %d %D %i %t %p %d %D %i %t %C %p";
static const char long_spc328[]  = "MPI_Isendrecv(sendbuf=%p, sendcount=%d, %D, %i, %t, recvbuf=%p, recvcount=%d, %D, %i, %t, %C, request=%p) failed";
static const char short_spc329[] = "**mpi_isendrecv_c %p %c %D %i %t %p %c %D %i %t %C %p";
static const char long_spc329[]  = "MPI_Isendrecv_c(sendbuf=%p, sendcount=%c, %D, %i, %t, recvbuf=%p, recvcount=%c, %D, %i, %t, %C, request=%p) failed";
static const char short_spc330[] = "**mpi_isendrecv_replace %p %d %D %i %t %i %t %C %p";
static const char long_spc330[]  = "MPI_Isendrecv_replace(buf=%p, count=%d, %D, %i, %t, %i, %t, %C, request=%p) failed";
static const char short_spc331[] = "**mpi_isendrecv_replace_c %p %c %D %i %t %i %t %C %p";
static const char long_spc331[]  = "MPI_Isendrecv_replace_c(buf=%p, count=%c, %D, %i, %t, %i, %t, %C, request=%p) failed";
static const char short_spc332[] = "**mpi_issend %p %d %D %i %t %C %p";
static const char long_spc332[]  = "MPI_Issend(buf=%p, count=%d, %D, %i, %t, %C, request=%p) failed";
static const char short_spc333[] = "**mpi_issend_c %p %c %D %i %t %C %p";
static const char long_spc333[]  = "MPI_Issend_c(buf=%p, count=%c, %D, %i, %t, %C, request=%p) failed";
static const char short_spc334[] = "**mpi_lookup_name %s %I %p";
static const char long_spc334[]  = "MPI_Lookup_name(service_name=%s, %I, port_name=%p) failed";
static const char short_spc335[] = "**mpi_mprobe %i %t %C %p %p";
static const char long_spc335[]  = "MPI_Mprobe(%i, %t, %C, message=%p, status=%p) failed";
static const char short_spc336[] = "**mpi_mrecv %p %d %D %p %p";
static const char long_spc336[]  = "MPI_Mrecv(buf=%p, count=%d, %D, message=%p, status=%p) failed";
static const char short_spc337[] = "**mpi_mrecv_c %p %c %D %p %p";
static const char long_spc337[]  = "MPI_Mrecv_c(buf=%p, count=%c, %D, message=%p, status=%p) failed";
static const char short_spc338[] = "**mpi_neighbor_allgather %p %d %D %p %d %D %C";
static const char long_spc338[]  = "MPI_Neighbor_allgather(sendbuf=%p, sendcount=%d, %D, recvbuf=%p, recvcount=%d, %D, %C) failed";
static const char short_spc339[] = "**mpi_neighbor_allgather_c %p %c %D %p %c %D %C";
static const char long_spc339[]  = "MPI_Neighbor_allgather_c(sendbuf=%p, sendcount=%c, %D, recvbuf=%p, recvcount=%c, %D, %C) failed";
static const char short_spc340[] = "**mpi_neighbor_allgather_init %p %d %D %p %d %D %C %I %p";
static const char long_spc340[]  = "MPI_Neighbor_allgather_init(sendbuf=%p, sendcount=%d, %D, recvbuf=%p, recvcount=%d, %D, %C, %I, request=%p) failed";
static const char short_spc341[] = "**mpi_neighbor_allgather_init_c %p %c %D %p %c %D %C %I %p";
static const char long_spc341[]  = "MPI_Neighbor_allgather_init_c(sendbuf=%p, sendcount=%c, %D, recvbuf=%p, recvcount=%c, %D, %C, %I, request=%p) failed";
static const char short_spc342[] = "**mpi_neighbor_allgatherv %p %d %D %p %p %p %D %C";
static const char long_spc342[]  = "MPI_Neighbor_allgatherv(sendbuf=%p, sendcount=%d, %D, recvbuf=%p, recvcounts=%p, displs=%p, %D, %C) failed";
static const char short_spc343[] = "**mpi_neighbor_allgatherv_c %p %c %D %p %p %p %D %C";
static const char long_spc343[]  = "MPI_Neighbor_allgatherv_c(sendbuf=%p, sendcount=%c, %D, recvbuf=%p, recvcounts=%p, displs=%p, %D, %C) failed";
static const char short_spc344[] = "**mpi_neighbor_allgatherv_init %p %d %D %p %p %p %D %C %I %p";
static const char long_spc344[]  = "MPI_Neighbor_allgatherv_init(sendbuf=%p, sendcount=%d, %D, recvbuf=%p, recvcounts=%p, displs=%p, %D, %C, %I, request=%p) failed";
static const char short_spc345[] = "**mpi_neighbor_allgatherv_init_c %p %c %D %p %p %p %D %C %I %p";
static const char long_spc345[]  = "MPI_Neighbor_allgatherv_init_c(sendbuf=%p, sendcount=%c, %D, recvbuf=%p, recvcounts=%p, displs=%p, %D, %C, %I, request=%p) failed";
static const char short_spc346[] = "**mpi_neighbor_alltoall %p %d %D %p %d %D %C";
static const char long_spc346[]  = "MPI_Neighbor_alltoall(sendbuf=%p, sendcount=%d, %D, recvbuf=%p, recvcount=%d, %D, %C) failed";
static const char short_spc347[] = "**mpi_neighbor_alltoall_c %p %c %D %p %c %D %C";
static const char long_spc347[]  = "MPI_Neighbor_alltoall_c(sendbuf=%p, sendcount=%c, %D, recvbuf=%p, recvcount=%c, %D, %C) failed";
static const char short_spc348[] = "**mpi_neighbor_alltoall_init %p %d %D %p %d %D %C %I %p";
static const char long_spc348[]  = "MPI_Neighbor_alltoall_init(sendbuf=%p, sendcount=%d, %D, recvbuf=%p, recvcount=%d, %D, %C, %I, request=%p) failed";
static const char short_spc349[] = "**mpi_neighbor_alltoall_init_c %p %c %D %p %c %D %C %I %p";
static const char long_spc349[]  = "MPI_Neighbor_alltoall_init_c(sendbuf=%p, sendcount=%c, %D, recvbuf=%p, recvcount=%c, %D, %C, %I, request=%p) failed";
static const char short_spc350[] = "**mpi_neighbor_alltoallv %p %p %p %D %p %p %p %D %C";
static const char long_spc350[]  = "MPI_Neighbor_alltoallv(sendbuf=%p, sendcounts=%p, sdispls=%p, %D, recvbuf=%p, recvcounts=%p, rdispls=%p, %D, %C) failed";
static const char short_spc351[] = "**mpi_neighbor_alltoallv_c %p %p %p %D %p %p %p %D %C";
static const char long_spc351[]  = "MPI_Neighbor_alltoallv_c(sendbuf=%p, sendcounts=%p, sdispls=%p, %D, recvbuf=%p, recvcounts=%p, rdispls=%p, %D, %C) failed";
static const char short_spc352[] = "**mpi_neighbor_alltoallv_init %p %p %p %D %p %p %p %D %C %I %p";
static const char long_spc352[]  = "MPI_Neighbor_alltoallv_init(sendbuf=%p, sendcounts=%p, sdispls=%p, %D, recvbuf=%p, recvcounts=%p, rdispls=%p, %D, %C, %I, request=%p) failed";
static const char short_spc353[] = "**mpi_neighbor_alltoallv_init_c %p %p %p %D %p %p %p %D %C %I %p";
static const char long_spc353[]  = "MPI_Neighbor_alltoallv_init_c(sendbuf=%p, sendcounts=%p, sdispls=%p, %D, recvbuf=%p, recvcounts=%p, rdispls=%p, %D, %C, %I, request=%p) failed";
static const char short_spc354[] = "**mpi_neighbor_alltoallw %p %p %p %p %p %p %p %p %C";
static const char long_spc354[]  = "MPI_Neighbor_alltoallw(sendbuf=%p, sendcounts=%p, sdispls=%p, sendtypes=%p, recvbuf=%p, recvcounts=%p, rdispls=%p, recvtypes=%p, %C) failed";
static const char short_spc355[] = "**mpi_neighbor_alltoallw_c %p %p %p %p %p %p %p %p %C";
static const char long_spc355[]  = "MPI_Neighbor_alltoallw_c(sendbuf=%p, sendcounts=%p, sdispls=%p, sendtypes=%p, recvbuf=%p, recvcounts=%p, rdispls=%p, recvtypes=%p, %C) failed";
static const char short_spc356[] = "**mpi_neighbor_alltoallw_init %p %p %p %p %p %p %p %p %C %I %p";
static const char long_spc356[]  = "MPI_Neighbor_alltoallw_init(sendbuf=%p, sendcounts=%p, sdispls=%p, sendtypes=%p, recvbuf=%p, recvcounts=%p, rdispls=%p, recvtypes=%p, %C, %I, request=%p) failed";
static const char short_spc357[] = "**mpi_neighbor_alltoallw_init_c %p %p %p %p %p %p %p %p %C %I %p";
static const char long_spc357[]  = "MPI_Neighbor_alltoallw_init_c(sendbuf=%p, sendcounts=%p, sdispls=%p, sendtypes=%p, recvbuf=%p, recvcounts=%p, rdispls=%p, recvtypes=%p, %C, %I, request=%p) failed";
static const char short_spc358[] = "**mpi_op_commutative %O %p";
static const char long_spc358[]  = "MPI_Op_commutative(%O, commute=%p) failed";
static const char short_spc359[] = "**mpi_op_create %p %d %p";
static const char long_spc359[]  = "MPI_Op_create(user_fn=%p, commute=%d, op=%p) failed";
static const char short_spc360[] = "**mpi_op_create_c %p %d %p";
static const char long_spc360[]  = "MPI_Op_create_c(user_fn=%p, commute=%d, op=%p) failed";
static const char short_spc361[] = "**mpi_op_free %p";
static const char long_spc361[]  = "MPI_Op_free(op=%p) failed";
static const char short_spc362[] = "**mpi_open_port %I %p";
static const char long_spc362[]  = "MPI_Open_port(%I, port_name=%p) failed";
static const char short_spc363[] = "**mpi_pack %p %d %D %p %d %p %C";
static const char long_spc363[]  = "MPI_Pack(inbuf=%p, incount=%d, %D, outbuf=%p, outsize=%d, position=%p, %C) failed";
static const char short_spc364[] = "**mpi_pack_c %p %c %D %p %c %p %C";
static const char long_spc364[]  = "MPI_Pack_c(inbuf=%p, incount=%c, %D, outbuf=%p, outsize=%c, position=%p, %C) failed";
static const char short_spc365[] = "**mpi_pack_external %s %p %d %D %p %L %p";
static const char long_spc365[]  = "MPI_Pack_external(datarep=%s, inbuf=%p, incount=%d, %D, outbuf=%p, outsize=%L, position=%p) failed";
static const char short_spc366[] = "**mpi_pack_external_c %s %p %c %D %p %c %p";
static const char long_spc366[]  = "MPI_Pack_external_c(datarep=%s, inbuf=%p, incount=%c, %D, outbuf=%p, outsize=%c, position=%p) failed";
static const char short_spc367[] = "**mpi_pack_external_size %s %d %D %p";
static const char long_spc367[]  = "MPI_Pack_external_size(datarep=%s, incount=%d, %D, size=%p) failed";
static const char short_spc368[] = "**mpi_pack_external_size_c %s %c %D %p";
static const char long_spc368[]  = "MPI_Pack_external_size_c(datarep=%s, incount=%c, %D, size=%p) failed";
static const char short_spc369[] = "**mpi_pack_size %d %D %C %p";
static const char long_spc369[]  = "MPI_Pack_size(incount=%d, %D, %C, size=%p) failed";
static const char short_spc370[] = "**mpi_pack_size_c %c %D %C %p";
static const char long_spc370[]  = "MPI_Pack_size_c(incount=%c, %D, %C, size=%p) failed";
static const char short_spc371[] = "**mpi_parrived %R %d %p";
static const char long_spc371[]  = "MPI_Parrived(%R, partition=%d, flag=%p) failed";
static const char short_spc372[] = "**mpi_pready %d %R";
static const char long_spc372[]  = "MPI_Pready(partition=%d, %R) failed";
static const char short_spc373[] = "**mpi_pready_list %d %p %R";
static const char long_spc373[]  = "MPI_Pready_list(length=%d, array_of_partitions=%p, %R) failed";
static const char short_spc374[] = "**mpi_pready_range %d %d %R";
static const char long_spc374[]  = "MPI_Pready_range(partition_low=%d, partition_high=%d, %R) failed";
static const char short_spc375[] = "**mpi_precv_init %p %d %c %D %i %t %C %I %p";
static const char long_spc375[]  = "MPI_Precv_init(buf=%p, partitions=%d, count=%c, %D, %i, %t, %C, %I, request=%p) failed";
static const char short_spc376[] = "**mpi_probe %i %t %C %p";
static const char long_spc376[]  = "MPI_Probe(%i, %t, %C, status=%p) failed";
static const char short_spc377[] = "**mpi_psend_init %p %d %c %D %i %t %C %I %p";
static const char long_spc377[]  = "MPI_Psend_init(buf=%p, partitions=%d, count=%c, %D, %i, %t, %C, %I, request=%p) failed";
static const char short_spc378[] = "**mpi_publish_name %s %I %s";
static const char long_spc378[]  = "MPI_Publish_name(service_name=%s, %I, port_name=%s) failed";
static const char short_spc379[] = "**mpi_put %p %d %D %d %L %d %D %W";
static const char long_spc379[]  = "MPI_Put(origin_addr=%p, origin_count=%d, %D, target_rank=%d, target_disp=%L, target_count=%d, %D, %W) failed";
static const char short_spc380[] = "**mpi_put_c %p %c %D %d %L %c %D %W";
static const char long_spc380[]  = "MPI_Put_c(origin_addr=%p, origin_count=%c, %D, target_rank=%d, target_disp=%L, target_count=%c, %D, %W) failed";
static const char short_spc381[] = "**mpi_query_thread %p";
static const char long_spc381[]  = "MPI_Query_thread(provided=%p) failed";
static const char short_spc382[] = "**mpi_raccumulate %p %d %D %d %L %d %D %O %W %p";
static const char long_spc382[]  = "MPI_Raccumulate(origin_addr=%p, origin_count=%d, %D, target_rank=%d, target_disp=%L, target_count=%d, %D, %O, %W, request=%p) failed";
static const char short_spc383[] = "**mpi_raccumulate_c %p %c %D %d %L %c %D %O %W %p";
static const char long_spc383[]  = "MPI_Raccumulate_c(origin_addr=%p, origin_count=%c, %D, target_rank=%d, target_disp=%L, target_count=%c, %D, %O, %W, request=%p) failed";
static const char short_spc384[] = "**mpi_recv %p %d %D %i %t %C %p";
static const char long_spc384[]  = "MPI_Recv(buf=%p, count=%d, %D, %i, %t, %C, status=%p) failed";
static const char short_spc385[] = "**mpi_recv_c %p %c %D %i %t %C %p";
static const char long_spc385[]  = "MPI_Recv_c(buf=%p, count=%c, %D, %i, %t, %C, status=%p) failed";
static const char short_spc386[] = "**mpi_recv_init %p %d %D %i %t %C %p";
static const char long_spc386[]  = "MPI_Recv_init(buf=%p, count=%d, %D, %i, %t, %C, request=%p) failed";
static const char short_spc387[] = "**mpi_recv_init_c %p %c %D %i %t %C %p";
static const char long_spc387[]  = "MPI_Recv_init_c(buf=%p, count=%c, %D, %i, %t, %C, request=%p) failed";
static const char short_spc388[] = "**mpi_reduce %p %p %d %D %O %i %C";
static const char long_spc388[]  = "MPI_Reduce(sendbuf=%p, recvbuf=%p, count=%d, %D, %O, %i, %C) failed";
static const char short_spc389[] = "**mpi_reduce_c %p %p %c %D %O %i %C";
static const char long_spc389[]  = "MPI_Reduce_c(sendbuf=%p, recvbuf=%p, count=%c, %D, %O, %i, %C) failed";
static const char short_spc390[] = "**mpi_reduce_init %p %p %d %D %O %i %C %I %p";
static const char long_spc390[]  = "MPI_Reduce_init(sendbuf=%p, recvbuf=%p, count=%d, %D, %O, %i, %C, %I, request=%p) failed";
static const char short_spc391[] = "**mpi_reduce_init_c %p %p %c %D %O %i %C %I %p";
static const char long_spc391[]  = "MPI_Reduce_init_c(sendbuf=%p, recvbuf=%p, count=%c, %D, %O, %i, %C, %I, request=%p) failed";
static const char short_spc392[] = "**mpi_reduce_local %p %p %d %D %O";
static const char long_spc392[]  = "MPI_Reduce_local(inbuf=%p, inoutbuf=%p, count=%d, %D, %O) failed";
static const char short_spc393[] = "**mpi_reduce_local_c %p %p %c %D %O";
static const char long_spc393[]  = "MPI_Reduce_local_c(inbuf=%p, inoutbuf=%p, count=%c, %D, %O) failed";
static const char short_spc394[] = "**mpi_reduce_scatter %p %p %p %D %O %C";
static const char long_spc394[]  = "MPI_Reduce_scatter(sendbuf=%p, recvbuf=%p, recvcounts=%p, %D, %O, %C) failed";
static const char short_spc395[] = "**mpi_reduce_scatter_block %p %p %d %D %O %C";
static const char long_spc395[]  = "MPI_Reduce_scatter_block(sendbuf=%p, recvbuf=%p, recvcount=%d, %D, %O, %C) failed";
static const char short_spc396[] = "**mpi_reduce_scatter_block_c %p %p %c %D %O %C";
static const char long_spc396[]  = "MPI_Reduce_scatter_block_c(sendbuf=%p, recvbuf=%p, recvcount=%c, %D, %O, %C) failed";
static const char short_spc397[] = "**mpi_reduce_scatter_block_init %p %p %d %D %O %C %I %p";
static const char long_spc397[]  = "MPI_Reduce_scatter_block_init(sendbuf=%p, recvbuf=%p, recvcount=%d, %D, %O, %C, %I, request=%p) failed";
static const char short_spc398[] = "**mpi_reduce_scatter_block_init_c %p %p %c %D %O %C %I %p";
static const char long_spc398[]  = "MPI_Reduce_scatter_block_init_c(sendbuf=%p, recvbuf=%p, recvcount=%c, %D, %O, %C, %I, request=%p) failed";
static const char short_spc399[] = "**mpi_reduce_scatter_c %p %p %p %D %O %C";
static const char long_spc399[]  = "MPI_Reduce_scatter_c(sendbuf=%p, recvbuf=%p, recvcounts=%p, %D, %O, %C) failed";
static const char short_spc400[] = "**mpi_reduce_scatter_init %p %p %p %D %O %C %I %p";
static const char long_spc400[]  = "MPI_Reduce_scatter_init(sendbuf=%p, recvbuf=%p, recvcounts=%p, %D, %O, %C, %I, request=%p) failed";
static const char short_spc401[] = "**mpi_reduce_scatter_init_c %p %p %p %D %O %C %I %p";
static const char long_spc401[]  = "MPI_Reduce_scatter_init_c(sendbuf=%p, recvbuf=%p, recvcounts=%p, %D, %O, %C, %I, request=%p) failed";
static const char short_spc402[] = "**mpi_remove_error_class %d";
static const char long_spc402[]  = "MPI_Remove_error_class(errorclass=%d) failed";
static const char short_spc403[] = "**mpi_remove_error_code %d";
static const char long_spc403[]  = "MPI_Remove_error_code(errorcode=%d) failed";
static const char short_spc404[] = "**mpi_remove_error_string %d";
static const char long_spc404[]  = "MPI_Remove_error_string(errorcode=%d) failed";
static const char short_spc405[] = "**mpi_request_free %p";
static const char long_spc405[]  = "MPI_Request_free(request=%p) failed";
static const char short_spc406[] = "**mpi_request_get_status %R %p %p";
static const char long_spc406[]  = "MPI_Request_get_status(%R, flag=%p, status=%p) failed";
static const char short_spc407[] = "**mpi_request_get_status_all %d %p %p %p";
static const char long_spc407[]  = "MPI_Request_get_status_all(count=%d, array_of_requests=%p, flag=%p, array_of_statuses=%p) failed";
static const char short_spc408[] = "**mpi_request_get_status_any %d %p %p %p %p";
static const char long_spc408[]  = "MPI_Request_get_status_any(count=%d, array_of_requests=%p, indx=%p, flag=%p, status=%p) failed";
static const char short_spc409[] = "**mpi_request_get_status_some %d %p %p %p %p";
static const char long_spc409[]  = "MPI_Request_get_status_some(incount=%d, array_of_requests=%p, outcount=%p, array_of_indices=%p, array_of_statuses=%p) failed";
static const char short_spc410[] = "**mpi_rget %p %d %D %d %L %d %D %W %p";
static const char long_spc410[]  = "MPI_Rget(origin_addr=%p, origin_count=%d, %D, target_rank=%d, target_disp=%L, target_count=%d, %D, %W, request=%p) failed";
static const char short_spc411[] = "**mpi_rget_accumulate %p %d %D %p %d %D %d %L %d %D %O %W %p";
static const char long_spc411[]  = "MPI_Rget_accumulate(origin_addr=%p, origin_count=%d, %D, result_addr=%p, result_count=%d, %D, target_rank=%d, target_disp=%L, target_count=%d, %D, %O, %W, request=%p) failed";
static const char short_spc412[] = "**mpi_rget_accumulate_c %p %c %D %p %c %D %d %L %c %D %O %W %p";
static const char long_spc412[]  = "MPI_Rget_accumulate_c(origin_addr=%p, origin_count=%c, %D, result_addr=%p, result_count=%c, %D, target_rank=%d, target_disp=%L, target_count=%c, %D, %O, %W, request=%p) failed";
static const char short_spc413[] = "**mpi_rget_c %p %c %D %d %L %c %D %W %p";
static const char long_spc413[]  = "MPI_Rget_c(origin_addr=%p, origin_count=%c, %D, target_rank=%d, target_disp=%L, target_count=%c, %D, %W, request=%p) failed";
static const char short_spc414[] = "**mpi_rput %p %d %D %d %L %d %D %W %p";
static const char long_spc414[]  = "MPI_Rput(origin_addr=%p, origin_count=%d, %D, target_rank=%d, target_disp=%L, target_count=%d, %D, %W, request=%p) failed";
static const char short_spc415[] = "**mpi_rput_c %p %c %D %d %L %c %D %W %p";
static const char long_spc415[]  = "MPI_Rput_c(origin_addr=%p, origin_count=%c, %D, target_rank=%d, target_disp=%L, target_count=%c, %D, %W, request=%p) failed";
static const char short_spc416[] = "**mpi_rsend %p %d %D %i %t %C";
static const char long_spc416[]  = "MPI_Rsend(buf=%p, count=%d, %D, %i, %t, %C) failed";
static const char short_spc417[] = "**mpi_rsend_c %p %c %D %i %t %C";
static const char long_spc417[]  = "MPI_Rsend_c(buf=%p, count=%c, %D, %i, %t, %C) failed";
static const char short_spc418[] = "**mpi_rsend_init %p %d %D %i %t %C %p";
static const char long_spc418[]  = "MPI_Rsend_init(buf=%p, count=%d, %D, %i, %t, %C, request=%p) failed";
static const char short_spc419[] = "**mpi_rsend_init_c %p %c %D %i %t %C %p";
static const char long_spc419[]  = "MPI_Rsend_init_c(buf=%p, count=%c, %D, %i, %t, %C, request=%p) failed";
static const char short_spc420[] = "**mpi_scan %p %p %d %D %O %C";
static const char long_spc420[]  = "MPI_Scan(sendbuf=%p, recvbuf=%p, count=%d, %D, %O, %C) failed";
static const char short_spc421[] = "**mpi_scan_c %p %p %c %D %O %C";
static const char long_spc421[]  = "MPI_Scan_c(sendbuf=%p, recvbuf=%p, count=%c, %D, %O, %C) failed";
static const char short_spc422[] = "**mpi_scan_init %p %p %d %D %O %C %I %p";
static const char long_spc422[]  = "MPI_Scan_init(sendbuf=%p, recvbuf=%p, count=%d, %D, %O, %C, %I, request=%p) failed";
static const char short_spc423[] = "**mpi_scan_init_c %p %p %c %D %O %C %I %p";
static const char long_spc423[]  = "MPI_Scan_init_c(sendbuf=%p, recvbuf=%p, count=%c, %D, %O, %C, %I, request=%p) failed";
static const char short_spc424[] = "**mpi_scatter %p %d %D %p %d %D %i %C";
static const char long_spc424[]  = "MPI_Scatter(sendbuf=%p, sendcount=%d, %D, recvbuf=%p, recvcount=%d, %D, %i, %C) failed";
static const char short_spc425[] = "**mpi_scatter_c %p %c %D %p %c %D %i %C";
static const char long_spc425[]  = "MPI_Scatter_c(sendbuf=%p, sendcount=%c, %D, recvbuf=%p, recvcount=%c, %D, %i, %C) failed";
static const char short_spc426[] = "**mpi_scatter_init %p %d %D %p %d %D %i %C %I %p";
static const char long_spc426[]  = "MPI_Scatter_init(sendbuf=%p, sendcount=%d, %D, recvbuf=%p, recvcount=%d, %D, %i, %C, %I, request=%p) failed";
static const char short_spc427[] = "**mpi_scatter_init_c %p %c %D %p %c %D %i %C %I %p";
static const char long_spc427[]  = "MPI_Scatter_init_c(sendbuf=%p, sendcount=%c, %D, recvbuf=%p, recvcount=%c, %D, %i, %C, %I, request=%p) failed";
static const char short_spc428[] = "**mpi_scatterv %p %p %p %D %p %d %D %i %C";
static const char long_spc428[]  = "MPI_Scatterv(sendbuf=%p, sendcounts=%p, displs=%p, %D, recvbuf=%p, recvcount=%d, %D, %i, %C) failed";
static const char short_spc429[] = "**mpi_scatterv_c %p %p %p %D %p %c %D %i %C";
static const char long_spc429[]  = "MPI_Scatterv_c(sendbuf=%p, sendcounts=%p, displs=%p, %D, recvbuf=%p, recvcount=%c, %D, %i, %C) failed";
static const char short_spc430[] = "**mpi_scatterv_init %p %p %p %D %p %d %D %i %C %I %p";
static const char long_spc430[]  = "MPI_Scatterv_init(sendbuf=%p, sendcounts=%p, displs=%p, %D, recvbuf=%p, recvcount=%d, %D, %i, %C, %I, request=%p) failed";
static const char short_spc431[] = "**mpi_scatterv_init_c %p %p %p %D %p %c %D %i %C %I %p";
static const char long_spc431[]  = "MPI_Scatterv_init_c(sendbuf=%p, sendcounts=%p, displs=%p, %D, recvbuf=%p, recvcount=%c, %D, %i, %C, %I, request=%p) failed";
static const char short_spc432[] = "**mpi_send %p %d %D %i %t %C";
static const char long_spc432[]  = "MPI_Send(buf=%p, count=%d, %D, %i, %t, %C) failed";
static const char short_spc433[] = "**mpi_send_c %p %c %D %i %t %C";
static const char long_spc433[]  = "MPI_Send_c(buf=%p, count=%c, %D, %i, %t, %C) failed";
static const char short_spc434[] = "**mpi_send_init %p %d %D %i %t %C %p";
static const char long_spc434[]  = "MPI_Send_init(buf=%p, count=%d, %D, %i, %t, %C, request=%p) failed";
static const char short_spc435[] = "**mpi_send_init_c %p %c %D %i %t %C %p";
static const char long_spc435[]  = "MPI_Send_init_c(buf=%p, count=%c, %D, %i, %t, %C, request=%p) failed";
static const char short_spc436[] = "**mpi_sendrecv %p %d %D %i %t %p %d %D %i %t %C %p";
static const char long_spc436[]  = "MPI_Sendrecv(sendbuf=%p, sendcount=%d, %D, %i, %t, recvbuf=%p, recvcount=%d, %D, %i, %t, %C, status=%p) failed";
static const char short_spc437[] = "**mpi_sendrecv_c %p %c %D %i %t %p %c %D %i %t %C %p";
static const char long_spc437[]  = "MPI_Sendrecv_c(sendbuf=%p, sendcount=%c, %D, %i, %t, recvbuf=%p, recvcount=%c, %D, %i, %t, %C, status=%p) failed";
static const char short_spc438[] = "**mpi_sendrecv_replace %p %d %D %i %t %i %t %C %p";
static const char long_spc438[]  = "MPI_Sendrecv_replace(buf=%p, count=%d, %D, %i, %t, %i, %t, %C, status=%p) failed";
static const char short_spc439[] = "**mpi_sendrecv_replace_c %p %c %D %i %t %i %t %C %p";
static const char long_spc439[]  = "MPI_Sendrecv_replace_c(buf=%p, count=%c, %D, %i, %t, %i, %t, %C, status=%p) failed";
static const char short_spc440[] = "**mpi_session_attach_buffer %S %p %d";
static const char long_spc440[]  = "MPI_Session_attach_buffer(%S, buffer=%p, size=%d) failed";
static const char short_spc441[] = "**mpi_session_attach_buffer_c %S %p %c";
static const char long_spc441[]  = "MPI_Session_attach_buffer_c(%S, buffer=%p, size=%c) failed";
static const char short_spc442[] = "**mpi_session_call_errhandler %S %d";
static const char long_spc442[]  = "MPI_Session_call_errhandler(%S, errorcode=%d) failed";
static const char short_spc443[] = "**mpi_session_create_errhandler %p %p";
static const char long_spc443[]  = "MPI_Session_create_errhandler(session_errhandler_fn=%p, errhandler=%p) failed";
static const char short_spc444[] = "**mpi_session_detach_buffer %S %p %p";
static const char long_spc444[]  = "MPI_Session_detach_buffer(%S, buffer_addr=%p, size=%p) failed";
static const char short_spc445[] = "**mpi_session_detach_buffer_c %S %p %p";
static const char long_spc445[]  = "MPI_Session_detach_buffer_c(%S, buffer_addr=%p, size=%p) failed";
static const char short_spc446[] = "**mpi_session_finalize %p";
static const char long_spc446[]  = "MPI_Session_finalize(session=%p) failed";
static const char short_spc447[] = "**mpi_session_flush_buffer %S";
static const char long_spc447[]  = "MPI_Session_flush_buffer(%S) failed";
static const char short_spc448[] = "**mpi_session_get_errhandler %S %p";
static const char long_spc448[]  = "MPI_Session_get_errhandler(%S, errhandler=%p) failed";
static const char short_spc449[] = "**mpi_session_get_info %S %p";
static const char long_spc449[]  = "MPI_Session_get_info(%S, info_used=%p) failed";
static const char short_spc450[] = "**mpi_session_get_nth_pset %S %I %d %p %p";
static const char long_spc450[]  = "MPI_Session_get_nth_pset(%S, %I, n=%d, pset_len=%p, pset_name=%p) failed";
static const char short_spc451[] = "**mpi_session_get_num_psets %S %I %p";
static const char long_spc451[]  = "MPI_Session_get_num_psets(%S, %I, npset_names=%p) failed";
static const char short_spc452[] = "**mpi_session_get_pset_info %S %s %p";
static const char long_spc452[]  = "MPI_Session_get_pset_info(%S, pset_name=%s, info=%p) failed";
static const char short_spc453[] = "**mpi_session_iflush_buffer %S %p";
static const char long_spc453[]  = "MPI_Session_iflush_buffer(%S, request=%p) failed";
static const char short_spc454[] = "**mpi_session_init %I %E %p";
static const char long_spc454[]  = "MPI_Session_init(%I, %E, session=%p) failed";
static const char short_spc455[] = "**mpi_session_set_errhandler %S %E";
static const char long_spc455[]  = "MPI_Session_set_errhandler(%S, %E) failed";
static const char short_spc456[] = "**mpi_ssend %p %d %D %i %t %C";
static const char long_spc456[]  = "MPI_Ssend(buf=%p, count=%d, %D, %i, %t, %C) failed";
static const char short_spc457[] = "**mpi_ssend_c %p %c %D %i %t %C";
static const char long_spc457[]  = "MPI_Ssend_c(buf=%p, count=%c, %D, %i, %t, %C) failed";
static const char short_spc458[] = "**mpi_ssend_init %p %d %D %i %t %C %p";
static const char long_spc458[]  = "MPI_Ssend_init(buf=%p, count=%d, %D, %i, %t, %C, request=%p) failed";
static const char short_spc459[] = "**mpi_ssend_init_c %p %c %D %i %t %C %p";
static const char long_spc459[]  = "MPI_Ssend_init_c(buf=%p, count=%c, %D, %i, %t, %C, request=%p) failed";
static const char short_spc460[] = "**mpi_start %p";
static const char long_spc460[]  = "MPI_Start(request=%p) failed";
static const char short_spc461[] = "**mpi_startall %d %p";
static const char long_spc461[]  = "MPI_Startall(count=%d, array_of_requests=%p) failed";
static const char short_spc462[] = "**mpi_status_c2f %p %p";
static const char long_spc462[]  = "MPI_Status_c2f(c_status=%p, f_status=%p) failed";
static const char short_spc463[] = "**mpi_status_c2f08 %p %p";
static const char long_spc463[]  = "MPI_Status_c2f08(c_status=%p, f08_status=%p) failed";
static const char short_spc464[] = "**mpi_status_f082c %p %p";
static const char long_spc464[]  = "MPI_Status_f082c(f08_status=%p, c_status=%p) failed";
static const char short_spc465[] = "**mpi_status_f082f %p %p";
static const char long_spc465[]  = "MPI_Status_f082f(f08_status=%p, f_status=%p) failed";
static const char short_spc466[] = "**mpi_status_f2c %p %p";
static const char long_spc466[]  = "MPI_Status_f2c(f_status=%p, c_status=%p) failed";
static const char short_spc467[] = "**mpi_status_f2f08 %p %p";
static const char long_spc467[]  = "MPI_Status_f2f08(f_status=%p, f08_status=%p) failed";
static const char short_spc468[] = "**mpi_status_set_cancelled %p %d";
static const char long_spc468[]  = "MPI_Status_set_cancelled(status=%p, flag=%d) failed";
static const char short_spc469[] = "**mpi_status_set_elements %p %D %d";
static const char long_spc469[]  = "MPI_Status_set_elements(status=%p, %D, count=%d) failed";
static const char short_spc470[] = "**mpi_status_set_elements_c %p %D %c";
static const char long_spc470[]  = "MPI_Status_set_elements_c(status=%p, %D, count=%c) failed";
static const char short_spc471[] = "**mpi_status_set_elements_x %p %D %c";
static const char long_spc471[]  = "MPI_Status_set_elements_x(status=%p, %D, count=%c) failed";
static const char short_spc472[] = "**mpi_test %p %p %p";
static const char long_spc472[]  = "MPI_Test(request=%p, flag=%p, status=%p) failed";
static const char short_spc473[] = "**mpi_test_cancelled %p %p";
static const char long_spc473[]  = "MPI_Test_cancelled(status=%p, flag=%p) failed";
static const char short_spc474[] = "**mpi_testall %d %p %p %p";
static const char long_spc474[]  = "MPI_Testall(count=%d, array_of_requests=%p, flag=%p, array_of_statuses=%p) failed";
static const char short_spc475[] = "**mpi_testany %d %p %p %p %p";
static const char long_spc475[]  = "MPI_Testany(count=%d, array_of_requests=%p, indx=%p, flag=%p, status=%p) failed";
static const char short_spc476[] = "**mpi_testsome %d %p %p %p %p";
static const char long_spc476[]  = "MPI_Testsome(incount=%d, array_of_requests=%p, outcount=%p, array_of_indices=%p, array_of_statuses=%p) failed";
static const char short_spc477[] = "**mpi_topo_test %C %p";
static const char long_spc477[]  = "MPI_Topo_test(%C, status=%p) failed";
static const char short_spc478[] = "**mpi_type_commit %p";
static const char long_spc478[]  = "MPI_Type_commit(datatype=%p) failed";
static const char short_spc479[] = "**mpi_type_contiguous %d %D %p";
static const char long_spc479[]  = "MPI_Type_contiguous(count=%d, %D, newtype=%p) failed";
static const char short_spc480[] = "**mpi_type_contiguous_c %c %D %p";
static const char long_spc480[]  = "MPI_Type_contiguous_c(count=%c, %D, newtype=%p) failed";
static const char short_spc481[] = "**mpi_type_create_darray %d %d %d %p %p %p %p %d %D %p";
static const char long_spc481[]  = "MPI_Type_create_darray(size=%d, rank=%d, ndims=%d, array_of_gsizes=%p, array_of_distribs=%p, array_of_dargs=%p, array_of_psizes=%p, order=%d, %D, newtype=%p) failed";
static const char short_spc482[] = "**mpi_type_create_darray_c %d %d %d %p %p %p %p %d %D %p";
static const char long_spc482[]  = "MPI_Type_create_darray_c(size=%d, rank=%d, ndims=%d, array_of_gsizes=%p, array_of_distribs=%p, array_of_dargs=%p, array_of_psizes=%p, order=%d, %D, newtype=%p) failed";
static const char short_spc483[] = "**mpi_type_create_f90_complex %d %d %p";
static const char long_spc483[]  = "MPI_Type_create_f90_complex(p=%d, r=%d, newtype=%p) failed";
static const char short_spc484[] = "**mpi_type_create_f90_integer %d %p";
static const char long_spc484[]  = "MPI_Type_create_f90_integer(r=%d, newtype=%p) failed";
static const char short_spc485[] = "**mpi_type_create_f90_real %d %d %p";
static const char long_spc485[]  = "MPI_Type_create_f90_real(p=%d, r=%d, newtype=%p) failed";
static const char short_spc486[] = "**mpi_type_create_hindexed %d %p %p %D %p";
static const char long_spc486[]  = "MPI_Type_create_hindexed(count=%d, array_of_blocklengths=%p, array_of_displacements=%p, %D, newtype=%p) failed";
static const char short_spc487[] = "**mpi_type_create_hindexed_block %d %d %p %D %p";
static const char long_spc487[]  = "MPI_Type_create_hindexed_block(count=%d, blocklength=%d, array_of_displacements=%p, %D, newtype=%p) failed";
static const char short_spc488[] = "**mpi_type_create_hindexed_block_c %c %c %p %D %p";
static const char long_spc488[]  = "MPI_Type_create_hindexed_block_c(count=%c, blocklength=%c, array_of_displacements=%p, %D, newtype=%p) failed";
static const char short_spc489[] = "**mpi_type_create_hindexed_c %c %p %p %D %p";
static const char long_spc489[]  = "MPI_Type_create_hindexed_c(count=%c, array_of_blocklengths=%p, array_of_displacements=%p, %D, newtype=%p) failed";
static const char short_spc490[] = "**mpi_type_create_hvector %d %d %L %D %p";
static const char long_spc490[]  = "MPI_Type_create_hvector(count=%d, blocklength=%d, stride=%L, %D, newtype=%p) failed";
static const char short_spc491[] = "**mpi_type_create_hvector_c %c %c %c %D %p";
static const char long_spc491[]  = "MPI_Type_create_hvector_c(count=%c, blocklength=%c, stride=%c, %D, newtype=%p) failed";
static const char short_spc492[] = "**mpi_type_create_indexed_block %d %d %p %D %p";
static const char long_spc492[]  = "MPI_Type_create_indexed_block(count=%d, blocklength=%d, array_of_displacements=%p, %D, newtype=%p) failed";
static const char short_spc493[] = "**mpi_type_create_indexed_block_c %c %c %p %D %p";
static const char long_spc493[]  = "MPI_Type_create_indexed_block_c(count=%c, blocklength=%c, array_of_displacements=%p, %D, newtype=%p) failed";
static const char short_spc494[] = "**mpi_type_create_keyval %p %p %p %p";
static const char long_spc494[]  = "MPI_Type_create_keyval(type_copy_attr_fn=%p, type_delete_attr_fn=%p, type_keyval=%p, extra_state=%p) failed";
static const char short_spc495[] = "**mpi_type_create_resized %D %L %L %p";
static const char long_spc495[]  = "MPI_Type_create_resized(%D, lb=%L, extent=%L, newtype=%p) failed";
static const char short_spc496[] = "**mpi_type_create_resized_c %D %c %c %p";
static const char long_spc496[]  = "MPI_Type_create_resized_c(%D, lb=%c, extent=%c, newtype=%p) failed";
static const char short_spc497[] = "**mpi_type_create_struct %d %p %p %p %p";
static const char long_spc497[]  = "MPI_Type_create_struct(count=%d, array_of_blocklengths=%p, array_of_displacements=%p, array_of_types=%p, newtype=%p) failed";
static const char short_spc498[] = "**mpi_type_create_struct_c %c %p %p %p %p";
static const char long_spc498[]  = "MPI_Type_create_struct_c(count=%c, array_of_blocklengths=%p, array_of_displacements=%p, array_of_types=%p, newtype=%p) failed";
static const char short_spc499[] = "**mpi_type_create_subarray %d %p %p %p %d %D %p";
static const char long_spc499[]  = "MPI_Type_create_subarray(ndims=%d, array_of_sizes=%p, array_of_subsizes=%p, array_of_starts=%p, order=%d, %D, newtype=%p) failed";
static const char short_spc500[] = "**mpi_type_create_subarray_c %d %p %p %p %d %D %p";
static const char long_spc500[]  = "MPI_Type_create_subarray_c(ndims=%d, array_of_sizes=%p, array_of_subsizes=%p, array_of_starts=%p, order=%d, %D, newtype=%p) failed";
static const char short_spc501[] = "**mpi_type_delete_attr %D %K";
static const char long_spc501[]  = "MPI_Type_delete_attr(%D, %K) failed";
static const char short_spc502[] = "**mpi_type_dup %D %p";
static const char long_spc502[]  = "MPI_Type_dup(%D, newtype=%p) failed";
static const char short_spc503[] = "**mpi_type_extent %D %p";
static const char long_spc503[]  = "MPI_Type_extent(%D, extent=%p) failed";
static const char short_spc504[] = "**mpi_type_free %p";
static const char long_spc504[]  = "MPI_Type_free(datatype=%p) failed";
static const char short_spc505[] = "**mpi_type_free_keyval %p";
static const char long_spc505[]  = "MPI_Type_free_keyval(type_keyval=%p) failed";
static const char short_spc506[] = "**mpi_type_get_attr %D %K %p %p";
static const char long_spc506[]  = "MPI_Type_get_attr(%D, %K, attribute_val=%p, flag=%p) failed";
static const char short_spc507[] = "**mpi_type_get_contents %D %d %d %d %p %p %p";
static const char long_spc507[]  = "MPI_Type_get_contents(%D, max_integers=%d, max_addresses=%d, max_datatypes=%d, array_of_integers=%p, array_of_addresses=%p, array_of_datatypes=%p) failed";
static const char short_spc508[] = "**mpi_type_get_contents_c %D %c %c %c %c %p %p %p %p";
static const char long_spc508[]  = "MPI_Type_get_contents_c(%D, max_integers=%c, max_addresses=%c, max_large_counts=%c, max_datatypes=%c, array_of_integers=%p, array_of_addresses=%p, array_of_large_counts=%p, array_of_datatypes=%p) failed";
static const char short_spc509[] = "**mpi_type_get_envelope %D %p %p %p %p";
static const char long_spc509[]  = "MPI_Type_get_envelope(%D, num_integers=%p, num_addresses=%p, num_datatypes=%p, combiner=%p) failed";
static const char short_spc510[] = "**mpi_type_get_envelope_c %D %p %p %p %p %p";
static const char long_spc510[]  = "MPI_Type_get_envelope_c(%D, num_integers=%p, num_addresses=%p, num_large_counts=%p, num_datatypes=%p, combiner=%p) failed";
static const char short_spc511[] = "**mpi_type_get_extent %D %p %p";
static const char long_spc511[]  = "MPI_Type_get_extent(%D, lb=%p, extent=%p) failed";
static const char short_spc512[] = "**mpi_type_get_extent_c %D %p %p";
static const char long_spc512[]  = "MPI_Type_get_extent_c(%D, lb=%p, extent=%p) failed";
static const char short_spc513[] = "**mpi_type_get_extent_x %D %p %p";
static const char long_spc513[]  = "MPI_Type_get_extent_x(%D, lb=%p, extent=%p) failed";
static const char short_spc514[] = "**mpi_type_get_name %D %p %p";
static const char long_spc514[]  = "MPI_Type_get_name(%D, type_name=%p, resultlen=%p) failed";
static const char short_spc515[] = "**mpi_type_get_true_extent %D %p %p";
static const char long_spc515[]  = "MPI_Type_get_true_extent(%D, true_lb=%p, true_extent=%p) failed";
static const char short_spc516[] = "**mpi_type_get_true_extent_c %D %p %p";
static const char long_spc516[]  = "MPI_Type_get_true_extent_c(%D, true_lb=%p, true_extent=%p) failed";
static const char short_spc517[] = "**mpi_type_get_true_extent_x %D %p %p";
static const char long_spc517[]  = "MPI_Type_get_true_extent_x(%D, true_lb=%p, true_extent=%p) failed";
static const char short_spc518[] = "**mpi_type_get_value_index %D %D %p";
static const char long_spc518[]  = "MPI_Type_get_value_index(%D, %D, pair_type=%p) failed";
static const char short_spc519[] = "**mpi_type_indexed %d %p %p %D %p";
static const char long_spc519[]  = "MPI_Type_indexed(count=%d, array_of_blocklengths=%p, array_of_displacements=%p, %D, newtype=%p) failed";
static const char short_spc520[] = "**mpi_type_indexed_c %c %p %p %D %p";
static const char long_spc520[]  = "MPI_Type_indexed_c(count=%c, array_of_blocklengths=%p, array_of_displacements=%p, %D, newtype=%p) failed";
static const char short_spc521[] = "**mpi_type_lb %D %p";
static const char long_spc521[]  = "MPI_Type_lb(%D, displacement=%p) failed";
static const char short_spc522[] = "**mpi_type_match_size %d %d %p";
static const char long_spc522[]  = "MPI_Type_match_size(typeclass=%d, size=%d, datatype=%p) failed";
static const char short_spc523[] = "**mpi_type_set_attr %D %K %p";
static const char long_spc523[]  = "MPI_Type_set_attr(%D, %K, attribute_val=%p) failed";
static const char short_spc524[] = "**mpi_type_set_name %D %s";
static const char long_spc524[]  = "MPI_Type_set_name(%D, type_name=%s) failed";
static const char short_spc525[] = "**mpi_type_size %D %p";
static const char long_spc525[]  = "MPI_Type_size(%D, size=%p) failed";
static const char short_spc526[] = "**mpi_type_size_c %D %p";
static const char long_spc526[]  = "MPI_Type_size_c(%D, size=%p) failed";
static const char short_spc527[] = "**mpi_type_size_x %D %p";
static const char long_spc527[]  = "MPI_Type_size_x(%D, size=%p) failed";
static const char short_spc528[] = "**mpi_type_ub %D %p";
static const char long_spc528[]  = "MPI_Type_ub(%D, displacement=%p) failed";
static const char short_spc529[] = "**mpi_type_vector %d %d %d %D %p";
static const char long_spc529[]  = "MPI_Type_vector(count=%d, blocklength=%d, stride=%d, %D, newtype=%p) failed";
static const char short_spc530[] = "**mpi_type_vector_c %c %c %c %D %p";
static const char long_spc530[]  = "MPI_Type_vector_c(count=%c, blocklength=%c, stride=%c, %D, newtype=%p) failed";
static const char short_spc531[] = "**mpi_unpack %p %d %p %p %d %D %C";
static const char long_spc531[]  = "MPI_Unpack(inbuf=%p, insize=%d, position=%p, outbuf=%p, outcount=%d, %D, %C) failed";
static const char short_spc532[] = "**mpi_unpack_c %p %c %p %p %c %D %C";
static const char long_spc532[]  = "MPI_Unpack_c(inbuf=%p, insize=%c, position=%p, outbuf=%p, outcount=%c, %D, %C) failed";
static const char short_spc533[] = "**mpi_unpack_external %s %p %L %p %p %d %D";
static const char long_spc533[]  = "MPI_Unpack_external(datarep=%s, inbuf=%p, insize=%L, position=%p, outbuf=%p, outcount=%d, %D) failed";
static const char short_spc534[] = "**mpi_unpack_external_c %s %p %c %p %p %c %D";
static const char long_spc534[]  = "MPI_Unpack_external_c(datarep=%s, inbuf=%p, insize=%c, position=%p, outbuf=%p, outcount=%c, %D) failed";
static const char short_spc535[] = "**mpi_unpublish_name %s %I %s";
static const char long_spc535[]  = "MPI_Unpublish_name(service_name=%s, %I, port_name=%s) failed";
static const char short_spc536[] = "**mpi_wait %p %p";
static const char long_spc536[]  = "MPI_Wait(request=%p, status=%p) failed";
static const char short_spc537[] = "**mpi_waitall %d %p %p";
static const char long_spc537[]  = "MPI_Waitall(count=%d, array_of_requests=%p, array_of_statuses=%p) failed";
static const char short_spc538[] = "**mpi_waitany %d %p %p %p";
static const char long_spc538[]  = "MPI_Waitany(count=%d, array_of_requests=%p, indx=%p, status=%p) failed";
static const char short_spc539[] = "**mpi_waitsome %d %p %p %p %p";
static const char long_spc539[]  = "MPI_Waitsome(incount=%d, array_of_requests=%p, outcount=%p, array_of_indices=%p, array_of_statuses=%p) failed";
static const char short_spc540[] = "**mpi_win_allocate %L %d %I %C %p %p";
static const char long_spc540[]  = "MPI_Win_allocate(size=%L, disp_unit=%d, %I, %C, baseptr=%p, win=%p) failed";
static const char short_spc541[] = "**mpi_win_allocate_c %L %L %I %C %p %p";
static const char long_spc541[]  = "MPI_Win_allocate_c(size=%L, disp_unit=%L, %I, %C, baseptr=%p, win=%p) failed";
static const char short_spc542[] = "**mpi_win_allocate_shared %L %d %I %C %p %p";
static const char long_spc542[]  = "MPI_Win_allocate_shared(size=%L, disp_unit=%d, %I, %C, baseptr=%p, win=%p) failed";
static const char short_spc543[] = "**mpi_win_allocate_shared_c %L %L %I %C %p %p";
static const char long_spc543[]  = "MPI_Win_allocate_shared_c(size=%L, disp_unit=%L, %I, %C, baseptr=%p, win=%p) failed";
static const char short_spc544[] = "**mpi_win_attach %W %p %L";
static const char long_spc544[]  = "MPI_Win_attach(%W, base=%p, size=%L) failed";
static const char short_spc545[] = "**mpi_win_call_errhandler %W %d";
static const char long_spc545[]  = "MPI_Win_call_errhandler(%W, errorcode=%d) failed";
static const char short_spc546[] = "**mpi_win_complete %W";
static const char long_spc546[]  = "MPI_Win_complete(%W) failed";
static const char short_spc547[] = "**mpi_win_create %p %L %d %I %C %p";
static const char long_spc547[]  = "MPI_Win_create(base=%p, size=%L, disp_unit=%d, %I, %C, win=%p) failed";
static const char short_spc548[] = "**mpi_win_create_c %p %L %L %I %C %p";
static const char long_spc548[]  = "MPI_Win_create_c(base=%p, size=%L, disp_unit=%L, %I, %C, win=%p) failed";
static const char short_spc549[] = "**mpi_win_create_dynamic %I %C %p";
static const char long_spc549[]  = "MPI_Win_create_dynamic(%I, %C, win=%p) failed";
static const char short_spc550[] = "**mpi_win_create_errhandler %p %p";
static const char long_spc550[]  = "MPI_Win_create_errhandler(win_errhandler_fn=%p, errhandler=%p) failed";
static const char short_spc551[] = "**mpi_win_create_keyval %p %p %p %p";
static const char long_spc551[]  = "MPI_Win_create_keyval(win_copy_attr_fn=%p, win_delete_attr_fn=%p, win_keyval=%p, extra_state=%p) failed";
static const char short_spc552[] = "**mpi_win_delete_attr %W %K";
static const char long_spc552[]  = "MPI_Win_delete_attr(%W, %K) failed";
static const char short_spc553[] = "**mpi_win_detach %W %p";
static const char long_spc553[]  = "MPI_Win_detach(%W, base=%p) failed";
static const char short_spc554[] = "**mpi_win_fence %A %W";
static const char long_spc554[]  = "MPI_Win_fence(%A, %W) failed";
static const char short_spc555[] = "**mpi_win_flush %d %W";
static const char long_spc555[]  = "MPI_Win_flush(rank=%d, %W) failed";
static const char short_spc556[] = "**mpi_win_flush_all %W";
static const char long_spc556[]  = "MPI_Win_flush_all(%W) failed";
static const char short_spc557[] = "**mpi_win_flush_local %d %W";
static const char long_spc557[]  = "MPI_Win_flush_local(rank=%d, %W) failed";
static const char short_spc558[] = "**mpi_win_flush_local_all %W";
static const char long_spc558[]  = "MPI_Win_flush_local_all(%W) failed";
static const char short_spc559[] = "**mpi_win_free %p";
static const char long_spc559[]  = "MPI_Win_free(win=%p) failed";
static const char short_spc560[] = "**mpi_win_free_keyval %p";
static const char long_spc560[]  = "MPI_Win_free_keyval(win_keyval=%p) failed";
static const char short_spc561[] = "**mpi_win_get_attr %W %K %p %p";
static const char long_spc561[]  = "MPI_Win_get_attr(%W, %K, attribute_val=%p, flag=%p) failed";
static const char short_spc562[] = "**mpi_win_get_errhandler %W %p";
static const char long_spc562[]  = "MPI_Win_get_errhandler(%W, errhandler=%p) failed";
static const char short_spc563[] = "**mpi_win_get_group %W %p";
static const char long_spc563[]  = "MPI_Win_get_group(%W, group=%p) failed";
static const char short_spc564[] = "**mpi_win_get_info %W %p";
static const char long_spc564[]  = "MPI_Win_get_info(%W, info_used=%p) failed";
static const char short_spc565[] = "**mpi_win_get_name %W %p %p";
static const char long_spc565[]  = "MPI_Win_get_name(%W, win_name=%p, resultlen=%p) failed";
static const char short_spc566[] = "**mpi_win_lock %d %d %A %W";
static const char long_spc566[]  = "MPI_Win_lock(lock_type=%d, rank=%d, %A, %W) failed";
static const char short_spc567[] = "**mpi_win_lock_all %A %W";
static const char long_spc567[]  = "MPI_Win_lock_all(%A, %W) failed";
static const char short_spc568[] = "**mpi_win_post %G %A %W";
static const char long_spc568[]  = "MPI_Win_post(%G, %A, %W) failed";
static const char short_spc569[] = "**mpi_win_set_attr %W %K %p";
static const char long_spc569[]  = "MPI_Win_set_attr(%W, %K, attribute_val=%p) failed";
static const char short_spc570[] = "**mpi_win_set_errhandler %W %E";
static const char long_spc570[]  = "MPI_Win_set_errhandler(%W, %E) failed";
static const char short_spc571[] = "**mpi_win_set_info %W %I";
static const char long_spc571[]  = "MPI_Win_set_info(%W, %I) failed";
static const char short_spc572[] = "**mpi_win_set_name %W %s";
static const char long_spc572[]  = "MPI_Win_set_name(%W, win_name=%s) failed";
static const char short_spc573[] = "**mpi_win_shared_query %W %d %p %p %p";
static const char long_spc573[]  = "MPI_Win_shared_query(%W, rank=%d, size=%p, disp_unit=%p, baseptr=%p) failed";
static const char short_spc574[] = "**mpi_win_shared_query_c %W %d %p %p %p";
static const char long_spc574[]  = "MPI_Win_shared_query_c(%W, rank=%d, size=%p, disp_unit=%p, baseptr=%p) failed";
static const char short_spc575[] = "**mpi_win_start %G %A %W";
static const char long_spc575[]  = "MPI_Win_start(%G, %A, %W) failed";
static const char short_spc576[] = "**mpi_win_sync %W";
static const char long_spc576[]  = "MPI_Win_sync(%W) failed";
static const char short_spc577[] = "**mpi_win_test %W %p";
static const char long_spc577[]  = "MPI_Win_test(%W, flag=%p) failed";
static const char short_spc578[] = "**mpi_win_unlock %d %W";
static const char long_spc578[]  = "MPI_Win_unlock(rank=%d, %W) failed";
static const char short_spc579[] = "**mpi_win_unlock_all %W";
static const char long_spc579[]  = "MPI_Win_unlock_all(%W) failed";
static const char short_spc580[] = "**mpi_win_wait %W";
static const char long_spc580[]  = "MPI_Win_wait(%W) failed";
static const char short_spc581[] = "**mpix_allreduce_enqueue %p %p %d %D %O %C";
static const char long_spc581[]  = "MPIX_Allreduce_enqueue(sendbuf=%p, recvbuf=%p, count=%d, %D, %O, %C) failed";
static const char short_spc582[] = "**mpix_allreduce_enqueue_c %p %p %c %D %O %C";
static const char long_spc582[]  = "MPIX_Allreduce_enqueue_c(sendbuf=%p, recvbuf=%p, count=%c, %D, %O, %C) failed";
static const char short_spc583[] = "**mpix_async_spawn %p %p %p %x";
static const char long_spc583[]  = "MPIX_Async_spawn(async_thing=%p, poll_fn=%p, extra_state=%p, %x) failed";
static const char short_spc584[] = "**mpix_async_start %p %p %x";
static const char long_spc584[]  = "MPIX_Async_start(poll_fn=%p, extra_state=%p, %x) failed";
static const char short_spc585[] = "**mpix_comm_agree %C %p";
static const char long_spc585[]  = "MPIX_Comm_agree(%C, flag=%p) failed";
static const char short_spc586[] = "**mpix_comm_create_errhandler_x %p %p %p %p";
static const char long_spc586[]  = "MPIX_Comm_create_errhandler_x(comm_errhandler_fn_x=%p, destructor_fn=%p, extra_state=%p, errhandler=%p) failed";
static const char short_spc587[] = "**mpix_comm_failure_ack %C";
static const char long_spc587[]  = "MPIX_Comm_failure_ack(%C) failed";
static const char short_spc588[] = "**mpix_comm_failure_get_acked %C %p";
static const char long_spc588[]  = "MPIX_Comm_failure_get_acked(%C, failedgrp=%p) failed";
static const char short_spc589[] = "**mpix_comm_get_failed %C %p";
static const char long_spc589[]  = "MPIX_Comm_get_failed(%C, failedgrp=%p) failed";
static const char short_spc590[] = "**mpix_comm_get_stream %C %d %p";
static const char long_spc590[]  = "MPIX_Comm_get_stream(%C, idx=%d, stream=%p) failed";
static const char short_spc591[] = "**mpix_comm_revoke %C";
static const char long_spc591[]  = "MPIX_Comm_revoke(%C) failed";
static const char short_spc592[] = "**mpix_comm_shrink %C %p";
static const char long_spc592[]  = "MPIX_Comm_shrink(%C, newcomm=%p) failed";
static const char short_spc593[] = "**mpix_comm_test_threadcomm %C %p";
static const char long_spc593[]  = "MPIX_Comm_test_threadcomm(%C, flag=%p) failed";
static const char short_spc594[] = "**mpix_file_create_errhandler_x %p %p %p %p";
static const char long_spc594[]  = "MPIX_File_create_errhandler_x(comm_errhandler_fn_x=%p, destructor_fn=%p, extra_state=%p, errhandler=%p) failed";
static const char short_spc595[] = "**mpix_gpu_query_support %d %p";
static const char long_spc595[]  = "MPIX_GPU_query_support(gpu_type=%d, is_supported=%p) failed";
static const char short_spc596[] = "**mpix_grequest_class_allocate %x %p %p";
static const char long_spc596[]  = "MPIX_Grequest_class_allocate(%x, extra_state=%p, request=%p) failed";
static const char short_spc597[] = "**mpix_grequest_class_create %p %p %p %p %p %p";
static const char long_spc597[]  = "MPIX_Grequest_class_create(query_fn=%p, free_fn=%p, cancel_fn=%p, poll_fn=%p, wait_fn=%p, greq_class=%p) failed";
static const char short_spc598[] = "**mpix_grequest_start %p %p %p %p %p %p %p";
static const char long_spc598[]  = "MPIX_Grequest_start(query_fn=%p, free_fn=%p, cancel_fn=%p, poll_fn=%p, wait_fn=%p, extra_state=%p, request=%p) failed";
static const char short_spc599[] = "**mpix_info_set_hex %I %s %p %d";
static const char long_spc599[]  = "MPIX_Info_set_hex(%I, key=%s, value=%p, value_size=%d) failed";
static const char short_spc600[] = "**mpix_irecv_enqueue %p %d %D %i %t %C %p";
static const char long_spc600[]  = "MPIX_Irecv_enqueue(buf=%p, count=%d, %D, %i, %t, %C, request=%p) failed";
static const char short_spc601[] = "**mpix_irecv_enqueue_c %p %c %D %i %t %C %p";
static const char long_spc601[]  = "MPIX_Irecv_enqueue_c(buf=%p, count=%c, %D, %i, %t, %C, request=%p) failed";
static const char short_spc602[] = "**mpix_isend_enqueue %p %d %D %i %t %C %p";
static const char long_spc602[]  = "MPIX_Isend_enqueue(buf=%p, count=%d, %D, %i, %t, %C, request=%p) failed";
static const char short_spc603[] = "**mpix_isend_enqueue_c %p %c %D %i %t %C %p";
static const char long_spc603[]  = "MPIX_Isend_enqueue_c(buf=%p, count=%c, %D, %i, %t, %C, request=%p) failed";
static const char short_spc604[] = "**mpix_op_create_x %p %p %d %p %p";
static const char long_spc604[]  = "MPIX_Op_create_x(user_fn_x=%p, destructor_fn=%p, commute=%d, extra_state=%p, op=%p) failed";
static const char short_spc605[] = "**mpix_recv_enqueue %p %d %D %i %t %C %p";
static const char long_spc605[]  = "MPIX_Recv_enqueue(buf=%p, count=%d, %D, %i, %t, %C, status=%p) failed";
static const char short_spc606[] = "**mpix_recv_enqueue_c %p %c %D %i %t %C %p";
static const char long_spc606[]  = "MPIX_Recv_enqueue_c(buf=%p, count=%c, %D, %i, %t, %C, status=%p) failed";
static const char short_spc607[] = "**mpix_send_enqueue %p %d %D %i %t %C";
static const char long_spc607[]  = "MPIX_Send_enqueue(buf=%p, count=%d, %D, %i, %t, %C) failed";
static const char short_spc608[] = "**mpix_send_enqueue_c %p %c %D %i %t %C";
static const char long_spc608[]  = "MPIX_Send_enqueue_c(buf=%p, count=%c, %D, %i, %t, %C) failed";
static const char short_spc609[] = "**mpix_session_create_errhandler_x %p %p %p %p";
static const char long_spc609[]  = "MPIX_Session_create_errhandler_x(comm_errhandler_fn_x=%p, destructor_fn=%p, extra_state=%p, errhandler=%p) failed";
static const char short_spc610[] = "**mpix_start_progress_thread %x";
static const char long_spc610[]  = "MPIX_Start_progress_thread(%x) failed";
static const char short_spc611[] = "**mpix_stop_progress_thread %x";
static const char long_spc611[]  = "MPIX_Stop_progress_thread(%x) failed";
static const char short_spc612[] = "**mpix_stream_comm_create %C %x %p";
static const char long_spc612[]  = "MPIX_Stream_comm_create(%C, %x, newcomm=%p) failed";
static const char short_spc613[] = "**mpix_stream_comm_create_multiplex %C %d %p %p";
static const char long_spc613[]  = "MPIX_Stream_comm_create_multiplex(%C, count=%d, array_of_streams=%p, newcomm=%p) failed";
static const char short_spc614[] = "**mpix_stream_create %I %p";
static const char long_spc614[]  = "MPIX_Stream_create(%I, stream=%p) failed";
static const char short_spc615[] = "**mpix_stream_free %p";
static const char long_spc615[]  = "MPIX_Stream_free(stream=%p) failed";
static const char short_spc616[] = "**mpix_stream_irecv %p %d %D %i %t %C %d %d %p";
static const char long_spc616[]  = "MPIX_Stream_irecv(buf=%p, count=%d, %D, %i, %t, %C, source_stream_index=%d, dest_stream_index=%d, request=%p) failed";
static const char short_spc617[] = "**mpix_stream_irecv_c %p %c %D %i %t %C %d %d %p";
static const char long_spc617[]  = "MPIX_Stream_irecv_c(buf=%p, count=%c, %D, %i, %t, %C, source_stream_index=%d, dest_stream_index=%d, request=%p) failed";
static const char short_spc618[] = "**mpix_stream_isend %p %d %D %i %t %C %d %d %p";
static const char long_spc618[]  = "MPIX_Stream_isend(buf=%p, count=%d, %D, %i, %t, %C, source_stream_index=%d, dest_stream_index=%d, request=%p) failed";
static const char short_spc619[] = "**mpix_stream_isend_c %p %c %D %i %t %C %d %d %p";
static const char long_spc619[]  = "MPIX_Stream_isend_c(buf=%p, count=%c, %D, %i, %t, %C, source_stream_index=%d, dest_stream_index=%d, request=%p) failed";
static const char short_spc620[] = "**mpix_stream_progress %x";
static const char long_spc620[]  = "MPIX_Stream_progress(%x) failed";
static const char short_spc621[] = "**mpix_stream_recv %p %d %D %i %t %C %d %d %p";
static const char long_spc621[]  = "MPIX_Stream_recv(buf=%p, count=%d, %D, %i, %t, %C, source_stream_index=%d, dest_stream_index=%d, status=%p) failed";
static const char short_spc622[] = "**mpix_stream_recv_c %p %c %D %i %t %C %d %d %p";
static const char long_spc622[]  = "MPIX_Stream_recv_c(buf=%p, count=%c, %D, %i, %t, %C, source_stream_index=%d, dest_stream_index=%d, status=%p) failed";
static const char short_spc623[] = "**mpix_stream_send %p %d %D %i %t %C %d %d";
static const char long_spc623[]  = "MPIX_Stream_send(buf=%p, count=%d, %D, %i, %t, %C, source_stream_index=%d, dest_stream_index=%d) failed";
static const char short_spc624[] = "**mpix_stream_send_c %p %c %D %i %t %C %d %d";
static const char long_spc624[]  = "MPIX_Stream_send_c(buf=%p, count=%c, %D, %i, %t, %C, source_stream_index=%d, dest_stream_index=%d) failed";
static const char short_spc625[] = "**mpix_threadcomm_finish %C";
static const char long_spc625[]  = "MPIX_Threadcomm_finish(%C) failed";
static const char short_spc626[] = "**mpix_threadcomm_free %p";
static const char long_spc626[]  = "MPIX_Threadcomm_free(threadcomm=%p) failed";
static const char short_spc627[] = "**mpix_threadcomm_init %C %d %p";
static const char long_spc627[]  = "MPIX_Threadcomm_init(%C, num_threads=%d, newthreadcomm=%p) failed";
static const char short_spc628[] = "**mpix_threadcomm_start %C";
static const char long_spc628[]  = "MPIX_Threadcomm_start(%C) failed";
static const char short_spc629[] = "**mpix_type_iov %D %c %p %c %p";
static const char long_spc629[]  = "MPIX_Type_iov(%D, iov_offset=%c, iov=%p, max_iov_len=%c, actual_iov_len=%p) failed";
static const char short_spc630[] = "**mpix_type_iov_len %D %c %p %p";
static const char long_spc630[]  = "MPIX_Type_iov_len(%D, max_iov_bytes=%c, iov_len=%p, actual_iov_bytes=%p) failed";
static const char short_spc631[] = "**mpix_wait_enqueue %p %p";
static const char long_spc631[]  = "MPIX_Wait_enqueue(request=%p, status=%p) failed";
static const char short_spc632[] = "**mpix_waitall_enqueue %d %p %p";
static const char long_spc632[]  = "MPIX_Waitall_enqueue(count=%d, array_of_requests=%p, array_of_statuses=%p) failed";
static const char short_spc633[] = "**mpix_win_create_errhandler_x %p %p %p %p";
static const char long_spc633[]  = "MPIX_Win_create_errhandler_x(comm_errhandler_fn_x=%p, destructor_fn=%p, extra_state=%p, errhandler=%p) failed";
static const char short_spc634[] = "**namepubfile %s %s %s";
static const char long_spc634[]  = "Unable to publish service name %s using file %s for reason %s";
static const char short_spc635[] = "**namepubnotfound %s";
static const char long_spc635[]  = "Lookup failed for service name %s";
static const char short_spc636[] = "**namepubnotpub %s";
static const char long_spc636[]  = "Publish failed for service name %s";
static const char short_spc637[] = "**nomem %d";
static const char long_spc637[]  = "Out of memory (unable to allocate %d bytes)";
static const char short_spc638[] = "**nomem %s";
static const char long_spc638[]  = "Out of memory (unable to allocate a '%s')";
static const char short_spc639[] = "**nomem %s %d";
static const char long_spc639[]  = "Out of memory (unable to allocate a '%s' of size %d)";
static const char short_spc640[] = "**nomem2 %d %s";
static const char long_spc640[]  = "Unable to allocate %d bytes of memory for %s (probably out of memory)";
static const char short_spc641[] = "**nomemuereq %d";
static const char long_spc641[]  = "Failed to allocate memory for an unexpected message. %d unexpected messages queued.";
static const char short_spc642[] = "**notimpl %s";
static const char long_spc642[]  = "Function %s not implemented";
static const char short_spc643[] = "**notsame %s %s";
static const char long_spc643[]  = "Inconsistent arguments %s to collective routine %s";
static const char short_spc644[] = "**nullptr %s";
static const char long_spc644[]  = "Null pointer in parameter %s";
static const char short_spc645[] = "**nullptrtype %s";
static const char long_spc645[]  = "Null %s pointer";
static const char short_spc646[] = "**ofid_atomicto %s %s";
static const char long_spc646[]  = "OFI call atomicto failed (default nic=%s: %s)";
static const char short_spc647[] = "**ofid_avclose %s %s";
static const char long_spc647[]  = "OFI call avclose failed (default nic=%s: %s)";
static const char short_spc648[] = "**ofid_avlookup %s %s";
static const char long_spc648[]  = "OFI call avlookup failed (default nic=%s: %s)";
static const char short_spc649[] = "**ofid_avmap %s %s";
static const char long_spc649[]  = "OFI call avmap failed (default nic=%s: %s)";
static const char short_spc650[] = "**ofid_avopen %s %s";
static const char long_spc650[]  = "OFI call avopen failed (default nic=%s: %s)";
static const char short_spc651[] = "**ofid_bind %s %s";
static const char long_spc651[]  = "OFI call bind failed (default nic=%s: %s)";
static const char short_spc652[] = "**ofid_cancel %s %s";
static const char long_spc652[]  = "OFI cancel failed (default nic=%s: %s)";
static const char short_spc653[] = "**ofid_cntr_wait %s %s";
static const char long_spc653[]  = "OFI OFI Counter wait failed (default nic=%s: %s)";
static const char short_spc654[] = "**ofid_cntrclose %s %s";
static const char long_spc654[]  = "OFI call cntrclose failed (default nic=%s: %s)";
static const char short_spc655[] = "**ofid_control %s %s";
static const char long_spc655[]  = "OFI call control failed (default nic=%s: %s)";
static const char short_spc656[] = "**ofid_cqclose %s %s";
static const char long_spc656[]  = "OFI call cqclose failed (default nic=%s: %s)";
static const char short_spc657[] = "**ofid_domainclose %s %s";
static const char long_spc657[]  = "OFI call domainclose failed (default nic=%s: %s)";
static const char short_spc658[] = "**ofid_ep %s %s";
static const char long_spc658[]  = "OFI call ep failed (default nic=%s: %s)";
static const char short_spc659[] = "**ofid_ep_enable %s %s";
static const char long_spc659[]  = "OFI call ep_enable failed (default nic=%s: %s)";
static const char short_spc660[] = "**ofid_epclose %s %s";
static const char long_spc660[]  = "OFI call epclose failed (default nic=%s: %s)";
static const char short_spc661[] = "**ofid_fabric %s %s";
static const char long_spc661[]  = "OFI call fabric failed (default nic=%s: %s)";
static const char short_spc662[] = "**ofid_fabricclose %s %s";
static const char long_spc662[]  = "OFI call fabricclose failed (default nic=%s: %s)";
static const char short_spc663[] = "**ofid_fi_close %s %s";
static const char long_spc663[]  = "OFI call fi_close failed (default nic=%s: %s)";
static const char short_spc664[] = "**ofid_getinfo %s %s";
static const char long_spc664[]  = "OFI call getinfo failed (default nic=%s: %s)";
static const char short_spc665[] = "**ofid_getname %s %s";
static const char long_spc665[]  = "OFI call getname failed (default nic=%s: %s)";
static const char short_spc666[] = "**ofid_inject %s %s";
static const char long_spc666[]  = "OFI call inject failed (default nic=%s: %s)";
static const char short_spc667[] = "**ofid_mr_bind %s %s";
static const char long_spc667[]  = "OFI call mr_bind failed (default nic=%s: %s)";
static const char short_spc668[] = "**ofid_mr_enable %s %s";
static const char long_spc668[]  = "OFI call mr_enable failed (default nic=%s: %s)";
static const char short_spc669[] = "**ofid_mr_reg %s %s";
static const char long_spc669[]  = "OFI call mr_reg failed (default nic=%s: %s)";
static const char short_spc670[] = "**ofid_mr_regattr %s %s";
static const char long_spc670[]  = "OFI call mr_regattr failed (default nic=%s: %s)";
static const char short_spc671[] = "**ofid_mr_unreg %s %s";
static const char long_spc671[]  = "OFI call mr_unreg failed (default nic=%s: %s)";
static const char short_spc672[] = "**ofid_opencq %s %s";
static const char long_spc672[]  = "OFI call opencq failed (default nic=%s: %s)";
static const char short_spc673[] = "**ofid_openct %s %s";
static const char long_spc673[]  = "OFI call openct failed (default nic=%s: %s)";
static const char short_spc674[] = "**ofid_opendomain %s %s";
static const char long_spc674[]  = "OFI call opendomain failed (default nic=%s: %s)";
static const char short_spc675[] = "**ofid_poll %s %s";
static const char long_spc675[]  = "OFI poll failed (default nic=%s: %s)";
static const char short_spc676[] = "**ofid_prepost %s %s";
static const char long_spc676[]  = "OFI call prepost failed (default nic=%s: %s)";
static const char short_spc677[] = "**ofid_rdma_atomicto %s %s";
static const char long_spc677[]  = "OFI call rdma_atomicto failed (default nic=%s: %s)";
static const char short_spc678[] = "**ofid_rdma_inject_write %s %s";
static const char long_spc678[]  = "OFI call rdma_inject_write failed (default nic=%s: %s)";
static const char short_spc679[] = "**ofid_rdma_readfrom %s %s";
static const char long_spc679[]  = "OFI call rdma_readfrom failed (default nic=%s: %s)";
static const char short_spc680[] = "**ofid_rdma_write %s %s";
static const char long_spc680[]  = "OFI call rdma_write failed (default nic=%s: %s)";
static const char short_spc681[] = "**ofid_send %s %s";
static const char long_spc681[]  = "OFI call send failed (default nic=%s: %s)";
static const char short_spc682[] = "**ofid_setopt %s %s";
static const char long_spc682[]  = "OFI call setopt failed (default nic=%s: %s)";
static const char short_spc683[] = "**ofid_stx_ctx_close %s %s";
static const char long_spc683[]  = "OFI call stx_ctx_close failed (default nic=%s: %s)";
static const char short_spc684[] = "**ofid_tinject %s %s";
static const char long_spc684[]  = "OFI call tinject failed (default nic=%s: %s)";
static const char short_spc685[] = "**ofid_tinjectdata %s %s";
static const char long_spc685[]  = "OFI call tinjectdata failed (default nic=%s: %s)";
static const char short_spc686[] = "**ofid_trecv %s %s";
static const char long_spc686[]  = "OFI call trecv failed (default nic=%s: %s)";
static const char short_spc687[] = "**ofid_trecvmsg %s %s";
static const char long_spc687[]  = "OFI call trecvmsg failed (default nic=%s: %s)";
static const char short_spc688[] = "**ofid_trecvsync %s %s";
static const char long_spc688[]  = "OFI call trecvsync failed (default nic=%s: %s)";
static const char short_spc689[] = "**ofid_tsend %s %s";
static const char long_spc689[]  = "OFI call tsend failed (default nic=%s: %s)";
static const char short_spc690[] = "**ofid_tsenddata %s %s";
static const char long_spc690[]  = "OFI call tsenddata failed (default nic=%s: %s)";
static const char short_spc691[] = "**ofid_tsendv %s %s";
static const char long_spc691[]  = "OFI call tsendv failed (default nic=%s: %s)";
static const char short_spc692[] = "**opencolltuningfile %s";
static const char long_spc692[]  = " Unable to open collective tuning file %s.\nCheck the file or unset MPIR_CVAR_COLL_SELECTION_TUNING_JSON_FILE to use the default settings.";
static const char short_spc693[] = "**opnotpredefined %d";
static const char long_spc693[]  = "only predefined ops are valid (op = %d)";
static const char short_spc694[] = "**opundefined %s";
static const char long_spc694[]  = "MPI_Op %s operation not defined for this datatype ";
static const char short_spc695[] = "**parse_thread_affinity %s";
static const char long_spc695[]  = "Failed to parse async thread affinity string [%s]";
static const char short_spc696[] = "**partitioninvalid %d";
static const char long_spc696[]  = " Invalid partition, value is %d ";
static const char short_spc697[] = "**partitioninvalid %d %d";
static const char long_spc697[]  = " Invalid partition range, values are %d %d";
static const char short_spc698[] = "**pglookup %s";
static const char long_spc698[]  = "unable to find the process group structure with id <%s>";
static const char short_spc699[] = "**pmi_spawn_multiple %d";
static const char long_spc699[]  = "PMI_Spawn_multiple returned %d";
static const char short_spc700[] = "**pmix_load_topo %d";
static const char long_spc700[]  = " PMIx_Load_topology failed with error %d";
static const char short_spc701[] = "**pmix_unknown_topo %s";
static const char long_spc701[]  = " PMIx_Load_topology returns unknown topology with error %s";
static const char short_spc702[] = "**poll %s";
static const char long_spc702[]  = "poll of socket fds failed - %s";
static const char short_spc703[] = "**portexist %s";
static const char long_spc703[]  = "Named port %s does not exist";
static const char short_spc704[] = "**psetinvalidn %d";
static const char long_spc704[]  = "Invalid pset number - %d";
static const char short_spc705[] = "**pthread_mutex %s";
static const char long_spc705[]  = "pthread mutex routine failed (%s)";
static const char short_spc706[] = "**qmpi_invalid_name %s";
static const char long_spc706[]  = " tool name is invalid (name=%s)";
static const char short_spc707[] = "**rangedup %d %d %d";
static const char long_spc707[]  = "The range array specifies duplicate entries; process %d specified in range array %d was previously specified in range array %d";
static const char short_spc708[] = "**rangeendinvalid %d %d %d";
static const char long_spc708[]  = "The %dth element of a range array ends at %d but must be nonnegative and less than %d";
static const char short_spc709[] = "**rangestartinvalid %d %d %d";
static const char long_spc709[]  = "The %dth element of a range array starts at %d but must be nonnegative and less than %d";
static const char short_spc710[] = "**rank %d %d";
static const char long_spc710[]  = "Invalid rank has value %d but must be nonnegative and less than %d";
static const char short_spc711[] = "**rankarray %d %d %d";
static const char long_spc711[]  = "Invalid rank in rank array at index %d; value is %d but must be in the range 0 to %d";
static const char short_spc712[] = "**rankdup %d %d %d";
static const char long_spc712[]  = "Duplicate ranks in rank array at index %d, has value %d which is also the value at index %d";
static const char short_spc713[] = "**ranklocal %d %d";
static const char long_spc713[]  = "Error specifying local_leader; rank given was %d but must be in the range 0 to %d";
static const char short_spc714[] = "**rankremote %d %d";
static const char long_spc714[]  = "Error specifying remote_leader; rank given was %d but must be in the range 0 to %d";
static const char short_spc715[] = "**read %d %s";
static const char long_spc715[]  = "read from socket failed - nread=%d %s";
static const char short_spc716[] = "**read %s";
static const char long_spc716[]  = "read from socket failed - %s";
static const char short_spc717[] = "**read_file %s %s";
static const char long_spc717[]  = "Failed to read from file %s error: %s";
static const char short_spc718[] = "**recv %s %d";
static const char long_spc718[]  = "recv failed, %s (errno %d)";
static const char short_spc719[] = "**recvmsg %s %d";
static const char long_spc719[]  = "recvmsg failed, %s (errno %d)";
static const char short_spc720[] = "**request %d";
static const char long_spc720[]  = "Invalid MPI_Request in array element %d (from 0)";
static const char short_spc721[] = "**request_invalid_kind %d %d";
static const char long_spc721[]  = "The supplied request in array element %d was invalid (kind=%d)";
static const char short_spc722[] = "**rmasize %d";
static const char long_spc722[]  = "Invalid size argument in RMA call (value is %d)";
static const char short_spc723[] = "**rmatypenotatomic %D";
static const char long_spc723[]  = " Datatype (%D) not permitted for atomic operations";
static const char short_spc724[] = "**root %d";
static const char long_spc724[]  = "Invalid root (value given was %d)";
static const char short_spc725[] = "**rsendnomatch %d %d";
static const char long_spc725[]  = "Ready send from source %d and with tag %d had no matching receive";
static const char short_spc726[] = "**sem_destroy %s";
static const char long_spc726[]  = "sem_destroy() failed %s";
static const char short_spc727[] = "**sem_init %s";
static const char long_spc727[]  = "sem_init() failed %s";
static const char short_spc728[] = "**sem_post %s";
static const char long_spc728[]  = "sem_post() failed %s";
static const char short_spc729[] = "**sem_wait %s";
static const char long_spc729[]  = "sem_wait() failed %s";
static const char short_spc730[] = "**sendmsg %s %d";
static const char long_spc730[]  = "sendmsg failed, %s (errno %d)";
static const char short_spc731[] = "**sessioninuse %d";
static const char long_spc731[]  = "MPI_Session is referenced by %d other objects and cannot be released";
static const char short_spc732[] = "**set_thread_affinity %d";
static const char long_spc732[]  = "Failed to set the async thread affinity to the logical processor [%d]";
static const char short_spc733[] = "**signal %s";
static const char long_spc733[]  = "signal() failed: %s";
static const char short_spc734[] = "**snprintf %d";
static const char long_spc734[]  = "snprintf returned %d";
static const char short_spc735[] = "**sock_accept %s";
static const char long_spc735[]  = "accept of socket fd failed - %s";
static const char short_spc736[] = "**sock_accept %s %d";
static const char long_spc736[]  = "accept failed, %s (errno %d) ";
static const char short_spc737[] = "**sock_close %s %d";
static const char long_spc737[]  = " close of socket failed, %s (errno %d)";
static const char short_spc738[] = "**sock_connect %d %s";
static const char long_spc738[]  = "connect failed - %s (errno %d)";
static const char short_spc739[] = "**sock_create %s %d";
static const char long_spc739[]  = "unable to create a socket, %s (errno %d)";
static const char short_spc740[] = "**sock_gethost %s %d";
static const char long_spc740[]  = "gethostname failed, %s (errno %d)";
static const char short_spc741[] = "**sock_unlink %s %d";
static const char long_spc741[]  = "unlink failed, %s (errno %d)";
static const char short_spc742[] = "**sock|badiovn %d %d %d";
static const char long_spc742[]  = "size of iov is invalid (set=%d,sock=%d,iov_n=%d)";
static const char short_spc743[] = "**sock|badlen %d %d %d %d";
static const char long_spc743[]  = "bad length parameter(s) (set=%d,sock=%d,min=%d,max=%d)";
static const char short_spc744[] = "**sock|badport %d";
static const char long_spc744[]  = "port number is out of range (sock=%d)";
static const char short_spc745[] = "**sock|closing %d %d";
static const char long_spc745[]  = "sock is in the process of being closed locally (set=%d,sock=%d)";
static const char short_spc746[] = "**sock|closing_already %d %d";
static const char long_spc746[]  = "a close operation is already post (set=%d,sock=%d)";
static const char short_spc747[] = "**sock|connclosed %d %d";
static const char long_spc747[]  = "connection closed by peer (set=%d,sock=%d)";
static const char short_spc748[] = "**sock|listener_bad_sock %d %d";
static const char long_spc748[]  = "supplied sock is not a listener (set=%d,sock=%d)";
static const char short_spc749[] = "**sock|listener_bad_state %d %d %d";
static const char long_spc749[]  = "supplied listener sock is in a bad state (set=%d,sock=%d,state=%d)";
static const char short_spc750[] = "**sock|listener_read %d %d";
static const char long_spc750[]  = "read operation not allowed on a listener (set=%d,sock=%d)";
static const char short_spc751[] = "**sock|listener_write %d %d";
static const char long_spc751[]  = "write operation not allowed on a listener (set=%d,sock=%d)";
static const char short_spc752[] = "**sock|notconnected %d %d";
static const char long_spc752[]  = "sock is not connected (set=%d,sock=%d)";
static const char short_spc753[] = "**sock|osnomem %s %d %d";
static const char long_spc753[]  = "operating system routine %s failed due to lack of memory (set=%d,sock=%d)";
static const char short_spc754[] = "**sock|poll|accept %d %s";
static const char long_spc754[]  = "accept failed to acquire a new socket (errno=%d:%s)";
static const char short_spc755[] = "**sock|poll|badbuf %d %d %d %s";
static const char long_spc755[]  = "the supplied buffer contains invalid memory (set=%d,sock=%d,errno=%d:%s)";
static const char short_spc756[] = "**sock|poll|badhandle %d %d %d";
static const char long_spc756[]  = "sock contains an invalid file descriptor (set=%d,sock=%d,fd=%d)";
static const char short_spc757[] = "**sock|poll|badhandle %d %d %d %d";
static const char long_spc757[]  = "sock contains an invalid file descriptor (set=%d,sock=%d,fd=%d:%d)";
static const char short_spc758[] = "**sock|poll|bind %d %d %s";
static const char long_spc758[]  = "unable to bind socket to port (port=%d,errno=%d:%s)";
static const char short_spc759[] = "**sock|poll|connclosed %d %d %d %s";
static const char long_spc759[]  = "connection closed by peer (set=%d,sock=%d,errno=%d:%s)";
static const char short_spc760[] = "**sock|poll|connfailed %d %d %d %s";
static const char long_spc760[]  = "connection failure (set=%d,sock=%d,errno=%d:%s)";
static const char short_spc761[] = "**sock|poll|connrefused %d %d %s";
static const char long_spc761[]  = "connection refused (set=%d,sock=%d,host=%s)";
static const char short_spc762[] = "**sock|poll|eqfail %d %d %d";
static const char long_spc762[]  = "fatal error: failed to enqueue an event; event was lost (set=%d,sock=%d,op=%d)";
static const char short_spc763[] = "**sock|poll|listen %d %s";
static const char long_spc763[]  = "listen() failed (errno=%d:%s)";
static const char short_spc764[] = "**sock|poll|nodelay %d %s";
static const char long_spc764[]  = "unable to set TCP no delay attribute on socket (errno=%d:%s)";
static const char short_spc765[] = "**sock|poll|nonblock %d %s";
static const char long_spc765[]  = "unable to set socket to nonblocking (errno=%d:%s)";
static const char short_spc766[] = "**sock|poll|oserror %d %d %d %s";
static const char long_spc766[]  = "unexpected operating system error (set=%d,sock=%d,errno=%d:%s)";
static const char short_spc767[] = "**sock|poll|oserror %d %s";
static const char long_spc767[]  = "unexpected operating system error (errno=%d:%s)";
static const char short_spc768[] = "**sock|poll|oserror %s %d %d %d %s";
static const char long_spc768[]  = "unpected operating system error from %s (set=%d,sock=%d,errno=%d:%s)";
static const char short_spc769[] = "**sock|poll|osnomem %d %d %d %s";
static const char long_spc769[]  = "operating system routine failed due to lack of memory (set=%d,sock=%d,errno=%d:%s)";
static const char short_spc770[] = "**sock|poll|pipe %d %s";
static const char long_spc770[]  = "unable to allocate pipe to wakeup a blocking poll() (errno=%d:%s)";
static const char short_spc771[] = "**sock|poll|pipenonblock %d %s";
static const char long_spc771[]  = "unable to set wakeup pipe to nonblocking (errno=%d:%s)";
static const char short_spc772[] = "**sock|poll|reuseaddr %d %s";
static const char long_spc772[]  = "unable to set reuseaddr attribute on socket (errno=%d:%s)";
static const char short_spc773[] = "**sock|poll|setrcvbufsz %d %d %s";
static const char long_spc773[]  = " unable to set the receive socket buffer size (size=%d,errno=%d:%s)";
static const char short_spc774[] = "**sock|poll|setsndbufsz %d %d %s";
static const char long_spc774[]  = " unable to set the send socket buffer size (size=%d,errno=%d:%s)";
static const char short_spc775[] = "**sock|poll|socket %d %s";
static const char long_spc775[]  = "unable to obtain new socket (errno=%d:%s)";
static const char short_spc776[] = "**sock|poll|unhandledstate %d";
static const char long_spc776[]  = "encountered an unexpected state (%d)";
static const char short_spc777[] = "**sock|poll|unhandledtype %d";
static const char long_spc777[]  = "encountered an unexpected sock type (%d)";
static const char short_spc778[] = "**sock|reads %d %d";
static const char long_spc778[]  = "attempt to perform multiple simultaneous reads (set=%d,sock=%d)";
static const char short_spc779[] = "**sock|writes %d %d";
static const char long_spc779[]  = "attempt to perform multiple simultaneous writes (set=%d,sock=%d)";
static const char short_spc780[] = "**splittype %d";
static const char long_spc780[]  = "Invalid split_type argument (%d)";
static const char short_spc781[] = "**storageorder %d";
static const char long_spc781[]  = " Invalid storage order (%d)";
static const char short_spc782[] = "**stride %d %d %d";
static const char long_spc782[]  = "Range (start = %d, end = %d, stride = %d) does not terminate";
static const char short_spc783[] = "**tag %d";
static const char long_spc783[]  = "Invalid tag, value is %d";
static const char short_spc784[] = "**thread_level %d";
static const char long_spc784[]  = " Invalid thread level (%d)";
static const char short_spc785[] = "**too_big_for_input %s";
static const char long_spc785[]  = "The input argument %s is too big to fit for internal routines";
static const char short_spc786[] = "**toomanycomm %d %d %d";
static const char long_spc786[]  = "Too many communicators (%d/%d free on this process; ignore_id=%d)";
static const char short_spc787[] = "**toomanycommfrag %d %d %d";
static const char long_spc787[]  = " Cannot allocate context ID because of fragmentation (%d/%d free on this process; ignore_id=%d)";
static const char short_spc788[] = "**topotoolarge %d %d";
static const char long_spc788[]  = "Topology size %d is larger than communicator size (%d)";
static const char short_spc789[] = "**treetype %d";
static const char long_spc789[]  = " Invalid tree type (%d) used for initializing Tree algorithms";
static const char short_spc790[] = "**truncate %d %d";
static const char long_spc790[]  = "Message truncated; %d bytes received but buffer size is %d";
static const char short_spc791[] = "**truncate %d %d %d %d";
static const char long_spc791[]  = "Message from rank %d and tag %d truncated; %d bytes received but buffer size is %d";
static const char short_spc792[] = "**typeinitbadmem %d";
static const char long_spc792[]  = "%dth builtin datatype handle references invalid memory";
static const char short_spc793[] = "**typematchsize %s %d";
static const char long_spc793[]  = "No MPI datatype available for typeclass %s and size %d";
static const char short_spc794[] = "**ucx_nm_rq_error %s %d %s %s";
static const char long_spc794[]  = " returned failed request in UCX netmod(%s %d %s %s)";
static const char short_spc795[] = "**ucx_nm_status %s %d %s %s";
static const char long_spc795[]  = " ucx function returned with failed status(%s %d %s %s)";
static const char short_spc796[] = "**unknowngpid %d %d";
static const char long_spc796[]  = "Internal MPI error: Unknown gpid (%d)%d";
static const char short_spc797[] = "**usercancel %d";
static const char long_spc797[]  = "user request cancel function returned error code %d";
static const char short_spc798[] = "**usercopy %d";
static const char long_spc798[]  = "user copy function returned error code %d";
static const char short_spc799[] = "**userdel %d";
static const char long_spc799[]  = "user delete function returned error code %d";
static const char short_spc800[] = "**userfree %d";
static const char long_spc800[]  = "user request free function returned error code %d";
static const char short_spc801[] = "**userquery %d";
static const char long_spc801[]  = "user request query function returned error code %d";
static const char short_spc802[] = "**windows_mutex %s";
static const char long_spc802[]  = "Windows mutex routine failed (%s)";
static const char short_spc803[] = "**winflavor %s";
static const char long_spc803[]  = " Window flavor is not compatible with the given operation (expected %s)";
static const char short_spc804[] = "**write %s";
static const char long_spc804[]  = "write to socket failed - %s";
static const char short_spc805[] = "**writev %s";
static const char long_spc805[]  = "writev to socket failed - %s";
static const char short_spc806[] = "**xpmem_attach %p %d";
static const char long_spc806[]  = " xpmem_attach failed (remote_addr=%p, size=%d)";

static const int specific_msgs_len = 807;
static const msgpair specific_err_msgs[] = {
    { 0xacebad03, short_spc0, long_spc0, 0xcb0bfa11 },
    { 0xacebad03, short_spc1, long_spc1, 0xcb0bfa11 },
    { 0xacebad03, short_spc2, long_spc2, 0xcb0bfa11 },
    { 0xacebad03, short_spc3, long_spc3, 0xcb0bfa11 },
    { 0xacebad03, short_spc4, long_spc4, 0xcb0bfa11 },
    { 0xacebad03, short_spc5, long_spc5, 0xcb0bfa11 },
    { 0xacebad03, short_spc6, long_spc6, 0xcb0bfa11 },
    { 0xacebad03, short_spc7, long_spc7, 0xcb0bfa11 },
    { 0xacebad03, short_spc8, long_spc8, 0xcb0bfa11 },
    { 0xacebad03, short_spc9, long_spc9, 0xcb0bfa11 },
    { 0xacebad03, short_spc10, long_spc10, 0xcb0bfa11 },
    { 0xacebad03, short_spc11, long_spc11, 0xcb0bfa11 },
    { 0xacebad03, short_spc12, long_spc12, 0xcb0bfa11 },
    { 0xacebad03, short_spc13, long_spc13, 0xcb0bfa11 },
    { 0xacebad03, short_spc14, long_spc14, 0xcb0bfa11 },
    { 0xacebad03, short_spc15, long_spc15, 0xcb0bfa11 },
    { 0xacebad03, short_spc16, long_spc16, 0xcb0bfa11 },
    { 0xacebad03, short_spc17, long_spc17, 0xcb0bfa11 },
    { 0xacebad03, short_spc18, long_spc18, 0xcb0bfa11 },
    { 0xacebad03, short_spc19, long_spc19, 0xcb0bfa11 },
    { 0xacebad03, short_spc20, long_spc20, 0xcb0bfa11 },
    { 0xacebad03, short_spc21, long_spc21, 0xcb0bfa11 },
    { 0xacebad03, short_spc22, long_spc22, 0xcb0bfa11 },
    { 0xacebad03, short_spc23, long_spc23, 0xcb0bfa11 },
    { 0xacebad03, short_spc24, long_spc24, 0xcb0bfa11 },
    { 0xacebad03, short_spc25, long_spc25, 0xcb0bfa11 },
    { 0xacebad03, short_spc26, long_spc26, 0xcb0bfa11 },
    { 0xacebad03, short_spc27, long_spc27, 0xcb0bfa11 },
    { 0xacebad03, short_spc28, long_spc28, 0xcb0bfa11 },
    { 0xacebad03, short_spc29, long_spc29, 0xcb0bfa11 },
    { 0xacebad03, short_spc30, long_spc30, 0xcb0bfa11 },
    { 0xacebad03, short_spc31, long_spc31, 0xcb0bfa11 },
    { 0xacebad03, short_spc32, long_spc32, 0xcb0bfa11 },
    { 0xacebad03, short_spc33, long_spc33, 0xcb0bfa11 },
    { 0xacebad03, short_spc34, long_spc34, 0xcb0bfa11 },
    { 0xacebad03, short_spc35, long_spc35, 0xcb0bfa11 },
    { 0xacebad03, short_spc36, long_spc36, 0xcb0bfa11 },
    { 0xacebad03, short_spc37, long_spc37, 0xcb0bfa11 },
    { 0xacebad03, short_spc38, long_spc38, 0xcb0bfa11 },
    { 0xacebad03, short_spc39, long_spc39, 0xcb0bfa11 },
    { 0xacebad03, short_spc40, long_spc40, 0xcb0bfa11 },
    { 0xacebad03, short_spc41, long_spc41, 0xcb0bfa11 },
    { 0xacebad03, short_spc42, long_spc42, 0xcb0bfa11 },
    { 0xacebad03, short_spc43, long_spc43, 0xcb0bfa11 },
    { 0xacebad03, short_spc44, long_spc44, 0xcb0bfa11 },
    { 0xacebad03, short_spc45, long_spc45, 0xcb0bfa11 },
    { 0xacebad03, short_spc46, long_spc46, 0xcb0bfa11 },
    { 0xacebad03, short_spc47, long_spc47, 0xcb0bfa11 },
    { 0xacebad03, short_spc48, long_spc48, 0xcb0bfa11 },
    { 0xacebad03, short_spc49, long_spc49, 0xcb0bfa11 },
    { 0xacebad03, short_spc50, long_spc50, 0xcb0bfa11 },
    { 0xacebad03, short_spc51, long_spc51, 0xcb0bfa11 },
    { 0xacebad03, short_spc52, long_spc52, 0xcb0bfa11 },
    { 0xacebad03, short_spc53, long_spc53, 0xcb0bfa11 },
    { 0xacebad03, short_spc54, long_spc54, 0xcb0bfa11 },
    { 0xacebad03, short_spc55, long_spc55, 0xcb0bfa11 },
    { 0xacebad03, short_spc56, long_spc56, 0xcb0bfa11 },
    { 0xacebad03, short_spc57, long_spc57, 0xcb0bfa11 },
    { 0xacebad03, short_spc58, long_spc58, 0xcb0bfa11 },
    { 0xacebad03, short_spc59, long_spc59, 0xcb0bfa11 },
    { 0xacebad03, short_spc60, long_spc60, 0xcb0bfa11 },
    { 0xacebad03, short_spc61, long_spc61, 0xcb0bfa11 },
    { 0xacebad03, short_spc62, long_spc62, 0xcb0bfa11 },
    { 0xacebad03, short_spc63, long_spc63, 0xcb0bfa11 },
    { 0xacebad03, short_spc64, long_spc64, 0xcb0bfa11 },
    { 0xacebad03, short_spc65, long_spc65, 0xcb0bfa11 },
    { 0xacebad03, short_spc66, long_spc66, 0xcb0bfa11 },
    { 0xacebad03, short_spc67, long_spc67, 0xcb0bfa11 },
    { 0xacebad03, short_spc68, long_spc68, 0xcb0bfa11 },
    { 0xacebad03, short_spc69, long_spc69, 0xcb0bfa11 },
    { 0xacebad03, short_spc70, long_spc70, 0xcb0bfa11 },
    { 0xacebad03, short_spc71, long_spc71, 0xcb0bfa11 },
    { 0xacebad03, short_spc72, long_spc72, 0xcb0bfa11 },
    { 0xacebad03, short_spc73, long_spc73, 0xcb0bfa11 },
    { 0xacebad03, short_spc74, long_spc74, 0xcb0bfa11 },
    { 0xacebad03, short_spc75, long_spc75, 0xcb0bfa11 },
    { 0xacebad03, short_spc76, long_spc76, 0xcb0bfa11 },
    { 0xacebad03, short_spc77, long_spc77, 0xcb0bfa11 },
    { 0xacebad03, short_spc78, long_spc78, 0xcb0bfa11 },
    { 0xacebad03, short_spc79, long_spc79, 0xcb0bfa11 },
    { 0xacebad03, short_spc80, long_spc80, 0xcb0bfa11 },
    { 0xacebad03, short_spc81, long_spc81, 0xcb0bfa11 },
    { 0xacebad03, short_spc82, long_spc82, 0xcb0bfa11 },
    { 0xacebad03, short_spc83, long_spc83, 0xcb0bfa11 },
    { 0xacebad03, short_spc84, long_spc84, 0xcb0bfa11 },
    { 0xacebad03, short_spc85, long_spc85, 0xcb0bfa11 },
    { 0xacebad03, short_spc86, long_spc86, 0xcb0bfa11 },
    { 0xacebad03, short_spc87, long_spc87, 0xcb0bfa11 },
    { 0xacebad03, short_spc88, long_spc88, 0xcb0bfa11 },
    { 0xacebad03, short_spc89, long_spc89, 0xcb0bfa11 },
    { 0xacebad03, short_spc90, long_spc90, 0xcb0bfa11 },
    { 0xacebad03, short_spc91, long_spc91, 0xcb0bfa11 },
    { 0xacebad03, short_spc92, long_spc92, 0xcb0bfa11 },
    { 0xacebad03, short_spc93, long_spc93, 0xcb0bfa11 },
    { 0xacebad03, short_spc94, long_spc94, 0xcb0bfa11 },
    { 0xacebad03, short_spc95, long_spc95, 0xcb0bfa11 },
    { 0xacebad03, short_spc96, long_spc96, 0xcb0bfa11 },
    { 0xacebad03, short_spc97, long_spc97, 0xcb0bfa11 },
    { 0xacebad03, short_spc98, long_spc98, 0xcb0bfa11 },
    { 0xacebad03, short_spc99, long_spc99, 0xcb0bfa11 },
    { 0xacebad03, short_spc100, long_spc100, 0xcb0bfa11 },
    { 0xacebad03, short_spc101, long_spc101, 0xcb0bfa11 },
    { 0xacebad03, short_spc102, long_spc102, 0xcb0bfa11 },
    { 0xacebad03, short_spc103, long_spc103, 0xcb0bfa11 },
    { 0xacebad03, short_spc104, long_spc104, 0xcb0bfa11 },
    { 0xacebad03, short_spc105, long_spc105, 0xcb0bfa11 },
    { 0xacebad03, short_spc106, long_spc106, 0xcb0bfa11 },
    { 0xacebad03, short_spc107, long_spc107, 0xcb0bfa11 },
    { 0xacebad03, short_spc108, long_spc108, 0xcb0bfa11 },
    { 0xacebad03, short_spc109, long_spc109, 0xcb0bfa11 },
    { 0xacebad03, short_spc110, long_spc110, 0xcb0bfa11 },
    { 0xacebad03, short_spc111, long_spc111, 0xcb0bfa11 },
    { 0xacebad03, short_spc112, long_spc112, 0xcb0bfa11 },
    { 0xacebad03, short_spc113, long_spc113, 0xcb0bfa11 },
    { 0xacebad03, short_spc114, long_spc114, 0xcb0bfa11 },
    { 0xacebad03, short_spc115, long_spc115, 0xcb0bfa11 },
    { 0xacebad03, short_spc116, long_spc116, 0xcb0bfa11 },
    { 0xacebad03, short_spc117, long_spc117, 0xcb0bfa11 },
    { 0xacebad03, short_spc118, long_spc118, 0xcb0bfa11 },
    { 0xacebad03, short_spc119, long_spc119, 0xcb0bfa11 },
    { 0xacebad03, short_spc120, long_spc120, 0xcb0bfa11 },
    { 0xacebad03, short_spc121, long_spc121, 0xcb0bfa11 },
    { 0xacebad03, short_spc122, long_spc122, 0xcb0bfa11 },
    { 0xacebad03, short_spc123, long_spc123, 0xcb0bfa11 },
    { 0xacebad03, short_spc124, long_spc124, 0xcb0bfa11 },
    { 0xacebad03, short_spc125, long_spc125, 0xcb0bfa11 },
    { 0xacebad03, short_spc126, long_spc126, 0xcb0bfa11 },
    { 0xacebad03, short_spc127, long_spc127, 0xcb0bfa11 },
    { 0xacebad03, short_spc128, long_spc128, 0xcb0bfa11 },
    { 0xacebad03, short_spc129, long_spc129, 0xcb0bfa11 },
    { 0xacebad03, short_spc130, long_spc130, 0xcb0bfa11 },
    { 0xacebad03, short_spc131, long_spc131, 0xcb0bfa11 },
    { 0xacebad03, short_spc132, long_spc132, 0xcb0bfa11 },
    { 0xacebad03, short_spc133, long_spc133, 0xcb0bfa11 },
    { 0xacebad03, short_spc134, long_spc134, 0xcb0bfa11 },
    { 0xacebad03, short_spc135, long_spc135, 0xcb0bfa11 },
    { 0xacebad03, short_spc136, long_spc136, 0xcb0bfa11 },
    { 0xacebad03, short_spc137, long_spc137, 0xcb0bfa11 },
    { 0xacebad03, short_spc138, long_spc138, 0xcb0bfa11 },
    { 0xacebad03, short_spc139, long_spc139, 0xcb0bfa11 },
    { 0xacebad03, short_spc140, long_spc140, 0xcb0bfa11 },
    { 0xacebad03, short_spc141, long_spc141, 0xcb0bfa11 },
    { 0xacebad03, short_spc142, long_spc142, 0xcb0bfa11 },
    { 0xacebad03, short_spc143, long_spc143, 0xcb0bfa11 },
    { 0xacebad03, short_spc144, long_spc144, 0xcb0bfa11 },
    { 0xacebad03, short_spc145, long_spc145, 0xcb0bfa11 },
    { 0xacebad03, short_spc146, long_spc146, 0xcb0bfa11 },
    { 0xacebad03, short_spc147, long_spc147, 0xcb0bfa11 },
    { 0xacebad03, short_spc148, long_spc148, 0xcb0bfa11 },
    { 0xacebad03, short_spc149, long_spc149, 0xcb0bfa11 },
    { 0xacebad03, short_spc150, long_spc150, 0xcb0bfa11 },
    { 0xacebad03, short_spc151, long_spc151, 0xcb0bfa11 },
    { 0xacebad03, short_spc152, long_spc152, 0xcb0bfa11 },
    { 0xacebad03, short_spc153, long_spc153, 0xcb0bfa11 },
    { 0xacebad03, short_spc154, long_spc154, 0xcb0bfa11 },
    { 0xacebad03, short_spc155, long_spc155, 0xcb0bfa11 },
    { 0xacebad03, short_spc156, long_spc156, 0xcb0bfa11 },
    { 0xacebad03, short_spc157, long_spc157, 0xcb0bfa11 },
    { 0xacebad03, short_spc158, long_spc158, 0xcb0bfa11 },
    { 0xacebad03, short_spc159, long_spc159, 0xcb0bfa11 },
    { 0xacebad03, short_spc160, long_spc160, 0xcb0bfa11 },
    { 0xacebad03, short_spc161, long_spc161, 0xcb0bfa11 },
    { 0xacebad03, short_spc162, long_spc162, 0xcb0bfa11 },
    { 0xacebad03, short_spc163, long_spc163, 0xcb0bfa11 },
    { 0xacebad03, short_spc164, long_spc164, 0xcb0bfa11 },
    { 0xacebad03, short_spc165, long_spc165, 0xcb0bfa11 },
    { 0xacebad03, short_spc166, long_spc166, 0xcb0bfa11 },
    { 0xacebad03, short_spc167, long_spc167, 0xcb0bfa11 },
    { 0xacebad03, short_spc168, long_spc168, 0xcb0bfa11 },
    { 0xacebad03, short_spc169, long_spc169, 0xcb0bfa11 },
    { 0xacebad03, short_spc170, long_spc170, 0xcb0bfa11 },
    { 0xacebad03, short_spc171, long_spc171, 0xcb0bfa11 },
    { 0xacebad03, short_spc172, long_spc172, 0xcb0bfa11 },
    { 0xacebad03, short_spc173, long_spc173, 0xcb0bfa11 },
    { 0xacebad03, short_spc174, long_spc174, 0xcb0bfa11 },
    { 0xacebad03, short_spc175, long_spc175, 0xcb0bfa11 },
    { 0xacebad03, short_spc176, long_spc176, 0xcb0bfa11 },
    { 0xacebad03, short_spc177, long_spc177, 0xcb0bfa11 },
    { 0xacebad03, short_spc178, long_spc178, 0xcb0bfa11 },
    { 0xacebad03, short_spc179, long_spc179, 0xcb0bfa11 },
    { 0xacebad03, short_spc180, long_spc180, 0xcb0bfa11 },
    { 0xacebad03, short_spc181, long_spc181, 0xcb0bfa11 },
    { 0xacebad03, short_spc182, long_spc182, 0xcb0bfa11 },
    { 0xacebad03, short_spc183, long_spc183, 0xcb0bfa11 },
    { 0xacebad03, short_spc184, long_spc184, 0xcb0bfa11 },
    { 0xacebad03, short_spc185, long_spc185, 0xcb0bfa11 },
    { 0xacebad03, short_spc186, long_spc186, 0xcb0bfa11 },
    { 0xacebad03, short_spc187, long_spc187, 0xcb0bfa11 },
    { 0xacebad03, short_spc188, long_spc188, 0xcb0bfa11 },
    { 0xacebad03, short_spc189, long_spc189, 0xcb0bfa11 },
    { 0xacebad03, short_spc190, long_spc190, 0xcb0bfa11 },
    { 0xacebad03, short_spc191, long_spc191, 0xcb0bfa11 },
    { 0xacebad03, short_spc192, long_spc192, 0xcb0bfa11 },
    { 0xacebad03, short_spc193, long_spc193, 0xcb0bfa11 },
    { 0xacebad03, short_spc194, long_spc194, 0xcb0bfa11 },
    { 0xacebad03, short_spc195, long_spc195, 0xcb0bfa11 },
    { 0xacebad03, short_spc196, long_spc196, 0xcb0bfa11 },
    { 0xacebad03, short_spc197, long_spc197, 0xcb0bfa11 },
    { 0xacebad03, short_spc198, long_spc198, 0xcb0bfa11 },
    { 0xacebad03, short_spc199, long_spc199, 0xcb0bfa11 },
    { 0xacebad03, short_spc200, long_spc200, 0xcb0bfa11 },
    { 0xacebad03, short_spc201, long_spc201, 0xcb0bfa11 },
    { 0xacebad03, short_spc202, long_spc202, 0xcb0bfa11 },
    { 0xacebad03, short_spc203, long_spc203, 0xcb0bfa11 },
    { 0xacebad03, short_spc204, long_spc204, 0xcb0bfa11 },
    { 0xacebad03, short_spc205, long_spc205, 0xcb0bfa11 },
    { 0xacebad03, short_spc206, long_spc206, 0xcb0bfa11 },
    { 0xacebad03, short_spc207, long_spc207, 0xcb0bfa11 },
    { 0xacebad03, short_spc208, long_spc208, 0xcb0bfa11 },
    { 0xacebad03, short_spc209, long_spc209, 0xcb0bfa11 },
    { 0xacebad03, short_spc210, long_spc210, 0xcb0bfa11 },
    { 0xacebad03, short_spc211, long_spc211, 0xcb0bfa11 },
    { 0xacebad03, short_spc212, long_spc212, 0xcb0bfa11 },
    { 0xacebad03, short_spc213, long_spc213, 0xcb0bfa11 },
    { 0xacebad03, short_spc214, long_spc214, 0xcb0bfa11 },
    { 0xacebad03, short_spc215, long_spc215, 0xcb0bfa11 },
    { 0xacebad03, short_spc216, long_spc216, 0xcb0bfa11 },
    { 0xacebad03, short_spc217, long_spc217, 0xcb0bfa11 },
    { 0xacebad03, short_spc218, long_spc218, 0xcb0bfa11 },
    { 0xacebad03, short_spc219, long_spc219, 0xcb0bfa11 },
    { 0xacebad03, short_spc220, long_spc220, 0xcb0bfa11 },
    { 0xacebad03, short_spc221, long_spc221, 0xcb0bfa11 },
    { 0xacebad03, short_spc222, long_spc222, 0xcb0bfa11 },
    { 0xacebad03, short_spc223, long_spc223, 0xcb0bfa11 },
    { 0xacebad03, short_spc224, long_spc224, 0xcb0bfa11 },
    { 0xacebad03, short_spc225, long_spc225, 0xcb0bfa11 },
    { 0xacebad03, short_spc226, long_spc226, 0xcb0bfa11 },
    { 0xacebad03, short_spc227, long_spc227, 0xcb0bfa11 },
    { 0xacebad03, short_spc228, long_spc228, 0xcb0bfa11 },
    { 0xacebad03, short_spc229, long_spc229, 0xcb0bfa11 },
    { 0xacebad03, short_spc230, long_spc230, 0xcb0bfa11 },
    { 0xacebad03, short_spc231, long_spc231, 0xcb0bfa11 },
    { 0xacebad03, short_spc232, long_spc232, 0xcb0bfa11 },
    { 0xacebad03, short_spc233, long_spc233, 0xcb0bfa11 },
    { 0xacebad03, short_spc234, long_spc234, 0xcb0bfa11 },
    { 0xacebad03, short_spc235, long_spc235, 0xcb0bfa11 },
    { 0xacebad03, short_spc236, long_spc236, 0xcb0bfa11 },
    { 0xacebad03, short_spc237, long_spc237, 0xcb0bfa11 },
    { 0xacebad03, short_spc238, long_spc238, 0xcb0bfa11 },
    { 0xacebad03, short_spc239, long_spc239, 0xcb0bfa11 },
    { 0xacebad03, short_spc240, long_spc240, 0xcb0bfa11 },
    { 0xacebad03, short_spc241, long_spc241, 0xcb0bfa11 },
    { 0xacebad03, short_spc242, long_spc242, 0xcb0bfa11 },
    { 0xacebad03, short_spc243, long_spc243, 0xcb0bfa11 },
    { 0xacebad03, short_spc244, long_spc244, 0xcb0bfa11 },
    { 0xacebad03, short_spc245, long_spc245, 0xcb0bfa11 },
    { 0xacebad03, short_spc246, long_spc246, 0xcb0bfa11 },
    { 0xacebad03, short_spc247, long_spc247, 0xcb0bfa11 },
    { 0xacebad03, short_spc248, long_spc248, 0xcb0bfa11 },
    { 0xacebad03, short_spc249, long_spc249, 0xcb0bfa11 },
    { 0xacebad03, short_spc250, long_spc250, 0xcb0bfa11 },
    { 0xacebad03, short_spc251, long_spc251, 0xcb0bfa11 },
    { 0xacebad03, short_spc252, long_spc252, 0xcb0bfa11 },
    { 0xacebad03, short_spc253, long_spc253, 0xcb0bfa11 },
    { 0xacebad03, short_spc254, long_spc254, 0xcb0bfa11 },
    { 0xacebad03, short_spc255, long_spc255, 0xcb0bfa11 },
    { 0xacebad03, short_spc256, long_spc256, 0xcb0bfa11 },
    { 0xacebad03, short_spc257, long_spc257, 0xcb0bfa11 },
    { 0xacebad03, short_spc258, long_spc258, 0xcb0bfa11 },
    { 0xacebad03, short_spc259, long_spc259, 0xcb0bfa11 },
    { 0xacebad03, short_spc260, long_spc260, 0xcb0bfa11 },
    { 0xacebad03, short_spc261, long_spc261, 0xcb0bfa11 },
    { 0xacebad03, short_spc262, long_spc262, 0xcb0bfa11 },
    { 0xacebad03, short_spc263, long_spc263, 0xcb0bfa11 },
    { 0xacebad03, short_spc264, long_spc264, 0xcb0bfa11 },
    { 0xacebad03, short_spc265, long_spc265, 0xcb0bfa11 },
    { 0xacebad03, short_spc266, long_spc266, 0xcb0bfa11 },
    { 0xacebad03, short_spc267, long_spc267, 0xcb0bfa11 },
    { 0xacebad03, short_spc268, long_spc268, 0xcb0bfa11 },
    { 0xacebad03, short_spc269, long_spc269, 0xcb0bfa11 },
    { 0xacebad03, short_spc270, long_spc270, 0xcb0bfa11 },
    { 0xacebad03, short_spc271, long_spc271, 0xcb0bfa11 },
    { 0xacebad03, short_spc272, long_spc272, 0xcb0bfa11 },
    { 0xacebad03, short_spc273, long_spc273, 0xcb0bfa11 },
    { 0xacebad03, short_spc274, long_spc274, 0xcb0bfa11 },
    { 0xacebad03, short_spc275, long_spc275, 0xcb0bfa11 },
    { 0xacebad03, short_spc276, long_spc276, 0xcb0bfa11 },
    { 0xacebad03, short_spc277, long_spc277, 0xcb0bfa11 },
    { 0xacebad03, short_spc278, long_spc278, 0xcb0bfa11 },
    { 0xacebad03, short_spc279, long_spc279, 0xcb0bfa11 },
    { 0xacebad03, short_spc280, long_spc280, 0xcb0bfa11 },
    { 0xacebad03, short_spc281, long_spc281, 0xcb0bfa11 },
    { 0xacebad03, short_spc282, long_spc282, 0xcb0bfa11 },
    { 0xacebad03, short_spc283, long_spc283, 0xcb0bfa11 },
    { 0xacebad03, short_spc284, long_spc284, 0xcb0bfa11 },
    { 0xacebad03, short_spc285, long_spc285, 0xcb0bfa11 },
    { 0xacebad03, short_spc286, long_spc286, 0xcb0bfa11 },
    { 0xacebad03, short_spc287, long_spc287, 0xcb0bfa11 },
    { 0xacebad03, short_spc288, long_spc288, 0xcb0bfa11 },
    { 0xacebad03, short_spc289, long_spc289, 0xcb0bfa11 },
    { 0xacebad03, short_spc290, long_spc290, 0xcb0bfa11 },
    { 0xacebad03, short_spc291, long_spc291, 0xcb0bfa11 },
    { 0xacebad03, short_spc292, long_spc292, 0xcb0bfa11 },
    { 0xacebad03, short_spc293, long_spc293, 0xcb0bfa11 },
    { 0xacebad03, short_spc294, long_spc294, 0xcb0bfa11 },
    { 0xacebad03, short_spc295, long_spc295, 0xcb0bfa11 },
    { 0xacebad03, short_spc296, long_spc296, 0xcb0bfa11 },
    { 0xacebad03, short_spc297, long_spc297, 0xcb0bfa11 },
    { 0xacebad03, short_spc298, long_spc298, 0xcb0bfa11 },
    { 0xacebad03, short_spc299, long_spc299, 0xcb0bfa11 },
    { 0xacebad03, short_spc300, long_spc300, 0xcb0bfa11 },
    { 0xacebad03, short_spc301, long_spc301, 0xcb0bfa11 },
    { 0xacebad03, short_spc302, long_spc302, 0xcb0bfa11 },
    { 0xacebad03, short_spc303, long_spc303, 0xcb0bfa11 },
    { 0xacebad03, short_spc304, long_spc304, 0xcb0bfa11 },
    { 0xacebad03, short_spc305, long_spc305, 0xcb0bfa11 },
    { 0xacebad03, short_spc306, long_spc306, 0xcb0bfa11 },
    { 0xacebad03, short_spc307, long_spc307, 0xcb0bfa11 },
    { 0xacebad03, short_spc308, long_spc308, 0xcb0bfa11 },
    { 0xacebad03, short_spc309, long_spc309, 0xcb0bfa11 },
    { 0xacebad03, short_spc310, long_spc310, 0xcb0bfa11 },
    { 0xacebad03, short_spc311, long_spc311, 0xcb0bfa11 },
    { 0xacebad03, short_spc312, long_spc312, 0xcb0bfa11 },
    { 0xacebad03, short_spc313, long_spc313, 0xcb0bfa11 },
    { 0xacebad03, short_spc314, long_spc314, 0xcb0bfa11 },
    { 0xacebad03, short_spc315, long_spc315, 0xcb0bfa11 },
    { 0xacebad03, short_spc316, long_spc316, 0xcb0bfa11 },
    { 0xacebad03, short_spc317, long_spc317, 0xcb0bfa11 },
    { 0xacebad03, short_spc318, long_spc318, 0xcb0bfa11 },
    { 0xacebad03, short_spc319, long_spc319, 0xcb0bfa11 },
    { 0xacebad03, short_spc320, long_spc320, 0xcb0bfa11 },
    { 0xacebad03, short_spc321, long_spc321, 0xcb0bfa11 },
    { 0xacebad03, short_spc322, long_spc322, 0xcb0bfa11 },
    { 0xacebad03, short_spc323, long_spc323, 0xcb0bfa11 },
    { 0xacebad03, short_spc324, long_spc324, 0xcb0bfa11 },
    { 0xacebad03, short_spc325, long_spc325, 0xcb0bfa11 },
    { 0xacebad03, short_spc326, long_spc326, 0xcb0bfa11 },
    { 0xacebad03, short_spc327, long_spc327, 0xcb0bfa11 },
    { 0xacebad03, short_spc328, long_spc328, 0xcb0bfa11 },
    { 0xacebad03, short_spc329, long_spc329, 0xcb0bfa11 },
    { 0xacebad03, short_spc330, long_spc330, 0xcb0bfa11 },
    { 0xacebad03, short_spc331, long_spc331, 0xcb0bfa11 },
    { 0xacebad03, short_spc332, long_spc332, 0xcb0bfa11 },
    { 0xacebad03, short_spc333, long_spc333, 0xcb0bfa11 },
    { 0xacebad03, short_spc334, long_spc334, 0xcb0bfa11 },
    { 0xacebad03, short_spc335, long_spc335, 0xcb0bfa11 },
    { 0xacebad03, short_spc336, long_spc336, 0xcb0bfa11 },
    { 0xacebad03, short_spc337, long_spc337, 0xcb0bfa11 },
    { 0xacebad03, short_spc338, long_spc338, 0xcb0bfa11 },
    { 0xacebad03, short_spc339, long_spc339, 0xcb0bfa11 },
    { 0xacebad03, short_spc340, long_spc340, 0xcb0bfa11 },
    { 0xacebad03, short_spc341, long_spc341, 0xcb0bfa11 },
    { 0xacebad03, short_spc342, long_spc342, 0xcb0bfa11 },
    { 0xacebad03, short_spc343, long_spc343, 0xcb0bfa11 },
    { 0xacebad03, short_spc344, long_spc344, 0xcb0bfa11 },
    { 0xacebad03, short_spc345, long_spc345, 0xcb0bfa11 },
    { 0xacebad03, short_spc346, long_spc346, 0xcb0bfa11 },
    { 0xacebad03, short_spc347, long_spc347, 0xcb0bfa11 },
    { 0xacebad03, short_spc348, long_spc348, 0xcb0bfa11 },
    { 0xacebad03, short_spc349, long_spc349, 0xcb0bfa11 },
    { 0xacebad03, short_spc350, long_spc350, 0xcb0bfa11 },
    { 0xacebad03, short_spc351, long_spc351, 0xcb0bfa11 },
    { 0xacebad03, short_spc352, long_spc352, 0xcb0bfa11 },
    { 0xacebad03, short_spc353, long_spc353, 0xcb0bfa11 },
    { 0xacebad03, short_spc354, long_spc354, 0xcb0bfa11 },
    { 0xacebad03, short_spc355, long_spc355, 0xcb0bfa11 },
    { 0xacebad03, short_spc356, long_spc356, 0xcb0bfa11 },
    { 0xacebad03, short_spc357, long_spc357, 0xcb0bfa11 },
    { 0xacebad03, short_spc358, long_spc358, 0xcb0bfa11 },
    { 0xacebad03, short_spc359, long_spc359, 0xcb0bfa11 },
    { 0xacebad03, short_spc360, long_spc360, 0xcb0bfa11 },
    { 0xacebad03, short_spc361, long_spc361, 0xcb0bfa11 },
    { 0xacebad03, short_spc362, long_spc362, 0xcb0bfa11 },
    { 0xacebad03, short_spc363, long_spc363, 0xcb0bfa11 },
    { 0xacebad03, short_spc364, long_spc364, 0xcb0bfa11 },
    { 0xacebad03, short_spc365, long_spc365, 0xcb0bfa11 },
    { 0xacebad03, short_spc366, long_spc366, 0xcb0bfa11 },
    { 0xacebad03, short_spc367, long_spc367, 0xcb0bfa11 },
    { 0xacebad03, short_spc368, long_spc368, 0xcb0bfa11 },
    { 0xacebad03, short_spc369, long_spc369, 0xcb0bfa11 },
    { 0xacebad03, short_spc370, long_spc370, 0xcb0bfa11 },
    { 0xacebad03, short_spc371, long_spc371, 0xcb0bfa11 },
    { 0xacebad03, short_spc372, long_spc372, 0xcb0bfa11 },
    { 0xacebad03, short_spc373, long_spc373, 0xcb0bfa11 },
    { 0xacebad03, short_spc374, long_spc374, 0xcb0bfa11 },
    { 0xacebad03, short_spc375, long_spc375, 0xcb0bfa11 },
    { 0xacebad03, short_spc376, long_spc376, 0xcb0bfa11 },
    { 0xacebad03, short_spc377, long_spc377, 0xcb0bfa11 },
    { 0xacebad03, short_spc378, long_spc378, 0xcb0bfa11 },
    { 0xacebad03, short_spc379, long_spc379, 0xcb0bfa11 },
    { 0xacebad03, short_spc380, long_spc380, 0xcb0bfa11 },
    { 0xacebad03, short_spc381, long_spc381, 0xcb0bfa11 },
    { 0xacebad03, short_spc382, long_spc382, 0xcb0bfa11 },
    { 0xacebad03, short_spc383, long_spc383, 0xcb0bfa11 },
    { 0xacebad03, short_spc384, long_spc384, 0xcb0bfa11 },
    { 0xacebad03, short_spc385, long_spc385, 0xcb0bfa11 },
    { 0xacebad03, short_spc386, long_spc386, 0xcb0bfa11 },
    { 0xacebad03, short_spc387, long_spc387, 0xcb0bfa11 },
    { 0xacebad03, short_spc388, long_spc388, 0xcb0bfa11 },
    { 0xacebad03, short_spc389, long_spc389, 0xcb0bfa11 },
    { 0xacebad03, short_spc390, long_spc390, 0xcb0bfa11 },
    { 0xacebad03, short_spc391, long_spc391, 0xcb0bfa11 },
    { 0xacebad03, short_spc392, long_spc392, 0xcb0bfa11 },
    { 0xacebad03, short_spc393, long_spc393, 0xcb0bfa11 },
    { 0xacebad03, short_spc394, long_spc394, 0xcb0bfa11 },
    { 0xacebad03, short_spc395, long_spc395, 0xcb0bfa11 },
    { 0xacebad03, short_spc396, long_spc396, 0xcb0bfa11 },
    { 0xacebad03, short_spc397, long_spc397, 0xcb0bfa11 },
    { 0xacebad03, short_spc398, long_spc398, 0xcb0bfa11 },
    { 0xacebad03, short_spc399, long_spc399, 0xcb0bfa11 },
    { 0xacebad03, short_spc400, long_spc400, 0xcb0bfa11 },
    { 0xacebad03, short_spc401, long_spc401, 0xcb0bfa11 },
    { 0xacebad03, short_spc402, long_spc402, 0xcb0bfa11 },
    { 0xacebad03, short_spc403, long_spc403, 0xcb0bfa11 },
    { 0xacebad03, short_spc404, long_spc404, 0xcb0bfa11 },
    { 0xacebad03, short_spc405, long_spc405, 0xcb0bfa11 },
    { 0xacebad03, short_spc406, long_spc406, 0xcb0bfa11 },
    { 0xacebad03, short_spc407, long_spc407, 0xcb0bfa11 },
    { 0xacebad03, short_spc408, long_spc408, 0xcb0bfa11 },
    { 0xacebad03, short_spc409, long_spc409, 0xcb0bfa11 },
    { 0xacebad03, short_spc410, long_spc410, 0xcb0bfa11 },
    { 0xacebad03, short_spc411, long_spc411, 0xcb0bfa11 },
    { 0xacebad03, short_spc412, long_spc412, 0xcb0bfa11 },
    { 0xacebad03, short_spc413, long_spc413, 0xcb0bfa11 },
    { 0xacebad03, short_spc414, long_spc414, 0xcb0bfa11 },
    { 0xacebad03, short_spc415, long_spc415, 0xcb0bfa11 },
    { 0xacebad03, short_spc416, long_spc416, 0xcb0bfa11 },
    { 0xacebad03, short_spc417, long_spc417, 0xcb0bfa11 },
    { 0xacebad03, short_spc418, long_spc418, 0xcb0bfa11 },
    { 0xacebad03, short_spc419, long_spc419, 0xcb0bfa11 },
    { 0xacebad03, short_spc420, long_spc420, 0xcb0bfa11 },
    { 0xacebad03, short_spc421, long_spc421, 0xcb0bfa11 },
    { 0xacebad03, short_spc422, long_spc422, 0xcb0bfa11 },
    { 0xacebad03, short_spc423, long_spc423, 0xcb0bfa11 },
    { 0xacebad03, short_spc424, long_spc424, 0xcb0bfa11 },
    { 0xacebad03, short_spc425, long_spc425, 0xcb0bfa11 },
    { 0xacebad03, short_spc426, long_spc426, 0xcb0bfa11 },
    { 0xacebad03, short_spc427, long_spc427, 0xcb0bfa11 },
    { 0xacebad03, short_spc428, long_spc428, 0xcb0bfa11 },
    { 0xacebad03, short_spc429, long_spc429, 0xcb0bfa11 },
    { 0xacebad03, short_spc430, long_spc430, 0xcb0bfa11 },
    { 0xacebad03, short_spc431, long_spc431, 0xcb0bfa11 },
    { 0xacebad03, short_spc432, long_spc432, 0xcb0bfa11 },
    { 0xacebad03, short_spc433, long_spc433, 0xcb0bfa11 },
    { 0xacebad03, short_spc434, long_spc434, 0xcb0bfa11 },
    { 0xacebad03, short_spc435, long_spc435, 0xcb0bfa11 },
    { 0xacebad03, short_spc436, long_spc436, 0xcb0bfa11 },
    { 0xacebad03, short_spc437, long_spc437, 0xcb0bfa11 },
    { 0xacebad03, short_spc438, long_spc438, 0xcb0bfa11 },
    { 0xacebad03, short_spc439, long_spc439, 0xcb0bfa11 },
    { 0xacebad03, short_spc440, long_spc440, 0xcb0bfa11 },
    { 0xacebad03, short_spc441, long_spc441, 0xcb0bfa11 },
    { 0xacebad03, short_spc442, long_spc442, 0xcb0bfa11 },
    { 0xacebad03, short_spc443, long_spc443, 0xcb0bfa11 },
    { 0xacebad03, short_spc444, long_spc444, 0xcb0bfa11 },
    { 0xacebad03, short_spc445, long_spc445, 0xcb0bfa11 },
    { 0xacebad03, short_spc446, long_spc446, 0xcb0bfa11 },
    { 0xacebad03, short_spc447, long_spc447, 0xcb0bfa11 },
    { 0xacebad03, short_spc448, long_spc448, 0xcb0bfa11 },
    { 0xacebad03, short_spc449, long_spc449, 0xcb0bfa11 },
    { 0xacebad03, short_spc450, long_spc450, 0xcb0bfa11 },
    { 0xacebad03, short_spc451, long_spc451, 0xcb0bfa11 },
    { 0xacebad03, short_spc452, long_spc452, 0xcb0bfa11 },
    { 0xacebad03, short_spc453, long_spc453, 0xcb0bfa11 },
    { 0xacebad03, short_spc454, long_spc454, 0xcb0bfa11 },
    { 0xacebad03, short_spc455, long_spc455, 0xcb0bfa11 },
    { 0xacebad03, short_spc456, long_spc456, 0xcb0bfa11 },
    { 0xacebad03, short_spc457, long_spc457, 0xcb0bfa11 },
    { 0xacebad03, short_spc458, long_spc458, 0xcb0bfa11 },
    { 0xacebad03, short_spc459, long_spc459, 0xcb0bfa11 },
    { 0xacebad03, short_spc460, long_spc460, 0xcb0bfa11 },
    { 0xacebad03, short_spc461, long_spc461, 0xcb0bfa11 },
    { 0xacebad03, short_spc462, long_spc462, 0xcb0bfa11 },
    { 0xacebad03, short_spc463, long_spc463, 0xcb0bfa11 },
    { 0xacebad03, short_spc464, long_spc464, 0xcb0bfa11 },
    { 0xacebad03, short_spc465, long_spc465, 0xcb0bfa11 },
    { 0xacebad03, short_spc466, long_spc466, 0xcb0bfa11 },
    { 0xacebad03, short_spc467, long_spc467, 0xcb0bfa11 },
    { 0xacebad03, short_spc468, long_spc468, 0xcb0bfa11 },
    { 0xacebad03, short_spc469, long_spc469, 0xcb0bfa11 },
    { 0xacebad03, short_spc470, long_spc470, 0xcb0bfa11 },
    { 0xacebad03, short_spc471, long_spc471, 0xcb0bfa11 },
    { 0xacebad03, short_spc472, long_spc472, 0xcb0bfa11 },
    { 0xacebad03, short_spc473, long_spc473, 0xcb0bfa11 },
    { 0xacebad03, short_spc474, long_spc474, 0xcb0bfa11 },
    { 0xacebad03, short_spc475, long_spc475, 0xcb0bfa11 },
    { 0xacebad03, short_spc476, long_spc476, 0xcb0bfa11 },
    { 0xacebad03, short_spc477, long_spc477, 0xcb0bfa11 },
    { 0xacebad03, short_spc478, long_spc478, 0xcb0bfa11 },
    { 0xacebad03, short_spc479, long_spc479, 0xcb0bfa11 },
    { 0xacebad03, short_spc480, long_spc480, 0xcb0bfa11 },
    { 0xacebad03, short_spc481, long_spc481, 0xcb0bfa11 },
    { 0xacebad03, short_spc482, long_spc482, 0xcb0bfa11 },
    { 0xacebad03, short_spc483, long_spc483, 0xcb0bfa11 },
    { 0xacebad03, short_spc484, long_spc484, 0xcb0bfa11 },
    { 0xacebad03, short_spc485, long_spc485, 0xcb0bfa11 },
    { 0xacebad03, short_spc486, long_spc486, 0xcb0bfa11 },
    { 0xacebad03, short_spc487, long_spc487, 0xcb0bfa11 },
    { 0xacebad03, short_spc488, long_spc488, 0xcb0bfa11 },
    { 0xacebad03, short_spc489, long_spc489, 0xcb0bfa11 },
    { 0xacebad03, short_spc490, long_spc490, 0xcb0bfa11 },
    { 0xacebad03, short_spc491, long_spc491, 0xcb0bfa11 },
    { 0xacebad03, short_spc492, long_spc492, 0xcb0bfa11 },
    { 0xacebad03, short_spc493, long_spc493, 0xcb0bfa11 },
    { 0xacebad03, short_spc494, long_spc494, 0xcb0bfa11 },
    { 0xacebad03, short_spc495, long_spc495, 0xcb0bfa11 },
    { 0xacebad03, short_spc496, long_spc496, 0xcb0bfa11 },
    { 0xacebad03, short_spc497, long_spc497, 0xcb0bfa11 },
    { 0xacebad03, short_spc498, long_spc498, 0xcb0bfa11 },
    { 0xacebad03, short_spc499, long_spc499, 0xcb0bfa11 },
    { 0xacebad03, short_spc500, long_spc500, 0xcb0bfa11 },
    { 0xacebad03, short_spc501, long_spc501, 0xcb0bfa11 },
    { 0xacebad03, short_spc502, long_spc502, 0xcb0bfa11 },
    { 0xacebad03, short_spc503, long_spc503, 0xcb0bfa11 },
    { 0xacebad03, short_spc504, long_spc504, 0xcb0bfa11 },
    { 0xacebad03, short_spc505, long_spc505, 0xcb0bfa11 },
    { 0xacebad03, short_spc506, long_spc506, 0xcb0bfa11 },
    { 0xacebad03, short_spc507, long_spc507, 0xcb0bfa11 },
    { 0xacebad03, short_spc508, long_spc508, 0xcb0bfa11 },
    { 0xacebad03, short_spc509, long_spc509, 0xcb0bfa11 },
    { 0xacebad03, short_spc510, long_spc510, 0xcb0bfa11 },
    { 0xacebad03, short_spc511, long_spc511, 0xcb0bfa11 },
    { 0xacebad03, short_spc512, long_spc512, 0xcb0bfa11 },
    { 0xacebad03, short_spc513, long_spc513, 0xcb0bfa11 },
    { 0xacebad03, short_spc514, long_spc514, 0xcb0bfa11 },
    { 0xacebad03, short_spc515, long_spc515, 0xcb0bfa11 },
    { 0xacebad03, short_spc516, long_spc516, 0xcb0bfa11 },
    { 0xacebad03, short_spc517, long_spc517, 0xcb0bfa11 },
    { 0xacebad03, short_spc518, long_spc518, 0xcb0bfa11 },
    { 0xacebad03, short_spc519, long_spc519, 0xcb0bfa11 },
    { 0xacebad03, short_spc520, long_spc520, 0xcb0bfa11 },
    { 0xacebad03, short_spc521, long_spc521, 0xcb0bfa11 },
    { 0xacebad03, short_spc522, long_spc522, 0xcb0bfa11 },
    { 0xacebad03, short_spc523, long_spc523, 0xcb0bfa11 },
    { 0xacebad03, short_spc524, long_spc524, 0xcb0bfa11 },
    { 0xacebad03, short_spc525, long_spc525, 0xcb0bfa11 },
    { 0xacebad03, short_spc526, long_spc526, 0xcb0bfa11 },
    { 0xacebad03, short_spc527, long_spc527, 0xcb0bfa11 },
    { 0xacebad03, short_spc528, long_spc528, 0xcb0bfa11 },
    { 0xacebad03, short_spc529, long_spc529, 0xcb0bfa11 },
    { 0xacebad03, short_spc530, long_spc530, 0xcb0bfa11 },
    { 0xacebad03, short_spc531, long_spc531, 0xcb0bfa11 },
    { 0xacebad03, short_spc532, long_spc532, 0xcb0bfa11 },
    { 0xacebad03, short_spc533, long_spc533, 0xcb0bfa11 },
    { 0xacebad03, short_spc534, long_spc534, 0xcb0bfa11 },
    { 0xacebad03, short_spc535, long_spc535, 0xcb0bfa11 },
    { 0xacebad03, short_spc536, long_spc536, 0xcb0bfa11 },
    { 0xacebad03, short_spc537, long_spc537, 0xcb0bfa11 },
    { 0xacebad03, short_spc538, long_spc538, 0xcb0bfa11 },
    { 0xacebad03, short_spc539, long_spc539, 0xcb0bfa11 },
    { 0xacebad03, short_spc540, long_spc540, 0xcb0bfa11 },
    { 0xacebad03, short_spc541, long_spc541, 0xcb0bfa11 },
    { 0xacebad03, short_spc542, long_spc542, 0xcb0bfa11 },
    { 0xacebad03, short_spc543, long_spc543, 0xcb0bfa11 },
    { 0xacebad03, short_spc544, long_spc544, 0xcb0bfa11 },
    { 0xacebad03, short_spc545, long_spc545, 0xcb0bfa11 },
    { 0xacebad03, short_spc546, long_spc546, 0xcb0bfa11 },
    { 0xacebad03, short_spc547, long_spc547, 0xcb0bfa11 },
    { 0xacebad03, short_spc548, long_spc548, 0xcb0bfa11 },
    { 0xacebad03, short_spc549, long_spc549, 0xcb0bfa11 },
    { 0xacebad03, short_spc550, long_spc550, 0xcb0bfa11 },
    { 0xacebad03, short_spc551, long_spc551, 0xcb0bfa11 },
    { 0xacebad03, short_spc552, long_spc552, 0xcb0bfa11 },
    { 0xacebad03, short_spc553, long_spc553, 0xcb0bfa11 },
    { 0xacebad03, short_spc554, long_spc554, 0xcb0bfa11 },
    { 0xacebad03, short_spc555, long_spc555, 0xcb0bfa11 },
    { 0xacebad03, short_spc556, long_spc556, 0xcb0bfa11 },
    { 0xacebad03, short_spc557, long_spc557, 0xcb0bfa11 },
    { 0xacebad03, short_spc558, long_spc558, 0xcb0bfa11 },
    { 0xacebad03, short_spc559, long_spc559, 0xcb0bfa11 },
    { 0xacebad03, short_spc560, long_spc560, 0xcb0bfa11 },
    { 0xacebad03, short_spc561, long_spc561, 0xcb0bfa11 },
    { 0xacebad03, short_spc562, long_spc562, 0xcb0bfa11 },
    { 0xacebad03, short_spc563, long_spc563, 0xcb0bfa11 },
    { 0xacebad03, short_spc564, long_spc564, 0xcb0bfa11 },
    { 0xacebad03, short_spc565, long_spc565, 0xcb0bfa11 },
    { 0xacebad03, short_spc566, long_spc566, 0xcb0bfa11 },
    { 0xacebad03, short_spc567, long_spc567, 0xcb0bfa11 },
    { 0xacebad03, short_spc568, long_spc568, 0xcb0bfa11 },
    { 0xacebad03, short_spc569, long_spc569, 0xcb0bfa11 },
    { 0xacebad03, short_spc570, long_spc570, 0xcb0bfa11 },
    { 0xacebad03, short_spc571, long_spc571, 0xcb0bfa11 },
    { 0xacebad03, short_spc572, long_spc572, 0xcb0bfa11 },
    { 0xacebad03, short_spc573, long_spc573, 0xcb0bfa11 },
    { 0xacebad03, short_spc574, long_spc574, 0xcb0bfa11 },
    { 0xacebad03, short_spc575, long_spc575, 0xcb0bfa11 },
    { 0xacebad03, short_spc576, long_spc576, 0xcb0bfa11 },
    { 0xacebad03, short_spc577, long_spc577, 0xcb0bfa11 },
    { 0xacebad03, short_spc578, long_spc578, 0xcb0bfa11 },
    { 0xacebad03, short_spc579, long_spc579, 0xcb0bfa11 },
    { 0xacebad03, short_spc580, long_spc580, 0xcb0bfa11 },
    { 0xacebad03, short_spc581, long_spc581, 0xcb0bfa11 },
    { 0xacebad03, short_spc582, long_spc582, 0xcb0bfa11 },
    { 0xacebad03, short_spc583, long_spc583, 0xcb0bfa11 },
    { 0xacebad03, short_spc584, long_spc584, 0xcb0bfa11 },
    { 0xacebad03, short_spc585, long_spc585, 0xcb0bfa11 },
    { 0xacebad03, short_spc586, long_spc586, 0xcb0bfa11 },
    { 0xacebad03, short_spc587, long_spc587, 0xcb0bfa11 },
    { 0xacebad03, short_spc588, long_spc588, 0xcb0bfa11 },
    { 0xacebad03, short_spc589, long_spc589, 0xcb0bfa11 },
    { 0xacebad03, short_spc590, long_spc590, 0xcb0bfa11 },
    { 0xacebad03, short_spc591, long_spc591, 0xcb0bfa11 },
    { 0xacebad03, short_spc592, long_spc592, 0xcb0bfa11 },
    { 0xacebad03, short_spc593, long_spc593, 0xcb0bfa11 },
    { 0xacebad03, short_spc594, long_spc594, 0xcb0bfa11 },
    { 0xacebad03, short_spc595, long_spc595, 0xcb0bfa11 },
    { 0xacebad03, short_spc596, long_spc596, 0xcb0bfa11 },
    { 0xacebad03, short_spc597, long_spc597, 0xcb0bfa11 },
    { 0xacebad03, short_spc598, long_spc598, 0xcb0bfa11 },
    { 0xacebad03, short_spc599, long_spc599, 0xcb0bfa11 },
    { 0xacebad03, short_spc600, long_spc600, 0xcb0bfa11 },
    { 0xacebad03, short_spc601, long_spc601, 0xcb0bfa11 },
    { 0xacebad03, short_spc602, long_spc602, 0xcb0bfa11 },
    { 0xacebad03, short_spc603, long_spc603, 0xcb0bfa11 },
    { 0xacebad03, short_spc604, long_spc604, 0xcb0bfa11 },
    { 0xacebad03, short_spc605, long_spc605, 0xcb0bfa11 },
    { 0xacebad03, short_spc606, long_spc606, 0xcb0bfa11 },
    { 0xacebad03, short_spc607, long_spc607, 0xcb0bfa11 },
    { 0xacebad03, short_spc608, long_spc608, 0xcb0bfa11 },
    { 0xacebad03, short_spc609, long_spc609, 0xcb0bfa11 },
    { 0xacebad03, short_spc610, long_spc610, 0xcb0bfa11 },
    { 0xacebad03, short_spc611, long_spc611, 0xcb0bfa11 },
    { 0xacebad03, short_spc612, long_spc612, 0xcb0bfa11 },
    { 0xacebad03, short_spc613, long_spc613, 0xcb0bfa11 },
    { 0xacebad03, short_spc614, long_spc614, 0xcb0bfa11 },
    { 0xacebad03, short_spc615, long_spc615, 0xcb0bfa11 },
    { 0xacebad03, short_spc616, long_spc616, 0xcb0bfa11 },
    { 0xacebad03, short_spc617, long_spc617, 0xcb0bfa11 },
    { 0xacebad03, short_spc618, long_spc618, 0xcb0bfa11 },
    { 0xacebad03, short_spc619, long_spc619, 0xcb0bfa11 },
    { 0xacebad03, short_spc620, long_spc620, 0xcb0bfa11 },
    { 0xacebad03, short_spc621, long_spc621, 0xcb0bfa11 },
    { 0xacebad03, short_spc622, long_spc622, 0xcb0bfa11 },
    { 0xacebad03, short_spc623, long_spc623, 0xcb0bfa11 },
    { 0xacebad03, short_spc624, long_spc624, 0xcb0bfa11 },
    { 0xacebad03, short_spc625, long_spc625, 0xcb0bfa11 },
    { 0xacebad03, short_spc626, long_spc626, 0xcb0bfa11 },
    { 0xacebad03, short_spc627, long_spc627, 0xcb0bfa11 },
    { 0xacebad03, short_spc628, long_spc628, 0xcb0bfa11 },
    { 0xacebad03, short_spc629, long_spc629, 0xcb0bfa11 },
    { 0xacebad03, short_spc630, long_spc630, 0xcb0bfa11 },
    { 0xacebad03, short_spc631, long_spc631, 0xcb0bfa11 },
    { 0xacebad03, short_spc632, long_spc632, 0xcb0bfa11 },
    { 0xacebad03, short_spc633, long_spc633, 0xcb0bfa11 },
    { 0xacebad03, short_spc634, long_spc634, 0xcb0bfa11 },
    { 0xacebad03, short_spc635, long_spc635, 0xcb0bfa11 },
    { 0xacebad03, short_spc636, long_spc636, 0xcb0bfa11 },
    { 0xacebad03, short_spc637, long_spc637, 0xcb0bfa11 },
    { 0xacebad03, short_spc638, long_spc638, 0xcb0bfa11 },
    { 0xacebad03, short_spc639, long_spc639, 0xcb0bfa11 },
    { 0xacebad03, short_spc640, long_spc640, 0xcb0bfa11 },
    { 0xacebad03, short_spc641, long_spc641, 0xcb0bfa11 },
    { 0xacebad03, short_spc642, long_spc642, 0xcb0bfa11 },
    { 0xacebad03, short_spc643, long_spc643, 0xcb0bfa11 },
    { 0xacebad03, short_spc644, long_spc644, 0xcb0bfa11 },
    { 0xacebad03, short_spc645, long_spc645, 0xcb0bfa11 },
    { 0xacebad03, short_spc646, long_spc646, 0xcb0bfa11 },
    { 0xacebad03, short_spc647, long_spc647, 0xcb0bfa11 },
    { 0xacebad03, short_spc648, long_spc648, 0xcb0bfa11 },
    { 0xacebad03, short_spc649, long_spc649, 0xcb0bfa11 },
    { 0xacebad03, short_spc650, long_spc650, 0xcb0bfa11 },
    { 0xacebad03, short_spc651, long_spc651, 0xcb0bfa11 },
    { 0xacebad03, short_spc652, long_spc652, 0xcb0bfa11 },
    { 0xacebad03, short_spc653, long_spc653, 0xcb0bfa11 },
    { 0xacebad03, short_spc654, long_spc654, 0xcb0bfa11 },
    { 0xacebad03, short_spc655, long_spc655, 0xcb0bfa11 },
    { 0xacebad03, short_spc656, long_spc656, 0xcb0bfa11 },
    { 0xacebad03, short_spc657, long_spc657, 0xcb0bfa11 },
    { 0xacebad03, short_spc658, long_spc658, 0xcb0bfa11 },
    { 0xacebad03, short_spc659, long_spc659, 0xcb0bfa11 },
    { 0xacebad03, short_spc660, long_spc660, 0xcb0bfa11 },
    { 0xacebad03, short_spc661, long_spc661, 0xcb0bfa11 },
    { 0xacebad03, short_spc662, long_spc662, 0xcb0bfa11 },
    { 0xacebad03, short_spc663, long_spc663, 0xcb0bfa11 },
    { 0xacebad03, short_spc664, long_spc664, 0xcb0bfa11 },
    { 0xacebad03, short_spc665, long_spc665, 0xcb0bfa11 },
    { 0xacebad03, short_spc666, long_spc666, 0xcb0bfa11 },
    { 0xacebad03, short_spc667, long_spc667, 0xcb0bfa11 },
    { 0xacebad03, short_spc668, long_spc668, 0xcb0bfa11 },
    { 0xacebad03, short_spc669, long_spc669, 0xcb0bfa11 },
    { 0xacebad03, short_spc670, long_spc670, 0xcb0bfa11 },
    { 0xacebad03, short_spc671, long_spc671, 0xcb0bfa11 },
    { 0xacebad03, short_spc672, long_spc672, 0xcb0bfa11 },
    { 0xacebad03, short_spc673, long_spc673, 0xcb0bfa11 },
    { 0xacebad03, short_spc674, long_spc674, 0xcb0bfa11 },
    { 0xacebad03, short_spc675, long_spc675, 0xcb0bfa11 },
    { 0xacebad03, short_spc676, long_spc676, 0xcb0bfa11 },
    { 0xacebad03, short_spc677, long_spc677, 0xcb0bfa11 },
    { 0xacebad03, short_spc678, long_spc678, 0xcb0bfa11 },
    { 0xacebad03, short_spc679, long_spc679, 0xcb0bfa11 },
    { 0xacebad03, short_spc680, long_spc680, 0xcb0bfa11 },
    { 0xacebad03, short_spc681, long_spc681, 0xcb0bfa11 },
    { 0xacebad03, short_spc682, long_spc682, 0xcb0bfa11 },
    { 0xacebad03, short_spc683, long_spc683, 0xcb0bfa11 },
    { 0xacebad03, short_spc684, long_spc684, 0xcb0bfa11 },
    { 0xacebad03, short_spc685, long_spc685, 0xcb0bfa11 },
    { 0xacebad03, short_spc686, long_spc686, 0xcb0bfa11 },
    { 0xacebad03, short_spc687, long_spc687, 0xcb0bfa11 },
    { 0xacebad03, short_spc688, long_spc688, 0xcb0bfa11 },
    { 0xacebad03, short_spc689, long_spc689, 0xcb0bfa11 },
    { 0xacebad03, short_spc690, long_spc690, 0xcb0bfa11 },
    { 0xacebad03, short_spc691, long_spc691, 0xcb0bfa11 },
    { 0xacebad03, short_spc692, long_spc692, 0xcb0bfa11 },
    { 0xacebad03, short_spc693, long_spc693, 0xcb0bfa11 },
    { 0xacebad03, short_spc694, long_spc694, 0xcb0bfa11 },
    { 0xacebad03, short_spc695, long_spc695, 0xcb0bfa11 },
    { 0xacebad03, short_spc696, long_spc696, 0xcb0bfa11 },
    { 0xacebad03, short_spc697, long_spc697, 0xcb0bfa11 },
    { 0xacebad03, short_spc698, long_spc698, 0xcb0bfa11 },
    { 0xacebad03, short_spc699, long_spc699, 0xcb0bfa11 },
    { 0xacebad03, short_spc700, long_spc700, 0xcb0bfa11 },
    { 0xacebad03, short_spc701, long_spc701, 0xcb0bfa11 },
    { 0xacebad03, short_spc702, long_spc702, 0xcb0bfa11 },
    { 0xacebad03, short_spc703, long_spc703, 0xcb0bfa11 },
    { 0xacebad03, short_spc704, long_spc704, 0xcb0bfa11 },
    { 0xacebad03, short_spc705, long_spc705, 0xcb0bfa11 },
    { 0xacebad03, short_spc706, long_spc706, 0xcb0bfa11 },
    { 0xacebad03, short_spc707, long_spc707, 0xcb0bfa11 },
    { 0xacebad03, short_spc708, long_spc708, 0xcb0bfa11 },
    { 0xacebad03, short_spc709, long_spc709, 0xcb0bfa11 },
    { 0xacebad03, short_spc710, long_spc710, 0xcb0bfa11 },
    { 0xacebad03, short_spc711, long_spc711, 0xcb0bfa11 },
    { 0xacebad03, short_spc712, long_spc712, 0xcb0bfa11 },
    { 0xacebad03, short_spc713, long_spc713, 0xcb0bfa11 },
    { 0xacebad03, short_spc714, long_spc714, 0xcb0bfa11 },
    { 0xacebad03, short_spc715, long_spc715, 0xcb0bfa11 },
    { 0xacebad03, short_spc716, long_spc716, 0xcb0bfa11 },
    { 0xacebad03, short_spc717, long_spc717, 0xcb0bfa11 },
    { 0xacebad03, short_spc718, long_spc718, 0xcb0bfa11 },
    { 0xacebad03, short_spc719, long_spc719, 0xcb0bfa11 },
    { 0xacebad03, short_spc720, long_spc720, 0xcb0bfa11 },
    { 0xacebad03, short_spc721, long_spc721, 0xcb0bfa11 },
    { 0xacebad03, short_spc722, long_spc722, 0xcb0bfa11 },
    { 0xacebad03, short_spc723, long_spc723, 0xcb0bfa11 },
    { 0xacebad03, short_spc724, long_spc724, 0xcb0bfa11 },
    { 0xacebad03, short_spc725, long_spc725, 0xcb0bfa11 },
    { 0xacebad03, short_spc726, long_spc726, 0xcb0bfa11 },
    { 0xacebad03, short_spc727, long_spc727, 0xcb0bfa11 },
    { 0xacebad03, short_spc728, long_spc728, 0xcb0bfa11 },
    { 0xacebad03, short_spc729, long_spc729, 0xcb0bfa11 },
    { 0xacebad03, short_spc730, long_spc730, 0xcb0bfa11 },
    { 0xacebad03, short_spc731, long_spc731, 0xcb0bfa11 },
    { 0xacebad03, short_spc732, long_spc732, 0xcb0bfa11 },
    { 0xacebad03, short_spc733, long_spc733, 0xcb0bfa11 },
    { 0xacebad03, short_spc734, long_spc734, 0xcb0bfa11 },
    { 0xacebad03, short_spc735, long_spc735, 0xcb0bfa11 },
    { 0xacebad03, short_spc736, long_spc736, 0xcb0bfa11 },
    { 0xacebad03, short_spc737, long_spc737, 0xcb0bfa11 },
    { 0xacebad03, short_spc738, long_spc738, 0xcb0bfa11 },
    { 0xacebad03, short_spc739, long_spc739, 0xcb0bfa11 },
    { 0xacebad03, short_spc740, long_spc740, 0xcb0bfa11 },
    { 0xacebad03, short_spc741, long_spc741, 0xcb0bfa11 },
    { 0xacebad03, short_spc742, long_spc742, 0xcb0bfa11 },
    { 0xacebad03, short_spc743, long_spc743, 0xcb0bfa11 },
    { 0xacebad03, short_spc744, long_spc744, 0xcb0bfa11 },
    { 0xacebad03, short_spc745, long_spc745, 0xcb0bfa11 },
    { 0xacebad03, short_spc746, long_spc746, 0xcb0bfa11 },
    { 0xacebad03, short_spc747, long_spc747, 0xcb0bfa11 },
    { 0xacebad03, short_spc748, long_spc748, 0xcb0bfa11 },
    { 0xacebad03, short_spc749, long_spc749, 0xcb0bfa11 },
    { 0xacebad03, short_spc750, long_spc750, 0xcb0bfa11 },
    { 0xacebad03, short_spc751, long_spc751, 0xcb0bfa11 },
    { 0xacebad03, short_spc752, long_spc752, 0xcb0bfa11 },
    { 0xacebad03, short_spc753, long_spc753, 0xcb0bfa11 },
    { 0xacebad03, short_spc754, long_spc754, 0xcb0bfa11 },
    { 0xacebad03, short_spc755, long_spc755, 0xcb0bfa11 },
    { 0xacebad03, short_spc756, long_spc756, 0xcb0bfa11 },
    { 0xacebad03, short_spc757, long_spc757, 0xcb0bfa11 },
    { 0xacebad03, short_spc758, long_spc758, 0xcb0bfa11 },
    { 0xacebad03, short_spc759, long_spc759, 0xcb0bfa11 },
    { 0xacebad03, short_spc760, long_spc760, 0xcb0bfa11 },
    { 0xacebad03, short_spc761, long_spc761, 0xcb0bfa11 },
    { 0xacebad03, short_spc762, long_spc762, 0xcb0bfa11 },
    { 0xacebad03, short_spc763, long_spc763, 0xcb0bfa11 },
    { 0xacebad03, short_spc764, long_spc764, 0xcb0bfa11 },
    { 0xacebad03, short_spc765, long_spc765, 0xcb0bfa11 },
    { 0xacebad03, short_spc766, long_spc766, 0xcb0bfa11 },
    { 0xacebad03, short_spc767, long_spc767, 0xcb0bfa11 },
    { 0xacebad03, short_spc768, long_spc768, 0xcb0bfa11 },
    { 0xacebad03, short_spc769, long_spc769, 0xcb0bfa11 },
    { 0xacebad03, short_spc770, long_spc770, 0xcb0bfa11 },
    { 0xacebad03, short_spc771, long_spc771, 0xcb0bfa11 },
    { 0xacebad03, short_spc772, long_spc772, 0xcb0bfa11 },
    { 0xacebad03, short_spc773, long_spc773, 0xcb0bfa11 },
    { 0xacebad03, short_spc774, long_spc774, 0xcb0bfa11 },
    { 0xacebad03, short_spc775, long_spc775, 0xcb0bfa11 },
    { 0xacebad03, short_spc776, long_spc776, 0xcb0bfa11 },
    { 0xacebad03, short_spc777, long_spc777, 0xcb0bfa11 },
    { 0xacebad03, short_spc778, long_spc778, 0xcb0bfa11 },
    { 0xacebad03, short_spc779, long_spc779, 0xcb0bfa11 },
    { 0xacebad03, short_spc780, long_spc780, 0xcb0bfa11 },
    { 0xacebad03, short_spc781, long_spc781, 0xcb0bfa11 },
    { 0xacebad03, short_spc782, long_spc782, 0xcb0bfa11 },
    { 0xacebad03, short_spc783, long_spc783, 0xcb0bfa11 },
    { 0xacebad03, short_spc784, long_spc784, 0xcb0bfa11 },
    { 0xacebad03, short_spc785, long_spc785, 0xcb0bfa11 },
    { 0xacebad03, short_spc786, long_spc786, 0xcb0bfa11 },
    { 0xacebad03, short_spc787, long_spc787, 0xcb0bfa11 },
    { 0xacebad03, short_spc788, long_spc788, 0xcb0bfa11 },
    { 0xacebad03, short_spc789, long_spc789, 0xcb0bfa11 },
    { 0xacebad03, short_spc790, long_spc790, 0xcb0bfa11 },
    { 0xacebad03, short_spc791, long_spc791, 0xcb0bfa11 },
    { 0xacebad03, short_spc792, long_spc792, 0xcb0bfa11 },
    { 0xacebad03, short_spc793, long_spc793, 0xcb0bfa11 },
    { 0xacebad03, short_spc794, long_spc794, 0xcb0bfa11 },
    { 0xacebad03, short_spc795, long_spc795, 0xcb0bfa11 },
    { 0xacebad03, short_spc796, long_spc796, 0xcb0bfa11 },
    { 0xacebad03, short_spc797, long_spc797, 0xcb0bfa11 },
    { 0xacebad03, short_spc798, long_spc798, 0xcb0bfa11 },
    { 0xacebad03, short_spc799, long_spc799, 0xcb0bfa11 },
    { 0xacebad03, short_spc800, long_spc800, 0xcb0bfa11 },
    { 0xacebad03, short_spc801, long_spc801, 0xcb0bfa11 },
    { 0xacebad03, short_spc802, long_spc802, 0xcb0bfa11 },
    { 0xacebad03, short_spc803, long_spc803, 0xcb0bfa11 },
    { 0xacebad03, short_spc804, long_spc804, 0xcb0bfa11 },
    { 0xacebad03, short_spc805, long_spc805, 0xcb0bfa11 },
    { 0xacebad03, short_spc806, long_spc806, 0xcb0bfa11 }
};
static int class_to_index[] = {
    1058,33,122,146,1059,111,952,983,200,915,
    1068,139,4,1078,1071,923,229,228,927,965,
    170,171,178,120,131,176,177,169,210,213,
    221,218,238,833,3,857,182,181,935,184,
    185,992,1050,130,183,1085,25,274,270,975,
    981,980,976,18,0,978,974,979,977,0,
    0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,993,939,1083,0,0,
    157,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,
    0,940,168,973,153,845,0,1062
};
