/*
 * Topological Sort
 * ================
 * Linear ordering of vertices such that for every directed edge u→v,
 * vertex u comes before v. Only valid for DAGs (no cycles).
 *
 * Two approaches:
 *   1. Kahn's Algorithm (BFS-based) — uses indegree array + queue
 *      → Also detects if graph has a cycle (result < V vertices)
 *   2. DFS-based            — finish-time ordering via stack
 *
 * Real-world / Interview uses:
 *   - Build systems (which file compiles first?)
 *   - Task scheduling with dependencies
 *   - LeetCode 207 "Course Schedule"   ← top Google question
 *   - LeetCode 210 "Course Schedule II"
 *
 * Time  Complexity: O(V + E)
 * Space Complexity: O(V)
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXV 10

typedef struct Node { int val; struct Node *next; } Node;
Node *adj[MAXV];
int V;

void addEdge(int u, int v) { /* directed: u → v */
    Node *n = (Node *)malloc(sizeof(Node));
    n->val = v; n->next = adj[u]; adj[u] = n;
}

/* ============================================================
 * Method 1: Kahn's Algorithm (BFS)
 *   Step 1: compute indegree for every vertex
 *   Step 2: enqueue all zero-indegree vertices
 *   Step 3: process queue: print node, reduce neighbors' indegree,
 *           enqueue if indegree becomes 0
 *   Step 4: if count < V → cycle exists (no valid toposort)
 * ============================================================ */
void topoSortBFS() {
    int indegree[MAXV] = {0};

    /* Compute indegrees */
    for (int u = 0; u < V; u++)
        for (Node *c = adj[u]; c; c = c->next)
            indegree[c->val]++;

    /* Enqueue zero-indegree nodes */
    int queue[MAXV]; int front = 0, rear = 0;
    for (int i = 0; i < V; i++)
        if (indegree[i] == 0) queue[rear++] = i;

    int count = 0;
    int order[MAXV];

    while (front < rear) {
        int u = queue[front++];
        order[count++] = u;

        for (Node *c = adj[u]; c; c = c->next) {
            if (--indegree[c->val] == 0)
                queue[rear++] = c->val;
        }
    }

    if (count != V) {
        printf("Kahn's : Graph has a CYCLE — topological sort impossible!\n");
        return;
    }

    printf("Kahn's (BFS) topo order: ");
    for (int i = 0; i < count; i++)
        printf("%d%s", order[i], i < count-1 ? " -> " : "\n");
}

/* ============================================================
 * Method 2: DFS-based Topological Sort
 *   DFS and push to stack after exploring all neighbors.
 *   Pop the stack for the final order.
 * ============================================================ */
int stack[MAXV];
int stackTop = -1;
bool visited[MAXV];

void dfsTopoUtil(int u) {
    visited[u] = true;
    for (Node *c = adj[u]; c; c = c->next)
        if (!visited[c->val]) dfsTopoUtil(c->val);
    stack[++stackTop] = u; /* Push after all children done */
}

void topoSortDFS() {
    memset(visited, false, sizeof(visited));
    stackTop = -1;

    for (int i = 0; i < V; i++)
        if (!visited[i]) dfsTopoUtil(i);

    printf("DFS-based topo order:    ");
    while (stackTop >= 0)
        printf("%d%s", stack[stackTop--], stackTop >= 0 ? " -> " : "\n");
}

/* ============================================================
 * MAIN — Course Schedule example
 * ============================================================ */
int main() {
    /*
     * Courses:  0=Math, 1=Physics, 2=Chemistry, 3=Bio, 4=CompSci
     * Prerequisites:
     *   Math  → Physics → Chemistry
     *   Math  → Bio
     *   CompSci has no prereqs
     *
     * Directed edges: prereq → course
     *   0→1, 1→2, 0→3, 4 (standalone)
     */
    V = 5;
    for (int i = 0; i < V; i++) adj[i] = NULL;
    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(0, 3);

    printf("===== Topological Sort (DAG) =====\n");
    topoSortBFS();
    topoSortDFS();

    /* Cyclic graph test */
    printf("\n===== Cyclic Graph =====\n");
    for (int i = 0; i < V; i++) adj[i] = NULL;
    addEdge(0, 1); addEdge(1, 2); addEdge(2, 0); /* cycle */
    topoSortBFS();

    return 0;
}
