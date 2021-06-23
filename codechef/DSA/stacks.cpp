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
        int n{};
        cin>>n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<int> v;
        v.push_back(a[0]);
        for (int i = 1; i < n; i++)
        {
            auto it= upper_bound(v.begin(),v.end(),a[i]);
            if(it==v.end()) v.push_back(a[i]);
            else *it=a[i];
        }
        cout<<v.size()<<" ";
        for(auto i:v) cout<<i<<" ";
        cout<<"\n";
    }

    return 0;
}