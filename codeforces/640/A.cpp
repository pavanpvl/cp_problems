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
        int n, i{},m;
        cin >> m;
        n=m;
        while (n != 0)
        {
            int l = n % 10;
            n = n / 10;
            if (l == 0)
            {
                continue;
            }
            i++;
        }
        cout<<i<<"\n";
        i=0;
        n=m;
        while (n != 0)
        {
            int l = n % 10;
            n = n / 10;
            if (l == 0)
            {
                i++;
                continue;
            }
            cout << l;
            for (int j = 0; j < i; j++)
                cout << "0";
            cout << " ";
            i++;
        }
        cout << "\n";
    }

    return 0;
}