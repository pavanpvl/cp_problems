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

    int q;
    string s;
    cin >> s >> q;
    vector<int> cnt(s.length(),0);
    for (int i = 1; i < s.length(); i++)
    {
        if(s[i]==s[i-1]) cnt[i]=cnt[i-1]+1;
        else cnt[i]=cnt[i-1];
    }
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        cout<<cnt[r]-cnt[l]<<"\n";
    }
    return 0;
}