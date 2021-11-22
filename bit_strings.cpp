#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;

    long long result = 1;
    for (int i=0; i < n; i++) {
        result *= 2;
        result = result % (long long) (1e9 + 7);
    }

    cout << result << endl;
}
