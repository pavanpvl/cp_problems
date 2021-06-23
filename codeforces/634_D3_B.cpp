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
        int n,a,b;
        cin>>n>>a>>b;
        string res;
        char x{'a'};
        for(int i=0;i<b;i++){
            res+=x;
            x=static_cast<char>(x+1);
        }
        for(int i=b;i<n;i++){
            int j;
            j=i%b;
            res+=res[j];
        }
        cout<<res<<'\n';
    }
    return 0;
}