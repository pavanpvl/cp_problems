#include<bits/stdc++.h>

#define DEBUG

using namespace std;

int min(int a,int b)
{
    return a<b?a:b;
}

void constgraph(vector<int> g[],vector<string> &v )
{
    for(int i=0;i<v.size()-1;i++)
    {
        for(int j=0;j<min(v[i].length(),v[i+1].length());j++){
            if(v[i][j]!=v[i+1][j]){
                g[v[i][j]-'a'].push_back(v[i+1][j]-'a');
                break;
            }             
        }
    }
}
void printlist(vector<int> g[],int k)
{
    for(int i=0;i<k;i++){
        cout<<(char)('a'+i)<<"---";
        for(int j=0;j<g[i].size();j++){
            cout<<(char)('a'+g[i][j])<<",";
        }
        cout<<"\n";
    }
}
void dfs(vector<int> g[],int i,stack<int> &st,bool *vis)
{
    vis[i]=true;
    for(auto j=g[i].begin();j!=g[i].end();j++){
        if(!vis[*j]){
            dfs(g,*j,st,vis);
        }
    }
    st.push(i);
}


void topolsort(vector<int> g[],int k)
{
    bool vis[k];
    stack<int> st;
    for(int i=0;i<k;i++){
        vis[i]=false;
    }
    for(int i=0;i<k;i++){
        if(!vis[i]){
            dfs(g,i,st,vis);
        }
    }
    while(!st.empty())
    {
        char s='a'+st.top();
        cout<<s<<" ";
        st.pop();
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
    int n,k;
    cin>>n>>k;
    string s;
    vector<string> v;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        v.push_back(s);
    }
    vector<int> g[k];
    constgraph(g,v);
    //printlist(g,k);
    topolsort(g,k);
    return 0;
}