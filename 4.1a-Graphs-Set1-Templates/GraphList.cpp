#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Implement a directed graph with vertices 1..n.
// addEdge(u, v) adds only the arc u -> v; it does NOT add v -> u.
class ListGraph {
    // Add the data members you need here.
    vector<vector<int>> adjList; // adjacency list representation
public:
    explicit ListGraph(int n) : adjList(n + 1) {
        // your code here

    }

    // Adds the directed arc u -> v.
    void addEdge(int u, int v) {
        // your code here
        adjList[u].push_back(v);
    }

    bool hasEdge(int u, int v) const {
        // your code here
        for (int neighbor : adjList[u]) {
            if (neighbor == v) {
                return true;
            }
        }
        return false;
    }

    const vector<int>& neighbors(int u) const {
        // your code here
        return adjList[u];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    ListGraph g(n);

    for (int i = 0; i < q; ++i) {
        string command;
        cin >> command;

        if (command == "ADD") {
            int u, v;
            cin >> u >> v;
            g.addEdge(u, v);
        } else if (command == "HAS") {
            int u, v;
            cin >> u >> v;
            cout << (g.hasEdge(u, v) ? "true" : "false") << '\n';
        } else { // NEIGHBORS
            int u;
            cin >> u;
            const vector<int>& out = g.neighbors(u);
            if (out.empty()) {
                cout << "(empty)\n";
            } else {
                for (int j = 0; j < static_cast<int>(out.size()); ++j) {
                    cout << (j == 0 ? "" : " ") << out[j];
                }
                cout << '\n';
            }
        }
    }
    return 0;
}
