#include <stdio.h>
#include "graph.h"

int main(void) {
    /* Eventually grab from standard input */
    int flag = 0;
    int numpoints = 500;
    int numtrails = 0;
    int dimension = 4;

    graph *g = generateGraph(numpoints, dimension);
    if (g == NULL) {
        exit(0);
    }

    edge *ptr = g->e;

    for (int x = 0; x < numpoints; x++, ptr++) {
        printf("Vertex %f \n", ptr->weight);
    }
}
