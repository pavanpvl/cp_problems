#include <bits/stdc++.h>

#define DEBUG

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.first > b.first)
        return 1;
    else if (a.first < b.first)
        return 0;
    else
    {
        if (a.second < b.second)
            return 1;
        else
            return 0;
    }
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

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n, 0);
        set<pair<int, int>, decltype(comp) *> s(comp);
        s.insert({n, 0});
        for (int i = 0; i < n; i++)
        {
            int x, pos;
            auto it = s.begin();
            x = it->first;
            pos = it->second;
            s.erase(it);
            
            if (x & 1)
            {
                v[pos + (x / 2)] = i + 1;
                if ((x / 2) != 0)
                {
                    s.insert({x / 2, pos});
                    s.insert({x / 2, pos + (x / 2) + 1});
                }
            }
            else
            {
                v[pos + (x / 2)-1] = i + 1;
                if ((x / 2) != 1)
                {
                    s.insert({(x / 2) - 1, pos});
                }
                s.insert({x / 2, pos + (x / 2)});
            }
        }
        for (auto i : v)
            cout << i << " ";
        cout << "\n";
    }

    return 0;
}