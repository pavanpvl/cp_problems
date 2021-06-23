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
        int n;
        cin>>n;
        string s{},res{};
        cin>>s;
        for(int i=0;i<2*n-1;i+=2)
        {
            res+=s[i];
        }
        cout<<res<<"\n";
    }


    return 0;
}