#include <vector>
using namespace std;

// Graph from P16: adjacency lists, vertices 1..n, directed.
class ListGraph {
    vector<vector<int>> adj;
public:
    explicit ListGraph(int n) : adj(n + 1) {}
    void addEdge(int u, int v) { adj[u].push_back(v); }
    const vector<int>& neighbors(int u) const { return adj[u]; }
};

vector<int> dfsOrder(const ListGraph &g, int n, int s) {
    // your code here
    return {};
}
