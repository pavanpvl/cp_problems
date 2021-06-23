#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("../../a.in", "r", stdin);
    freopen("../../a.out", "w", stdout);
#endif
    int t{};
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        /* vector<int> v(n, 0);
        for (auto &e : v)
            cin >> e; */
        int mxl{INT_MAX};
        int temp, cnt{};
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            if (temp <= mxl)
                cnt++;
            mxl = min(temp, mxl);
        }
        cout<<cnt<<'\n';
    }
    return 0;
}