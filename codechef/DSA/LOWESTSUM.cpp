#include <bits/stdc++.h>

#define DEBUG

using namespace std;

void solve()
{
    int k, q,s;
    cin >> k >> q;
    int a[k], b[k];
    vector<int> v(k * k, 0);
    for (int i = 0; i < k; i++)
        cin >> a[i];
    for (int i = 0; i < k; i++)
        cin >> b[i];
    int pos = 0;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            v[pos++] = a[i] + b[j];
        }
    }
    int res[k*k];
    memset(res,0,sizeof(res));
    make_heap(v.begin(), v.end(),greater<int>());
    for (int i = 0; (i < 10000) && (i < k * k); i++)
    {
        res[i]=v.front();
        pop_heap(v.begin(),v.end(),greater<int>());
        v.pop_back();
    }
    for (int i = 0; i < q; i++)
    {
        int pos;
        cin >> pos;
        //if(pos>s+1) cout<<"error\n";
        cout<<res[pos-1]<<"\n";
    }
}

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
        solve();
    }

    return 0;
}