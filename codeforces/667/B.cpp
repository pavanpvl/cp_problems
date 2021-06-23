#include <bits/stdc++.h>

#define DEBUG

using namespace std;

long long prod(long long a, long long b, long long n, long long x, long long y)
{
    int temp;
    if (a - x >= n)
        a -= n;
    else
    {
        temp = a - x;
        a = x;
        b = b - n + temp;
        if (b < y)
            b = y;
    }
    return a*b;
}


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
        long long a, b, x, y, n,p1,p2;
        cin >> a >> b >> x >> y >> n;
        p1=prod(a,b,n,x,y);
        p2=prod(b,a,n,y,x);
        if(p1<p2) cout<<p1<<"\n";
        else cout<<p2<<"\n";
    }

    return 0;
}