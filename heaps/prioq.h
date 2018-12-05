/* Do not edit this file. */

#ifndef PRIOQ_H
#define PRIOQ_H

#include "array.h"

struct heap {
    struct array *array;
    /* compare(a, b) compares a and b. It returns an integer less than, equal to,
       or greater than zero if a is found respectively, to be less than, to
       match, or be greater than b. */
    int (*compare)(const void *a, const void *b);
};

typedef struct heap prioq;

/* Create priority queue where the elements are ordered using the compare
 * function.
 * Return a pointer to empty prioq on success, NULL on error. */
prioq *prioq_init(int (*compare)(const void *, const void *));

/* Return the size of priority queue. */
long int prioq_size(struct heap *h);

/* Free the elements in the priority queue using the free_func()
 * parameter, then free the priority queue itself.
 * Return 0 on success, something else on error. */
int prioq_cleanup(prioq *h, void free_func(void *));

/* Insert the element p into the priority queue h.
 * Return 0 on success, something else on error. */
int prioq_insert(prioq *h, void *p);

/* Pop the top element from the prioq and return it.
   Return a pointer to top element on success, NULL on error. */
void *prioq_pop(prioq *h);

#endif
