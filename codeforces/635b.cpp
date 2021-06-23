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
        int x,n,m;
        cin>>x>>n>>m;
        while(((x+1)/2)>10&&n>0){
            x=(x/2)+10;
            n--;
        }
        if(x>10*m) cout<<"NO\n";
        else cout<<"YES\n";
    }   
    return 0;
}