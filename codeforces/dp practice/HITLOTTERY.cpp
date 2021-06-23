#include<bits/stdc++.h>

#define DEBUG

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("/home/pavan/cp_problems/a.in","r",stdin);
    freopen("/home/pavan/cp_problems/a.out","w",stdout);
    #endif

    int n{},res{};
    int den[]={100,20,10,5,1};
    cin>>n;
    for(int i=0;i<5;i++){
        res+=n/den[i];
        n=n%den[i];
    }
   /*  res+=n/100;
    n=n%100;
    res+=n/20;
    n=n%20;
    res+=n/10;
    n=n%10;
    res+=n/5;
    n=n%5;
    res+=n; */
    cout<<res<<"\n";
    return 0;
}