#include <bits/stdc++.h>

using namespace std;

#define P pair<int, int>

/* Almost same as sum_of_three_values, 
 * except fix two values instead of 1.
 *
 * O(n^3) time.
 */

bool comp(P p1, P p2) {
    return p1.first < p2.first;
}

int main() {
    int n, x;
    cin >> n >> x;

    P a[n];
    P p;
    for (int i=0; i < n; i++) {
        cin >> p.first;
        p.second = i+1;
        a[i] = p;
    }

    // sort the array
    sort(a, a+n, comp);

    // fix two values
    P fixed1;
    P fixed2;
    for (int l=0; l < n; l++) {
        for (int k=0; k < n; k++) {
            // make sure the indices are different
            if (k == l) {
                continue;
            }
            fixed1 = a[l];
            fixed2 = a[k];

            // run two finger on rest of them
            int i = 0;
            int j = n-1;
            while (i < j && k != i && k != j && l != i && l != j) {
                if (a[i].first + a[j].first + fixed1.first + fixed2.first == x) {
                    cout <<  a[i].second << " " << a[j].second << " " << fixed1.second << " " << fixed2.second << "\n";
                    return 0;
                } else if (a[i].first + a[j].first + fixed1.first + fixed2.first > x) {
                    j--;
                } else {
                    i++;
                }
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}
