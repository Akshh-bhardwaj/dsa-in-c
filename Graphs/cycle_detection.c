/*
 * Cycle Detection in Graphs
 * =========================
 *
 * Problem 1: Detect cycle in UNDIRECTED graph
 *   - DFS approach: if a visited neighbor is not the parent → cycle
 *   - Union-Find approach: if both ends of an edge are in same set → cycle
 *
 * Problem 2: Detect cycle in DIRECTED graph
 *   - DFS with recursion stack (recStack[])
 *   - If we visit a node that is already in the current recursion stack → cycle
 *
 * Interview note: "Course Schedule" (LeetCode 207) = directed cycle detection
 *
 * Time  Complexity: O(V + E) for both
 * Space Complexity: O(V)
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXV 10

/* ============================================================
 * Helper: Adjacency List
 * ============================================================ */
typedef struct Node { int val; struct Node *next; } Node;

Node *adjU[MAXV]; /* undirected */
Node *adjD[MAXV]; /* directed   */
int V;

void addEdgeU(int u, int v) {
    Node *n1 = (Node *)malloc(sizeof(Node)); n1->val = v; n1->next = adjU[u]; adjU[u] = n1;
    Node *n2 = (Node *)malloc(sizeof(Node)); n2->val = u; n2->next = adjU[v]; adjU[v] = n2;
}
void addEdgeD(int u, int v) { /* directed: u → v */
    Node *n  = (Node *)malloc(sizeof(Node)); n->val  = v; n->next  = adjD[u]; adjD[u] = n;
}

/* ============================================================
 * 1. Cycle in UNDIRECTED graph — DFS
 * ============================================================ */
bool dfsUndirected(int u, int parent, bool visited[]) {
    visited[u] = true;
    for (Node *c = adjU[u]; c; c = c->next) {
        if (!visited[c->val]) {
            if (dfsUndirected(c->val, u, visited)) return true;
        } else if (c->val != parent) {
            return true; /* Back edge found → cycle */
        }
    }
    return false;
}

bool hasCycleUndirected() {
    bool visited[MAXV] = {false};
    for (int i = 0; i < V; i++)
        if (!visited[i] && dfsUndirected(i, -1, visited))
            return true;
    return false;
}

/* ============================================================
 * 2. Cycle in UNDIRECTED graph — Union-Find
 * ============================================================ */
int parent[MAXV], rank_uf[MAXV];

void ufInit() {
    for (int i = 0; i < MAXV; i++) { parent[i] = i; rank_uf[i] = 0; }
}
int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]); /* Path compression */
    return parent[x];
}
bool unionSets(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) return false; /* Already in same set → cycle */
    if (rank_uf[px] < rank_uf[py]) { int t = px; px = py; py = t; }
    parent[py] = px;
    if (rank_uf[px] == rank_uf[py]) rank_uf[px]++;
    return true;
}

/* ============================================================
 * 3. Cycle in DIRECTED graph — DFS + recursion stack
 * ============================================================ */
bool dfsDirected(int u, bool visited[], bool recStack[]) {
    visited[u]  = true;
    recStack[u] = true;

    for (Node *c = adjD[u]; c; c = c->next) {
        if (!visited[c->val] && dfsDirected(c->val, visited, recStack))
            return true;
        else if (recStack[c->val])
            return true; /* Back edge in directed graph → cycle */
    }

    recStack[u] = false; /* Remove from current path */
    return false;
}

bool hasCycleDirected() {
    bool visited[MAXV]  = {false};
    bool recStack[MAXV] = {false};
    for (int i = 0; i < V; i++)
        if (!visited[i] && dfsDirected(i, visited, recStack))
            return true;
    return false;
}

/* ============================================================
 * MAIN
 * ============================================================ */
int main() {
    V = 5;
    for (int i = 0; i < V; i++) { adjU[i] = NULL; adjD[i] = NULL; }

    /* --- Undirected with cycle --- */
    addEdgeU(0,1); addEdgeU(1,2); addEdgeU(2,3); addEdgeU(3,0);
    printf("Undirected graph (0-1-2-3-0): %s\n",
           hasCycleUndirected() ? "Cycle FOUND ✓" : "No cycle ✗");

    /* Reset for no-cycle case */
    for (int i = 0; i < V; i++) adjU[i] = NULL;
    addEdgeU(0,1); addEdgeU(1,2); addEdgeU(2,3);
    printf("Undirected graph (0-1-2-3):   %s\n",
           hasCycleUndirected() ? "Cycle FOUND ✓" : "No cycle ✗");

    /* --- Union-Find cycle detection --- */
    ufInit();
    /* Edges: 0-1, 1-2, 2-0 → cycle */
    printf("\nUnion-Find cycle check:\n");
    printf("Add 0-1: %s\n", !unionSets(0,1) ? "Cycle" : "OK");
    printf("Add 1-2: %s\n", !unionSets(1,2) ? "Cycle" : "OK");
    printf("Add 2-0: %s\n", !unionSets(2,0) ? "Cycle FOUND ✓" : "OK");

    /* --- Directed cycle detection --- */
    printf("\nDirected graph:\n");
    /* 0→1→2→3→1 (cycle at 1-2-3) */
    addEdgeD(0,1); addEdgeD(1,2); addEdgeD(2,3); addEdgeD(3,1);
    printf("Directed graph (0→1→2→3→1): %s\n",
           hasCycleDirected() ? "Cycle FOUND ✓" : "No cycle");

    /* Directed no cycle: 0→1→2→3 (DAG) */
    for (int i = 0; i < V; i++) adjD[i] = NULL;
    addEdgeD(0,1); addEdgeD(1,2); addEdgeD(2,3);
    printf("Directed DAG  (0→1→2→3):   %s\n",
           hasCycleDirected() ? "Cycle FOUND" : "No cycle ✓");

    return 0;
}
