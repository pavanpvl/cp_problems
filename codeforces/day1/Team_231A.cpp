#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/pavan/cp_problems/a.in", "r", stdin);
    freopen("/home/pavan/cp_problems/a.out", "w", stdout);
#endif
    int n,res{};
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a,b,c;
        std::cin>>a>>b>>c;
        a=a+b+c;
        if(a>=2) res++;
    }
    std::cout<<res<<"\n";
}