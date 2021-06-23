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
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        int turn=1,c1=0,c0=0;
        int res{};
        for(int i=0;i<n;i++)
        {
            if(turn==1)
            {
                if(c1==0){
                    res+=a[i];
                    c1++;
                    continue;
                }
                else if(c1==1&&a[i]==1)
                    i--;
                turn =0;
                c1=0;
            }
            else {
                if(c0==0) c0++;
                else
                {
                    if(a[i]==0) i--;
                    turn=1;
                    c0=0;
                }
            }
        }
        cout<<res<<"\n";
    }


    return 0;
}