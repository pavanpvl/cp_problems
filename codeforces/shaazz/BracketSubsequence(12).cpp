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
    int n, k;
    cin >> n >> k;
    int lr, ll;
    lr = (n - k) / 2;
    ll = lr;
    string s{}, res{};
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            if (lr > 0)
                lr--;
            else
                res.push_back(s[i]);
        }
        else
        {
            if (ll > 0)
                ll--;
            else
                res.push_back(s[i]);
        }
    }
    cout<<res<<"\n";
    return 0;
}