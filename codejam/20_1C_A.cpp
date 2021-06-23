#include <bits/stdc++.h>

using namespace std;

void solve(int &res)
{
    int x, y, nx, ny;
    string s;
    cin >> x >> y >> s;
    map<int, int> m;
    m['N'] = 1;
    m['S'] = -1;
    m['E'] = 1;
    m['W'] = -1;
    int dis{};
    nx = x;
    ny = y;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'N' || s[i] == 'S')
            ny += m[s[i]];
        else if (s[i] == 'E' || s[i] == 'W')
            nx += m[s[i]];
        dis = abs(nx) + abs(ny);
        //cout<<dis<<"\n";
        if (dis <= i + 1)
        {
            res = i + 1;
            return;
        }
    }
    res = -1;
    return;
}

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
    for (int i = 1; i <= t; i++)
    {
        int res{};
        solve(res);
        if (res == -1)
            cout << "Case #" << i << ": "
                 << " IMPOSSIBLE\n";
        else
            cout << "Case #" << i << ": " << res << " \n";
    }
    return 0;
}