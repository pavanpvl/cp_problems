#include <bits/stdc++.h>

#define DEBUG

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("/home/pavan/cp_problems/a.in", "r", stdin);
    freopen("/home/pavan/cp_problems/a.out", "w", stdout);
#endif

    int m{}, s{}, s1{};
    cin >> m >> s1;
    s1 = s1 - 1;
    int mn[m];
    int mx[m];
    memset(mx, 0, sizeof(mx));
    memset(mn, 0, sizeof(mn));
    mx[0] = 1;
    mn[0] = mx[0];
    if (s1 == -1 &&m == 1)
        cout << "0 0\n";
    else if (s1 < 0)
        cout << "-1 -1\n";
    else
    {
        s = s1;
        for (int i = 0; s > 0 && i < m; i++)
        {
            if (s >= 9)
            {
                if (i == 0)
                {
                    s = s - 8;
                    mx[i] += 8;
                }
                else
                {
                    s = s - 9;
                    mx[i] += 9;
                }
            }
            else
            {
                mx[i] += s;
                s = 0;
            }
        }
        s = s1;
        for (int i = m - 1; s > 0 && i >= 0; i--)
        {
            if (s >= 9)
            {
                if (i == 0)
                {
                    s = s - 8;
                    mn[i] += 8;
                }
                else
                {
                    s = s - 9;
                    mn[i] += 9;
                }
            }
            else
            {
                mn[i] += s;
                s = 0;
            }
        }
        if (s != 0)
            cout << "-1 -1\n";
        else
        {
            for (int i = 0; i < m; i++)
            {
                cout << mn[i];
            }
            cout << " ";
            for (int i = 0; i < m; i++)
            {
                cout << mx[i];
            }
            cout << "\n";
        }
    }

    return 0;
}