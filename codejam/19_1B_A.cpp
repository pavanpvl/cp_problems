#include <bits/stdc++.h>

using namespace std;

int mincord(vector<int> &z, vector<int> &d)
{
    int res{}, mx{};
    map<int, int> p;
    p[0] = 0;
    for (int i = 0; i < z.size(); i++)
    {
        if (d[i] == 0)
        {
            p[z[i] + 1] = 0;
        }
    }
    for (int i = 0; i < z.size(); i++)
    {
        for (auto j=p.begin();j!=p.end();j++)
        {
            if ((d[i] == 0 && j->first > z[i]) || (d[i] == 1 && j->first < z[i]))
                j->second+=1;
        }
    }
    for (auto j = p.begin(); j != p.end(); j++)
    {
        int temp{};
        temp = max(mx, j->second);
        res = (mx >= j->second) ? res : j->first;
        mx=temp;
    }
    return res;
}

void solve(int &x, int &y)
{
    int np, q;
    cin >> np >> q;
    vector<int> X, Y, DX, DY;
    int a, b;
    char d;
    for (int i = 0; i < np; i++)
    {
        // N=0,S=1,E=2,W=3
        cin >> a >> b >> d;
        if (d == 'N' || d == 'S')
        {
            int temp;
            temp = (d == 'N') ? 0 : 1;
            DY.push_back(temp);
            Y.push_back(b);
        }
        else
        {
            int temp;
            temp = (d == 'E') ? 0 : 1;
            DX.push_back(temp);
            X.push_back(a);
        }
    }
    x = mincord(X, DX);
    y = mincord(Y, DY);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("../a.in", "r", stdin);
    freopen("../a.out", "w", stdout);
#endif
    int t{};
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int x, y;
        solve(x, y);
        cout << "Case #" << i << ": " << x << " " << y << " \n";
    }
    return 0;
}