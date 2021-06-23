#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("../a.in","r",stdin);
    freopen("../a.out","w",stdout);
    #endif
    int t{};
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        n=n-2;
        if(n<1) cout<<0<<'\n';
        else if(n&1) cout<< (n+1)/2<<'\n';
        else cout<<(n/2)<<'\n';
    }
    return 0;
}