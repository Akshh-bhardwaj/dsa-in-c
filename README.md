# dsa-in-c
DSA problems and solutions in C for interview prep

---

## ✅ Topics Covered & Progress

| Topic              | Status | Description                                          |
|--------------------|--------|------------------------------------------------------|
| Arrays             | ✅      | Basic problems, prefix sums, move zeroes             |
| Strings            | ✅      | Palindrome, anagrams, reverse                        |
| Sorting            | ✅      | Bubble, Insertion, Merge, Quick sort                 |
| Searching          | ✅      | Linear & Binary search                               |
| Linked List        | ✅      | Insert, delete, reverse                              |
| Stack              | ✅      | Array/LL impl, valid parentheses, infix→postfix      |
| Queue              | ✅      | Circular queue, queue using two stacks               |
| Recursion          | ✅      | Fibonacci (memoized), factorial                      |
| Trees              | ✅      | Traversals (all 4), BST insert/search, height, dia  |
| **Graphs**         | ✅      | BFS, DFS, Dijkstra, Bellman-Ford, Floyd-Warshall, MST, Topo Sort, SCC, Bridges |

---

## 📁 Folder Structure

```
dsa-in-c/
├── Arrays/
│   ├── two_sum.c
│   ├── max_min_element.c
│   ├── reverse_array.c
│   ├── move_zeroes.c
│   └── prefix_sum.c
├── Strings/
│   ├── palindrome.c
│   ├── anagram.c
│   └── reverse_string.c
├── Sorting/
│   ├── bubble_sort.c
│   ├── insertion_sort.c
│   ├── merge_sort.c
│   └── quick_sort.c
├── Searching/
│   ├── linear_search.c
│   └── binary_search.c
├── LinkedList/
│   ├── insert_node.c
│   ├── delete_node.c
│   ├── reverse_list.c
│   └── doubly_linked_list.c
├── Stack/
│   ├── stack_array.c         ← valid parentheses included
│   └── stack_linkedlist.c    ← infix → postfix included
├── Queue/
│   ├── queue_array.c         ← circular queue
│   └── queue_linkedlist.c    ← queue using two stacks
├── Recursion/
│   ├── factorial.c
│   └── fibonacci.c           ← simple + memoized
├── Trees/
│   ├── bst_insert.c
│   ├── inorder_traversal.c   ← all 4 traversals + level order
│   └── bst_height.c          ← height + diameter
└── Graphs/
    ├── graph_representation.c  ← adjacency list & matrix
    ├── graph_bfs.c             ← BFS + shortest path (unweighted)
    ├── graph_dfs.c             ← DFS recursive/iterative, all paths, components
    ├── cycle_detection.c       ← undirected (DFS+Union-Find) & directed (recStack)
    ├── topological_sort.c      ← Kahn's BFS + DFS-based (LeetCode 207/210)
    ├── dijkstra.c              ← single-source shortest path (non-negative weights)
    ├── bellman_ford.c          ← handles negative weights + detects negative cycles
    ├── floyd_warshall.c        ← all-pairs shortest path
    ├── kruskal_mst.c           ← MST with Union-Find (path compression + rank)
    ├── prims_mst.c             ← MST using greedy key selection
    ├── bipartite_check.c       ← 2-coloring BFS+DFS (LeetCode 785)
    ├── number_of_islands.c     ← BFS+DFS grid flood fill + max area (LC 200/695)
    ├── kosaraju_scc.c          ← Strongly Connected Components (2-pass DFS)
    └── bridges_articulation.c  ← Bridges & Articulation Points (Tarjan's)
```

---

## 🧪 Sample Problems

| Problem                    | Status | Topic       | LeetCode |
|----------------------------|--------|-------------|----------|
| Two Sum                    | ✅      | Arrays      | #1       |
| Binary Search              | ✅      | Searching   | #704     |
| Bubble Sort                | ✅      | Sorting     | —        |
| Move Zeroes                | ✅      | Arrays      | #283     |
| Reverse a Linked List      | ✅      | LinkedList  | #206     |
| Infix to Postfix           | ✅      | Stack       | —        |
| Level Order Traversal      | ✅      | Trees       | #102     |
| Number of Islands          | ✅      | Graphs      | #200     |
| Course Schedule            | ✅      | Graphs      | #207     |
| Is Graph Bipartite?        | ✅      | Graphs      | #785     |
| Network Delay Time         | ✅      | Graphs      | #743     |
| Critical Connections       | ✅      | Graphs      | #1192    |
| Min Cost to Connect Points | ✅      | Graphs      | #1584    |

---

## 🧠 Graph Algorithm Cheat Sheet

| Problem Type                  | Algorithm           | Complexity    |
|-------------------------------|---------------------|---------------|
| Shortest path (unweighted)    | BFS                 | O(V + E)      |
| Shortest path (weighted, ≥0)  | Dijkstra            | O(V² / ElogV) |
| Shortest path (negative wts)  | Bellman-Ford        | O(V × E)      |
| All-pairs shortest path       | Floyd-Warshall      | O(V³)         |
| Minimum Spanning Tree (sparse)| Kruskal + UnionFind | O(E log E)    |
| Minimum Spanning Tree (dense) | Prim's              | O(V²)         |
| Topological ordering / cycle  | Kahn's BFS / DFS    | O(V + E)      |
| Strongly Connected Components | Kosaraju's          | O(V + E)      |
| Bridges / Articulation Points | Tarjan's DFS        | O(V + E)      |
| Bipartite check               | BFS/DFS 2-coloring  | O(V + E)      |
| Flood fill / Islands          | BFS / DFS           | O(R × C)      |
| Cycle detection (undirected)  | DFS or Union-Find   | O(V + E)      |
| Cycle detection (directed)    | DFS + rec stack     | O(V + E)      |

---

## 🛠️ Languages Used

- ✅ C (Main)
- ✅ C++ (Planned)

---

## 🎯 Goals

- ✅ Master common DSA problems
- ✅ Improve speed and accuracy
- ✅ Build strong coding profile for placements
- ✅ Contribute to open-source DSA repositories

---

## ⚡ How to Compile & Run

Each `.c` file is standalone. To compile and run any file:

```bash
# Generic pattern
gcc Graphs/dijkstra.c -o dijkstra && ./dijkstra

# Examples
gcc Arrays/two_sum.c         -o two_sum      && ./two_sum
gcc Graphs/number_of_islands.c -o islands    && ./islands
gcc Graphs/topological_sort.c  -o topo_sort  && ./topo_sort
```

---

## 📈 My Coding Profiles

- 🔗 [GitHub Profile](https://github.com/Akshh-bhardwaj)
- 🔗 [LeetCode Profile](https://leetcode.com/) <!-- Add your LeetCode username here -->

---

## ⭐ How to Use This Repo

1. Browse folders by topic
2. Open `.c` files to see solutions with detailed comments
3. Check the **Graph Cheat Sheet** above before interviews
4. Practice by writing your own solution, then compare
5. Suggest improvements via Issues or Pull Requests!

---

## 🙌 Contributions

If you'd like to add a better solution or contribute a new topic, feel free to open a Pull Request!

---

> "Consistency is the key to mastery." 🔑
