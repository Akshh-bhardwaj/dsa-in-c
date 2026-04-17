/*
 * Floyd-Warshall Algorithm
 * ========================
 * ALL-PAIRS shortest path — finds shortest path between every pair (i, j).
 * Works with negative edges; detects negative cycles.
 *
 * Core idea (DP):
 *   dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
 *   for every intermediate vertex k from 0..V-1
 *
 * Time  Complexity: O(V^3)
 * Space Complexity: O(V^2)
 *
 * Interview note:
 *   - When you need ALL-PAIRS shortest paths (not just from one source)
 *   - Network routing tables
 *   - LeetCode 1334 "Find the City With the Smallest Number of Neighbors"
 *   - Simple to code in interviews (just 3 nested loops!)
 */

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

#define MAXV  6
#define INF   99999   /* Use a large number, NOT INT_MAX (overflow risk) */

int dist[MAXV][MAXV];
int next_v[MAXV][MAXV]; /* for path reconstruction */
int V;

void floydWarshall() {
    /* Initialize next_v for path reconstruction */
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            next_v[i][j] = (dist[i][j] == INF) ? -1 : j;

    /* Main DP: try every vertex k as intermediate */
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j]  = dist[i][k] + dist[k][j];
                    next_v[i][j] = next_v[i][k];
                }
            }
        }
    }
}

bool hasNegativeCycle() {
    for (int i = 0; i < V; i++)
        if (dist[i][i] < 0) return true;
    return false;
}

void printPath(int u, int v) {
    if (next_v[u][v] == -1) { printf("No path"); return; }
    printf("%d", u);
    while (u != v) {
        u = next_v[u][v];
        printf(" -> %d", u);
    }
}

void printResults() {
    printf("\nAll-Pairs Shortest Distances:\n");
    printf("      ");
    for (int j = 0; j < V; j++) printf("%6d", j);
    printf("\n      ");
    for (int j = 0; j < V; j++) printf("------");
    printf("\n");
    for (int i = 0; i < V; i++) {
        printf("%4d |", i);
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) printf("%6s", "INF");
            else printf("%6d", dist[i][j]);
        }
        printf("\n");
    }

    printf("\nSample paths:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i != j) {
                printf("  %d -> %d : ", i, j);
                printPath(i, j);
                printf(" (cost: %d)\n", dist[i][j] == INF ? -1 : dist[i][j]);
            }
        }
    }
}

int main() {
    V = 4;

    /*  Graph:
     *    0 --3-- 1
     *    |    \  |
     *    5      8  2
     *    |        \|
     *    3 --(-4)- 2
     */
    int g[4][4] = {
        {  0,  3,  INF,  5 },
        {  2,  0,  INF,  4 },
        {INF,  1,    0,INF },
        {INF,INF,  -4,   0 }
    };

    /* Copy to dist */
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = g[i][j];

    floydWarshall();

    if (hasNegativeCycle()) {
        printf("⚠️  Negative cycle detected!\n");
    } else {
        printResults();
    }

    return 0;
}
