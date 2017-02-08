#include "graph.h"

double randomDouble() {
  return (double)rand() / (double)RAND_MAX;
}

double distance(point p1, point p2) {
  return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2) + pow(p1.w - p2.w, 2));
}

double getWeight(vertex v1, vertex v2) {
  return distance(v1.p, v2.p);
}

vertex* generateVertices(int n, int d) {
  vertex* vertices = (vertex*) malloc (n * sizeof(vertex));
  if (vertices == NULL) {
    return NULL;
  }
  for (int x = 0; x < n; x++) {
    vertices[x].p = (point) {randomDouble(), randomDouble(), randomDouble(), randomDouble()};
  }
  return vertices;
}

edge* generateEdges(int n, vertex* v) {
  edge* edges = (edge*) malloc (n * n * sizeof(edge));
  if (edges == NULL) {
    return NULL;
  }
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      edges[x*y].v1 = &v[y];
      edges[x*y].v2 = &v[x];
      edges[x*y].weight = getWeight(v[y], v[x]);
    }
  }
  return edges;
}

graph* generateGraph(int n, int d) {
  vertex* v = generateVertices(n, d);
  if (v == NULL) {
    return NULL;
  }
  edge* e = generateEdges(n, v);
  if (e == NULL) {
    return NULL;
  }
  return &(graph) {v, e};
}
