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
        int a{}, b{};
        a = 1 << n;
        for (int i = 1; i < (n / 2); i++)
        {
            a+=1<<i;
        }
        for(int i=n/2;i<n;i++){
            b+=1<<i;
        }
        cout<<a-b<<"\n";
    }

    return 0;
}