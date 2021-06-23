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
        int n = s.length();
        int i{}, j{};
        map<char, int> m;
        int d{}, mx{INT_MAX};
        for (i = 0, j = 0; i < n && j < n;)
        {
            while (d != 3 && j < n)
            {
                if (m[s[j]] == 0)
                    d++;
                m[s[j]]++;
                j++;
            }
            if (d != 3)
                break;
            while (m[s[i]] != 1)
            {
                m[s[i]]--;
                i++;
            }
            //cout<<i<<" "<<j<<"\n";
            mx = min(mx, j - i);
            d--;
            m[s[i]]--;
            i++;
        }
        if (mx == INT_MAX)
            cout << "0\n";
        else
            cout << mx << "\n";
    }

    return 0;
}