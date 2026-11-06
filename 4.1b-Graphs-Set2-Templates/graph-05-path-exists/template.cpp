#include <queue>
#include <vector>
using namespace std;

// Do NOT change the class: only write the body of the function at the end of the file.
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

bool hasPath(const ListGraph &g, int n, int s, int t) {
	// your code here
	return false;
}
