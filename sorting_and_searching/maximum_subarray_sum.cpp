#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    int n;
    cin >> n;

    int a[n];

    for (int i=0; i < n; i++) {
        cin >> a[i];
    }

    ll maxGlobal = a[0];
    ll maxCurrent = a[0];
    for (int i=1; i < n; i++) {
        maxCurrent = max((long long)a[i], maxCurrent + a[i]);
        maxGlobal = max(maxCurrent, maxGlobal);
    }
    
    cout << maxGlobal << "\n";
}


// *
// Kadane's  algorithm 
//
// for given index i,
//      the maximum subarray sum for subarrays ending at the index i is either a[i] or max_current + a[i]
//      where, max_current is the maximum subarray's sum for previous subarrays
//
//
//
//  ref : Kadane's algorithm to maximum subarray problem [CS Dojo]
