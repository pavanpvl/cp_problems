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
        int carry{};
        long long n,s,sum{},n1;
        cin>>n>>s;
        vector<int> v;
        n1=n;
        while(n1 != 0LL)
        {
            v.push_back(n1%10);
            n1=n1/10;
        }
        for(int i=0;i<v.size();i++) sum+=v[i];
        int i;
        for(i=0;i<v.size();i++)
        {
            v[i]+=carry;
            carry=0;
            if(sum<=s) break;
            if(v[i]==0) continue;
            else
            {
                sum-=v[i];
                sum++;
                v[i]=0;
                carry=1;
            }
        }
        if(carry==1&&i==v.size()) v.push_back(1);
        unsigned long long res{},temp{};
        temp=n;
        for(int i=v.size()-1;i>=0;i--){
            res=res*10+v[i];
            //cout<<v[i]<<'\n';
        }
        //cout<<res<<" "<<n<<"\n";
        cout<<res-temp<<"\n";

    }


    return 0;
}