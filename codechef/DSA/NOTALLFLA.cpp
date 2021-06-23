#include <bits/stdc++.h>
#define DEBUG
using namespace std;

void solve(int &res)
{
    res=0;
    int n,k;
    cin>>n>>k;
    vector<int> v(n,0);
    vector<int>f(k+1,0);
    int ndis{0};
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int mx{INT_MIN};
    for(int i=0,j=0;j<n&&i<n;){
        while(j<n&&((ndis<k-1)||(f[v[j]]>0))){
            //cout<<f[v[j]]<<" "<<ndis<<" "<<j<<"\n";
            if(f[v[j]]==0) ndis++;
            f[v[j]]+=1;
            j++;
        }
        res=max(res,j-i);
        //cout<<res<<" "<<i<<" "<<j<<" "<<f[v[i]]<<" "<<ndis<<"\n";
        //if(j==n) break;
        f[v[i]]-=1;
        if(f[v[i]]==0) ndis--;
        i++;
    }
}
 
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
    while (t--)
    {
        int res{};
        solve(res);
        cout << res << '\n';
    }
    return 0;
}

