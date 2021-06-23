#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("../../a.in","r",stdin);
    freopen("../../a.out","w",stdout);
    #endif
    int n{};
    cin>>n;
    vector<long long> v(n,0LL);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    long long temp{},ml{LONG_LONG_MIN};
    for(int i=0;i<n;i++){
        if(i!=0&&v[i]==v[i-1]) continue;
        temp=v[i]*(n-i);
        ml=max(temp,ml);
    }
    cout<<ml<<'\n';
    return 0;
}