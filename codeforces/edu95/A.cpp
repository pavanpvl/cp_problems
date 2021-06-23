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
        long long x,y,k,n;
        cin>>x>>y>>k;
        n=(k+k*y-1)/(x-1);
        if((k+k*y-1)%(x-1)!=0) n++;
        cout<<k+n<<"\n";
    }


    return 0;
}