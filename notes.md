# 📚 Data Structures & Algorithms (DSA): Notes & Cheatsheet

This document provides a comprehensive technical reference for core data structures and algorithms, including complexity matrices, algorithmic patterns, and key implementation differences between C and Java.

---

## ⚡ 1. Complexity Reference Matrix

### Data Structure Operations:
| Data Structure | Access (Avg/Worst) | Search (Avg/Worst) | Insertion (Avg/Worst) | Deletion (Avg/Worst) | Space Complexity |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Array** | $O(1)$ | $O(N)$ | $O(N)$ | $O(N)$ | $O(N)$ |
| **Linked List** | $O(N)$ | $O(N)$ | $O(1)$ | $O(1)$ | $O(N)$ |
| **Stack / Queue**| $O(N)$ | $O(N)$ | $O(1)$ | $O(1)$ | $O(N)$ |
| **BST** | $O(\log N) / O(N)$ | $O(\log N) / O(N)$ | $O(\log N) / O(N)$ | $O(\log N) / O(N)$ | $O(N)$ |
| **Heap** | $O(1)$ | $O(N)$ | $O(\log N)$ | $O(\log N)$ | $O(N)$ |

### Sorting Algorithms:
| Algorithm | Time Complexity (Best) | Time Complexity (Avg) | Time Complexity (Worst) | Space Complexity | Stable? |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Bubble Sort** | $O(N)$ | $O(N^2)$ | $O(N^2)$ | $O(1)$ | Yes |
| **Insertion Sort**| $O(N)$ | $O(N^2)$ | $O(N^2)$ | $O(1)$ | Yes |
| **Merge Sort** | $O(N \log N)$ | $O(N \log N)$ | $O(N \log N)$ | $O(N)$ | Yes |
| **Quick Sort** | $O(N \log N)$ | $O(N \log N)$ | $O(N^2)$ | $O(\log N)$ | No |

---

## 🛠️ 2. Core Data Structures & Patterns

### I. Arrays & Strings (Two-Pointers & Sliding Window)
- **Two-Pointers**: Used in sorted arrays to find pairs (e.g., Two Sum II) or reversing arrays.
- **Sliding Window**: Maintaining a dynamic sub-segment to track sub-array aggregates or substring limits.

### II. Linked Lists (Pointer Manipulation)
- **List Reversal**: Iterative three-pointer swing (`prev`, `curr`, `next`).
- **Cycle Detection**: Floyd's Tortoise and Hare algorithm (fast pointer moves at 2x, slow pointer at 1x).

### III. Stacks & Queues
- **Monotonic Stack**: Maintains values in strictly increasing or decreasing order (used for finding "Next Greater Element").
- **Valid Parentheses**: Push opening brackets, pop and verify matching closing brackets.

### IV. Trees & Graphs
- **Depth-First Search (DFS)**: Uses Recursion (implicit stack) to traverse deep down branches.
- **Breadth-First Search (BFS)**: Uses a Queue to traverse level-by-level (finds shortest path in unweighted graphs).
- **Dijkstra's Algorithm**: BFS with a Priority Queue (Min-Heap) to find the shortest path in weighted graphs.

### V. Dynamic Programming (DP)
- **Memoization (Top-down)**: Recursion with cache storage.
- **Tabulation (Bottom-up)**: Table-based loop construction.
- **0/1 Knapsack Pattern**: Making decisions (include/exclude) on items to maximize value under weight limits.

---

## 🎨 3. C vs. Java: Key Implementation Differences

### I. Memory Allocation & Management
- **C**: Requires manual memory management via `malloc()` and `free()`.
- **Java**: Automatic management via `new` keyword and JVM Garbage Collection.

```c
// C implementation of Node creation
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
free(newNode); // Mandatory to prevent memory leak
```
```java
// Java implementation of Node creation
Node newNode = new Node();
// JVM automatically garbage collects unreachable nodes
```

### II. Reference/Pointers Behavior
- **C**: Direct memory address modification using pointers (`*`, `&`). Allows double pointers (`Node** head_ref`) to modify head references inside functions.
- **Java**: References are passed by value. Reassigning references inside methods does not modify original head variables. Requires returning the updated head or updating fields inside wrapper classes.

### III. Dynamic Sizing & Collections
- **C**: Fixed array sizes. Dynamic resizing requires `realloc()` and manually copying elements.
- **Java**: Built-in collections (e.g., `ArrayList`, `HashMap`) handle dynamic expansion automatically under the hood.
