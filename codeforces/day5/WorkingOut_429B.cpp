#include <iostream>
#include <cstring>
int max(int a, int b)
{
    return (a>b)?a:b;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/pavan/cp_problems/a.in", "r", stdin);
    freopen("/home/pavan/cp_problems/a.out", "w", stdout);
#endif
    int n, m;
    std::cin >> n >> m;
    int a[n + 1][m + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            std::cin >> a[i][j];
        }
    }
    int dp1[n + 2][m + 2];
    std::memset(dp1, 0, sizeof(dp1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp1[i][j] = a[i][j] + max(dp1[i - 1][j], dp1[i][j - 1]);
        }
    }
    int dp2[n + 2][m + 2];
    std::memset(dp2, 0, sizeof(dp2));
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= m; j++)
        {
            dp2[i][j] = a[i][j] + max(dp2[i][j - 1], dp2[i + 1][j]);
        }
    }
    int dp3[n + 2][m + 2];
    std::memset(dp3, 0, sizeof(dp3));
    for (int i = n; i >= 1; i--)
    {
        for (int j = m; j >= 1; j--)
        {
            dp3[i][j] = a[i][j] + max(dp3[i][j + 1], dp3[i + 1][j]);
        }
    }
    int dp4[n + 2][m + 2];
    std::memset(dp4, 0, sizeof(dp4));
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 1; j--)
        {
            dp4[i][j] = a[i][j] + max(dp4[i-1][j], dp4[i][j+1]);
        }
    }
    int mx1{-1}, mx2{-1},res{-1};

    for (int i = 2; i < n; i++)
    {
        for (int j = 2; j < m; j++)
        {
            mx1 = dp1[i - 1][j] + dp2[i][j - 1] + dp3[i + 1][j] + dp4[i][j + 1];
            mx2 = dp1[i][j - 1] + dp2[i + 1][j] + dp3[i][j + 1] + dp4[i - 1][j];
            mx1 = max(mx1, mx2);
            res = max(res, mx1);
            //std::cout<< dp1[i - 1][j]<<" "<<dp2[i][j - 1]<<" "<<dp3[i + 1][j]<<" "<<dp4[i][j + 1]<<"\n";
            //std::cout<<mx1<<" ";
        }
    }
    std::cout<<res<<"\n";
}