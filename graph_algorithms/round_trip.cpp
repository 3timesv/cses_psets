#include <bits/stdc++.h>

using namespace std;

// declare data structures
vector<vector<int>> adj;
vector<int> visited;
vector<int> parent;

bool dfs(int u, int p) {
    // set u as visited and set parent of u as p
    visited[u] = true;
    parent[u] = p;

    // neighbors of u
    for (int v: adj[u]) {
        // if v is already visited and is not a parent of u, then there's a cycle
        if (visited[v]) {
            if (v != p) {
                // vector to store cycle in
                vector<int> res;
                res.push_back(u);
                int u_copy = u;
                // add the cycle to the result
                while (u != v) {
                    res.push_back(parent[u]);
                    u = parent[u];
                }
                res.push_back(u_copy);

                // display result
                cout << res.size() << endl;
                for (int i=0; i < (int) res.size(); i++) {
                    cout << res[i] << " ";
                }
                cout << "\n";
                return true;
            }
        } else {
            // if v is not visited, call dfs on it
            if (dfs(v, u)) return true;
        }
    }
    return false;
}


int main() {
    int n, m; 
    cin >> n >> m;

    adj.resize(n+1);
    visited.resize(n+1);
    parent.resize(n+1);

    // build adjacency list
    int x, y;
    for (int i=0; i < m; i++) {
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // full DFS
    for (int i=1; i <= n; i++) {
        if (!visited[i]) {
            // if cycle detected and printed, end the program
            if(dfs(i, -1)) return 0;
        }
    }
    cout << "IMPOSSIBLE\n";

}
