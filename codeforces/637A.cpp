#include<bits/stdc++.h>

#define DEBUG

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("/home/pavan/cp_problems/a.in","r",stdin);
    freopen("/home/pavan/cp_problems/a.out","w",stdout);
    #endif

    int t{};
    cin>>t;

    while(t--)
    {
        int n,a,b,c,d;
        cin>>n>>a>>b>>c>>d;
        int r;
        r=n*(a+b);
        if(r>=c-d&&((n*(a-b))<=(c+d))) cout<<"YES\n";
        else cout<<"NO\n";
    }


    return 0;
}