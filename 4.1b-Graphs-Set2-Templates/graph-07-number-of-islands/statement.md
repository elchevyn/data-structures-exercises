# Number of Islands

You get a map as a grid of `'1'` (land) and `'0'` (water). An island is a group of land cells
connected **horizontally or vertically** (not diagonally). Return the number of islands.

Think of each land cell as a vertex with an edge to each land neighbor (up, down, left, right), and
count the connected components with a DFS or BFS. You may change `grid` (it is a copy).

```cpp
int numIslands(vector<string> grid);
```

Write only the function. If you need a helper, write it as a normal function. Do not write `main()`.

Each case gives the number of rows and columns, then one line per row.

## Examples

| grid | result |
|---|---|
| `11110` / `11010` / `11000` / `00000` | `1` |
| `11000` / `11000` / `00100` / `00011` | `3` |
| `0` | `0` |

(`/` separates the rows.)

## Constraints

- Between 1 and 100 rows and between 1 and 100 columns; every cell is `'0'` or `'1'`.
- Expected complexity: O(rows * columns).
