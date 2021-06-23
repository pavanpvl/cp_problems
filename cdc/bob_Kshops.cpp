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
    int n,s;
    cin>>n>>s;
    int dp[s+1][n+1];
    for(int i=0;i<s+1;i++){
        for(int j=0;j<n+1;j++){
            if(j==0) dp[i][j]=0;
            else  dp[i][j]=INT_MAX/4;
        }
    }
    int c[s+1],d[s+1],q[s+1];
    for(int i=1;i<=s;i++){
        cin>>q[i]>>c[i]>>d[i];
    }
    int mn=INT_MAX,tmp;;
    for(int i=1;i<s+1;i++){
        for(int j=1;j<n+1;j++){
            mn=INT_MAX;
            for(int k=0;k<=j&&k<=q[i];k++){
                tmp=dp[i-1][j-k]+k*c[i];
                if(k>0) tmp+=d[i];
                if(mn>tmp) mn=tmp;
            }
            dp[i][j]=mn;
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }


    cout<<dp[s][n]<<"\n";
    return 0;
}