# DFS Traversal Order

Given a directed graph `g` with vertices `1..n` stored as adjacency lists, perform a **depth-first search** starting at `s`.

Return the **visit order** (preorder): when you first reach a vertex, mark it visited and append it to the result.

Visit neighbors in the order given by `g.neighbors(v)`.

```cpp
vector<int> dfsOrder(const ListGraph &g, int n, int s);
```

- Only include vertices that are **reachable from `s`**.
- Do not visit a vertex more than once.

## Input / Output

Each test case provides `n m`, then `m` directed edges `u v` (meaning `u -> v`), then the start vertex `s`.

The platform prints the returned vector on one line, separated by spaces, or `(empty)` if it is empty.

## Constraints

- `1 <= n <= 200000`, `0 <= m <= 300000`
- Expected complexity: `O(V + E)`

> Note: recursion may overflow the call stack on large graphs. An iterative DFS with `std::stack` is recommended.
