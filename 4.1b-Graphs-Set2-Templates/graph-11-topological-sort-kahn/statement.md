# Topological Sort (Kahn's Algorithm)

Given a directed graph `g` with vertices `1..n` stored as adjacency lists, return a **topological order** of its vertices.

A topological order is a permutation of `1..n` such that for every edge `u -> v`, `u` appears before `v`.

Implement:

```cpp
vector<int> topologicalSort(const ListGraph &g, int n);
```

Requirements:
- If the graph has a **cycle**, return an **empty vector**.
- If multiple orders are valid, return the one that always picks the **smallest available vertex** (use a min-heap / priority queue).

## Input / Output

Each test case provides `n m`, then `m` directed edges `u v` (meaning `u -> v`).

The platform prints the returned vector on one line, separated by spaces, or `(empty)` if it is empty.

## Constraints

- `1 <= n <= 200000`, `0 <= m <= 300000`
- Expected complexity: `O((V + E) log V)` because of the min-heap.
