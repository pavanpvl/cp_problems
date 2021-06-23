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
        int n, k;
        string s;
        cin >> n >> k;
        cin >> s;
        vector<int> f(26, 0);
        for (int i = 0; i < n; i++)
        {
            f[s[i] - 'a']++;
        }
        int f1{0}, f2{1};
        string res{};
        int s{};
        for (int i = 0; i < 26; i++)
        {
            if (k == 1)
            {
                continue;
            }
            if (f[i] == 0)
                continue;
            else if (s + f[i] < k)
            {
                s += f[i];
                f1 = i + 1;
                f2++;
                continue;
            }
            if (f2 > 1)
            {
                res += static_cast<char>('a' + i);
                break;
            }
        }
    }
    res +=
        return 0;
}