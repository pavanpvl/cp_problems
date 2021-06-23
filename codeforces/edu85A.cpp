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
        int a[n][2];
        int flag{};
        for (int i = 0; i < n; i++)
            cin >> a[i][0] >> a[i][1];
        for (int i = 0; i < n; i++)
        {
            if (a[i][0] < 0 || a[i][1] < 0){
                flag=1;
                break;
            }
            else if(a[i][0]<a[i][1]){
                flag=1;
                break;
            }
            if (i > 0)
            {
                if ((a[i][0] - a[i - 1][0]) < (a[i][1] - a[i - 1][1]) || (a[i][1] - a[i - 1][1])<0 || (a[i][0] - a[i - 1][0]<0))
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}