#include <bits/stdc++.h>

using namespace std;

#define P pair<int, int>

/* Almost Same as sum_of_two_values, 
 *
 * keep one value fixed and find the other two using sum_of_two_values
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

    P fixed;
    for (int k=0; k < n; k++) {
        // keep one value fixed
        fixed = a[k];

        // two-finger algorithm
        int i = 0;
        int j = n-1;

        // make sure three indices are distinct
        while (i < j && k != i && k != j) {
            // if found, print and return
            if (a[i].first + a[j].first + fixed.first == x) {
                cout <<  a[i].second << " " << a[j].second << " " << fixed.second << "\n";
                return 0;
                // if greater, reduce right finger (j)
            } else if (a[i].first + a[j].first + fixed.first > x) {
                j--;
                // if smaller, increase left finger (i)
            } else {
                i++;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}
