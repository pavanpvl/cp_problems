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
    while(t--)
    {
        int n,i;
        int a{},b{},x{},y{};
        string s;
        cin>>n>>s;
        x=n;
        y=n;
        for(i=0;i<2*n;i++){
            if(a>b+y || b>a+x){
                cout<<i<<'\n';
                break;
            }
            if(i&1) {
                a+=(s[i]=='1')?1:0;
                x--;
            }
            else{
                b+=(s[i]=='1')?1:0;
                y--;
            }
        }
        if(i==2*n) cout<<i<<'\n';
    }
    return 0;
}