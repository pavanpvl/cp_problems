#include <bits/stdc++.h>

#define DEBUG

using namespace std;

int cntneig(int x,int y,const set<pair<int,int>> &pl){
    int res{};
    res=pl.count(make_pair(x+1,y))+pl.count(make_pair(x,y+1))+pl.count(make_pair(x-1,y))+pl.count(make_pair(x,y-1));
    return res;
}

int solve()
{
    int n, m, k, res{};
    cin >> n >> m >> k;
    //vector<pair<int, int>> v(k);
    set<pair<int, int>> pl;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        //v[i] = make_pair(x, y);
        res+=4-(2*cntneig(x,y,pl));
        pl.insert(make_pair(x, y));
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("/home/pavan/cp_problems/a.in", "r", stdin);
    freopen("/home/pavan/cp_problems/a.out", "w", stdout);
#endif

    int t{};
    cin >> t;

    while (t--)
    {
        int res{};
        res = solve();
        cout << res << "\n";
    }

    return 0;
}