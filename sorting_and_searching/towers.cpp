#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    int n;
    cin >> n;

    ll k[n];

    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }

    // will store towers in multiset (there may be multiple towers of same length at same time, thats why multi)
    multiset<ll> s;
    multiset<ll>::iterator it;

    // loop over k_i
    for (int i=0; i < n; i++) {
        // check if there is any tower upon which we can place k[i]
        it = s.upper_bound(k[i]);

        // yes ?
        if (it != s.end()) {
            // place on top of it (now top of tower is k[i], thats why erase)
            s.erase(it);
            s.insert(k[i]);
            // no ?
        } else {
            // create a new tower 
            s.insert(k[i]);
        }
    }

    // print the number of towers
    cout << s.size() << "\n";
}
