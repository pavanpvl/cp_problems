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
    int t{};
    cin>>t;
    while(t--){
        int g;
        cin>>g;
        for(int d=0;d<g;d++){
            int i,n,q;
            cin>>i>>n>>q;
            //i=1 H i=2 T for q same
            int num_h{},num_t{};
            if(i==1){
                num_h=n/2;
                num_t=(n&1) ? (n/2)+1:n/2;
            }
            else if(i==2){
                num_t=n/2;
                num_h=(n&1) ? (n/2)+1:n/2;
            }
            if(q==1) cout<<num_h<<'\n';
            else if(q==2) cout<<num_t<<'\n';
            else cout<<"error\n";

        }
    }
    return 0;
}