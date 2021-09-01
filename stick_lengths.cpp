#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n; 
    
    int arr[n];
    
    for (int i=0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    int median = arr[n/2];

    long long result = 0;
    for (int i=0; i < n; i++) {
        result += abs(median - arr[i]);
    }

    cout << result << "\n";

}
