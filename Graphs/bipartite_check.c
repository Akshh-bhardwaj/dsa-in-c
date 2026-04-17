/*
 * Bipartite Graph Check
 * =====================
 * A graph is bipartite if its vertices can be split into two sets such that
 * every edge goes between the two sets (no edges within a set).
 *
 * Equivalently: a graph is bipartite ↔ it can be 2-colored ↔ it has no odd-length cycle.
 *
 * Algorithm: BFS/DFS coloring
 *   - Color source with color 0
 *   - Color all neighbors with color 1 (opposite)
 *   - If any neighbor has the SAME color → not bipartite
 *
 * Time  Complexity: O(V + E)
 * Space Complexity: O(V)
 *
 * Interview note:
 *   - LeetCode 785 "Is Graph Bipartite?"   ← common Google question
 *   - LeetCode 886 "Possible Bipartition"
 *   - Use case: matching problems, scheduling
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXV 10
#define NO_COLOR -1

typedef struct Node { int val; struct Node *next; } Node;
Node *adj[MAXV];
int V;

void addEdge(int u, int v) {
    Node *n1 = (Node *)malloc(sizeof(Node)); n1->val = v; n1->next = adj[u]; adj[u] = n1;
    Node *n2 = (Node *)malloc(sizeof(Node)); n2->val = u; n2->next = adj[v]; adj[v] = n2;
}

/* ============================================================
 * BFS Bipartite Check
 * ============================================================ */
bool isBipartiteBFS() {
    int color[MAXV];
    memset(color, NO_COLOR, sizeof(color));

    for (int start = 0; start < V; start++) {
        if (color[start] != NO_COLOR) continue; /* Already processed */

        /* BFS from 'start' */
        int queue[MAXV]; int front = 0, rear = 0;
        color[start] = 0;
        queue[rear++] = start;

        while (front < rear) {
            int u = queue[front++];
            for (Node *c = adj[u]; c; c = c->next) {
                int v = c->val;
                if (color[v] == NO_COLOR) {
                    color[v] = 1 - color[u]; /* Opposite color */
                    queue[rear++] = v;
                } else if (color[v] == color[u]) {
                    return false; /* Same color neighbor → not bipartite */
                }
            }
        }
    }

    /* Print partition sets */
    printf("Set A (color 0): ");
    for (int i = 0; i < V; i++) if (color[i] == 0) printf("%d ", i);
    printf("\nSet B (color 1): ");
    for (int i = 0; i < V; i++) if (color[i] == 1) printf("%d ", i);
    printf("\n");

    return true;
}

/* ============================================================
 * DFS Bipartite Check
 * ============================================================ */
int color_dfs[MAXV];

bool dfsColor(int u, int c) {
    color_dfs[u] = c;
    for (Node *curr = adj[u]; curr; curr = curr->next) {
        int v = curr->val;
        if (color_dfs[v] == NO_COLOR) {
            if (!dfsColor(v, 1 - c)) return false;
        } else if (color_dfs[v] == c) {
            return false;
        }
    }
    return true;
}

bool isBipartiteDFS() {
    memset(color_dfs, NO_COLOR, sizeof(color_dfs));
    for (int i = 0; i < V; i++)
        if (color_dfs[i] == NO_COLOR && !dfsColor(i, 0))
            return false;
    return true;
}

int main() {
    /* ---- Test 1: Bipartite (even cycle) ---- */
    printf("=== Test 1: Bipartite Graph (cycle of 4) ===\n");
    V = 4;
    for (int i = 0; i < V; i++) adj[i] = NULL;
    /* Square: 0-1-2-3-0 */
    addEdge(0, 1); addEdge(1, 2); addEdge(2, 3); addEdge(3, 0);
    printf("BFS check: %s\n", isBipartiteBFS() ? "BIPARTITE ✓" : "NOT bipartite ✗");
    printf("DFS check: %s\n", isBipartiteDFS() ? "BIPARTITE ✓" : "NOT bipartite ✗");

    /* ---- Test 2: NOT bipartite (odd cycle) ---- */
    printf("\n=== Test 2: NOT Bipartite Graph (triangle) ===\n");
    V = 3;
    for (int i = 0; i < V; i++) adj[i] = NULL;
    /* Triangle: 0-1-2-0 */
    addEdge(0, 1); addEdge(1, 2); addEdge(2, 0);
    printf("BFS check: %s\n", isBipartiteBFS() ? "BIPARTITE ✓" : "NOT bipartite ✗");
    printf("DFS check: %s\n", isBipartiteDFS() ? "BIPARTITE ✓" : "NOT bipartite ✗");

    /* ---- Test 3: Complete bipartite K3,3 ---- */
    printf("\n=== Test 3: K3,3 Bipartite Graph ===\n");
    V = 6;
    for (int i = 0; i < V; i++) adj[i] = NULL;
    /* {0,1,2} fully connected to {3,4,5} */
    for (int i = 0; i < 3; i++)
        for (int j = 3; j < 6; j++)
            addEdge(i, j);
    printf("BFS check: %s\n", isBipartiteBFS() ? "BIPARTITE ✓" : "NOT bipartite ✗");

    return 0;
}
