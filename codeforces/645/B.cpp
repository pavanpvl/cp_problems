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
        int n;
        cin >> n;
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        sort(v.begin(), v.end());
        int j = 1;
        int ans{1};
        for (int i = 0; i < n; i++, j++)
        {
            if (v[i] <= j)
            {   
                ans=j+1;
                continue;
            }
            else if(v[i]>j+1){
                continue;
            }
            else continue;
        }
        cout<<ans<<"\n";
    }

    return 0;
}