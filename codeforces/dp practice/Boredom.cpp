#include <bits/stdc++.h>

#define DEBUG

using namespace std;
int cnt[100000];
long long res[100000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("/home/pavan/cp_problems/a.in", "r", stdin);
    freopen("/home/pavan/cp_problems/a.out", "w", stdout);
#endif

    int n{}, mx{};
    cin >> n;
    memset(cnt, 0, sizeof(cnt));
    memset(res,0,sizeof(res));
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        cnt[a]++;
        mx = max(mx, a);
    }
    res[1]=cnt[1];
    for (long long i = 2; i <= mx; i++)
    {
        res[i]=max(cnt[i]*i+res[i-2],res[i-1]);
    }
    cout<<res[mx]<<"\n";
    return 0;
}