/*
#include <iostream>
#include <string>
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/pavan/cp_problems/a.in", "r", stdin);
    freopen("/home/pavan/cp_problems/a.out", "w", stdout);
#endif
    std::string s;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> s;
        if (s.length()>10)
        {
            std::cout<<s[0];
            std::cout<<s.length()-2;
            std::cout<<s[s.length()-1]<<"\n";
        }
        else std::cout<<s<<"\n";
    }
}
*/
#include<iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/pavan/cp_problems/a.in", "r", stdin);
    freopen("/home/pavan/cp_problems/a.out", "w", stdout);
#endif
    int n;
    std::cin>>n;
    char s[102];
    for(int i=0;i<n;i++){
        std::cin>>s;
        int l;
        for(l=0;s[l]!='\0';l++);
        if(l>10)
        {
            std::cout<<s[0]<<l-2<<s[l-1]<<'\n';
        }
        else std::cout<<s<<"\n";
    }
}