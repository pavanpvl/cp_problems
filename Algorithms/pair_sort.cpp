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
    int n,a,b;
    cin>>n;
    vector<pair<int,int> > v;
    for(int i=0;i<n;i++){ 
        cin>>a>>b;
        v.push_back({a,b});
    } 
    sort(v.begin(),v.end(),less<pair<int,int> >());
    for(int i=0;i<n;i++){
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    }
    return 0;
}