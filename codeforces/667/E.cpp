#include <bits/stdc++.h>

#define DEBUG

using namespace std;

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
        int n, l, t, cnt{1};
        cin >> n >> l;
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        for (int i = 0; i < n; i++)
            cin >> t;
        sort(v.begin(), v.end());
        vector<pair<int, int>> vp;
        for (int i = 1; i < n; i++)
        {
            if (v[i] == v[i - 1])
            {
                cnt++;
            }
            else
            {
                vp.push_back({v[i - 1], cnt});
                cnt = 1;
            }
        }
        vp.push_back({v[n - 1], cnt});
        /*
        for(int i=0;i<vp.size();i++) cout<<vp[i].first<<" "<<vp[i].second<<" ";
        cout<<"\n";
        */
        int res{}; 
        int j=0,len=0,cur=vp[0].second,mx{cur},temp;
        int st{},ed{};
        for (int i = 0; i < vp.size()&&j<vp.size(); i++)
        {
            if(i!=0)
            {
                cur-=vp[i-1].second;
                if(j<i){
                    j=i;
                    cur=vp[i].second;
                }
            }
            len=vp[j].first-vp[i].first;
            while (len <= l)
            {
                j++;
                if(j>=vp.size()) break;
                cur+=vp[j].second;
                len =vp[j].first-vp[i].first;
            }
            if(j==vp.size())
            {
                temp=max(mx,cur);
                if(temp==cur)
                {
                    st=i;
                    ed=j-1;
                }
                mx=temp;
            }
            else
            {
                cur-=vp[j].second;
                j--;
                temp=max(mx,cur);
                if(temp==cur)
                {
                    st=i;
                    ed=j;
                }
                mx=temp;
            }
        }
        res+=mx;
        vp.erase(vp.begin()+st,vp.begin()+ed+1);
        if(vp.size()==0){
            cout<<res<<"\n";
            continue;
        }
        j=0;
        len=0;
        cur=vp[0].second;
        mx=cur;
        st=0;
        ed=0;
        for (int i = 0; i < vp.size()&&j<vp.size(); i++)
        {
            if(i!=0)
            {
                cur-=vp[i-1].second;
                if(j<i){
                    j=i;
                    cur=vp[i].second;
                }
            }
            len=vp[j].first-vp[i].first;
            while (len <= l)
            {
                j++;
                if(j>=vp.size()) break;
                cur+=vp[j].second;
                len =vp[j].first-vp[i].first;
            }
            if(j==vp.size())
            {
                temp=max(mx,cur);
                if(temp==cur)
                {
                    st=i;
                    ed=j-1;
                }
                mx=temp;
            }
            else
            {
                cur-=vp[j].second;
                j--;
                temp=max(mx,cur);
                if(temp==cur)
                {
                    st=i;
                    ed=j;
                }
                mx=temp;
            }
        }
        res+=mx;
        cout<<res<<"\n";
        

    }

    return 0;
}