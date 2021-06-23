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
        int n,flag{};
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 1; i < n - 1; i++)
        {
            if ((a[i] > a[i - 1] )&& (a[i] > a[i + 1]))
            {
                cout<<"YES\n"<<i<<" "<<i+1<<" "<<i+2<<"\n";
                flag=1;
                break;
            }
        }
        if(flag==0) cout<<"NO\n";
    }

    return 0;
}