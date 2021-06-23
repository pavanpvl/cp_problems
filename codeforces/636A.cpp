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
        int n,res{};
        cin>>n;
        int x=4;
        for(;x<=n+1;x=x*2){
            int y=x-1;
            if(n%y==0) res=n/y;  
        }
        cout<<res<<'\n'; 
    }
    return 0;
}