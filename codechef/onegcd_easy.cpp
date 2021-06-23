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
        int n{};
        cin >> n;
        if (n == 1)
        {   
            cout<<"1\n";
            cout << 1 << ' ' << 1 << '\n';
            continue;
        }
        //int cnt{};
        cout<<(n/2)<<'\n';
        int i=1;
        while (i<=n)
        {
            if ((n&1)&&i==1)
            {
                cout<<"3 1 2 3\n";
                i+=3;
            }
            else
            {
                cout<<"2 "<<i<<' '<<i+1<<'\n';
                i+=2;
            }
        }
    }
    return 0;
}