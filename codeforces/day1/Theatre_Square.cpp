#include <iostream>
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("/home/pavan/cp_problems/a.in", "r", stdin);
    freopen("/home/pavan/cp_problems/a.out", "w", stdout);
#endif
    long long n, m, a;
    std::cin >> n >> m >> a;
    n = (n - 1) / a;
    m = (m - 1) / a;
    n++;
    m++;
    std::cout << n * m << "\n";
}