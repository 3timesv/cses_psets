#include <bits/stdc++.h>

#define boost_inp ios_base::sync_with_stdio(0); cin.tie(NULL);

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    
    vector<int> p; 

    for (int i=0; i < n; i++)
    {
       int inp; 
       cin >> inp;
       p.push_back(inp);
    }

    sort(p.begin(), p.end());

    int count = 0;
    int i=0;
    int j=n-1;

    while (j-i >= 0)
    {
        if (p[i]+p[j] <= x)
        {
            count++;
            i++;
            j--;
        }
        else
        {
            count++;
            j--;
        }
    }
    cout << count << '\n';
}
