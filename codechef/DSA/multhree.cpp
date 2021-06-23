#include <bits/stdc++.h>

using namespace std;

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
        long long s, temp{}, res{}, rem{};
        long long d0, d1,d2;
        cin >> s >> d0 >> d1;
        if (s == 2)
        {
            if((d0+d1)%3==0) cout<<"YES\n";
            else cout<<"NO\n";
            continue;
        }
        d2=(d0+d1)%10;
        temp = ((s - 3) / 4)*((2*d2)%10+(4*d2)%10+(8*d2)%10+(6*d2)%10);
        rem = (s-3)%4;
        if (rem == 1)
            temp += (2*d2)%10;
        else if (rem == 2)
            temp +=(2*d2)%10+(4*d2)%10;
        else if (rem == 3)
            temp +=(2*d2)%10+(4*d2)%10+(8*d2)%10;
        res = d0+d1+d2+temp;
        if (res % 3 == 0LL)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}