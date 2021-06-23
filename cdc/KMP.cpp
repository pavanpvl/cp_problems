#include<bits/stdc++.h>

#define DEBUG

using namespace std;

void precompute(int *lps,int m,string p)
{
    int k=0;
    lps[0]=0;
    for(int i=1;i<m;i++){
        while(k>0&&p[k]!=p[i]){
            k=lps[k-1];
        }
        if(p[k]==p[i]) k++;
        lps[i]=k;
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("/home/pavan/cp_problems/a.in","r",stdin);
    freopen("/home/pavan/cp_problems/a.out","w",stdout);
    #endif
    string s,p;
    cin>>s>>p;
    int n,m;
    n=s.length();
    m=p.length();
    int lps[m];
    memset(lps,0,sizeof(lps));
    precompute(lps,m,p);
    for(int i=0;i<m;i++){
        cout<<lps[i]<<" ";
    }
    cout<<"\n";

    int k=0;
    for(int i=0;i<n;i++){
        while(k>0&&s[i]!=p[k]){
            k=lps[k-1];
        }
        if(s[i]==p[k]) k++;
        if(k==m){
            cout<<i-m+1<<"\n";
            k=lps[k-1];
        }
    }




    return 0;
}