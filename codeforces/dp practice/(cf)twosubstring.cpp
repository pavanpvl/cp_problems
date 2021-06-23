#include <bits/stdc++.h>

#define DEBUG

using namespace std;

int findp(string &s, int st, int p)
{
    int f{-1};
    if (p == 1)
    {
        for (int i = st; i < s.length() - 1; i++)
        {
            if (s[i] == 'A' && s[i + 1] == 'B')
            {
                f = i + 2;
                return f;
            }
        }
    }
    else
    {
        for (int i = st; i < s.length() - 1; i++)
        {
            if (s[i] == 'B' && s[i + 1] == 'A')
            {
                f = i + 2;
                return f;
            }
        }
    }
    return f;
}

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
    int i, pos{},flag{};
    pos = findp(s, 0, 1);
    if (pos == -1)
    {
        cout << "NO\n";
        return 0;
    }
    else
    {
        pos=findp(s,pos,2);
        if(pos!=-1) flag=1;
    }
    pos = findp(s, 0, 2);
    if (pos == -1 )
    {
        cout << "NO\n";
        return 0;
    }
    else
    {
        pos=findp(s,pos,1);
        if(pos!=-1) flag=1;
    }
    if(flag) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}