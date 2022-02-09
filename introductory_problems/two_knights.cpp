#include <bits/stdc++.h>

using namespace std;

/* 
 * Total number of ways to place two knights on a kxk board = k^2 (k^2 - 1) / 2
 * For each 2x3 and 3x2 boards, there are 2 ways of placing two knights so that they threaten each other.
 *
 * Number of 2x3 boards on a nxn board = (n-1)(n-2)
 * Number of 3x2 boards on a nxn board = (n-2)(n-1)
 *
 * => Number of ways to place two knights on a nxn board so that they threaten each other = 4(n-1)(n-2)
 *
 * => Number of ways to place two knights on a nxn board so that they don't attack each other = 
 *    Total number of ways to place two knights on a nxn board - 
 *    Number of ways to place two knights on nxn board so that they attack each other.
 */

#define ll long long

int main() {
    int n;
    cin >> n;

    for (ll i=1; i <= n; i++) {
        ll totalWays = (i*i*(i*i - 1))/2;
        ll attackWays = 4 * (i-1) * (i-2);

        ll nonAttackWays = totalWays - attackWays;
        cout << nonAttackWays << "\n";
    }

}
