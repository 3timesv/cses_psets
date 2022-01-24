#include <bits/stdc++.h>

#define boost_inp ios_base::sync_with_stdio(0); cin.tie(NULL);

using namespace std;

int main()
{
    boost_inp;

    int size;
    cin >> size;

    int count = 0;
    set<int> seen;

    for (int i = 0; i < size; i++)
    {
        int inp;
        cin >> inp;
        if (!seen.count(inp))
        {
            seen.insert(inp);
            count += 1;
        }

    }
    cout << count;

}
