#include <malloc.h>
#include <alloca.h>
#include <string.h>
#include "trie.h"

static cache_t trie_create(const cache_functions *underlying_functions);
static void trie_free(cache_t *cache);
static int trie_insert(cache_t cache, uintptr_t key, size_t size, void *data);
static int trie_delete(cache_t cache, uintptr_t key);
static void * trie_find(cache_t cache, uintptr_t key);
static int trie_next(cache_t cache, void **next);

cache_functions trie_functions = {
    .create = trie_create,
    .free = trie_free,
    .insert = trie_insert,
    .delete = trie_delete,
    .find = trie_find,
    .next = trie_next
};

typedef struct trie {
   struct trie *children[256];
   size_t size;
   void *data;
} trie;

static const int num_children = sizeof(((trie *)0)->children) / sizeof(((trie *)0)->children[0]);

static cache_t trie_create(const cache_functions *underlying_functions) {
    trie *t = malloc(sizeof(trie));
    memset(t, 0, sizeof(trie));

    return (cache_t)t;
}

static void trie_free(cache_t *cache) {
    trie *t = *(trie **)cache;
    int level = 0;
    int index_stack[9];
    trie *trie_stack[9];
    index_stack[0] = 0;
    trie_stack[0] = t;

    while(level >= 0) {
        int is_empty = 1;
        t = trie_stack[level];
        for (int i = index_stack[level]; i < num_children; ++i) {
            if (t->children[i] != NULL) {
                index_stack[level] = i + 1;
                level++;
                index_stack[level] = 0;
                trie_stack[level] = t->children[i];
                is_empty = 0;
                break;
            }
        }
        if (!is_empty) {
            continue;
        }
        free(t);
        level--;
    }

    *cache = NULL;
}

static int trie_insert(cache_t cache, uintptr_t key, size_t size, void *data) {
    trie *t = (trie *)cache;
    unsigned char *b;
    unsigned char *s = (unsigned char *)(&key);
    trie *next;

    for (b = (unsigned char *)&key + sizeof(key) - 1; b >= s; --b) {
        next = t->children[(unsigned int)*b];
        if (next == NULL) {
            break;
        }

        t = next;
    }

    if (b == s) {
        /* already inserted */
        return 1;
    }

    for (; b >= s; --b) {
        t->children[(unsigned int)*b] = malloc(sizeof(trie));
        t = t->children[(unsigned int)*b];
        memset(t, 0, sizeof(trie));
    }
    t->size = size;
    t->data = (void *)key;

    return 0;
}

static int trie_delete(cache_t cache, uintptr_t key) {
    trie *t = (trie *)cache;
    unsigned char *b;
    unsigned char *s = (unsigned char *)(&key);
    trie *next;
    int level = 0;

    trie *stack[9];
    stack[level] = t;

    for (b = (unsigned char *)&key + sizeof(key) - 1; b >= s; --b) {
        next = t->children[(unsigned int)*b];
        if (next == NULL) {
            break;
        }

        t = next;
        level++;
        stack[level] = t;
    }

    if (b >= s) {
        /* key does not exist in trie */
        return 1;
    }

    /* Remove the leave node */
    free(stack[8]);
    level = 7;

    /* Remove intermediate nodes if they don't lead to any leaf nodes anymore */
    for (b = s; b < (unsigned char *)&key + sizeof(key); ++b) {
        int is_empty = 1;

        /* grab the node containing child corresponding to this character */
        t = stack[level];

        /* blank out the deleted trie */
        t->children[(unsigned int)*b] = NULL;

        /* check for emptiness */
        for (int i = 0; i < num_children; ++i) {
            if (t->children[i] != NULL) {
                is_empty = 0;
                break;
            }
        }

        /* Don't delete if not empty or the root node */
        if (!is_empty || level == 0) {
            break;
        }
        free(t);
        level--;
    }

    return 0;
}

static void * trie_find(cache_t cache, uintptr_t key) {
    trie *t = (trie *)cache;
    uintptr_t closest_key = key;
    unsigned char *b;
    unsigned char *s = (unsigned char *)(&closest_key);
    trie *next;
    int level = 0;
    int i;

    trie *stack[9];
    stack[level] = t;

    for (b = (unsigned char *)&closest_key + sizeof(closest_key) - 1; b >= s; --b) {
        next = t->children[(unsigned int)*b];
        if (next == NULL) {
            break;
        }

        t = next;

        /* keep track of visited nodes so we can easily find ancestors */
        level++;
        stack[level] = t;
    }

    if (b < s) {
        /* Exact match found. Let's get outta here */
        return t->data;
    }

    /* Exact key does not exist in trie. Look for allocation with the next lowest
     * base pointer address */
    while (level >= 0) {
        t = stack[level];
        for (i = *b - 1; i >= 0; --i) {
            if (t->children[i] != NULL) {
                break;
            }
        }
        if (i >= 0) {
            break;
        }

        /* No branches leading to lower addresses at this level. Must go up */
        level--;
        b++;
    }

    if (level < 0) {
        /* No base pointer addresses less than the query */
        return NULL;
    }

    *b = i;
    b--;
    t = t->children[i];
    level++;

    /* Keep grabbing the largest branch at each level until until we've
     * constructed a full address */
    while (b >= s) {
        for (int i = num_children - 1; i >= 0; i--) {
            if (t->children[i] != NULL) {
                t = t->children[i];
                *b = (char)i;
                b--;
                break;
            }
        }
    }

    if (closest_key + t->size <= key) {
        /* key not within range of allocation with next lowest base pointer address */
        return NULL;
    }

    return t->data;
}

static int trie_next(cache_t cache, void **next) {
    return 1;
}
