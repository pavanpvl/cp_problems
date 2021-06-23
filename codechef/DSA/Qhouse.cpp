#include <bits/stdc++.h>

#define DEBUG

using namespace std;

int find(int c, int d)
{
    int l = 0, r = 1000, res{};
    int m;
    string s;
    while (l <= r)
    {
        m = l + (r - l) / 2;
        if (d)
            cout << "? " << m << " " << c << endl
                 << flush;
        else
            cout << "? " << c << " " << m << endl
                 << flush;
        cin >> s;
        if (s == "YES")
        {
            res = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    return res;
}

int main()
{
    /*   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("/home/pavan/cp_problems/a.in", "r", stdin);
    freopen("/home/pavan/cp_problems/a.out", "w", stdout);
#endif */

    int a, b, c;
    int x, y, res{};
    x = 0;
    y = 0;
    a = find(x, 0);
    b = find(y, 1);
    c = find(2 * b, 1);
    res = (a - 2 * b) * c + (4*b)*b;
    cout << "! " << res << endl<<flush;
    return 0;
}