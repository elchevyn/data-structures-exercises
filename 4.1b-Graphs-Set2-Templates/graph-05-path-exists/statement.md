# Find if a Path Exists

Given an undirected graph `g` with vertices `1..n`, return `true` if there is a path from `s` to `t`, and
`false` otherwise. A vertex always has a path to itself. Use a DFS or a BFS.

```cpp
bool hasPath(const ListGraph &g, int n, int s, int t);
```

The template contains the class `ListGraph` from P16 (adjacency lists, vertices `1..n`). **Do not change
it**: write only the body of the function at the end of the file. Use `g.neighbors(v)` to visit the
neighbors of `v`. If you need a helper, write it as a normal function. Do not write `main()`.

Each case gives `n` and `m`, then `m` undirected edges `u v`, then `s` and `t`. Each edge is added in both directions (`u -> v` and `v -> u`), in input order, so `g.neighbors(v)` lists them in that order.

## Examples

| n, edges | s, t | result |
|---|---|---|
| `6`; `1-2 2-3 4-5` | `1 3` | `true` |
| `6`; `1-2 2-3 4-5` | `1 5` | `false` |
| `1`; none | `1 1` | `true` |

## Constraints

- `1 <= n <= 10^4`, `0 <= m <= 2 * 10^4`; no self-loops or repeated edges.
- `1 <= s, t <= n`.
- Expected complexity: O(V + E).
