#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    long long count = 0;

    for (int i=0; i < n; i++) {
        cin >> arr[i];
    }

    int ext;
    for (int i=1; i < n; i++) {
        if (arr[i-1] > arr[i]) {
            ext = arr[i-1] - arr[i];
            arr[i] += ext;
            count += ext;
        }
    }
    cout << count << "\n";

}
