/***************************************************************************************
*    Title: Quicksort
*    Author:  Kyle Loudon
*    Date: 1999
*    Code version: 1.0.0
*    Availability: Mastering Algorithms with C
*
***************************************************************************************/
#include <stdlib.h>
#include <string.h>
#include "qsort.h"

// compare the weights of two edges
static int compare_weights(const edge* edge1, const edge* edge2) {
    if (edge1->weight > edge2->weight) {
        return 1;
    } else if (edge1->weight < edge2->weight) {
        return -1;
    } else {
        return 0;
    }
}

int issort(void *data, int size, uint esize, int (*compare) (const edge* edge1, const edge* edge2)) {
    edge* e = data;
    void* key;
    int i, j;

    if ((key = (edge*) malloc (esize)) == NULL) {
        return -1;
    }

    for (j = 1; j < size; j++) {
        memcpy(key, &e[j * esize], esize);
        i = j - 1;

        while (i >= 0 && compare(&e[i  * esize], key) > 0) {
            memcpy(&e[(i + 1) * esize], &e[i * esize], esize);
            i--;
        }

        memcpy(&e[(i + 1) * esize], key, esize);
    }
    free(key);
    return 0;
}


static int partition(edge* data, uint esize, int i, int k, int (*compare)(const edge* edge1, const edge* edge2)) {
    edge *a = data;
    void *pval, *temp;
    int r[3];

    if ((pval = malloc(esize)) == NULL) {
        return -1;
    }

    if ((temp = malloc(esize)) == NULL) {
        free(pval);
        return -1;
    }

    // median-of-three method
    r[0] = (rand() % (k - i + 1)) + i;
    r[1] = (rand() % (k - i + 1)) + i;
    r[2] = (rand() % (k - i + 1)) + i;
    issort(r, 3, sizeof(int), compare_weights);
    memcpy(pval, &a[r[1] * esize], esize);

    i--;
    k--;

    while (1) {
        do {
            k--;
        } while (compare(&a[k * esize], pval) > 0);

        do {
            i++;
        } while (compare(&a[i * esize], pval) < 0);

        if (i >= k) {
            break;
        } else {
            memcpy(temp, &a[i * esize], esize);
            memcpy(&a[i * esize], &a[k * esize], esize);
            memcpy(&a[k * esize], temp, esize);
        }
    }
    free(pval);
    free(temp);
    return k;
}

int qksort(void *data, int size, uint esize, int i, int k, int (*compare) (const edge* edge1, const edge* edge2)) {
    int j;

    while (i < k) {
        if ((j = partition(data, esize, i, k, compare)) < 0) {
            return -1;
        }

        if (qksort(data, size, esize, i, j, compare) < 0) {
            return -1;
        }

        i = j + 1;
    }
    return 0;
}
