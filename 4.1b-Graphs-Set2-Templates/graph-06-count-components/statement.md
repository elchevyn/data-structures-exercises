# Number of Connected Components

Given an undirected graph `g` with vertices `1..n`, return its number of connected components. An
isolated vertex is a component by itself. Start a new DFS (or BFS) from every vertex not visited yet.

```cpp
int countComponents(const ListGraph &g, int n);
```

The template contains the class `ListGraph` from P16 (adjacency lists, vertices `1..n`). **Do not change
it**: write only the body of the function at the end of the file. Use `g.neighbors(v)` to visit the
neighbors of `v`. If you need a helper, write it as a normal function. Do not write `main()`.

Each case gives `n` and `m`, then `m` undirected edges `u v`. Each edge is added in both directions (`u -> v` and `v -> u`), in input order, so `g.neighbors(v)` lists them in that order.

## Examples

| n | edges | result |
|---|---|---|
| `5` | `1-2 2-3 4-5` | `2` |
| `5` | none | `5` |
| `4` | `1-2 2-3 3-4 4-1` | `1` |

## Constraints

- `1 <= n <= 10^4`, `0 <= m <= 2 * 10^4`; no self-loops or repeated edges.
- Expected complexity: O(V + E).
