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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int x = a - b;
        if (x <= 0)
        {
            cout << b << "\n";
            continue;
        }
        else
        {
            if (c - d <= 0)
            {
                cout << -1 << "\n";
                continue;
            }
            else
            {
                long long k=x/(c-d);
                int a=x%(c-d);
                if(a) k++;
                long long ans;
                ans=b+k*c;
                cout<<ans<<"\n";
            }
        }
    }

    return 0;
}