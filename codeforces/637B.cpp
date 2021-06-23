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
        int n,k;
        cin>>n>>k;
        vector <int>v(n,0);
        vector<int>p(n,0);
        for(int i=0;i<n;i++) cin>>v[i];
        for(int i=1;i<n-1;i++){
            if(v[i]>v[i-1]&&v[i]>v[i+1]) p[i]=1;
        } 
        int cp{},mp{},mpos{0};
        for(int j=1;j<k-1;j++) if(p[j]) cp++; 
        mp=cp;
        for(int i=1;i<=n-k;i++){
            if(p[i]) cp--;
            if(p[i+k-2]) cp++;
            mpos=(cp>mp)?i:mpos;
            mp=max(cp,mp);
        }
        cout<<mp+1<<" "<<mpos+1<<"\n";
    }


    return 0;
}