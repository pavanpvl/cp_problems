#include<bits/stdc++.h>
using namespace std;
void findpos(vector<long long> &a, int x)
{
    int n = a.size();
    unordered_map<long long, long long> m;
    long long sum{};
    m[0] = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = a[i];
        sum += temp;
        if (m.find(sum - x) != m.end())
        {
            cout << m[sum - x] + 1 << " " << i + 1 << "\n";
            return;
        }
        else
            m[sum] = i + 1;
    }
    cout << "-1\n";
    return;
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
        int n, s;
        cin >> n >> s;
        vector<long long> a(n, 0LL);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        findpos(a, s);
        //cout << maxLen(a,s) << "\n";
    }
    return 0;
}
