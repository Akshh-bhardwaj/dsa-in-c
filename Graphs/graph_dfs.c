/*
 * DFS — Depth First Search
 * ========================
 * Visit nodes by going as deep as possible before backtracking.
 *
 * Applications (must know for interviews):
 *  - Path existence between two nodes
 *  - Cycle detection
 *  - Topological sort (DFS-based)
 *  - Connected components / Flood Fill
 *  - Strongly Connected Components (Kosaraju)
 *  - Finding bridges and articulation points
 *
 * Time  Complexity: O(V + E)
 * Space Complexity: O(V)  — recursion stack + visited array
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXV 100

typedef struct Node {
    int val;
    struct Node *next;
} Node;

Node *adj[MAXV];
int V;

void addEdge(int u, int v) {
    Node *n1 = (Node *)malloc(sizeof(Node));
    n1->val = v; n1->next = adj[u]; adj[u] = n1;
    Node *n2 = (Node *)malloc(sizeof(Node));
    n2->val = u; n2->next = adj[v]; adj[v] = n2;
}

/* -------------------------------------------------------
 * Recursive DFS
 * ------------------------------------------------------- */
bool visited[MAXV];

void dfsUtil(int u) {
    visited[u] = true;
    printf("%d ", u);
    for (Node *curr = adj[u]; curr; curr = curr->next) {
        if (!visited[curr->val])
            dfsUtil(curr->val);
    }
}

void dfs(int src) {
    for (int i = 0; i < V; i++) visited[i] = false;
    printf("DFS from %d: ", src);
    dfsUtil(src);
    printf("\n");
}

/* -------------------------------------------------------
 * Iterative DFS (useful to avoid stack overflow on deep graphs)
 * ------------------------------------------------------- */
void dfsIterative(int src) {
    bool vis[MAXV] = {false};
    int stack[MAXV];
    int top = -1;

    stack[++top] = src;
    printf("DFS (iterative) from %d: ", src);

    while (top >= 0) {
        int u = stack[top--];
        if (vis[u]) continue;
        vis[u] = true;
        printf("%d ", u);
        for (Node *curr = adj[u]; curr; curr = curr->next) {
            if (!vis[curr->val])
                stack[++top] = curr->val;
        }
    }
    printf("\n");
}

/* -------------------------------------------------------
 * All Paths from Source to Destination  ← Google Interview classic
 * ------------------------------------------------------- */
int path[MAXV];
int pathLen;

void findAllPaths(int u, int dest, bool vis[]) {
    vis[u] = true;
    path[pathLen++] = u;

    if (u == dest) {
        printf("Path: ");
        for (int i = 0; i < pathLen; i++)
            printf("%d%s", path[i], i == pathLen-1 ? "\n" : " -> ");
    } else {
        for (Node *curr = adj[u]; curr; curr = curr->next)
            if (!vis[curr->val])
                findAllPaths(curr->val, dest, vis);
    }

    /* Backtrack */
    pathLen--;
    vis[u] = false;
}

/* -------------------------------------------------------
 * Count Connected Components
 * ------------------------------------------------------- */
int countComponents() {
    bool vis[MAXV] = {false};
    int count = 0;
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            count++;
            /* Simple DFS to mark the component */
            int stack[MAXV]; int top = -1;
            stack[++top] = i;
            while (top >= 0) {
                int u = stack[top--];
                if (vis[u]) continue;
                vis[u] = true;
                for (Node *c = adj[u]; c; c = c->next)
                    if (!c->val < V && !vis[c->val]) stack[++top] = c->val;
            }
        }
    }
    return count;
}

int main() {
    V = 7;
    for (int i = 0; i < V; i++) adj[i] = NULL;

    addEdge(0, 1); addEdge(1, 2);
    addEdge(0, 3); addEdge(2, 5);
    addEdge(3, 4); addEdge(4, 5);
    addEdge(4, 6);

    dfs(0);
    dfsIterative(0);

    printf("\nAll paths from 0 to 6:\n");
    bool vis[MAXV] = {false};
    pathLen = 0;
    findAllPaths(0, 6, vis);

    printf("\nConnected components: %d\n", countComponents());

    return 0;
}
