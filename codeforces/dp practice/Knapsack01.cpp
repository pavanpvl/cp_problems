#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("/home/pavan/cp_problems/a.in", "r", stdin);
    freopen("/home/pavan/cp_problems/a.out", "w", stdout);
#endif
    int t{};
    cin >> t;

    while (t--)
    {
        int n, c;
        cin >> n >> c;
        int w[n];
        int v[n];
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> w[i];
        }
        int m[n + 1][c+1];
        memset(m, 0, sizeof(m[0][0]) * (n + 1) * (c+1));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= c; j++)
            {
                if (j < w[i - 1])
                    m[i][j] = m[i - 1][j];
                else
                {
                    m[i][j]=max(m[i-1][j],m[i-1][j-w[i-1]]+v[i-1]);
                }
            }
        }
        cout<<m[n][c]<<"\n";
    }

    return 0;
}