#include <bits/stdc++.h>

using namespace std;

// checks that range of a index in grid is valid
bool isValid(int n, int m, int i, int j) {
    return (i >= 0 && j >= 0 && i < n && j < m);
}

void dfs(vector<string> &grid, vector<vector<int>> &visited, int n, int m, int i, int j) {
    // set current vertex as visited
    visited[i][j] = 1;

    // left
    if (isValid(n, m, i, j-1) && visited[i][j-1] == 0 && grid[i][j-1] == '.') {
        dfs(grid, visited, n, m, i, j-1);
    }

    // right
    if (isValid(n, m, i, j+1) && visited[i][j+1] == 0 && grid[i][j+1] == '.') {
        dfs(grid, visited, n, m, i, j+1);
    }

    // up
    if (isValid(n, m, i-1, j) && visited[i-1][j] == 0 && grid[i-1][j] == '.') {
        dfs(grid, visited, n, m, i-1, j);
    }

    // down
    if (isValid(n, m, i+1, j) && visited[i+1][j] == 0 && grid[i+1][j] == '.') {
        dfs(grid, visited, n, m, i+1, j);
    }
}

int main() {
    // get input
    int n, m;
    cin >> n >> m;

    vector<string> grid;

    string row;
    for (int i=0; i < n; i++) {
        cin >> row;
        grid.push_back(row);
    }

    // initialize a 2D vector of int to store 0 for not visited and 1 for visited
    vector<vector<int>> visited(n, vector<int>(m)) ;

    // initialize result to 0
    int count = 0;

    /* 
     * Invariant: If a '.' is found, all dots connected to it (including self) will be marked as visited
     */

    // iterate over 2D grid
    for (int i=0; i < n; i++) {
        for (int j=0; j < m; j++) {
            // if a '.' is found and it is not yet visited
            if (grid[i][j] == '.' && visited[i][j] == 0) {
                // it must be a new connected component (bcz of the invariant)
                count++;
                // call dfs to move to other vertices in this connected component
                dfs(grid, visited, n, m, i, j);
            }
        }
    }

    cout << count << "\n";
}
