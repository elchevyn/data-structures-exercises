# In-Degree of Every Vertex

Given a directed graph `g` with vertices `1..n`, stored as adjacency lists, return the in-degree of every
vertex: how many arcs **enter** it. With lists, `g.neighbors(u)` gives the arcs that leave `u`, so you must
find the arcs that enter each vertex from the other side. Position 0 of the result is not used: return a
vector of size `n + 1` where `result[v]` is the in-degree of `v`.

```cpp
vector<int> inDegrees(const ListGraph &g, int n);
```

The template contains the class `ListGraph` from P16 (adjacency lists, vertices `1..n`). **Do not change
it**: write only the body of the function at the end of the file. Use `g.neighbors(v)` to visit the
neighbors of `v`. If you need a helper, write it as a normal function. Do not write `main()`.

Each case gives `n` and `m`, then `m` arcs `u v` (the arc `u -> v`). The platform prints `result[1..n]` on
one line.

## Examples

| n, arcs | result |
|---|---|
| `4`; `1>2 1>3 2>3 3>1 4>3` | `1 1 3 0` |
| `3`; none | `0 0 0` |
| `3`; `1>2 2>3 3>1` | `1 1 1` |

## Constraints

- `1 <= n <= 5 * 10^4`, `0 <= m <= 10^5`; no self-loops or repeated arcs.
- Expected complexity: O(V + E).
