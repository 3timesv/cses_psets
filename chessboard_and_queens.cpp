#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 8;
    char board[n][n];

    for (int i=0; i < n; i++) {
        for (int j=0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    // columns where queens are placed
    int cols[n];
    // fills cols with 0 to n
    iota(cols, cols+n, 0);

    // initialize result with 0
    int result = 0;

    // loop over all permutations of columns
    do {  
        // permutation is valid
        bool valid = true;

        // if any queen is sitting at reserved spot, its not valid
        for (int i=0; i < n; i++) {
            if (board[i][cols[i]] == '*') {
                valid = false;
                break;
            }
        }

        // check diagonal attacks
        for (int i=0; i < n; i++) {
            for (int j=0; j < n; j++) {
                if (i != j) {
                    if ((7 + cols[i] - i == 7 + cols[j] - j) || (i + cols[i] == j + cols[j])) {
                        valid = false;
                        break;
                    }
                }
            }
            if (!valid) {
                break;
            }
        }

        if (valid) {
            result++;
        }
    } while (next_permutation(cols, cols+n));

    cout << result << "\n";
}
