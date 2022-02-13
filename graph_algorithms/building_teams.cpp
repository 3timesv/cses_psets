#include <bits/stdc++.h>

using namespace std;

// P. check if graph is bipartite
// S. use full bfs and color alternate levels alternate colors.

// bfs on node v
bool bfs(vector<int> adj[], vector<bool> &visited, vector<string> &colors, int v) {
    // base case
    queue<int> q;
    q.push(v);
    visited[v] = true;
    colors[v] = "1";

    bool impossible = false;
    string color;
    while (!q.empty()) {
        int s = q.front(); q.pop();

        // pick alternate color for neighbors of s
        if (colors[s] == "1") {
            color = "2";
        } else {
            color = "1";
        }

        for (int u: adj[s]) {
            // if neighbor u is already colored same as s, then the graph is not bipartite
            if (colors[u] == colors[s]) {
                impossible = true;
                break;
            }
            if (visited[u]) continue;

            visited[u] = true;
            q.push(u);
            colors[u] = color;
        }
        if (impossible) {
            break;
        }
    }
    return impossible;
}

int main() {
    int n, m;
    cin >> n >> m;

    // build adjacency list
    vector<int> adj[n+1];
    int x, y;
    for (int i=0; i < m; i++) {
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }


    // declare data structures
    queue<int> q;
    vector<bool> visited(n+1, false);
    vector<string> colors(n+1, "");

    bool impossible = false;
    // full bfs
    for (int i=1; i <= n; i++) {
        if (!visited[i]) {
            impossible = bfs(adj, visited, colors, i);
        }
        if (impossible) {
            break;
        }
    }

    // display result
    if (impossible) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (int i=1; i <= n; i++) {
            cout << colors[i] << " ";
        }
        cout << "\n";
    }
}
