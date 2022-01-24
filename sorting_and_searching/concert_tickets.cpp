# include <bits/stdc++.h>
#define boost_inp ios_base::sync_with_stdio(0); cin.tie(NULL);

using namespace std;


int main()
{
    boost_inp;

    int n, m;
    cin >> n >> m;

    multiset<int> h;

    for (int i=0; i < n; i++)
    {
        int inp;
        cin >> inp;
        h.insert(inp);
    }

    int inp;
    for (int k=0; k < m; k++)
    {
        cin >> inp;
        auto it = h.upper_bound(inp);
//        if (distance(h.begin(), it) <= 0) cout << -1 << '\n';
//        distance is O(len(range))
        if (it == h.begin()) cout << -1 << '\n';
        else
        {
            it--;
            cout << *it << '\n';
            h.erase(it);
        }
    }

}
