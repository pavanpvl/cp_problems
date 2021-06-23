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
        int n, k;
        cin >> n >> k;
        vector<int> a(n, 0);
        vector<int> b(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<int>());
        int l{0}, m{0};
        for (int i = 0; i < k; i++)
        {
            if (a[l] >= b[m])
                break;
            else
            {
                int temp = a[l];
                a[l] = b[m];
                b[m] = temp;
                l++;
                m++;
            }
        }
        int s{};
        for (int i = 0; i < n; i++)
        {
            s+=a[i];
        }
        cout<<s<<"\n";
    }

    return 0;
}