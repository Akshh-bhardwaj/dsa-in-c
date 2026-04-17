/*
 * Bridges and Articulation Points (Tarjan's Algorithm)
 * ======================================================
 * Bridge: An edge whose removal disconnects the graph.
 * Articulation Point: A vertex whose removal disconnects the graph.
 *
 * Algorithm (Tarjan's):
 *   - disc[u]  = discovery time of vertex u
 *   - low[u]   = minimum discovery time reachable from subtree of u
 *   - If low[v] > disc[u] for edge u-v → (u,v) is a BRIDGE
 *   - If u is root with ≥2 DFS children → ARTICULATION POINT
 *   - If u is not root and low[v] >= disc[u] → u is ARTICULATION POINT
 *
 * Time  Complexity: O(V + E)
 * Space Complexity: O(V)
 *
 * Interview note:
 *   - LeetCode 1192 "Critical Connections in a Network" (find all bridges)
 *   - Used in network reliability analysis
 *   - Finding single points of failure in systems
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define MAXV 10

typedef struct Node { int val; struct Node *next; } Node;
Node *adj[MAXV];
int V;

int disc[MAXV];   /* Discovery time */
int low[MAXV];    /* Lowest reachable disc time */
bool visited[MAXV];
bool isAP[MAXV];  /* Is articulation point? */
int timer_g = 0;

void addEdge(int u, int v) {
    Node *n1 = (Node *)malloc(sizeof(Node)); n1->val = v; n1->next = adj[u]; adj[u] = n1;
    Node *n2 = (Node *)malloc(sizeof(Node)); n2->val = u; n2->next = adj[v]; adj[v] = n2;
}

void dfs(int u, int parent) {
    visited[u] = true;
    disc[u] = low[u] = timer_g++;
    int childCount = 0;

    for (Node *c = adj[u]; c; c = c->next) {
        int v = c->val;
        if (!visited[v]) {
            childCount++;
            dfs(v, u);
            low[u] = low[u] < low[v] ? low[u] : low[v]; /* min */

            /* ---- BRIDGE check ---- */
            if (low[v] > disc[u]) {
                printf("Bridge: %d -- %d\n", u, v);
            }

            /* ---- ARTICULATION POINT check ---- */
            if (parent == -1 && childCount > 1) isAP[u] = true;
            if (parent != -1 && low[v] >= disc[u])  isAP[u] = true;

        } else if (v != parent) {
            /* Back edge: update low */
            low[u] = low[u] < disc[v] ? low[u] : disc[v];
        }
    }
}

void findBridgesAndAPs() {
    memset(visited, false, sizeof(visited));
    memset(isAP,    false, sizeof(isAP));
    timer_g = 0;

    for (int i = 0; i < V; i++)
        if (!visited[i]) dfs(i, -1);

    printf("Articulation Points: ");
    bool found = false;
    for (int i = 0; i < V; i++)
        if (isAP[i]) { printf("%d ", i); found = true; }
    if (!found) printf("None");
    printf("\n");
}

int main() {
    /*
     *  Graph:
     *  1 -- 0 -- 3
     *  |    |
     *  2    4
     *
     *  Bridges: 0-3, 0-4
     *  Articulation Point: 0
     */
    printf("=== Test 1 ===\n");
    V = 5;
    for (int i = 0; i < V; i++) adj[i] = NULL;
    addEdge(1, 0); addEdge(0, 2); addEdge(2, 1);
    addEdge(0, 3); addEdge(3, 4);
    findBridgesAndAPs();

    /*
     *  Graph:
     *  0 -- 1 -- 2 -- 3
     *             |
     *             4
     *  Bridges: 0-1, 1-2, 2-3, 2-4
     *  APs: 1, 2
     */
    printf("\n=== Test 2 ===\n");
    V = 5;
    for (int i = 0; i < V; i++) adj[i] = NULL;
    addEdge(0, 1); addEdge(1, 2); addEdge(2, 3); addEdge(2, 4);
    findBridgesAndAPs();

    return 0;
}
