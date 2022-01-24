#include <bits/stdc++.h>

using namespace std;

#define P pair<int, int>

bool comp(P p1, P p2) {
    return p1.second < p2.second;
}


int main() {
    int n;
    cin >> n;

    vector<P> v;

    P p;
    for (int i=0; i < n; i++) {
        cin >> p.first;
        cin >> p.second;
        v.push_back(p);
    }

    sort(v.begin(), v.end(), comp);

    int count = 1;
    P prev;
    P curr;
    prev = v[0];
    for (int i=1; i < n; i++) {
        curr = v[i];
        if (curr.first >= prev.second) {
            prev = curr;
            count++;
        }
    }
    cout << count << "\n";
}
