# BFS Distances

Given a directed graph `g` with vertices `1..n` stored as adjacency lists, run **breadth-first search** from `s`.

Return a vector `dist` of size `n + 1` where:
- `dist[s] = 0`
- `dist[v]` is the minimum number of edges on a path from `s` to `v`
- `dist[v] = -1` if `v` is not reachable from `s`

```cpp
vector<int> bfsDistances(const ListGraph &g, int n, int s);
```

Visit neighbors in the order given by `g.neighbors(v)`.

## Input / Output

Each test case provides `n m`, then `m` directed edges `u v` (meaning `u -> v`), then the start vertex `s`.

The platform prints `dist[1..n]` on one line.

## Constraints

- `1 <= n <= 200000`, `0 <= m <= 300000`
- Expected complexity: `O(V + E)`
