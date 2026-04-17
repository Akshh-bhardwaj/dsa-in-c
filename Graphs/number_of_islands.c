/*
 * Number of Islands
 * =================
 * Classic grid-based BFS/DFS problem.
 *
 * Problem: Given a 2D grid of '1' (land) and '0' (water),
 *          count the number of islands.
 *          An island is surrounded by water and formed by connecting
 *          adjacent lands horizontally or vertically.
 *
 * Approach 1: BFS  — iterative, queue-based
 * Approach 2: DFS  — recursive flood fill
 *
 * Time  Complexity: O(R * C) where R=rows, C=cols
 * Space Complexity: O(R * C) for visited/queue in worst case
 *
 * Interview note:
 *   - LeetCode 200 "Number of Islands"   ← #1 Google interview question
 *   - LeetCode 695 "Max Area of Island"
 *   - LeetCode 994 "Rotting Oranges"     (multi-source BFS)
 *   - LeetCode 130 "Surrounded Regions"
 *   - LeetCode 417 "Pacific Atlantic Water Flow"
 *
 * Variation: Count the LARGEST island, find total land area, etc.
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAXR 10
#define MAXC 10

int rows, cols;

/* 4 directions: up, down, left, right */
int dr[] = {-1, 1, 0,  0};
int dc[] = { 0, 0, -1, 1};

/* ============================================================
 * BFS approach
 * ============================================================ */
int countIslandsBFS(char grid[][MAXC]) {
    /* Make a copy so we don't destroy original */
    char g[MAXR][MAXC];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            g[i][j] = grid[i][j];

    int count = 0;
    int qr[MAXR * MAXC], qc[MAXR * MAXC]; /* BFS queue (row, col) */

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (g[i][j] == '1') {
                count++;
                /* BFS to sink entire island */
                int front = 0, rear = 0;
                qr[rear] = i; qc[rear++] = j;
                g[i][j] = '0'; /* Mark visited */

                while (front < rear) {
                    int r = qr[front], c = qc[front++];
                    for (int d = 0; d < 4; d++) {
                        int nr = r + dr[d], nc = c + dc[d];
                        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols
                            && g[nr][nc] == '1') {
                            g[nr][nc] = '0';
                            qr[rear] = nr; qc[rear++] = nc;
                        }
                    }
                }
            }
        }
    }
    return count;
}

/* ============================================================
 * DFS approach (flood fill)
 * ============================================================ */
char dfs_grid[MAXR][MAXC];

void dfsFlood(int r, int c) {
    if (r < 0 || r >= rows || c < 0 || c >= cols || dfs_grid[r][c] != '1')
        return;
    dfs_grid[r][c] = '0'; /* Sink this land */
    for (int d = 0; d < 4; d++)
        dfsFlood(r + dr[d], c + dc[d]);
}

int countIslandsDFS(char grid[][MAXC]) {
    /* Copy grid */
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            dfs_grid[i][j] = grid[i][j];

    int count = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (dfs_grid[i][j] == '1') {
                count++;
                dfsFlood(i, j);
            }
    return count;
}

/* ============================================================
 * Bonus: Max Area of Island (LeetCode 695 variant)
 * ============================================================ */
int maxAreaDFS(int r, int c, char g[][MAXC]) {
    if (r < 0 || r >= rows || c < 0 || c >= cols || g[r][c] != '1') return 0;
    g[r][c] = '0';
    int area = 1;
    for (int d = 0; d < 4; d++)
        area += maxAreaDFS(r + dr[d], c + dc[d], g);
    return area;
}

int maxAreaOfIsland(char grid[][MAXC]) {
    char g[MAXR][MAXC];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            g[i][j] = grid[i][j];

    int maxArea = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (g[i][j] == '1') {
                int a = maxAreaDFS(i, j, g);
                if (a > maxArea) maxArea = a;
            }
    return maxArea;
}

void printGrid(char g[][MAXC]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) printf("%c ", g[i][j]);
        printf("\n");
    }
}

int main() {
    /* Test 1 */
    rows = 4; cols = 5;
    char grid1[MAXR][MAXC] = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    printf("Grid 1:\n"); printGrid(grid1);
    printf("Islands (BFS): %d\n", countIslandsBFS(grid1));
    printf("Islands (DFS): %d\n", countIslandsDFS(grid1));

    /* Test 2 */
    rows = 4; cols = 5;
    char grid2[MAXR][MAXC] = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    printf("\nGrid 2:\n"); printGrid(grid2);
    printf("Islands (BFS): %d\n", countIslandsBFS(grid2));
    printf("Islands (DFS): %d\n", countIslandsDFS(grid2));

    /* Test 3: Max area */
    rows = 4; cols = 5;
    char grid3[MAXR][MAXC] = {
        {'1','1','0','1','0'},
        {'1','1','0','1','1'},
        {'0','0','0','0','0'},
        {'0','1','0','0','0'}
    };
    printf("\nGrid 3 (Max Area):\n"); printGrid(grid3);
    printf("Max Island Area: %d\n", maxAreaOfIsland(grid3));

    return 0;
}
