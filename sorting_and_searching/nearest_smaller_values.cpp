#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    // after index i, stack contains all the elements that are smaller than or equal to a[i]
    // pair = (index, value)
    stack<pair<int, int>> s;

    // initialize resulting array with 0
    int r[n] = {0};

    int elem;
    for (int i = 0; i < n; i++) {
        cin >> elem;

        while ((!s.empty()) && (s.top().second >= elem)) {
            s.pop();
        }

        if (!s.empty()) {
            r[i] = s.top().first + 1;
        }

        pair<int, int> p = {i, elem};
        s.push(p);
    }

    for (int i=0; i < n; i++) {
        cout << r[i] << " ";
    }
    cout << "\n";
}
