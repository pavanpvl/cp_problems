#include <iostream>
using namespace std;

int g[50][50];
int n, m;
bool vis[50][50];
int Gup[8] = {0, 1, 1, 0, 1, 0, 0, 1};
int Gdown[8] = {0, 1, 1, 0, 0, 1, 1, 0};
int Gleft[8] = {0, 1, 0, 1, 0, 0, 1, 1};
int Gright[8] = {0, 1, 0, 1, 1, 1, 0, 0};

void dfs(int x, int y, int l)
{
    if (x < 0 || y < 0 || x >= n || y >= m || l == 0)
        return;
    vis[x][y] = true;
    if (x - 1 >= 0 && Gup[g[x][y]] && Gdown[g[x - 1][y]])
        dfs(x - 1, y, l - 1);
    if (x + 1 < n && Gdown[g[x][y]] && Gup[g[x + 1][y]])
        dfs(x + 1, y, l - 1);
    if (y - 1 >= 0 && Gleft[g[x][y]] && Gright[g[x][y - 1]])
        dfs(x, y - 1, l - 1);
    if (y + 1 < m && Gright[g[x][y]] && Gleft[g[x][y + 1]])
        dfs(x, y + 1, l - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/pavan/cp_problems/a.in", "r", stdin);
    freopen("/home/pavan/cp_problems/a.out", "w", stdout);
#endif
    int t, x, y, l, cnt;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n >> m >> x >> y >> l;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> g[i][j];
                vis[i][j] = false;
            }
        }
        dfs(x, y, l);
        cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j]){
                    cnt++;
                    //cout<<1<<" ";
                }
                //else cout<<"0 ";
            }
            //cout<<"\n";
        }
        cout << cnt << "\n";
    }
}