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
        long long k;
        cin>>n;
        cin>>k;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        int min,max;
        min=a[0];
        max=a[0];
        for(int i=1;i<n;i++)
        {
            if(min>a[i]) min=a[i];
            if(max<a[i]) max=a[i];
        }
        for(int i=0;i<n;i++){
            if(k&1) cout<<max-a[i]<<" ";
            else cout<<a[i]-min<<" ";
        }
        cout<<"\n";
    }


    return 0;
}