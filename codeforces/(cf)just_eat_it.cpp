#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    int n,t,cntendi,cnti;
    long long maxendi, max1i;
    cin >> t;
    while (t--)
    {
        long long s=0,a,b;
        vector<long long> v;
        cin >> n;
        v.assign(n, 0);
        for (auto i = v.begin(); i != v.end(); i++)
        {
            cin >> *i;
        }
        maxendi = v[0];
        max1i = v[0];
        cnti=1;
        cntendi=cnti;
        for (int i = 1; i < n; i++)
        {
            s+=v[i];
            a=maxendi + v[i];
            maxendi = max(a, v[i]);
            cntendi=(maxendi==v[i])? 1:cntendi+1;
            b=max(max1i, maxendi);
            cnti=(b==max1i)?cnti:cntendi;
            max1i=b;
            //cout<<i<<' '<<cnti<<' '<<cntendi<<'\n';
        }
        //cout<<cnti<<'\n';
        if(s>max1i || cnti==n) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
         
    }
    return 0;
}