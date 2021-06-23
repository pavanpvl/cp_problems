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
        int n, x;
        cin >> n >> x;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n, greater<int>());
        //for(int i=0;i<n;i++) cout<<a[i]<<" ";
        int res{},cnt{1};
        for (int i = 0; i < n; i++)
        {
            if(cnt*a[i]>=x){
                cnt=1;
                res++;
            } 
            else cnt++;
        }
        cout<<res<<"\n";
    }

    return 0;
}