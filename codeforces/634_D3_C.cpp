#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("../a.in","r",stdin);
    freopen("../a.out","w",stdout);
    #endif
    int t{};
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector <int> v(n,0);
        int temp=1;
        for(int i=0;i<n;i++) cin>>v[i];
        sort(v.begin(),v.end());
        vector<int> cnt;
        vector<int> b;
        int i,mb{INT_MIN};
        if(n==1) mb=0;
        for(i=1;i<n;i++){
            if(v[i]==v[i-1]) temp++;
            else {
                b.push_back(v[i-1]);
                cnt.push_back(temp);
                mb=max(temp,mb);
                temp=1;
            }
        }
        b.push_back(v[i-1]);
        cnt.push_back(temp);
        mb=max(temp,mb);
        /* for(int j=0;j<b.size();j++){
            cout<<b[j]<<' '<<cnt[j]<<"\n";
        }
        cout<<'\n'; */
        if(mb==b.size()) cout<<mb-1<<'\n';
        else{
            mb=min(mb,(int)b.size());
            cout<<mb<<'\n';
        }
    }
    return 0;
}