#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, n;
    cin >> x;
    cin >> n;

    // store positions
    set<int> s;
    s.insert(0);
    s.insert(x);

    // store passage lengths without street light
    multiset<int> ms;
    ms.insert(x - 0);

    int a;
    set<int>::iterator iter;
    for (int i=0; i < n; i++) {
        cin >> a;

        // add new traffic light
        s.insert(a);
        iter = s.find(a);

        // find traffic light on the left
        int l = *prev(iter);
        // find traffic light on the right
        int r = *next(iter);

        // remove previous passage length
        ms.erase(ms.find(r - l));

        // add two new passage lengths
        ms.insert(r - a);
        ms.insert(a - l);

        // print the longest passage
        cout <<  *ms.rbegin() << " ";
    }
}
