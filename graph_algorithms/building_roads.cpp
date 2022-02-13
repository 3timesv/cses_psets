#include <bits/stdc++.h>

using namespace std;

#define p pair<int, int>

const int mn = 1e5+10;

bool visited[mn];
// Adjacency list
vector<int> adj[mn];
// connected components as vectors of vectors of ints
vector<vector<int>> CC;

// DFS on u 
void dfs(vector<int> &cc, int u) {
    // neighbors of u
    for (int v: adj[u]) {
        // that are not visited
        if (!visited[v]) {
            // add to connected component and call dfs on it
            cc.push_back(v);
            visited[v] = true;
            dfs(cc, v);
        }
    }
}

// Run DFS on u and store all the reachable nodes from u in a vector
void run_dfs(int u) {
    // connected component of which u is a part
    vector<int> cc;
    // add u (obvious :|
    cc.push_back(u);
    visited[u] = true;

    // call dfs on u
    dfs(cc, u);
    CC.push_back(cc);
}

int main() {
    int n, m;
    cin >> n >> m;

    // build adjacency list
    int x, y;
    for (int i=0; i < m; i++) {
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }
        
    // count of connected components
    int count = 0;
    // Full DFS
    for (int i=1; i <= n; i++) {
        if (!visited[i]) {
            count++;
            run_dfs(i);
        }
    }

    // number of edges required to make the graph connected are number of connected components minus 1
    cout << count-1 << "\n";

    // pick any nodes from all pairs of connected components (choosing 0th node without loss of generality)
    for (int i=0; i < (int) CC.size()-1; i++) {
        cout << CC[i][0] << " " << CC[i+1][0] << "\n";
    }
}
