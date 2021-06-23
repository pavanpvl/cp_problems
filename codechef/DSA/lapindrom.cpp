#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("../../a.in", "r", stdin);
    freopen("../../a.out", "w", stdout);
#endif
    int t{};
    cin >> t;
    //cout<<1;
    while (t--)
    {
        string s;
        cin>>s;
        map<char,int> a,b;
        int n=s.size();
        int j1;
        if(n&1) j1=(n/2)+1;
        else j1=n/2;
        for(int i=0;i<n/2;i++,j1++){
            a[s[i]]+=1;
            b[s[j1]]+=1;
        }
        auto j=b.begin();
        int flag{};
        for(auto i=a.begin();i!=a.end();i++,j++){

           // cout<<i->second<<j->second<<i->first<<j->first<<'\n'; 
            if(i->second!=j->second||i->first!=j->first ){
                flag=1;
            }
        }
        if(flag) cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}