#include <bits/stdc++.h>

using namespace std;

int Pow(int n, int x)
{
    int cnt{};
    int y=x;
    while(y<=n){
        cnt+=n/y;
        y*=x;
    }
    return cnt;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("../../a.in", "r", stdin);
    freopen("../../a.out", "w", stdout);
#endif
    int t{};
    cin >> t;
    while (t--)
    {
        int n;
        long long a{}, b{},res{};
        cin >> n;
        a = Pow(n, 2);
        b = Pow(n, 5);
        res=min(a,b);
        cout<<res<<'\n';
    }
    return 0;
}