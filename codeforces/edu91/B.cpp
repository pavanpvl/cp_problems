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
        int cr{}, cp{}, cs{};
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'R')
                cr++;
            else if (s[i] == 'P')
                cp++;
            else
                cs++;
        }
        if (cp >= cr && cp >= cs)
        {
            for (int i = 0; i < s.length(); i++)
                cout << "S";
        }
        else if (cr >= cp && cr >= cs)
        {
            for (int i = 0; i < s.length(); i++)
                cout << "P";
        }
        else
        {
            for(int i=0;i<s.length();i++) cout<<"R";
        }
        cout<<"\n";
    }

    return 0;
}