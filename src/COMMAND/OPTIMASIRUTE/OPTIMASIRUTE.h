#include <stdio.h>
#include "../master_header_command.h"

#ifndef OPTIMASI_RUTE_H
#define OPTIMASI_RUTE_H

#define MAX_NODES 100
#define INF 99999

typedef struct {
    int graph[MAX_NODES][MAX_NODES];
    int nodes;
    int edges;
    int totalDistance;
    int path[MAX_NODES];
} Graph;

void createGraph(Graph *g);
void addEdge(Graph *g, int from, int to, int weight);
void findOptimalRoute(Graph *g);
void processRoute();

#endif
