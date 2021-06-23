#include <bits/stdc++.h>

#define DEBUG

// Header files, namespaces,
// macros as defined above
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<pair<int, int>, null_type, less_equal<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
int f[1000000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("/home/pavan/cp_problems/a.in", "r", stdin);
    freopen("/home/pavan/cp_problems/a.out", "w", stdout);
#endif

    int n, k;
    cin >> n >> k;
    ordered_set s;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        s.insert({a, f[a]});
        f[a]++;
    }
    memset(f, 0, sizeof(f));
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        if (x > 0)
        {
            s.insert({x, f[x]});
            f[x]++;
        }
        else
        {
            int a = abs(x);
            auto it = s.find_by_order(a-1);
            //cout<<it->first<<" "<<it->second<<"\n";
            f[it->first]--;
            if (it != s.end())
                s.erase(it);
        }
    }
    if (s.empty())
        cout << 0 << "\n";
    else
    {
        auto it = s.find_by_order(0);
        cout<< it->first <<"\n";
    }

    return 0;
}