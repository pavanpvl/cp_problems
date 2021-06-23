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

    string s;
    cin >> s;
    char mx{'a'};
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] > mx)
            mx = s[i];
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (mx == s[i])
            cout << mx;
    }
    cout << "\n";

    return 0;
}