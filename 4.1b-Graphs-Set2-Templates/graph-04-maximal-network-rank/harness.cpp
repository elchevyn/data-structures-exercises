// Input: n m and m roads a b.  Output: maximalNetworkRank(g, n).
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
};

// Written by the student in solution.cpp.
int maximalNetworkRank(const MatrixGraph &g, int n);

int main() {
	ios::sync_with_stdio(false);
	int n = 0, m = 0;
	if (!(cin >> n >> m)) {
		return 2;
	}
	MatrixGraph g(n);
	for (int i = 0; i < m; i++) {
		int a = 0, b = 0;
		cin >> a >> b;
		g.addEdge(a, b);
		g.addEdge(b, a);
	}
	cout << maximalNetworkRank(g, n) << "\n";
	return 0;
}
