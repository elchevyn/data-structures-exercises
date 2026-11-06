// Input: n m and m arcs u v.  Output: inDegrees(g, n)[1..n] on one line.
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

// Graph from P16: adjacency lists, vertices 1..n.
class ListGraph {
	vector<vector<int>> adj;               // adj[u]: the vertices adjacent to u
public:
	explicit ListGraph(int n) : adj(n + 1) {}
	void addEdge(int u, int v) { adj[u].push_back(v); }       // O(1) amortized
	bool hasEdge(int u, int v) const {                        // O(deg(u))
		for (int w : adj[u])
			if (w == v) return true;
		return false;
	}
	const vector<int> &neighbors(int u) const {               // O(1) to get it,
		return adj[u];                                        // O(deg(u)) to scan it
	}
};

// Written by the student in solution.cpp.
vector<int> inDegrees(const ListGraph &g, int n);

// Reads n, m and m edges u v; adds u->v (and v->u if undirected) in input order.
bool readGraph(ListGraph *&g, int &n, bool undirected) {
	int m = 0;
	if (!(cin >> n >> m)) {
		return false;
	}
	g = new ListGraph(n);
	for (int i = 0; i < m; i++) {
		int u = 0, v = 0;
		cin >> u >> v;
		g->addEdge(u, v);
		if (undirected) {
			g->addEdge(v, u);
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	ListGraph *g = nullptr;
	int n = 0;
	if (!readGraph(g, n, false)) {
		return 2;
	}
	vector<int> indeg = inDegrees(*g, n);
	for (int v = 1; v <= n; ++v) {
		cout << (v > 1 ? " " : "") << (v < (int)indeg.size() ? indeg[v] : -1);
	}
	cout << "\n";
	delete g;
	return 0;
}
