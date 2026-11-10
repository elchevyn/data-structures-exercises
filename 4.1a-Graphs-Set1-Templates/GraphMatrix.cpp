#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Directed graph: addEdge(u, v) adds only the arc u -> v.
// It does NOT add v -> u.
class MatrixGraph {  
    // Add the data members you need.
    int n;  // 1 ... n vertices 
    vector<vector<bool>> adjMatrix; // adj[u][v]: is there an edge u -> v?
public:
    explicit MatrixGraph(int n) {
        // your code here
        adjMatrix.assign(n, vector<bool>(n, false)); // Initialize the adjacency matrix with false values
    }

    void addEdge(int u, int v) {
        // your code here
        adjMatrix[u][v] = true;
    }
    

    bool hasEdge(int u, int v) const {
        // your code here
        if (adjMatrix[u][v]) {
            return true;
        } else {
            return false;
        }
    }

    vector<int> neighbors(int u) const {
        // your code 
        vector<int> result;
        for (int v = 0; v < n; v++) {
            if (adjMatrix[u][v]) {
                result.push_back(v);
            }
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    MatrixGraph g(n);

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
            vector<int> out = g.neighbors(u);
            if (out.empty()) {
                cout << "(empty)\n";
            } else {
                for (int j = 0; j < (int)out.size(); ++j) {
                    cout << (j ? " " : "") << out[j];
                }
                cout << '\n';
            }
        }
    }
    return 0;
}
