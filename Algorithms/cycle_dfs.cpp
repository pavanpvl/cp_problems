#include<iostream>
#define DEBUG
using namespace std;
int g[101][101];

bool dfs(int n,int ind,bool *vis,bool *st,int *cnode,bool *cy)
{
    vis[ind]=true;
    st[ind]=true;
    bool ans;
    for(int i=1;i<=n;i++)
    {
        if(g[ind][i]==1){
            if(!vis[i]){
                ans=dfs(n,i,vis,st,cnode,cy);
                if(ans){
                    if(*cnode!=-1){
                        cy[ind]=true;
                        if(ind==*cnode) *cnode=-1;
                    } 
                    return true;
                }
            }
            else if(st[i]){
                *cnode=i;
                cy[ind]=true;
                return true;
            }
        }
    }
    st[ind]=false;
    return false;
}

void print(bool *st,int n)
{
    for(int i=1;i<=n;i++)
    {
        if(st[i]) cout<<i<<" "; 
    }
    cout<<"\n";
}

bool cycle(int n)
{
    bool *vis=new bool[n+1];
    bool *st=new bool[n+1];
    bool *cy=new bool[n+1];
    for(int i=0;i<=n;i++) {
        vis[i]=false;
        st[i]=false;
        cy[i]=false;
    }
    bool ans;
    int cnode=-1;
    for(int i=1;i<=n;i++)
    {
        ans=false;
        if(!vis[i]) ans=dfs(n,i,vis,st,&cnode,cy);
        if(ans)
        {
            print(cy,n);
            return true;
        }
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
    int n,a,b,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        g[a][b]=1;
    }
    if(!cycle(n)) cout<<0<<"\n";
    return 0;
}