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
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int move = 0;
        int pre = 0;
        int st{0}, end{n - 1};
        int al{},bo{},cur{};
        while (st <= end)
        {
            if ((move & 1)==0)
            {
                while (st <= end && cur <= pre)
                {
                    cur += a[st];
                    st++;
                }
                pre = cur;
                al+=cur;
                cur=0;
                move++;
            }
            else
            {
                while (st <= end && cur <= pre)
                {
                    cur += a[end];
                    end--;
                }
                pre = cur;
                bo+=cur;
                cur=0;
                move++;   
            }
        }
        cout<<move<<" "<<al<<" "<<bo<<"\n";
    }

    return 0;
}