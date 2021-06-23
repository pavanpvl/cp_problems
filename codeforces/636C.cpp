#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("../a.in", "r", stdin);
    freopen("../a.out", "w", stdout);
#endif
    int t{};
    cin >> t;
    while (t--)
    {
        int n, ps, cs, ms{INT_MIN};
        cin>>n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<int> v;
        ps = (a[0] > 0) ? 0 : 1;
        for (int i = 0; i < n; i++)
        {
            cs = (a[i] > 0) ? 0 : 1;
            if (cs == ps)
            {
                ms = max(a[i], ms);
            }
            else
            {
                v.push_back(ms);
                ms=a[i];
                ps=cs;
            }
        }
        v.push_back(ms);
        long long res{};
        for(auto i:v){
            res+=i;
        }
        cout<<res<<'\n';
    }
    return 0;
}