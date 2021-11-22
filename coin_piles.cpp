#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int l;
    int r;
    for (int i=0; i < n; i++) {
        cin >> l >> r;

        if (2 * l < r || 2 * r < l) {
            cout << "NO\n";
            continue;
        }

        if ((2 * l - r) % 3 == 0 && (2 * r - l) % 3 == 0) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}
