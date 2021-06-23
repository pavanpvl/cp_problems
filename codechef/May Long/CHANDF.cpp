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
        long long x, y, l, r;
        cin >> x >> y >> l >> r;
        long long mx = max(x, y);
        int cnt{};
        long long up{1},temp{},res{};
        while (mx != 0)
        {
            cnt++;
            mx = mx >> 1;
            up = (up * 2) + 1;
        }
        long long u;
        for (long long i = l; i <= r && i <= up; i++)
        {
            temp=(x&i)*(y&i);
            u=max(temp,mx);
            res=(u==mx)?res:i;
        }
        cout<<res<<"\n";
    }

    return 0;
}