/*
 * Bellman-Ford Algorithm
 * ======================
 * Single-source shortest path that handles NEGATIVE WEIGHT EDGES.
 * Also detects negative weight cycles.
 *
 * Algorithm:
 *   1. Init dist[src] = 0, all others = INF
 *   2. Relax ALL edges (V-1) times
 *   3. On V-th relaxation: if any distance still decreases → negative cycle
 *
 * Why (V-1) iterations?
 *   The shortest path in a graph with V vertices has at most V-1 edges.
 *
 * Time  Complexity: O(V * E)
 * Space Complexity: O(V)
 *
 * Interview note:
 *   Use Dijkstra when no negative weights (faster).
 *   Use Bellman-Ford when negative weights exist.
 *   LeetCode 743, 787 may need Bellman-Ford variant.
 */

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

#define MAXV 10
#define MAXE 50
#define INF  INT_MAX

typedef struct {
    int src, dest, weight;
} Edge;

Edge edges[MAXE];
int V, E;

void bellmanFord(int src) {
    int dist[MAXV];
    int parent[MAXV];

    /* Step 1: Initialize distances */
    for (int i = 0; i < V; i++) {
        dist[i]   = INF;
        parent[i] = -1;
    }
    dist[src] = 0;

    /* Step 2: Relax edges V-1 times */
    for (int i = 1; i <= V - 1; i++) {
        bool updated = false;
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v]   = dist[u] + w;
                parent[v] = u;
                updated = true;
            }
        }
        if (!updated) break; /* Early termination */
    }

    /* Step 3: Check for negative-weight cycles */
    bool negCycle = false;
    for (int j = 0; j < E; j++) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int w = edges[j].weight;
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            negCycle = true;
            break;
        }
    }

    /* Print results */
    printf("Bellman-Ford from vertex %d:\n", src);
    if (negCycle) {
        printf("⚠️  Negative weight cycle detected! Shortest paths unreliable.\n");
        return;
    }
    printf("%-10s %-12s %s\n", "Vertex", "Distance", "Path");
    printf("-------------------------------\n");
    for (int v = 0; v < V; v++) {
        printf("%-10d ", v);
        if (dist[v] == INF) {
            printf("%-12s Unreachable\n", "INF");
            continue;
        }
        printf("%-12d", dist[v]);
        /* Print path */
        int path[MAXV], plen = 0;
        for (int x = v; x != -1; x = parent[x]) path[plen++] = x;
        for (int i = plen-1; i >= 0; i--)
            printf("%d%s", path[i], i > 0 ? " -> " : "\n");
    }
}

int main() {
    /* Graph with negative edges (but no negative cycle) */
    V = 5; E = 8;
    edges[0] = (Edge){0, 1, -1};
    edges[1] = (Edge){0, 2,  4};
    edges[2] = (Edge){1, 2,  3};
    edges[3] = (Edge){1, 3,  2};
    edges[4] = (Edge){1, 4,  2};
    edges[5] = (Edge){3, 2,  5};
    edges[6] = (Edge){3, 1,  1};
    edges[7] = (Edge){4, 3, -3};

    printf("=== Bellman-Ford (negative weights, no cycle) ===\n");
    bellmanFord(0);

    /* Graph with negative cycle */
    printf("\n=== Bellman-Ford (negative weight CYCLE) ===\n");
    V = 3; E = 3;
    edges[0] = (Edge){0, 1, 1};
    edges[1] = (Edge){1, 2, -3};
    edges[2] = (Edge){2, 0,  1}; /* cycle: 0→1→2→0, weight=-1 → negative cycle */
    bellmanFord(0);

    return 0;
}
