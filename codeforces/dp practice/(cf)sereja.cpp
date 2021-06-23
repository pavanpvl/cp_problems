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

    int n{}, k{};
    cin >> n >> k;
    int a[n];
    int res[n + 1];
    memset(res, 0, sizeof(res));
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map<int, int> m;
    for (int i = n - 1; i >= 0; i--)
    {
        m[a[i]]++;
        if (m[a[i]] == 1)
        {
            res[i] = res[i + 1] + 1;
        }
        else
            res[i] = res[i + 1];
    }
    for (int i = 0; i < k; i++)
    {
        int x;
        cin>>x;
        cout<<res[x-1]<<'\n';
    }

    return 0;
}