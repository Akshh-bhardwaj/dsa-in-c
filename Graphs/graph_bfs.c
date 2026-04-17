/*
 * BFS — Breadth First Search
 * ==========================
 * Visit all nodes level by level using a queue.
 *
 * Applications (must know for interviews):
 *  - Shortest path in unweighted graph     ← VERY common
 *  - Level order traversal of a graph
 *  - Finding connected components
 *  - Bipartite check
 *  - 0-1 BFS for 0/1 weighted graphs
 *
 * Time  Complexity: O(V + E)
 * Space Complexity: O(V)  — queue + visited array
 *
 * Interview Question Pattern: "Find shortest path between A and B"
 * → BFS on unweighted graph = guaranteed shortest path
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXV 100

/* Adjacency list node */
typedef struct Node {
    int val;
    struct Node *next;
} Node;

Node *adj[MAXV];
int V;

void addEdge(int u, int v) {
    /* u -> v */
    Node *n1 = (Node *)malloc(sizeof(Node));
    n1->val = v; n1->next = adj[u]; adj[u] = n1;
    /* v -> u (undirected) */
    Node *n2 = (Node *)malloc(sizeof(Node));
    n2->val = u; n2->next = adj[v]; adj[v] = n2;
}

/* -------------------------------------------------------
 * BFS traversal from source src
 * ------------------------------------------------------- */
void bfs(int src) {
    bool visited[MAXV] = {false};
    int queue[MAXV];
    int front = 0, rear = 0;

    visited[src] = true;
    queue[rear++] = src;

    printf("BFS from %d: ", src);
    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);

        for (Node *curr = adj[u]; curr; curr = curr->next) {
            if (!visited[curr->val]) {
                visited[curr->val] = true;
                queue[rear++] = curr->val;
            }
        }
    }
    printf("\n");
}

/* -------------------------------------------------------
 * BFS Shortest Path (unweighted)
 * Returns -1 if no path exists
 * ------------------------------------------------------- */
int bfsShortestPath(int src, int dest) {
    bool visited[MAXV] = {false};
    int dist[MAXV];
    int parent[MAXV];
    int queue[MAXV];
    int front = 0, rear = 0;

    memset(dist,   -1, sizeof(dist));
    memset(parent, -1, sizeof(parent));

    visited[src] = true;
    dist[src] = 0;
    queue[rear++] = src;

    while (front < rear) {
        int u = queue[front++];
        for (Node *curr = adj[u]; curr; curr = curr->next) {
            int v = curr->val;
            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                parent[v] = u;
                queue[rear++] = v;
                if (v == dest) {
                    /* Reconstruct path */
                    int path[MAXV], plen = 0;
                    for (int x = dest; x != -1; x = parent[x])
                        path[plen++] = x;
                    printf("Shortest path %d -> %d (dist=%d): ", src, dest, dist[dest]);
                    for (int i = plen - 1; i >= 0; i--)
                        printf("%d%s", path[i], i ? " -> " : "\n");
                    return dist[dest];
                }
            }
        }
    }
    return -1;
}

int main() {
    V = 7;
    for (int i = 0; i < V; i++) adj[i] = NULL;

    /*   Graph:
     *   0 - 1 - 2
     *   |       |
     *   3 - 4 - 5
     *       |
     *       6
     */
    addEdge(0, 1); addEdge(1, 2);
    addEdge(0, 3); addEdge(2, 5);
    addEdge(3, 4); addEdge(4, 5);
    addEdge(4, 6);

    bfs(0);

    printf("\n");
    int d = bfsShortestPath(0, 6);
    if (d == -1) printf("No path exists!\n");

    d = bfsShortestPath(0, 5);

    return 0;
}
