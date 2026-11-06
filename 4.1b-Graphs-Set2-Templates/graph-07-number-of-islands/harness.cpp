// Input: rows cols and the rows of the grid.  Output: numIslands(grid).
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;


// Written by the student in solution.cpp.
int numIslands(vector<string> grid);

int main() {
	ios::sync_with_stdio(false);
	int rows = 0, cols = 0;
	if (!(cin >> rows >> cols)) {
		return 2;
	}
	vector<string> grid(rows);
	for (int i = 0; i < rows; i++) {
		cin >> grid[i];
	}
	cout << numIslands(grid) << "\n";
	return 0;
}
