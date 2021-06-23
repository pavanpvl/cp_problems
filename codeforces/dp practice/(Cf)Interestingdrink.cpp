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

    int n{};
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x;
        cin>>x;
        auto it = upper_bound(v.begin(), v.end(), x);
        cout<<(it-v.begin())<<"\n";
    }

    return 0;
}