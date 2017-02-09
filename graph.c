#include "graph.h"

double randomDouble() {
    return (double) PMrand();
}

point genPoint1D() {
    return (point) {randomDouble(), (double) 0.0, (double) 0.0, (double) 0.0};
}

point genPoint2D() {
    return (point) {randomDouble(), randomDouble(), (double) 0.0, (double) 0.0};
}

point genPoint3D() {
    return (point) {randomDouble(), randomDouble(), randomDouble(), (double) 0.0};
}

point genPoint4D() {
    return (point) {randomDouble(), randomDouble(), randomDouble(), randomDouble()};
}

double distance(point p1, point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2) + pow(p1.w - p2.w, 2));
}

double weight(vertex v1, vertex v2) {
    return distance(v1.p, v2.p);
}

vertex *generateVertices(int n, int d) {
    vertex *vertices = (vertex *) malloc(n * sizeof(vertex));
    if (vertices == NULL) {
        return NULL;
    }
    for (int x = 0; x < n; x++) {
        //(vertices + (sizeof(vertex) * n) = genPoint4D();
        vertices[x].p = genPoint1D();
    }
    return vertices;
}

edge *generateEdges(int n, vertex *v) {
    edge *edges = (edge *) malloc((n * (n - 1) / 2) * sizeof(edge));
    if (edges == NULL) {
        return NULL;
    }
    edge *ptr = edges;
    for (int x = 0; x < (n / 2); x++) {
        for (int y = 0; y < n; y++) {
            if (x != y) {
                ptr->v1 = &v[y];
                ptr->v2 = &v[x];
                ptr->weight = weight(v[x], v[y]);
                ptr++;
            }
        }
    }
    return edges;
}

graph *generateGraph(int n, int d) {
    vertex *v = generateVertices(n, d);
    if (v == NULL) {
        return NULL;
    }
    edge *e = generateEdges(n, v);
    if (e == NULL) {
        return NULL;
    }
    return &(graph) {v, e};
}
