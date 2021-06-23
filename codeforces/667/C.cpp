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

    int t{};
    cin>>t;

    while(t--)
    {
        int n,st,ed,pos,d;
        cin>>n>>st>>ed;
        vector<int> res;
        for(int i=n-1;i>0;i--)
        {
            if((ed-st)%i==0)
            {
                d=(ed-st)/i;
                pos=i+1;
                break;
            }
        }
        res.push_back(st);
        res.push_back(ed);
        for(int i=1;i<=pos-2;i++)
        {
            res.push_back(st+i*d);
        }
        st-=d;
        while(st>0&&(res.size()<n))
        {
            res.push_back(st);
            st-=d;
        }
        while(res.size()<n)
        {
            ed=ed+d;
            res.push_back(ed);
        }
        for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
        cout<<"\n";
    }


    return 0;
}