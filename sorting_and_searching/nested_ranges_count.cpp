#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

    int csor[n] = {0}; 
    int sorc[n] = {0};

    // declare an ordered set of pair of integers
    ordered_set<pair<int, int>> R;

    for (int i=0; i < n; i++) {
        // add right element and its -ve index to the set
        R.insert({get<1>(v[i]), -1 * i});
        // perform set.size() - index of pair - 1 to get the number of pairs greater than current pair
        sorc[get<2>(v[i])] = R.size() - R.order_of_key({get<1>(v[i]), -1*i}) - 1;
    }

    R.clear();
    for (int i=n-1; i >= 0; i--) {
        // add right element and its -ve index to the set
        R.insert({get<1>(v[i]), -1*i});
        // get index of pair in the set, to get the elements smaller than current pair
        csor[get<2>(v[i])] = R.order_of_key({get<1>(v[i]), -1*i});
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
