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

    int t{};
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        long long d, r;
        long long res;
        d = k / (n - 1);
        r = k % (n - 1);
        res = d * n;
        if (r == 0)
        {
            res--;
        }
        else
        {
            res += r;
        }
        cout << res << "\n";
    }

    return 0;
}