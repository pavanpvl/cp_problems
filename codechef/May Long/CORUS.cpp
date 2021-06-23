#include <bits/stdc++.h>

//#define DEBUG

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
    int n, q, a[26];
    string s;
    while (t--)
    {
        memset(a, 0, sizeof(a));
        cin >> n >> q >> s;
        for (int i = 0; i < n; i++)
        {
            int temp = static_cast<int>(s[i] - 'a');
            a[temp]++;
        }
        #ifdef DEBUG
        for (int i = 0; i < 26; i++)
        {
            cout << a[i] << " ";
        }
        cout << "\n";
        #endif
        for(int i=0;i<q;i++){
            int c,res{};
            cin>>c;
            for(int i=0;i<26;i++) if(a[i]>c) res+=a[i]-c;
            cout<<res<<"\n";
        }
    }
    return 0;
}