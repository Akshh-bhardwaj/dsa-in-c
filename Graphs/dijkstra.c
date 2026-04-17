/*
 * Dijkstra's Shortest Path Algorithm
 * ====================================
 * Single-source shortest path for graphs with NON-NEGATIVE edge weights.
 *
 * Algorithm:
 *   1. Init dist[] = INF, dist[src] = 0
 *   2. Use a min-priority-queue (here: simple linear scan for clarity)
 *   3. Pick unvisited vertex with minimum distance
 *   4. Relax all its neighbors
 *   5. Repeat until all vertices processed
 *
 * Time  Complexity: O(V^2) with array, O((V+E) log V) with min-heap
 * Space Complexity: O(V)
 *
 * Interview note:
 *   - Does NOT work with negative weights → use Bellman-Ford
 *   - LeetCode 743 "Network Delay Time"
 *   - LeetCode 787 "Cheapest Flights Within K Stops"
 *   - Google Maps, GPS routing
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define MAXV 10
#define INF  INT_MAX

int dist[MAXV];
bool visited[MAXV];
int parent[MAXV];
int graph[MAXV][MAXV]; /* Weighted adjacency matrix, 0 = no edge */
int V;

/* Pick unvisited vertex with minimum distance */
int minDistance() {
    int min = INF, minIdx = -1;
    for (int v = 0; v < V; v++)
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            minIdx = v;
        }
    return minIdx;
}

void dijkstra(int src) {
    /* Initialization */
    for (int i = 0; i < V; i++) {
        dist[i]    = INF;
        visited[i] = false;
        parent[i]  = -1;
    }
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance();
        if (u == -1) break;
        visited[u] = true;

        /* Relax neighbors */
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v]   = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
}

void printShortestPaths(int src) {
    printf("\nDijkstra from vertex %d:\n", src);
    printf("%-10s %-10s %s\n", "Vertex", "Distance", "Path");
    printf("------------------------------\n");
    for (int v = 0; v < V; v++) {
        printf("%-10d ", v);
        if (dist[v] == INF) {
            printf("%-10s", "INF");
        } else {
            printf("%-10d", dist[v]);
        }

        /* Print path */
        if (dist[v] != INF) {
            int path[MAXV], plen = 0;
            for (int x = v; x != -1; x = parent[x]) path[plen++] = x;
            for (int i = plen-1; i >= 0; i--)
                printf("%d%s", path[i], i > 0 ? " -> " : "");
        } else {
            printf("Unreachable");
        }
        printf("\n");
    }
}

int main() {
    /*
     *  Graph (directed, weighted):
     *         4
     *   0 -------> 1
     *   |        / | \
     *  8|       /  |  \9
     *   |     11   8   \
     *   v   /   v   v    v
     *   7 <-- - 2   6 <-- 5
     *   |  \        /
     *  1|   7\      /2
     *   v      v  v
     *   6 -----> 8
     *       6
     */

    V = 9;
    memset(graph, 0, sizeof(graph));

    /* Source: 0 */
    graph[0][1] = 4;  graph[0][7] = 8;
    graph[1][2] = 8;  graph[1][7] = 11;
    graph[2][3] = 7;  graph[2][5] = 4;  graph[2][8] = 2;
    graph[3][4] = 9;  graph[3][5] = 14;
    graph[4][5] = 10;
    graph[5][6] = 2;
    graph[6][7] = 1;  graph[6][8] = 6;
    graph[7][8] = 7;

    /* Make undirected */
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            if (graph[i][j]) graph[j][i] = graph[i][j];

    dijkstra(0);
    printShortestPaths(0);

    return 0;
}
