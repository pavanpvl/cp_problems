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
        int n;
        cin>>n;
        int flag{};
        vector<int>v(n,0);
        for(int i=0;i<n;i++) cin>>v[i];
        int ckey=1,nkey=0;
        for(int i=n-1;i>=0;i--){
            nkey=v[i]+1;
            while(v[i]!=ckey){
                if(i==0){
                    flag=1;
                    break;
                }
                else if(v[i]!=v[i-1]+1){
                    flag=1;
                    break;
                }
                i--;
            }
            if(flag) break;
            else ckey=nkey;
        }
        if(flag) cout<<"NO\n";
        else cout<<"YES\n";
    }


    return 0;
}