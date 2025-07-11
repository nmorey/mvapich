#ifndef CACHE_H
#define CACHE_H 1

#include <stdint.h>
#include <stddef.h>

struct cache_functions;

/* cache handle */
typedef void *cache_t;

/* create cache and return handle */
typedef cache_t (*cache_create_t) (const struct cache_functions *);

/* release resources associated with cache handle */
typedef void (*cache_free_t) (cache_t *);

/* insert key/value pair into cache */
typedef int (*cache_insert_t) (cache_t, uintptr_t key, size_t size, void * data);

/* delete key/value pair from cache if key is found */
typedef int (*cache_delete_t) (cache_t, uintptr_t key);

/* return value from key/value pair if found in cache */
typedef void * (*cache_find_t) (cache_t, uintptr_t key);

/* apply foreach function to each value */
typedef int (*cache_next_t) (cache_t, void **);

/* cache implementations will declare a variable of the following type */
typedef struct cache_functions {
    cache_create_t create;
    cache_free_t free;
    cache_insert_t insert;
    cache_delete_t delete;
    cache_find_t find;
    cache_next_t next;
} cache_functions;

#endif /* #ifndef CACHE */
