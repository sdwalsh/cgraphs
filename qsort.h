#ifndef CGRAPH_QSORT_H
#define CGRAPH_QSORT_H
#import "graph.h"

// Mastering Algorithms with C : Chapter 12.6
int issort(void *data, int size, uint esize, int (*compare) (const edge* edge1, const edge* edge2));

int qksort(void *data, int size, uint esize, int i, int k, int (*compare) (const edge* edge1, const edge* edge2));


#endif
