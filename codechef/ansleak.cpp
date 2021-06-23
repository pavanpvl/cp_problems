#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    int t{};
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> res(n, 0);
        int p[n][k];
        int v[n][m + 1];
        for (int i = 0; i < n; i++)
        {
            //vector<int> v(m, 0);
            int m = 0, temp;
            for (int j = 0; j < k; j++)
            {
                cin >> p[i][j];
                v[i][p[i][j]] += 1;
                m = max(v[i][p[i][j]], m);
                temp = (m == v[i][p[i][j]]) ? p[i][j] : temp;
            }
            res[i] = temp;
        }
        int cnt{};
        for (int j = 0; j < k; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (res[i] != p[i][j])
                    cnt++;
            }
            if (cnt == n)
            {
                int m = 0, temp, pos, ks;
                for (ks = 0; ks < n; ks++)
                {
                    m = max(v[ks][p[ks][j]], m);
                    temp = (m == v[ks][p[ks][j]]) ? p[ks][j] : temp;
                    pos = (m == v[ks][p[ks][j]]) ? ks : pos;
                }
                res[ks] = temp;
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << res[i] << '\n';
        }
    }
    return 0;
}