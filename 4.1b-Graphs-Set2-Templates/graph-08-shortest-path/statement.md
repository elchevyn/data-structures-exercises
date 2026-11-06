# Shortest Path in an Unweighted Graph

Given a directed graph `g` with vertices `1..n`, return the minimum number of edges on a path from `s` to
`t`, or `-1` if `t` cannot be reached. Use a BFS: a DFS finds a path, not always the shortest one.

```cpp
int shortestPath(const ListGraph &g, int n, int s, int t);
```

The template contains the class `ListGraph` from P16 (adjacency lists, vertices `1..n`). **Do not change
it**: write only the body of the function at the end of the file. Use `g.neighbors(v)` to visit the
neighbors of `v`. If you need a helper, write it as a normal function. Do not write `main()`.

Each case gives `n` and `m`, then `m` directed edges `u v`, then `s` and `t`. Each edge `u v` is the arc `u -> v`, in input order, so `g.neighbors(v)` lists them in that order.

## Examples

| n, arcs | s, t | result |
|---|---|---|
| `6`; `1>2 2>3 1>4 4>5 3>6 5>6 2>6` | `1 6` | `2` |
| same graph | `6 1` | `-1` |
| `3`; `1>2` | `3 3` | `0` |

## Constraints

- `1 <= n <= 10^4`, `0 <= m <= 2 * 10^4`; no self-loops or repeated arcs.
- `1 <= s, t <= n`.
- Expected complexity: O(V + E).
