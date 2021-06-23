#include <bits/stdc++.h>
using namespace std;
bool findpos(vector<long long> &a, int x)
{
    int st, en;
    int n = a.size();
    long long sum{};
    int flag{};
    for (int i = 0, j = 0; i < n;)
    {
        while (sum < x && j < n)
        {
            sum += a[j];
            j++;
        }
        //if(sum>=x) cout<<i+1<<" "<<j<<"\n";
        st = i + 1;
        en = j;
        if (sum == x && en - st > 0)
        {

            flag = 1;
            break;
        }
        sum -= a[i];
        i++;
    }
    return flag;
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
        int n,res{};
        cin >> n;
        vector<long long> a(n, 0);
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            m[a[i]] += 1;
        }
        for (auto it = m.begin(); it != m.end(); it++)
        {
            int f = findpos(a, it->first);
            if (f)
            {
                res+=it->second;       
            }
        }
        cout<<res<<"\n";
        //cout << maxLen(a,s) << "\n";
    }
    return 0;
}
