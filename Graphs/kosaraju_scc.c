/*
 * Strongly Connected Components (SCC) — Kosaraju's Algorithm
 * ===========================================================
 * An SCC is a maximal set of vertices such that there is a path from
 * each vertex to every other vertex in the set.
 *
 * Kosaraju's Algorithm (2 DFS passes):
 *   Pass 1: Run DFS on ORIGINAL graph, push vertices to stack in finish order
 *   Pass 2: Transpose the graph (reverse all edges)
 *           Run DFS on TRANSPOSED graph in stack's order → each DFS tree = 1 SCC
 *
 * Time  Complexity: O(V + E)
 * Space Complexity: O(V + E)
 *
 * Interview note:
 *   - SCCs reveal "cycles" in directed graphs
 *   - Used in compilers (variable dependency analysis)
 *   - Used in web crawling (find groups of mutually linking pages)
 *   - LeetCode 1192 "Critical Connections in a Network" (bridges)
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXV 10

typedef struct Node { int val; struct Node *next; } Node;
Node *adj[MAXV];        /* Original graph */
Node *adjT[MAXV];       /* Transposed graph */
int V;
bool visited[MAXV];
int stack[MAXV];
int stackTop = -1;

void addEdge(int u, int v) {
    Node *n = (Node *)malloc(sizeof(Node)); n->val = v; n->next = adj[u];  adj[u]  = n;
    Node *t = (Node *)malloc(sizeof(Node)); t->val = u; t->next = adjT[v]; adjT[v] = t;
}

/* DFS Pass 1 — fill stack by finish time */
void dfs1(int u) {
    visited[u] = true;
    for (Node *c = adj[u]; c; c = c->next)
        if (!visited[c->val]) dfs1(c->val);
    stack[++stackTop] = u;
}

/* DFS Pass 2 — on transposed graph */
void dfs2(int u, int sccId) {
    visited[u] = true;
    printf("%d ", u);
    for (Node *c = adjT[u]; c; c = c->next)
        if (!visited[c->val]) dfs2(c->val, sccId);
}

void kosarajuSCC() {
    /* Pass 1: DFS on original graph */
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < V; i++)
        if (!visited[i]) dfs1(i);

    /* Pass 2: DFS on transposed graph in stack order */
    memset(visited, false, sizeof(visited));
    int sccCount = 0;
    printf("Strongly Connected Components:\n");
    while (stackTop >= 0) {
        int u = stack[stackTop--];
        if (!visited[u]) {
            printf("  SCC %d: { ", ++sccCount);
            dfs2(u, sccCount);
            printf("}\n");
        }
    }
    printf("Total SCCs: %d\n", sccCount);
}

int main() {
    /*
     *  Graph:
     *  0 → 2 → 3 → 4 → 5
     *  ↑ ↙         ↑ ↙
     *  1            6
     *
     *  SCCs: {0,1,2}, {3}, {4,5,6}
     */
    V = 7;
    for (int i = 0; i < V; i++) { adj[i] = NULL; adjT[i] = NULL; }

    addEdge(0, 2);
    addEdge(2, 1);
    addEdge(1, 0);
    addEdge(2, 3);
    addEdge(3, 4);
    addEdge(4, 5);
    addEdge(5, 6);
    addEdge(6, 4);

    kosarajuSCC();

    return 0;
}
