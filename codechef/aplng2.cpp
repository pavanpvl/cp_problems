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
        int n,flag=0,k,cnt;
        cin>>n;
        vector<int> v;
        v.assign(n,0);
        for(int i=0;i<n;i++) cin>>v[i];
        cnt=6;
        for(int i=0;i<n;i++){
            if(v[i] && cnt<6){
                flag=1;
                break;
            }
            else if(v[i]) cnt=1;
            else cnt++; 
        }
        if (flag) cout<<"NO"<<'\n';
        else cout<<"YES\n";
    }
    return 0;
}