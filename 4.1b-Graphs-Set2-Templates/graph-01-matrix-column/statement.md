# Adjacency Matrix: Who Points to Me?

The class `MatrixGraph` is the adjacency matrix from P16: a directed graph with vertices `1..n`, where
`adj[u][v]` is `true` if there is an arc `u -> v`. The method `neighbors(u)` reads row `u` and returns the
vertices that `u` points to.

Implement `inNeighbors`: return the vertices that point **to** `v` (every `u` with an arc `u -> v`), in
ascending order. In the matrix, that answer is in a column.

```cpp
vector<int> MatrixGraph::inNeighbors(int v) const;
```

The template contains the class. **Do not change it**: write only the body of the method, which is
defined outside the class as `MatrixGraph::inNeighbors`. Inside the body, use the attributes `n` and `adj`
directly. If you need a helper, write it as a normal function outside the class. Do not write `main()`.

Each case gives `n` and `m`, then `m` arcs `u v` (added with `addEdge(u, v)`), then the vertex `v`. The
result is printed on one line, separated by spaces.

## Examples

| n, arcs | v | result |
|---|---|---|
| `4`; `1>2 1>3 2>3 3>1 4>3` | `3` | `1 2 4` |
| same graph | `1` | `3` |
| same graph | `4` | `(empty)` |

## Constraints

- `1 <= n <= 1000`, `0 <= m <= 2 * 10^4`; no self-loops or repeated arcs; `1 <= v <= n`.
- If no vertex points to `v`, the result is empty and the platform prints `(empty)`.
- Expected complexity: Θ(V).
