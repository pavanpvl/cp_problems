#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int g_m = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("/home/pavan/cp_problems/a.in", "r", stdin);
    freopen("/home/pavan/cp_problems/a.out", "w", stdout);
#endif

    int n{}, k{};
    long long temp, res{1};
    cin >> n >> k;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n - 1; i++)
    {
        int j;
        int cur = v[i];
        int nxt;
        for ( j = i + 1; j < n; j++)
        {
            if (v[j] < cur)
            {
                nxt = j;
                break;
            }
        }
        if (j == n)
            temp = 1;
        else
            temp = (nxt - i + 1);
        res = (res * temp) % g_m;
    }
    cout << res << "\n";

    return 0;
}