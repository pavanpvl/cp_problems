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
    int t;
    cin>>t;
    while(t--){
        int x,k;
        cin>>x>>k;
        if(x==1){
            cout<<0<<'\n';
            continue;
        }
        if(k==1){           
        }
        for(int i=2;i<x;i++){
            if(x%i==0) {
                cout<<1<<'\n';
                break;
            }
        }
        cout<<0<<'\n';
    }
    
    return 0;
}