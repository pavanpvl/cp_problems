#include <bits/stdc++.h>

#define DEBUG

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("/home/pavan/cp_problems/a.in", "r", stdin);
    freopen("/home/pavan/cp_problems/a.out", "w", stdout);
#endif

    int n{}, nq{};
    cin >> n >> nq;
    vector<int> v(n + 1, 0);
    set<int> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    s.insert(1);
    for (int i = 2; i < n; i++)
    {
        if (v[i] % v[i - 1] != 0)
            s.insert(i);
    }
    for (int i = 0; i < nq; i++)
    {
        int q, id;
        cin >> q >> id;
        if (q == 1)
        {
            int x;
            cin >> x;
            //v[x]=p;
            v[id] = x;
            if (n == 1)
                continue;
            if (id == 1)
            {
                if(v[2] % v[1]!=0) s.insert(2);
                else if(s.count(2)) s.erase(2);
            }
            else if (id == n)
            {
                if(v[n] % v[n - 1]!=0) s.insert(n);
                else if(s.count(n)) s.erase(n);
            }
            else
            {
                s.insert(id);
                s.insert(id + 1);
                if (v[id] % v[id - 1] != 0);    
                else if (s.count(id))
                    s.erase(id);
                if (v[id + 1] % v[id] != 0);
                else if (s.count(id + 1))
                    s.erase(id + 1);
            } 
           /*  s.insert(x);
            s.insert(x + 1);
            if (x != 1 && v[x] % v[x - 1] == 0)
                s.erase(x);
            if (x != n && v[x + 1] % v[x] == 0)
                s.erase(x + 1); */
        }
        else
        {
            auto it=s.upper_bound(id);
            it--;
            cout<<*it<<"\n";
        }
    }

    return 0;
}