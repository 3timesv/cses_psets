#include <bits/stdc++.h>

using namespace std;
#define p pair<int, int>

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid;
    string row;
    for (int i=0; i < n; i++) {
        cin >> row;
        grid.push_back(row);
    }

    // find position of A in the grid
    p Apos;
    bool found = false;
    for (int i=0; i < n; i++)  {
        for (int j=0; j < m; j++) {
            if (grid[i][j] == 'A') {
                Apos.first = i;
                Apos.second = j;
                found = true;
                break;
            }
        }
        if (found) {
            break;
        }
    }

    // initialize queue of coordinates
    queue<p> q;

    // 2D vector to check whether a vertex is visited or not
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    // 2D vector to store distance from 'A'
    int distance[n][m];

    // map to store parent of a vertex, also the direction as char
    map<p, pair<p, char>> P;

    // base case , set entries for 'A'
    visited[Apos.first][Apos.second] = true;
    distance[Apos.first][Apos.second] = 0;
    q.push(Apos);
    P.insert(make_pair(Apos, make_pair(make_pair(-1, -1), 'E')));

    // exist will remain false if there's no B in the grid
    bool exist = false;

    while (!q.empty()) {
        // get a node
        p s = q.front(); q.pop();

        // if it's B, 
        if (grid[s.first][s.second] == 'B') {
            exist = true;

            // get its distance (its shortest by definition of BFS)
            int dist = distance[s.first][s.second];
            // res to store moves
            string res = "";

            // trace moves from B to A
            while (P.at(make_pair(s.first, s.second)).second != 'E') {
                pair<p, char> prev = P.at(make_pair(s.first, s.second));
                s = prev.first;
                res += prev.second;
            }
            // display result
            cout << "YES\n";
            cout << dist << "\n";
            for (int i=res.length()-1; i >= 0; i--) {
                cout << res[i];
            }
            cout << "\n";

            break;
        }

        // iterate over neighbors of s, left/right/up/down
        vector<pair<p, char>> neighbors;
        neighbors.push_back(make_pair(make_pair(0, -1), 'L'));
        neighbors.push_back(make_pair(make_pair(0, 1), 'R'));
        neighbors.push_back(make_pair(make_pair(-1, 0), 'U'));
        neighbors.push_back(make_pair(make_pair(1, 0), 'D'));

        for (pair<p, char> adj: neighbors) {
            int x = s.first + adj.first.first;
            int y = s.second + adj.first.second;
            p v = make_pair(x, y);

            // if its a invalid neighbor, continue
            if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == '#') {
                continue;
            }

            // otherwise and if its not visited, add it to entries
            if (!visited[v.first][v.second]) {
                visited[v.first][v.second] = true;
                distance[v.first][v.second] = distance[s.first][s.second] + 1;
                q.push(v);
                P.insert(make_pair(v, make_pair(s, adj.second)));
            }
        }
    }

    if (!exist) {
        cout << "NO\n";
    }
}
