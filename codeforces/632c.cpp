#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    #endif
    long long n;
    cin>>n;
    long long a[n];
    long long s,res;
    for(long long i=0;i<n;i++) cin>>a[i];
    vector<pair<long long,long long>>v;
    for(long long i=0;i<n;i++){
        s=0;
        for(long long j=i;j<n;j++){
            s+=a[j];
            if(s==0){
                v.push_back(make_pair(i+1,j+1));
            }
        }
    }
    res=(n*(n+1))/2;
    for(auto &i : v){
        res-=(i.first)*(n-i.second+1);
        //cout<<i.first<<i.second<<'\n'; 
    }
    cout<<res;

    return 0;
}