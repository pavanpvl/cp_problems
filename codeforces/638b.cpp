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
        int n,k,d{};
        cin>>n>>k;
        int a[n];
        vector<int> dis;
        vector<int> cnt(n+1,0);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            if(cnt[a[i]]==0){
                d++;
                dis.push_back(a[i]);
            }
            cnt[a[i]]+=1;
        }
        if(d>k) cout<<"-1\n";
        else {
            cout<<n*k<<"\n";
            for(int i=0;i<n;i++){
                for(int j=0;j<k;j++){
                    cout<<dis[j%d]<<" ";
                }
            }
            cout<<"\n";
        }
    }


    return 0;
}