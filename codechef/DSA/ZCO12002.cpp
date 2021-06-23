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

    int n{}, x, y;
    cin >> n >> x >> y;
    vector<pair<int,int>>c(n);
    vector<int> v(x,0),w(y,0);
    for (int i = 0; i < n; i++)
    {
        cin>>c[i].first>>c[i].second;
    }
    for(int i=0;i<x;i++) cin>>v[i];
    for(int i=0;i<y;i++) cin>>w[i];
    sort(v.begin(),v.end());
    sort(w.begin(),w.end());
    int clen,mlen{INT_MAX};
    for(int i=0;i<n;i++){
        auto en=lower_bound(w.begin(),w.end(),c[i].second);
        auto st=upper_bound(v.begin(),v.end(),c[i].first);
        if(en==w.end()||st==v.begin()) continue;
        st--;
        clen=(*en)-(*st)+1;
        mlen=min(mlen,clen); 
    }
    cout<<mlen<<"\n";
    return 0;
}