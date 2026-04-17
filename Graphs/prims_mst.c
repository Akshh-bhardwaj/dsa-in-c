/*
 * Prim's Minimum Spanning Tree
 * =============================
 * Builds the MST by always adding the minimum weight edge that connects
 * a new vertex to the growing MST.
 *
 * Algorithm:
 *   1. Start from any vertex (say 0), mark it in MST
 *   2. key[] tracks the minimum edge weight to reach each vertex
 *   3. At each step, pick the vertex NOT in MST with smallest key value
 *   4. Update keys of its neighbors if a smaller edge is found
 *
 * Time  Complexity: O(V^2) with array, O(E log V) with min-heap
 * Space Complexity: O(V)
 *
 * Prim vs Kruskal:
 *   - Prim  → better for DENSE graphs (many edges)
 *   - Kruskal → better for SPARSE graphs (fewer edges)
 *
 * Interview note:
 *   - Both must know algorithms for any SWE interview
 *   - LeetCode 1584 "Min Cost to Connect All Points" (Prim or Kruskal)
 */

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

#define MAXV  10
#define INF   INT_MAX

int graph[MAXV][MAXV]; /* Weighted adjacency matrix */
int V;

int key[MAXV];      /* Minimum weight edge to include each vertex */
int parent[MAXV];   /* MST parent array */
bool inMST[MAXV];   /* Is this vertex already in MST? */

/* Pick vertex NOT in MST with minimum key value */
int minKey() {
    int min = INF, minIdx = -1;
    for (int v = 0; v < V; v++)
        if (!inMST[v] && key[v] < min) {
            min = key[v];
            minIdx = v;
        }
    return minIdx;
}

void primMST() {
    /* Initialize */
    for (int i = 0; i < V; i++) {
        key[i]    = INF;
        inMST[i]  = false;
        parent[i] = -1;
    }
    key[0] = 0; /* Start from vertex 0 */

    for (int count = 0; count < V - 1; count++) {
        int u = minKey();
        if (u == -1) break;
        inMST[u] = true;

        /* Update key values of adjacent vertices */
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v]    = graph[u][v];
                parent[v] = u;
            }
        }
    }

    /* Print MST */
    printf("Prim's MST:\n");
    printf("%-8s %-8s %-8s\n", "Edge", "->", "Weight");
    printf("------------------------\n");
    int total = 0;
    for (int v = 1; v < V; v++) {
        printf("  %d   <->   %d   :   %d\n", parent[v], v, graph[parent[v]][v]);
        total += graph[parent[v]][v];
    }
    printf("Total MST Weight: %d\n", total);
}

int main() {
    /*
     *  Graph (same as Kruskal example for easy comparison):
     *       2
     *   0 ----- 3
     *   |  \    |  \
     *  6|   8\  |5   \7
     *   |     \ |     \
     *   1 ----- 2 ---- 4
     *       3       9
     */
    V = 5;
    memset(graph, 0, sizeof(graph));

    /* Helper to set undirected weighted edge */
    #define ADD(u,v,w) graph[u][v] = graph[v][u] = w

    ADD(0, 1, 6);
    ADD(0, 2, 8);
    ADD(0, 3, 2);
    ADD(1, 2, 3);
    ADD(2, 3, 5);
    ADD(2, 4, 9);
    ADD(3, 4, 7);

    primMST();

    return 0;
}
