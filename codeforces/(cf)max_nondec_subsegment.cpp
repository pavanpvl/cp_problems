#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    #endif
    int n,res,c;
    vector <int> v;
    cin>>n;
    v.assign(n,0);
    for(int i=0;i<n;i++) cin>>v[i];
    res=1;
    c=1;
    for(int i=1;i<n;i++){
        if(v[i]>=v[i-1]) c++;
        else c=1;
        res=max(res,c);
    }
    cout<<res;
    return 0;
}