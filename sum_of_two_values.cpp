#include <bits/stdc++.h>

using namespace std;

#define P pair<int, int>

bool comp(P p1, P p2) {
    return p1.first < p2.first;
}

int main() {
    int n, x;
    cin >> n >> x; 

    vector<P> v;

    P p;
    for (int i=0; i < n; i++) {
        cin >> p.first;
        p.second = i+1;
        v.push_back(p);
    }

    sort(v.begin(), v.end(), comp);

    int i = 0;
    int j = n-1;

    while (j-i >= 1) {
        if (v[i].first + v[j].first == x) {
            cout << v[i].second << " " << v[j].second << "\n";
            return 0;
        }
        else if (v[i].first + v[j].first > x) {
            j--;
        }
        else {
            i++;
        }
    }
    cout << "IMPOSSIBLE\n";
}
