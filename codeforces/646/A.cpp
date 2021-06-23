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
        int x, n, ne{}, no{}, ho{},f{};
        cin >> n >> x;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            if (a & 1 == 1)
                no++;
            else
                ne++;
        }
        if (no == 0)
        {
            cout << "No\n";
            continue;
        }
        no = (no & 1) ? no : no - 1;
        for (int i = 1; i <= no&&i<=x; i += 2)
        {
            int r=x-i;
            if(r<=ne){ 
                f=1;
                break;
            }
        }
        if(f) cout<<"Yes\n";
        else cout<<"No\n";
    }

    return 0;
}