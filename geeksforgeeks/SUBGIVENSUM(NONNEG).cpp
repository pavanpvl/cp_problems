#include <bits/stdc++.h>
using namespace std;
void findpos(vector<long long> &a, int x)
{
    int st, en;
    int n = a.size();
    long long sum{};
    int flag{};
    for (int i = 0, j = 0; i < n ;)
    {
        while (sum < x && j < n)
        {
            sum += a[j];
            j++;
        }
        if(sum>=x) cout<<i+1<<" "<<j<<"\n";
        if (sum == x)
        {
            st = i + 1;
            en = j;
            flag = 1;
            break;
        }
        sum -= a[i];
        i++;
    }
    if (flag)
        cout << st << " " << en << "\n";
    else
        cout << "-1\n";
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
        vector<long long> a(n, 0);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        findpos(a, s);
        //cout << maxLen(a,s) << "\n";
    }
    return 0;
}
