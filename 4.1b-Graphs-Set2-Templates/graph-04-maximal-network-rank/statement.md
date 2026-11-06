# Maximal Network Rank

There are `n` cities, labeled `1..n`, joined by two-way roads. The network rank of two different
cities is the number of roads that touch **either** city; a road that joins the two cities counts once.
Return the maximal network rank over all pairs of cities. Hint: degrees, plus "are they linked?" in O(1),
which is what the matrix gives you.

```cpp
int maximalNetworkRank(const MatrixGraph &g, int n);
```

The template contains the class `MatrixGraph` from P16 (adjacency matrix, vertices `1..n`). **Do not change
it**: write only the body of the function at the end of the file. Use `g.hasEdge(u, v)` (O(1)) and
`g.neighbors(v)`. If you need a helper, write it as a normal function. Do not write `main()`.

Each case gives `n` and `m`, then `m` roads `a b`. Each road is added in both directions (`a -> b` and
`b -> a`).

## Examples

| n | roads | result |
|---|---|---|
| `4` | `1-2 1-4 2-3 2-4` | `4` |
| `5` | `1-2 1-3 2-3 2-4 3-4 3-5 4-5` | `5` |
| `2` | none | `0` |

## Constraints

- `2 <= n <= 100`, `0 <= m <= n * (n - 1) / 2`; no self-loops or repeated roads.
- Expected complexity: O(V^2).
