#include<bits/stdc++.h>

using namespace std;
int maxpairs(vector<int> &a,vector<int> &b,vector<vector<int>> &d,int i,int j){
    if(d[i][j]!=-1) return d[i][j];
    if(i==(int)a.size()-1)
    {
        //cout<<'\n'<<i<<' '<<j<<'\n';
        for(;j<(int)b.size();j++){
            if(abs(a[i]-b[j]) <=1) { 
                return 1;
            }
        }
        return 0;
    }
    else if(j==(int)b.size()-1)
    {
        //cout<<'\n'<<i<<' '<<j<<'\n';
        for(;i<(int)a.size();i++){
            if( abs(a[i]-b[j]) <=1 ) { 
                return 1;
            }
        }
        return 0;
    }
    else 
    {
        int pij,eqij;
        eqij= (abs(a[i]-b[j]) <= 1)? 1:0;
        if(d[i+1][j]==-1) d[i+1][j]=maxpairs(a,b,d,i+1,j);
        if(d[i][j+1]==-1) d[i][j+1]=maxpairs(a,b,d,i,j+1);
        if(d[i+1][j+1]==-1) d[i+1][j+1]=maxpairs(a,b,d,i+1,j+1);    
        pij=max( d[i+1][j] , d[i][j+1] );
        d[i][j]=max( d[i+1][j+1]+eqij, pij );
        //cout<<'\n'<<i<<' '<<j<<' '<<d[i][j]<<'\n';
        return d[i][j];
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    vector<int> a,b;
    cin>>n;
    a.assign(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>m;
    vector< vector<int> > d (n,vector<int>(m,-1));
    b.assign(m,0);
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    cout<<maxpairs(a,b,d,0,0)<<'\n';
    //cout<<d[0][0]<<'/n';

    return 0;
}