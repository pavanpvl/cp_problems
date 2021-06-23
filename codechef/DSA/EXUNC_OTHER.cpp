#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("/home/pavan/cp_problems/a.in", "r", stdin);
    freopen("/home/pavan/cp_problems/a.out", "w", stdout);
#endif
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    set<int> s;
    cin >> v[1];
    s.insert(1);
    for (int i = 2; i <= n; i++)
    {
        cin >> v[i];
        if (v[i] % v[i - 1] != 0)
            s.insert(i);
    }
    /*for(auto j=s.begin();j!=s.end();j++)
		cout<<*j<<" ";K
	cout<<"\n";*/
    for (int i = 0; i < q; i++)
    {
        int no;
        cin >> no;
        if (no == 1)
        {
            int x, y;
            cin >> x >> y;
            s.insert(x);
            s.insert(x + 1);
            if (x != 1 && y % v[x - 1] == 0)
                s.erase(x);
            if (x != n && v[x + 1] % y == 0)
                s.erase(x + 1);
            v[x] = y;
            /*for(auto j=s.begin();j!=s.end();j++)
				cout<<*j<<" ";
			cout<<"\n";*/
        }
        else if (no == 2)
        {
            int x;
            cin >> x;
            auto it = s.upper_bound(x);
            int ans;
            if ((*it) == x)
                ans = x;
            else
                ans = *(--it);
            cout << ans << "\n";
        }
    }
    return 0;
}