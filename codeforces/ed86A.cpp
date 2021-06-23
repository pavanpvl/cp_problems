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
        long long x,y,res,a,b;
        cin>>x>>y;
        cin>>a>>b;
        long long  mn=min(x,y);
        long long  mx=max(x,y);
        res=min((x+y)*a,mn*b+(mx-mn)*a);
        cout<<res<<"\n";
    }


    return 0;
}