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

    int n{},m{};
    cin>>n>>m;
    vector<pair<int,int>>v(n),y(m);
    for(int i=0;i<n;i++){
        cin>>v[i].first;
        v[i].second=i;
    }
    for(int i=0;i<m;i++){
        cin>>y[i].first;
        y[i].second=i;
    }
    sort(v.begin(),v.end());
    sort(y.begin(),y.end());
    for(int i=0;i<n;i++){
        cout<<v[i].second<<" "<<y[0].second<<"\n";
    }
    for(int i=1;i<m;i++){
        cout<<v[n-1].second<<" "<<y[i].second<<"\n";
    }


    return 0;
}