// Input: n m, then m arcs u v, then s. Output: bfsDistances(g,n,s)[1..n].
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class ListGraph {
    vector<vector<int>> adj;
public:
    explicit ListGraph(int n) : adj(n + 1) {}
    void addEdge(int u, int v) { adj[u].push_back(v); }
    const vector<int>& neighbors(int u) const { return adj[u]; }
};

vector<int> bfsDistances(const ListGraph &g, int n, int s);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    ListGraph g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    int s;
    cin >> s;

    vector<int> dist = bfsDistances(g, n, s);
    for (int v = 1; v <= n; ++v) {
        cout << (v > 1 ? " " : "") << (v < (int)dist.size() ? dist[v] : -1);
    }
    cout << '\n';
    return 0;
}
