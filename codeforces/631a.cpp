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
    int t{};
    cin >> t;
    while (t--)
    {
        int n{}, x{}, res{},i{};
        cin >> n >> x;
        vector<int> v;
        v.assign(n, 0);
        for (auto &e : v)
        {
            cin >> e;
        }
        sort(v.begin(), v.end());
        for (i =n-1; i > 0; i--)
        {
            v[i]-=v[i-1];
        }
        for(i=0;i<n;i++){
            if(v[i]==1){ 
                res++; 
                continue;
            }
            else if(v[i]==0) continue;
            else if(x==0) break;
            else if(x>=v[i]-1){
                res+=v[i];
                x-=v[i]-1;
            }
        }
        if(x>0) res+=x;
        cout << res << '\n';
    }
    return 0;
}

/*  for (i=0; i < n && x > 0; i++)
       {
            if(v[i]==res) continue;
            else if (v[i] == res + 1){
                res++;
                continue;
            }
            else if (v[i] - res - 1 > x)
            {
                res = res + x;
                x=0;
                break;
            }
            else
            {
                x = x - (v[i] - res - 1);
                res = v[i];
            }
        }
        if(x) res+=x;
        else {
            while( i<n && (v[i]==v[i-1]||(v[i]==v[i-1]+1))){
                if(v[i]==v[i-1]+1){
                    res++;
                }
                i++;
            }
        } */