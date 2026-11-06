# Find the Town Judge

In a town there are `n` people, labeled `1..n`. An arc `a -> b` means that `a` trusts `b`.
The town judge, if there is one, trusts nobody, and everybody else trusts the judge. Return the label of
the judge, or `-1` if there is none. Hint: count, for each person, the arcs that enter and the arcs that
leave (in-degree and out-degree).

```cpp
int findJudge(const ListGraph &g, int n);
```

The template contains the class `ListGraph` from P16 (adjacency lists, vertices `1..n`). **Do not change
it**: write only the body of the function at the end of the file. Use `g.neighbors(v)` to visit the
neighbors of `v`. If you need a helper, write it as a normal function. Do not write `main()`.

Each case gives `n` and `m`, then `m` arcs `a b` (`a` trusts `b`).

## Examples

| n | arcs | result |
|---|---|---|
| `3` | `1>3 2>3` | `3` |
| `3` | `1>3 2>3 3>1` | `-1` |
| `2` | `1>2` | `2` |

## Constraints

- `1 <= n <= 2 * 10^4`, `0 <= m <= 6 * 10^4`; no self-loops or repeated arcs.
- Expected complexity: O(V + E).
