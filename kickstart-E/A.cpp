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

    for(int q=1;q<=t;q++)
    {
        int n,ml,cl,cnum;
        cin>>n;
        int a[n];
        int b[n-1];
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n-1;i++) b[i]=a[i+1]-a[i];
        cnum=b[0];
        ml=1;
        cl=1;
        for(int i=1;i<n-1;i++)
        {
            if(cnum==b[i]) cl++;
            else cl=1;
            ml=max(ml,cl);   
            cnum=b[i];
        }
        cout<<"Case #"<<q<<": "<<ml+1<<"\n";
    }


    return 0;
}