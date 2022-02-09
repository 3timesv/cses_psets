#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    ll n;
    cin >> n;

    ll sum = n * (n + 1) / 2;

    // if sum of sequence is odd, it can't be divisible into two equal sets
    if (sum % 2 != 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";

        // create two sets, add all the elements of sequence to first set
        set<ll> s1, s2;
        for (ll i=1; i <= n; i++) {
            s1.insert(i);
        }

        // goal is to have each set's sum == target
        ll target = sum / 2;
        
        // start with last element
        ll i = n; 

        // keep running the loop until the remaining target is present in the first set
        while (s1.count(target) == 0) {
            // subtract element from target
            target -= i;

            // move element from first set to second set
            s2.insert(i);
            s1.erase(i);

            // move to next element
            i--;
        }

        // move remaining target from first to second set
        s1.erase(target);
        s2.insert(target);

        // print the result
        cout << s1.size() << "\n";
        for (ll s: s1) {
            cout << s << " ";
        }
        cout << "\n";

        cout << s2.size() << "\n";
        for (ll s: s2) {
            cout << s << " ";
        }
        cout << "\n";
    }
}
