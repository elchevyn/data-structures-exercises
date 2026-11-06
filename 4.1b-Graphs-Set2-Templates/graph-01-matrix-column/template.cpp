#include <vector>
using namespace std;

// Do NOT change the class: only write the body of the method at the end of the file.
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

// Returns every u with an arc u -> v, in ascending order.
vector<int> MatrixGraph::inNeighbors(int v) const {
	// your code here
	return {};
}
