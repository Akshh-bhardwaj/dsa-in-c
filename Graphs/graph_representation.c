/*
 * Graph Representation
 * ====================
 * Two standard ways to represent a graph:
 *
 * 1. Adjacency Matrix  — 2D array, O(V^2) space, O(1) edge lookup
 * 2. Adjacency List    — Array of linked lists, O(V + E) space  ← preferred
 *
 * Supports directed and undirected graphs.
 *
 * Interview note: Always clarify directed/undirected + weighted/unweighted first.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXV 10  /* max vertices */

/* ============================================================
 * ADJACENCY MATRIX (unweighted, undirected)
 * ============================================================ */
typedef struct {
    int matrix[MAXV][MAXV];
    int V;
} MatrixGraph;

void initMatrix(MatrixGraph *g, int V) {
    g->V = V;
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            g->matrix[i][j] = 0;
}

void addEdgeMatrix(MatrixGraph *g, int u, int v) {
    g->matrix[u][v] = 1;
    g->matrix[v][u] = 1; /* Remove for directed graph */
}

void printMatrix(MatrixGraph *g) {
    printf("Adjacency Matrix:\n   ");
    for (int i = 0; i < g->V; i++) printf("%2d", i);
    printf("\n");
    for (int i = 0; i < g->V; i++) {
        printf("%2d:", i);
        for (int j = 0; j < g->V; j++)
            printf("%2d", g->matrix[i][j]);
        printf("\n");
    }
}

/* ============================================================
 * ADJACENCY LIST (unweighted, undirected)
 * ============================================================ */
typedef struct AdjNode {
    int dest;
    struct AdjNode *next;
} AdjNode;

typedef struct {
    AdjNode *head[MAXV];
    int V;
} ListGraph;

AdjNode *newAdjNode(int dest) {
    AdjNode *n = (AdjNode *)malloc(sizeof(AdjNode));
    n->dest = dest;
    n->next = NULL;
    return n;
}

void initList(ListGraph *g, int V) {
    g->V = V;
    for (int i = 0; i < V; i++) g->head[i] = NULL;
}

void addEdgeList(ListGraph *g, int u, int v) {
    /* Add v to u's list */
    AdjNode *n1 = newAdjNode(v);
    n1->next = g->head[u];
    g->head[u] = n1;

    /* Add u to v's list (remove for directed) */
    AdjNode *n2 = newAdjNode(u);
    n2->next = g->head[v];
    g->head[v] = n2;
}

void printList(ListGraph *g) {
    printf("Adjacency List:\n");
    for (int i = 0; i < g->V; i++) {
        printf("%d -> ", i);
        AdjNode *curr = g->head[i];
        while (curr) { printf("%d -> ", curr->dest); curr = curr->next; }
        printf("NULL\n");
    }
}

/* ============================================================
 * MAIN
 * ============================================================ */
int main() {
    int V = 5;
    int edges[][2] = {{0,1},{0,4},{1,2},{1,3},{1,4},{2,3},{3,4}};
    int E = 7;

    /* Matrix */
    MatrixGraph mg;
    initMatrix(&mg, V);
    for (int i = 0; i < E; i++) addEdgeMatrix(&mg, edges[i][0], edges[i][1]);
    printMatrix(&mg);

    printf("\n");

    /* List */
    ListGraph lg;
    initList(&lg, V);
    for (int i = 0; i < E; i++) addEdgeList(&lg, edges[i][0], edges[i][1]);
    printList(&lg);

    return 0;
}
