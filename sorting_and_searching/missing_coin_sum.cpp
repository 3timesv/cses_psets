#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n];

    for (int i=0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a+n);

    long long sum = 1;
    for (int i=0; i < n; i++) {
        if (sum < a[i]) {
            break;
        }
        sum += a[i];
    }
    cout << sum << "\n";
}
