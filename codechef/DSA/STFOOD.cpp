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
        int n, s, p, v;
        int mx{};
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> s >> p >> v;
            temp=p/(s+1);
            temp*=v;
            mx=max(temp,mx);
        }
        cout<<mx<<'\n';
    }
    return 0;
}