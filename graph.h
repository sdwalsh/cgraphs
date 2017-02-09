#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "random.h"

typedef struct {
  double x, y, z, w;
} point;

typedef struct {
  point p;
} vertex;

typedef struct {
  vertex* v1;
  vertex* v2;
  double weight;
} edge;

typedef struct {
  vertex* v;
  edge* e;
} graph;

double weight(vertex v1, vertex v2);

vertex* generateVertices(int n, int d);

edge* generateEdges(int n, vertex* v);

graph* generateGraph(int n, int d);

#endif
