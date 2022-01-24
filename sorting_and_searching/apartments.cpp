#include <bits/stdc++.h>

#define boost_inp ios_base::sync_with_stdio(0); cin.tie(NULL);

using namespace std;

vector<int> getInputVector(int size)
{
    vector<int> v;
    for (int i = 0; i < size; i++)
    {
        int inp;
        cin >> inp;
        v.push_back(inp);
    }
    return v;
}

int main()
{
    boost_inp;

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> n_vector = getInputVector(n);
    vector<int> m_vector = getInputVector(m);

    sort(n_vector.begin(), n_vector.end());
    sort(m_vector.begin(), m_vector.end());

    int count = 0;
    int i, j;
    for (i=0, j=0; i < n; i++)
    {
        while (j < m && m_vector[j] < n_vector[i]-k)
        {
            j++;
        }
        if (j < m && m_vector[j] <= n_vector[i] + k)
        {
            j++;
            count++;
        }
    }

    cout << count << '\n';
}
