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

    int n{},cnt{};
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v[i] = (a == 0) ? 1 : -1;
        if(a==1) cnt++; 
    }
    int maxei{v[0]}, maxs{v[0]};
    //int len{1};
    for (int i = 1; i < n; i++)
    {
        //int temp;
        maxei = max(maxei + v[i], v[i]);
        maxs= max(maxs, maxei);
        //len = (temp == maxs) ? len : len + 1;
        
    }
    //cout<<maxs<<"\n";
    if (maxs < 0)
        cout << n-1;
    else
    {
        cout<<cnt+maxs;
    }
    return 0;
}