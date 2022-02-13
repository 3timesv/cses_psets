#include <bits/stdc++.h>

using namespace std;

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
    int distance[n+1];
    map<int, int> P;
    bool visited[n+1] = {false};

    // base case for source vertex
    q.push(1);
    distance[1] = 0;
    P.insert(make_pair(1, -1));
    visited[1] = true;

    bool exist = false;
    while (!q.empty()) {
        int s = q.front() ; q.pop();

        // if current vertex is target vertex
        if (s == n) {
            // trace back parents until source
            exist = true;
            int dist = distance[s] + 1;
            vector<int> path;

            while (P.at(s) != -1) {
                path.push_back(s);
                s = P.at(s);
            }
            path.push_back(1);

            // display shortest distance and path
            cout << dist << "\n";
            for (int i = (int) path.size() - 1; i >= 0; i--) {
                cout << path[i] << " ";
            }
            cout << "\n";
            break;
        }

        // look at neighbors of s and add them to data structures
        for (int u: adj[s]) {
            if (visited[u]) continue;
            visited[u] = true;
            distance[u] = distance[s] + 1;
            q.push(u);
            P.insert(make_pair(u, s));
        }
    }

    if (!exist) {
        cout << "IMPOSSIBLE\n";
    }


}
