#include <bits/stdc++.h>

using namespace std;

#define ll long long 

int main() {
    int n;
    int arr[20];

    cin >> n;
    for (int i=0; i < n; i++) {
        cin >> arr[i];
    }

    ll minA = 1e16;

    // loop 0 to 2^n - 1
    for (int i=0; i < (1 << n); i++) {
        // sum of group 1 
        ll sum1 = 0;
        // sum of group 2
        ll sum2 = 0;
        for (int j=0; j < n; j++) {
            // if position j is ON, add element at position j to group 1
            if (i & (1<<j)) {
                sum1 += arr[j];
                // otherwise, add element at position j to group 2
            } else {
                sum2 += arr[j];
            }
        }
        // update the minimum
        minA = min(minA, abs(sum1 - sum2));
    }
    cout << minA << "\n";
}
