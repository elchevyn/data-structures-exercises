// Input: n m, then m arcs u v. Output: topologicalSort(g,n).
#include <iostream>
#include <vector>
using namespace std;

class ListGraph {
    vector<vector<int>> adj;
public:
    explicit ListGraph(int n) : adj(n + 1) {}
    void addEdge(int u, int v) { adj[u].push_back(v); }
    const vector<int>& neighbors(int u) const { return adj[u]; }
};

vector<int> topologicalSort(const ListGraph &g, int n);

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

    vector<int> order = topologicalSort(g, n);
    if (order.empty()) {
        cout << "(empty)\n";
    } else {
        for (int i = 0; i < (int)order.size(); ++i) {
            cout << (i ? " " : "") << order[i];
        }
        cout << '\n';
    }
    return 0;
}
