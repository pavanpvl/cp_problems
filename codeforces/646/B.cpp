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
        int f, d0{}, d1{}, n0{}, n1{}, mn{INT_MAX};
        string s;
        cin >> s;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '0')
                n0++;
            else
                n1++;
        }
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '0')
                d0++;
            else
                d1++;
            mn = min(mn, d0 + n1 - d1);
            mn = min(mn, d1 + n0 - d0);
            cout<<d0<<' '<<d1<<' '<<mn<<"\n";
        }
        cout << mn<<"\n";
    }

    return 0;
}