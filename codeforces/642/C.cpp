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
        int n;
        cin >> n;
        long long cur = n;
        long long res{},iter{};
        while (cur > 1)
        {
            long long temp{};
            temp=4*cur-4;
            iter+=temp;
            res+=iter;
            cur-=2;
        }
        cout<<res<<"\n";
    }

    return 0;
}