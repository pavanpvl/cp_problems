#include <bits/stdc++.h>

//#define DEBUG

using namespace std;
int cnt{};
int solve(int *a, int n, int *b)
{
    cnt++;
    if (b[n] >= 0)
        return b[n];
    int res{0};
    for (int i = 1; i <= n; i++)
    {
        res = max(res, a[i] + solve(a, n - i, b));
    }
#ifdef DEBUG
    cout << n << " " << res << "\n";
#endif
    b[n] = res;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("/home/pavan/cp_problems/a.in", "r", stdin);
    freopen("/home/pavan/cp_problems/a.out", "w", stdout);
#endif

    int n{}, res{};
    cin >> n;
    int a[n + 2], b[n + 1], c[n + 1];
    memset(a, 0, sizeof(a));
    memset(b, -1, sizeof(b));
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    //res = solve(a, n, b);
    b[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int mx{};
        for (int j = 1; j <= i; j++)
        {
            if (mx < a[j] + b[i - j])
            {
                mx =a[j] + b[i - j];
                c[i]=j;
            }
        }
        b[i] = mx;
    }
    for (int i = 0; i <= n; i++)
        cout << b[i] << " ";
    cout<<"\n";
    for (int i = 0; i <= n; i++)
        cout << c[i] << " ";
    return 0;
}