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
        int a[n],p[n];
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>p[i];
        vector<int> v;
        for(int i=0;i<n;i++){
            if(p[i]==0) v.push_back(a[i]);
        }
        sort(v.begin(),v.end(),greater<int>());
        int k=0;
        for(int i=0;i<n;i++){
            if(p[i]==0){ 
                cout<<v[k++]<<" ";
            }
            else cout<<a[i]<<" ";   
        }
        cout<<"\n";

    }


    return 0;
}