#include <bits/stdc++.h>

#define DEBUG

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>    
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree < pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("/home/pavan/cp_problems/a.in", "r", stdin);
    freopen("/home/pavan/cp_problems/a.out", "w", stdout);
#endif

    int n{}, a{};
    long long res{};
    cin >> n;
    ordered_set v;
    cin >> a;
    v.insert({a,0});
    for (int i = 1; i < n; i++)
    {
        cin >> a;
        auto it = v.upper_bound({a,i});
        if (it != v.end())
        {
            res+=v.size()-v.order_of_key(*it);
        }
        v.insert({a,i});
    }
    cout << res << "\n";
    return 0;
}