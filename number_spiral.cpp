#include <bits/stdc++.h>

using namespace std;

#define ll long long 

int main() {
    int t;
    cin >> t;

    int y, x;

    ll n;
    ll mid;
    ll res[t];

    for (int i=0; i < t; i++) {
        cin >> y >> x;

        n = max(y, x);
        mid = n * (n-1) + 1;

        if (n % 2 == 0) {
            res[i] = mid + y - x;
        }
        else {
            res[i] = mid + x - y;
        }
    }

    for (int i=0; i < t; i++) {
        cout << res[i] << "\n";
    }
}
