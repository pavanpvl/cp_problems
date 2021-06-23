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
        int n, k;
        cin >> n >> k;
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        map<int, int> m;
        int mn{INT_MAX};
        for (int i = 0; i < n / 2; i++)
        {
            m[v[i] + v[n - i - 1]] += 1;
        }
        vector<int> pref(2 * k + 2, 0);
        for (int i = 0; i < n / 2; i++)
        {
            pref[min(v[i],v[n-i-1])+1]+=1;
            pref[max(v[i],v[n-i-1])+k+1]-=1;
        }
        for(int i=1;i<pref.size();i++){
            pref[i]=pref[i]+pref[i-1];
        }
        for(int i=2;i<=2*k;i++){
            int temp;
            temp=n-m[i]-pref[i];
            mn=min(mn,temp);
        }
        cout << mn << "\n";
    }
    return 0;
}