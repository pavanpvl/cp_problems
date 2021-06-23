#include <iostream>
#include<limits.h>
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/pavan/cp_problems/a.in", "r", stdin);
    freopen("/home/pavan/cp_problems/a.out", "w", stdout);
#endif
    int n, k,f{INT_MAX},vk{-1},ik,t;
    std::cin >> n >> k;
    ik=k;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> t;
        if(t==0&&f==INT_MAX) f=i;
        if(i==k) vk=t;
        if(i>k&&vk==t) ik=i; 
    }
    if(f<=k) std::cout<<f-1;
    else std::cout<<ik;
}