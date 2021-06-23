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
        int n, z, res{};
        cin >> n >> z;
        priority_queue<int, vector<int>> mxh;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            mxh.push(a);
        }
        while (!mxh.empty() && z >= 0)
        {
            int c = mxh.top();
            mxh.pop();
            z = z - c;
            c = c / 2;
            if (c > 0)
                mxh.push(c);
            res++;
        }
        if (z > 0)
            cout << "Evacuate\n";
        else
            cout << res << "\n";
    }
    return 0;
}