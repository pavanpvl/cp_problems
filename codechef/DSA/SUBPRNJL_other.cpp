#include <iostream>
#include <bits/stdc++.h>
typedef int ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
// using PBDS
typedef tree<pair<ll, ll>, null_type, less_equal<pair<ll, ll>>, rb_tree_tag,
             tree_order_statistics_node_update>
    new_data_set;

ll M[2002];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/pavan/cp_problems/a.in", "r", stdin);
    freopen("/home/pavan/cp_problems/a.out", "w", stdout);
#endif
    int t;
    scanf("%d\n", &t);
    while (t--)
    {
        ll n, k;
        scanf("%d %d\n", &n, &k);
        ll arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &arr[i]);
        }
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            new_data_set s;
            memset(M, 0, sizeof(M));
            for (int j = i; j < n; j++)
            {
                //insert elements in s
                s.insert({arr[j], M[arr[j]]++});
                ll l = j - i + 1;
                ll m = (k + l - 1) / l;
                ll K = (k + m - 1) / m;
                cout<<arr[j]<<" "<<M[arr[j]]<<"\n";
                //cout<<l<<" "<<m<<" "<<K<<"\n";
                // find kth smallest element;
                auto it = s.find_by_order(K - 1);
                ll x = it->first;
                ll f = M[x];
                if (M[f] != 0)
                {
                    //cout<<i<<" "<<j<<"\n";
                    ans++;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
