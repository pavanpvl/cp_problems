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
        int n,m;
        cin>>n>>m;
        if(n==1) cout<<0<<"\n";
        else if(n==2) cout<<m<<"\n";
        else cout<<2*m<<"\n";
    }


    return 0;
}