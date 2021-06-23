#include<iostream>
#define DEBUG
using namespace std;

int g[50][50];
int n,m;
bool vis[50][50];

bool dfs(int i,int j,int *lvl)
{
    if(i<0||j<0||i>=n||j>=m) return false;
    vis[i][j]=true;
    if(g[i][j]==3) return true;
    bool ans=false;
    if( j-1>=0 && (g[i][j-1]==1||g[i][j-1]==3)&& !vis[i][j-1]) ans=ans||dfs(i,j-1,lvl);
    if( j+1<m && (g[i][j+1]==1||g[i][j+1]==3)&& !vis[i][j+1]) ans=ans||dfs(i,j+1,lvl);
    if(ans) return true;
    for(int h=1;h<=*lvl;h++)
    {
        if(i-h>=0 && (g[i-h][j]==1||g[i-h][j]==3)&& !vis[i-h][j]) ans=ans||dfs(i-h,j,lvl);
        if (ans) return ans;
        if(i+h<n && (g[i+h][j]==1||g[i+h][j]==3)&& !vis[i+h][j]) ans=ans||dfs(i+h,j,lvl);
        if (ans) return ans;
    }
    return false;

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("/home/pavan/cp_problems/a.in","r",stdin);
    freopen("/home/pavan/cp_problems/a.out","w",stdout);
    #endif
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
        }
    }
    int lvl;
    for(lvl=0;lvl<n;lvl++){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vis[i][j]=false;
            }
        }
        if(dfs(n-1,0,&lvl)) {
            cout<<lvl<<"\n";
            break;
        }
    }
    //cout<<n-1<<"\n";

    return 0;
}