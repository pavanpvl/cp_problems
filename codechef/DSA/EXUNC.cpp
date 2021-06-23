#include <bits/stdc++.h>

#define DEBUG

using namespace std;
void solve(int id, vector<int> &v, map<int, int> &m, map<int, int> &pos, int &ns)
{
    int x, y, st;
    cin >> x;
    y = v[id];
    v[id] = x;
    int n = v.size()-1;
    if (n == 1)
        return;
    if (id == 1)
    {
        if (v[2] % x==0)
        {
            pos[m[2]]=1;
            m[1]=m[2];
        }
        else
        {
            pos[m[2]] = 2;
            ns++;
            m[id] = ns;
            pos[ns] = id;
        }
        return;
    }
    if (id == n)
    {
        if (x % v[n - 1]==0)
        {
            m[n] = m[n - 1];
        }
        else
        {
            ns++;
            m[id] = ns;
            pos[ns] = id;
        }
        return;
    }
    if (x % v[id - 1]==0 && v[id + 1] % x==0)
    {
        m[id] = m[id - 1];
        pos[m[id + 1]] = pos[m[id - 1]];
    }
    else if (x % v[id - 1]==0)
    {
        m[id] = m[id - 1];
        pos[m[id + 1]] = id + 1;
    }
    else if (v[id + 1] % x==0)
    {
        m[id] = m[id + 1];
        pos[m[id]] = id;
    }
    else
    {
        ns++;
        m[id] = ns;
        pos[ns] = id;
        pos[m[id + 1]] = id + 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("/home/pavan/cp_problems/a.in", "r", stdin);
    freopen("/home/pavan/cp_problems/a.out", "w", stdout);
#endif

    int n, nq, ns{};
    cin >> n >> nq;
    vector<int> v(n + 1, 0);
    map<int, int> m;
    map<int, int> pos;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    m[1] = 0;
    pos[0] = 1;
    for (int i = 2; i <= n; i++)
    {
        int t;
        t = v[i-1];
        if (v[i] % t==0)
        {
            m[i] = m[i - 1];
        }
        else
        {
            ns++;
            m[i] = ns;
            pos[ns] = i;
        }
    }
    
    for (int j = 0; j < nq; j++)
    {
        int q, id;
        cin >> q >> id;
        if (q == 1)
        {
            solve(id, v, m, pos, ns);
        }
        else
        {
            cout << pos[m[id]] << "\n";
        }
    }

    return 0;
}