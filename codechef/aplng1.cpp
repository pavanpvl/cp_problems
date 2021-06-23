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
        int n,k;
        vector <int> s;
        long long res,m=1000000007;
        cin>>n;
        //cout<<' '<<n<<'\n';
        s.assign(n,0);
        for(int i=0;i<n;i++){
            cin>>s[i];
        }
        res=0;
        sort(s.begin(),s.end(),greater<int>());
        for(int i=0;i<n;i++){
            k=(s[i]-i);
            //cout<<k<<i<<'\n';
            if(k<=0) break;
            res=(res+k)%m;
        }
        cout<<res<<'\n';
    }
    return 0;
}