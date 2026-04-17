/*
 * Kruskal's Minimum Spanning Tree
 * ================================
 * Find the minimum weight spanning tree of an undirected weighted graph.
 * A spanning tree: connects all V vertices with exactly V-1 edges, min total weight.
 *
 * Algorithm:
 *   1. Sort all edges by weight (ascending)
 *   2. Pick edge greedily if it doesn't form a cycle (use Union-Find)
 *   3. Stop when MST has V-1 edges
 *
 * Union-Find (Disjoint Set Union):
 *   - find() with path compression
 *   - union() by rank
 *
 * Time  Complexity: O(E log E) dominated by sorting
 * Space Complexity: O(V + E)
 *
 * Interview note:
 *   - Great for sparse graphs (few edges)
 *   - Union-Find = must know data structure
 *   - LeetCode 1135 "Connecting Cities With Minimum Cost"
 *   - LeetCode 1584 "Min Cost to Connect All Points"
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXV  10
#define MAXE  50

/* ============================================================
 * Union-Find (DSU)
 * ============================================================ */
int parent[MAXV];
int rank_uf[MAXV];

void dsuInit(int n) {
    for (int i = 0; i < n; i++) { parent[i] = i; rank_uf[i] = 0; }
}

int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]); /* Path compression */
    return parent[x];
}

int unionSets(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) return 0; /* Already in same component → would form cycle */
    /* Union by rank */
    if (rank_uf[px] < rank_uf[py]) { int t = px; px = py; py = t; }
    parent[py] = px;
    if (rank_uf[px] == rank_uf[py]) rank_uf[px]++;
    return 1;
}

/* ============================================================
 * Edge structure
 * ============================================================ */
typedef struct {
    int src, dest, weight;
} Edge;

Edge edges[MAXE];
int E, V;

int cmpEdges(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

/* ============================================================
 * Kruskal's Algorithm
 * ============================================================ */
void kruskalMST() {
    /* Step 1: Sort edges by weight */
    qsort(edges, E, sizeof(Edge), cmpEdges);

    dsuInit(V);

    Edge mst[MAXV];
    int mstEdges = 0;
    int totalWeight = 0;

    /* Step 2: Greedily add edges */
    for (int i = 0; i < E && mstEdges < V - 1; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int w = edges[i].weight;

        if (unionSets(u, v)) { /* No cycle → add to MST */
            mst[mstEdges++] = edges[i];
            totalWeight += w;
        }
    }

    /* Print MST */
    printf("Kruskal's MST:\n");
    printf("%-8s %-8s %-8s\n", "Edge", "->", "Weight");
    printf("------------------------\n");
    for (int i = 0; i < mstEdges; i++)
        printf("  %d   <->   %d   :   %d\n", mst[i].src, mst[i].dest, mst[i].weight);
    printf("Total MST Weight: %d\n", totalWeight);
}

int main() {
    /*
     *  Graph:
     *       2
     *   0 ----- 3
     *   |  \    |  \
     *  6|   8\  |5   \7
     *   |     \ |     \
     *   1 ----- 2 ---- 4
     *       3       9
     */
    V = 5;
    E = 7;
    edges[0] = (Edge){0, 1, 6};
    edges[1] = (Edge){0, 2, 8};
    edges[2] = (Edge){0, 3, 2};
    edges[3] = (Edge){1, 2, 3};
    edges[4] = (Edge){2, 3, 5};
    edges[5] = (Edge){2, 4, 9};
    edges[6] = (Edge){3, 4, 7};

    kruskalMST();

    return 0;
}
