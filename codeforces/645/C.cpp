#include<bits/stdc++.h>

#define DEBUG

using namespace std;
long long binomialCoeff(long long  n, long long k)  
{  
    long long res = 1;  
    // Since C(n, k) = C(n, n-k)  
    if ( k > n - k )  
        k = n - k;  
  
    // Calculate value of  
    // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]  
    for (int i = 0; i < k; ++i)  
    {  
        res *= (n - i);  
        res /= (i + 1);  
    }  
  
    return res;  
} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("/home/pavan/cp_problems/a.in","r",stdin);
    freopen("/home/pavan/cp_problems/a.out","w",stdout);
    #endif

    int t{};
    cin>>t;

    while(t--)
    {
        long long a,b,c,d,e,f,mx,mn;
        long long res;
        cin>>a>>b>>c>>d;
        e=abs(a-c);
        f=abs(b-d);
        res=binomialCoeff(e+f,e);
        cout<<res<<"\n";
    }
    return 0;
}