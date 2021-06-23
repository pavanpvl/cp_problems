#include<iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/pavan/cp_problems/a.in", "r", stdin);
    freopen("/home/pavan/cp_problems/a.out", "w", stdout);
#endif
    char s[102];
    std::cin>>s;
    int l;
    for(l=0;s[l]!='\0';l++);
    for(int i=0;i<l;i++)
    {
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='y'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'||s[i]=='Y'){

        }
        else if((s[i]>='A')&&(s[i]<='Z')){
            char a=s[i]-('A')+('a');
            std::cout<<'.'<<a;
        }
        else {
            std::cout<<"."<<s[i];
        }
    }
    return 0;
}