#include <bits/stdc++.h>

using namespace std;

void solve(string &res)
{
    int x, y;
    cin >> x >> y;
    int fx{}, fy{};
    if (x < 0)
    {
        fx = 1;
        x = -1 * x;
    }
    if (y < 0)
    {
        y = -1 * y;
        fy = 1;
    }
    int cnt{};
    while (x > 0 || y > 0)
    {
        cnt++;
        if (x == 0 && y == 1)
        {
            y = 0;
            res += (fy) ? "S" : "N";
            break;
        }
        else if (y == 0 && x == 1)
        {
            x=0;
            res += (fx) ? "W" : "E";
            break;
        }
        int lx, ly;
        lx = x & 1;
        ly = y & 1;
        x = x / 2;
        y = y / 2;
        if (lx ^ ly == 0)
        {
            res = "IMPOSSIBLE";
            return;
        }
        else if (lx == 1)
        {
            int lly = y & 1;
            int llx = x & 1;
            if (llx ^ lly == 0)
            {
                x = x + 1;
                res += (fx) ? "E" : "W";
            }
            else
            {
                res += (fx) ? "W" : "E";
            }
        }
        else if (ly == 1)
        {
            int llx = x & 1;
            int lly = y & 1;
            if (llx ^ lly == 0)
            {
                y = y + 1;
                res += (fy) ? "N" : "S";
            }
            else
            {
                res += (fy) ? "S" : "N";
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("../a.in", "r", stdin);
    freopen("../a.out", "w", stdout);
#endif
    int t{};
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        string res{};
        solve(res);
        cout << "Case #" << i << ": " << res << " \n";
    }
    return 0;
}