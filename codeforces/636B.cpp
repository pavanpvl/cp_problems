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
        int n;
        cin >> n;
        if (n % 4 != 0)
            cout << "NO\n";
        else
        {

            cout << "YES\n";
            int a[n];
            for (int i = 0; i < n / 2; i++)
            {
                cout << (2 * i + 2) << " ";
            }
            for(int i=0;i<n/4;i++){
                cout << (2 * i + 1) << " ";    
            }
            for(int i=n/4+1;i<=n/2;i++){
                cout << (2 * i + 1) << " ";    
            }
            cout<<"\n";

        }
    }
    return 0;
}