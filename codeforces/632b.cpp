#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    int t{};
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], b[n], flag{};
        int s[3] = {0, 0, 0};
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        for (int i = 0; i < n; i++)
        {
            if (a[i] == b[i])
            {
                s[a[i] + 1] += 1;
                continue;
            }
            else if (a[i] > b[i])
            {
                if (s[0])
                {
                    s[a[i] + 1] += 1;
                    continue;
                }
                else
                {
                    flag = 1;
                    break;
                }
            }
            else
            {
                if (s[2])
                {
                    s[a[i] + 1] += 1;
                    continue;
                }
                else
                {
                    flag = 1;
                    break;
                }
            }
        }
        if(flag) cout<<"NO"<<'\n';
        else cout<<"YES"<<'\n';
    }
    return 0;
}