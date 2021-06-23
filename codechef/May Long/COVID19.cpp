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
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int cur{1},mn={INT_MAX},mx{INT_MIN};
        for (int i = 1; i <= n; i++)
        {
            if(a[i]-a[i-1]>2||i==n){
                mn=min(mn,cur);
                mx=max(mx,cur);
                cur=1;
            }
            else cur++;
        }
        /* mn=min(mn,cur);
        mx=max(mx,cur); */
        cout<<mn<<" "<<mx<<"\n";
    }

    return 0;
}