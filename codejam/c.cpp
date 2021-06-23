#include<bits/stdc++.h>

using namespace std;

bool comp(const pair<int,pair<int,int> > &a,const pair<int,pair<int,int> > &b ){
    return a.second.first < b.second.first ;
} 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    #endif
    int t,ts=1;
    cin>>t;
    while(t--){
        int n,c,y,tc,ty,T,flag=0,a,b;
        cin>>n;
        string s(n,'0');
        vector< pair<int,pair<int,int> > > v;
        for(int i=0;i<n;i++){
            cin>>a>>b;
            v.push_back(make_pair(i,make_pair(a,b)));
        }
        sort(v.begin(),v.end(),comp);
        c=0;
        y=0;
        tc=-1;
        ty=-1;
        for(int i=0;i<n;i++){
            T=v[i].second.first;
            if(T>=tc){
            tc=-1;
            c=0;
            }
            if(T>=ty){
            ty=-1;
            y=0;
            }
            if(c==0){
                c=1;
                s[v[i].first]='C';
                tc=v[i].second.second;
            }
            else if(y==0){
                y=1;
                s[v[i].first]='J';
                ty=v[i].second.second;
            }
            else{
                flag=1;
                break;
            }
        }
        if(flag) cout<<"Case #"<<ts<<": IMPOSSIBLE"<<'\n';
        else cout<<"Case #"<<ts<<": "<<s<<"\n"; 
        ts++;
    }
    return 0;
}