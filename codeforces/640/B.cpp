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
        //cout<<(n&1)<<" "<<(k&1)<<"\n";
        if (((n & 1) && (k & 1)) || (((n & 1) == 0) && ((k & 1) == 0)))
        {
            if (n < k)
                cout << "NO\n";
            else
            {
                cout<<"YES \n";
                if (k == 1)
                {
                    cout << n << "\n";
                    continue;
                }
                for (int i = 0; i < k - 1; i++)
                {
                    cout << "1 ";
                }
                cout << n - k + 1 << "\n";
            }
        }
        else if (((n & 1) == 0) &&(k & 1))
        {
            if (n < 2 * k)
            {
                cout << "NO\n";
                continue;
            }
            cout<<"YES\n";
            if (k == 1)
            {
                cout << n << "\n";
                continue;
            }
            for (int i = 0; i < k - 1; i++)
            {
                cout << "2 ";
            }
            cout << n - 2*(k - 1) << "\n";
        }
        else {
            cout<<"NO\n";
        }
        
    }

    return 0;
}