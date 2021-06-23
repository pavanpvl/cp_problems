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
        int n, k;
        vector<int> v;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> k;
            if (k & 1)
            {
                v.push_back(0);
            }
            else if ((k >> 1) & 1)
            {
                v.push_back(1);
            }
            else v.push_back(2);
        }
        
        for(int i=1;i<n;i++){
            v[i]+=v[i-1];
            //if(v[i]>2) v[i]=2;
        }
        /* for(auto i:v) cout<<i<<' ';
        cout<<'\n'; */
        int s;
        int cnt{};
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(i==0)
                    s=v[j];
                else s=v[j]-v[i-1];
                //cout<<s<<'\n';
                if(s==0) cnt++;
                else if(s==1) continue;
                else{
                    cnt+=n-j;
                    break;
                } 
            }
            //cout<<cnt<<'\n';
        } 
        cout<<cnt<<'\n';    
    }
    return 0;
}
