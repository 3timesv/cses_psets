#include <bits/stdc++.h>

using namespace std;

string result = "";
int moves = 0;

void solve(int n, int start, int end, int mid) {
    if (n == 1) {
        result += to_string(start) + " " + to_string(end) + "\n";
        moves++;
    } else {
        // move n-1 disks from start to mid using end as auxiliary
        solve(n-1, start, mid, end);

        // move the largest disk from start to end
        result += to_string(start) + " " + to_string(end) + "\n";
        moves++;

        // move the n-1 disks from mid to end using start as auxiliary
        solve(n-1, mid, end, start);
    }
}

int main() {
    int n;
    cin >> n;

    solve(n, 1, 3, 2);

    cout << moves << "\n";
    cout << result;

}
