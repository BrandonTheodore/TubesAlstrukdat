#include <stdio.h>
#include <stdlib.h>
#include "optimasiRute.h"

void createGraph(Graph *g) {
    g->nodes = 0;
    g->edges = 0;
    g->totalDistance = 0;
    
    for(int i = 0; i < MAX_NODES; i++) {
        for(int j = 0; j < MAX_NODES; j++) {
            g->graph[i][j] = INF;
        }
        g->path[i] = -1;
    }
}

void addEdge(Graph *g, int from, int to, int weight) {
    g->graph[from][to] = weight;
    g->graph[to][from] = weight;
    g->edges++;
}

void findBestRoute(Graph *g, int current, int depth, int currentDist,
    int visited, int tempPath[], int *bestDist, int bestPath[]) {
    if (depth == g->nodes) {
        if (currentDist < *bestDist) {
            *bestDist = currentDist;
            for (int i = 0; i < g->nodes; i++) {
                bestPath[i] = tempPath[i];
            }
        }
        return;
    }

    for (int next = 0; next < g->nodes; next++) {
        if (!(visited & (1 << next)) && g->graph[current][next] != INF) {
            tempPath[depth] = next;
            findBestRoute(g, next, depth + 1,
                         currentDist + g->graph[current][next],
                         visited | (1 << next),
                         tempPath, bestDist, bestPath);
        }
    }
}

void findOptimalRoute(Graph *g) {
    int tempPath[MAX_NODES];
    int bestPath[MAX_NODES];
    int bestDist = INF;
    
    tempPath[0] = 0; 
    
    findBestRoute(g, 0, 1, 0, 1, tempPath, &bestDist, bestPath);
    
    g->totalDistance = bestDist;
    for (int i = 0; i < g->nodes; i++) {
        g->path[i] = bestPath[i];
    }
}

void processRoute() {
    Graph g;
    createGraph(&g);
    
    printf(">> OPTIMASIRUTE\n");
    printf("Masukkan jumlah lokasi pengiriman (node): ");
    
    STARTWORD2();
    g.nodes = wordToInt(currentWord);
    
    printf("Masukkan jumlah rute (edge): ");
    STARTWORD2();
    int edges = wordToInt(currentWord);


    int maxEdges = (g.nodes * (g.nodes - 1)) / 2;  
    int minEdges = g.nodes - 1;                   

    if (edges > maxEdges) {
        printf("\n");
        printf("Jumlah edge terlalu banyak untuk %d node!\n", g.nodes);
        printf("Maksimum edge yang mungkin: %d\n", maxEdges);
        return;
    }

    if (edges < minEdges) {
        printf("\n");
        printf("Jumlah edge terlalu sedikit untuk %d node!\n", g.nodes);
        printf("Minimum edge yang dibutuhkan: %d\n", minEdges);
        return;
    }

    printf("Masukkan jarak antarlokasi (weight) dengan format <from> <to> <weight> :\n");

    for(int i = 0; i < edges; i++) {
        int from, to, weight;
        
        STARTWORD2();

        int spaceCount = 0;
        for(int j = 0; j < currentWord.Length; j++) {
            if(currentWord.TabWord[j] == ' ') {
                spaceCount++;
            }
        }
        
        if(spaceCount != 2) {
            printf("Command tidak valid! Format harus: <from> <to> <weight>\n");
            return;
        }
        
        for(int j = 0; j < currentWord.Length; j++) {
            if(currentWord.TabWord[j] != ' ' && 
            (currentWord.TabWord[j] < '0' || currentWord.TabWord[j] > '9')) {
                printf("Command tidak valid! Masukan harus berupa angka.\n");
                return;
            }
        }

        int num = 0;
        int numbers[3] = {0, 0, 0};  
        int numIndex = 0; 
        
        for(int j = 0; j < currentWord.Length; j++) {
            if(currentWord.TabWord[j] == ' ') {
                numbers[numIndex] = num;
                numIndex++;
                num = 0;
            } else {
                num = num * 10 + (currentWord.TabWord[j] - '0');
            }
        }
        numbers[numIndex] = num;
        
        from = numbers[0];
        to = numbers[1];
        weight = numbers[2];
        
        addEdge(&g, from, to, weight);
    }

    printf("Data diterima, silakan tunggu…\n");
    
    findOptimalRoute(&g);
    
    printf("A-ha! Rute paling efektif adalah ");
    for(int i = 0; i < g.nodes; i++) {
        printf("%d", g.path[i]);
        if(i < g.nodes - 1) printf("-");
    }
    printf(".\n");
    printf("Total jarak: %d\n", g.totalDistance);
}
