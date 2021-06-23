#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("../a.in", "r", stdin);
    freopen("../a.out", "w", stdout);
#endif
    int t{};
    cin >> t;
    while (t--)
    {
        int n{};
        cin >> n;
        vector<long long> a(n), b(n);
        /*  a.assign(n,0);
        b.assign(n,0); */
        for (int i = 0; i < n; i++)
        {
            cin >> a[i] >> b[i];
        }
        long long sum{};
        long long mn{LONG_LONG_MAX}, temp;
        for (int i = 0; i < n; i++)
        {
            int ni = i + 1;
            if (ni == n)
                ni = 0;
            //max(a[i],b[i]);
            temp = max(0LL, a[ni] - b[i]);
            sum += temp;
            mn = min(mn, a[ni] - temp);
        }
        sum += mn;
        cout << sum << '\n';
    }

    return 0;
}