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

    int t{};
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        map<char, int> d;
        d['N'] = 1;
        d['S'] = -1;
        d['E'] = 1;
        d['W'] = -1;
        set<pair<pair<int, int>, pair<int, int>>> mp;
        int x{}, y{}, res{};
        int px{}, py{};
        for (int i = 0; i < s.length(); i++)
        {
            px = x;
            py = y;
            int nx{x}, ny{y};
            if (s[i] == 'N' || s[i] == 'S')
            {
                y += d[s[i]];
                ny = max(py, y);
                py = min(py, y);
            }
            else
            {
                x += d[s[i]];
                nx = max(px, x);
                px = min(px, x);
            }
            if (mp.find({{px, py}, {nx, ny}}) != mp.end())
                res += 1;
            else
            {
                mp.insert({{px, py}, {nx, ny}});
                res += 5;
            }
        }
        cout << res << "\n";
    }

    return 0;
}