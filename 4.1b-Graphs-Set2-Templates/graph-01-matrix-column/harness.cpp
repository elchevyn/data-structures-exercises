// Input: n m, m arcs u v, and v.  Output: g.inNeighbors(v) on one line.
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

// Graph from P16: adjacency matrix, vertices 1..n, as in Weiss.
class MatrixGraph {
	int n;
	vector<vector<bool>> adj;              // adj[u][v]: is there an edge u -> v?
public:
	explicit MatrixGraph(int n) : n{n}, adj(n + 1, vector<bool>(n + 1, false)) {}
	void addEdge(int u, int v) { adj[u][v] = true; }          // O(1)
	bool hasEdge(int u, int v) const { return adj[u][v]; }    // O(1)
	vector<int> neighbors(int u) const {                      // Θ(V): reads the whole row
		vector<int> out;
		for (int v = 1; v <= n; ++v)
			if (adj[u][v]) out.push_back(v);
		return out;
	}
	vector<int> inNeighbors(int v) const;                     // reads the whole column
};

// Prints the values on one line, or (empty).
void printLine(const vector<int> &values) {
	if (values.empty()) {
		cout << "(empty)";
	}
	for (size_t i = 0; i < values.size(); i++) {
		cout << (i > 0 ? " " : "") << values[i];
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	int n = 0, m = 0;
	if (!(cin >> n >> m)) {
		return 2;
	}
	MatrixGraph g(n);
	for (int i = 0; i < m; i++) {
		int u = 0, v = 0;
		cin >> u >> v;
		g.addEdge(u, v);
	}
	int v = 0;
	cin >> v;
	printLine(g.inNeighbors(v));
	return 0;
}
