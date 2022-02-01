#include <bits/stdc++.h>

using namespace std;

// third element in tuple is index 
bool comp(tuple<int, int, int> p1, tuple<int, int, int> p2) {
    // if first elements of tuples are equal, the tuple with higher second element should come earlier
    if (get<0>(p1) == get<0>(p2)) {
        return get<1>(p1) > get<1>(p2);
        // otherwise smaller first should be earlier 
    } else {
        return get<0>(p1) < get<0>(p2);
    }
}

int main() {
    int n;
    cin >> n;

    vector<tuple<int, int, int>> v;
    int a, b;
    for (int i=0; i < n; i++) {
        cin >> a >> b;
        tuple<int, int, int> t = make_tuple(a, b, i);
        v.push_back(t);
    }

    // sort the input
    sort(v.begin(), v.end(), comp);

    int csor[n] = {0}; // i contains some other range
    int sorc[n] = {0}; // some other range contains i

    pair<int, int> maxRight = {0, -1};
    pair<int, int> minRight = {1e9, -1};
    for (int i=0; i < n; i++) {
        // if right of i is less than or equal to maxRight, then its contained by someone
        if (get<1>(v[i]) <= maxRight.first) {
            sorc[get<2>(v[i])] = 1;
            // otherwise it is not contained by someone, update maxRight
        } else {
            maxRight = get<1>(v[i]);
        }

        // start from last i.e n-1-i
        //
        // if current right is >= minRight, then current right contains someone
        if (get<1>(v[n-1-i]) >= minRight) {
            csor[get<2>(v[n-1-i])] = 1;
            // otherwise update minRight
        } else {
            minRight = get<1>(v[n-1-i]);
        }
    }

    // print contains some other range
    for (int j=0; j < n; j++) {
        cout << csor[j] << " ";
    }
    cout << "\n";

    // print contained by some other range
    for (int i=0; i < n; i++) {
        cout << sorc[i] << " ";
    }
    cout << "\n";
}
