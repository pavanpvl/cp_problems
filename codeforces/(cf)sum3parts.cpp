/*
n^2 worst case
*/
#include<bits/stdc++.h>

using namespace std;

bool compfirst(const pair<int,int>  &a,const pair <int,int> &val){
    return (a.first < val.first);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    #endif

    int n,m;
    long long res=0;
    vector <int> a;
    vector < pair<int,int> > b;
    cin>>n;
    a.assign(n,0);
    b.assign(n,make_pair(0,0));
    for(int i=0;i<n;i++) cin>>a[i];
    b[0].first=a[0];
    for(int i=1;i<n;i++){
         b[i].first += a[i]+b[i-1].first;
         b[i].second = i;
    }
    if(b[n-1].first%3!=0){
        cout<<0;
        return 0;
    }
    m=(b[n-1].first)/3;
    sort(b.begin(),b.end());
    /* for(auto j=b.begin();j!=b.end();j++){
        cout<< j->first << j->second <<'\n';
    }cout<<'\n'; */
    auto low1=lower_bound(b.begin(),b.end(),make_pair(m,INT_MAX),compfirst);
    auto up1=upper_bound(b.begin(),b.end(),make_pair(m,INT_MAX),compfirst);
    auto low2=lower_bound(b.begin(),b.end(),make_pair(2*m,INT_MAX),compfirst);
    auto up2=upper_bound(b.begin(),b.end(),make_pair(2*m,INT_MAX),compfirst);
    for (auto i=low1;i!=up1;i++){
        for(auto j=low2;j!=up2;j++){
                if((i->second < j->second) &&(j->second != n-1)) res++;
        }
    }
    //cout<<'\n';
    cout<<res;
    /*
    cout<<low1->first<<low1->second<<'\n';
    cout<<up1->first<<up1->second<<'\n';
    cout<<low2->first<<low2->second<<'\n';
    cout<<up2->first<<up2->second<<'\n';  */
    return 0;
}