#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("../a.in", "r", stdin);
    freopen("../a.out", "w", stdout);
#endif
    int t{};
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        map<int, int> m;
        for (int i = 0; i < n / 2; i++)
        {
            m[v[i] + v[n - i - 1]] += 1;
        }
        vector<pair<int, int>> fq;
        for (auto i = m.begin(); i != m.end(); i++)
        {
            //cout<<i->first<<" "<<i->second<<"\n";
            fq.push_back(make_pair(i->second, i->first));
        }
        sort(fq.begin(), fq.end());
        int mn{INT_MAX};
        for (auto c : fq)
        {
            //cout<<i.second<<" "<<i.first<<"\n";
            int rsum = c.second,cnt{0};

            for (int i = 0; i < n / 2; i++)
            {
                int csum=v[i] + v[n - i - 1];
                if(csum==rsum) continue;
                int lv,mv,temp=csum-rsum;
                lv=min(v[i],v[n-i-1]);
                mv=max(v[i],v[n-i-1]);
                if(temp>0&&(mv-temp>=1)) cnt+=1;  
                else if(temp<0&&(lv-temp<=k)) cnt+=1;
                else cnt+=2;
                //cout<<csum<<" "<<rsum<<" "<<cnt<<" \n";
            }
            mn=min(mn,cnt);
        }
        mn=min(mn,n/2);
        cout<<mn<<"\n";
    }
    return 0;
}