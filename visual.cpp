#include <bits/stdc++.h>

using namespace std;
int maxpairs(vector<int> &a, vector<int> &b, int i, int j)
{
    if (i == (int)a.size() - 1)
    {
        for (; j < (int)b.size(); j++)
        {
            if (abs(a[i] - b[j]) <= 1)
            {
                return 1;
                cout << '\n'
                     << i << ' ' << j << '\n';
            }
        }
        return 0;
    }
    else if (j == (int)b.size() - 1)
    {
        for (; i < (int)a.size(); i++)
        {
            if (abs(a[i] - b[j]) <= 1)
            {
                return 1;
                cout << '\n'
                     << i << ' ' << j << '\n';
            }
        }
        return 0;
    }
    else
    {
        int pij, eqij;
        eqij = (abs(a[i] - b[j]) <= 1) ? 1 : 0;
        pij = max(maxpairs(a, b, i + 1, j), maxpairs(a, b, i, j + 1));
        pij = max(maxpairs(a, b, i + 1, j + 1) + eqij, pij);
        return pij;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    int n{};
    int m;
    vector<int> a, b;
    cin >> n;
    a.assign(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    b.assign(m, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    cout << maxpairs(a, b, 0, 0) << '\n';
    /*
    cout<<'\n';
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
    cout<<'\n';
    for(int i=0;i<m;i++){
        cout<<b[i];
    }
    cout<<'\n'; 
*/
    return 0;
}