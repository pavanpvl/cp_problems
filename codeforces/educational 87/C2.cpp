#include <bits/stdc++.h>
#include <cmath>
#define DEBUG

using namespace std;
# define M_PI           3.14159265358979323846 
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
        double res{1};
        double a = M_PI / n;
        for (int i = 1; i <= (n-1) / 2; i++)
        {
            res+=2*sin(i*a);
        }
        cout<<fixed<<setprecision(8)<<res<<'\n';
    }

    return 0;
}