#include <bits/stdc++.h>

using namespace std;

void solve(string &s)
{
    int n;
    vector<string> c;
    cin >> n;
    map<char, char> opp;
    opp['R'] = 'P';
    opp['P'] = 'S';
    opp['S'] = 'R';
    c.assign(n, "0");
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    int pos{}, t{};
    while (c.size() )
    {
        t++;
        map<char, int> rps;
        for (auto i = c.begin(); i != c.end(); i++)
        {
            int sz = i->size();
            sz = pos % sz;
            rps[(*i)[sz]] = 1;
        }
        if (rps.size() == 3)
        {
            s = "IMPOSSIBLE";
            return;
        }
        else if (rps.size() == 1)
        {
            auto pr = rps.begin();
            s += opp[pr->first];
            return;
        }
        else
        {
            auto pr = rps.begin();
            char a, b, d, o;
            a = pr->first;
            pr++;
            b = pr->first;
            d = (b == opp[a]) ? b : a;
            o = (b == opp[a]) ? a : b;
            s += d;
            for (auto i = c.begin(); i != c.end(); i++)
            {
                int sz = i->size();
                sz = pos % sz;
                if ((*i)[sz] == o)
                {
                    i = c.erase(i);
                    i--;
                }
            }
            //cout<<c.size()<<" csize\n";
        }
        pos++;
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
        string s{};
        solve(s);
        if(s.length()>500) cout << "Case #" << i << ": " << "IMPOSSIBLE" << " \n";
        else cout << "Case #" << i << ": " << s << " \n";
    }
    return 0;
}