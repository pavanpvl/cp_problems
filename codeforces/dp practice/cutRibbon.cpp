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
    int n, a, b, c,m3;
    cin >> n >> a >> b >> c;
    int mp[n+1];
    memset(mp, -1, sizeof(mp));
    m3=min(a,b);
    m3=min(m3,c);
    mp[0]=0;
    for (int i = m3; i <= n; i++)
    {
        int mpa,mpb,mpc;
        mpa=(i<a)?-1:mp[i-a];
        mpb=(i<b)?-1:mp[i-b];
        mpc=(i<c)?-1:mp[i-c];
        mpa=max(mpa,mpb);
        mpa=max(mpa,mpc);
        if(mpa<0) mp[i]=-1;
        else mp[i]=1+mpa;
    }
    cout<<mp[n]<<"\n";

    return 0;
}