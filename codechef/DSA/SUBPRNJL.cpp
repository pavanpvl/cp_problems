#include <bits/stdc++.h>

#define DEBUG



// Header files, namespaces,
// macros as defined above
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree < pair<int, int>, null_type, less_equal<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

int f[2002];
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
        int n, k;
        cin >> n >> k;
        vector <int>v(n,0);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        int res{};
        for (int i = 0; i < n; i++)
        {
            ordered_set s;
            //vector<int> f(2002, 0);
            memset(f,0,sizeof(f));
            for (int j = i; j < n; j++)
            {
                int l = j - i + 1;
                int m = (k + l - 1) / l; // ceil(k/l)=floor(k+l-1/l);
                int pos = (k + m - 1) / m;
                //cout<<l<<" "<<m<<" "<<pos<<"\n";
                s.insert({v[j], f[v[j]]++});
                //cout<<arr[j]<<" "<<f[v[i]]<<"\n";
                auto it = s.find_by_order(pos - 1);
                int resx = it->first;
                int cnt = f[resx];
                if (f[cnt] != 0){
                    //cout<<i<<" "<<j<<"\n";
                    res++;
                }
            }
        }
        cout << res << "\n";
    }

    return 0;
}