#include <bits/stdc++.h>

#define DEBUG

using namespace std;
int maxLen(vector<int> &a)
{
    int n = a.size();
    map<int, int> m;
    int sum{};
    m[0] = -1;
    int mx{INT_MIN};
    for (int i = 0; i < n; i++)
    {
        int temp=a[i];
        if(temp==0) temp=-1;
        sum += temp;
        if (m.find(sum) == m.end())
        {
            m[sum]=i;
        }
        else mx=max(mx,i-m[sum]);
    }
    return mx;
}

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
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << maxLen(a) << "\n";
    }

    return 0;
}
