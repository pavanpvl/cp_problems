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
        string s;
        cin>>s;
        int c0{},c1{},n=s.length();
        for(int i=0;i<n;i++){
            (s[i]=='0')?c0++:c1++;
        }
        if(c0==n||c1==n||n==1) cout<<s<<"\n";
        else{
            string res(2*n,'0');
            for(int i=0;i<n;i++) {
                res[2*i]='1';
                res[2*i+1]='0';
            }
            cout<<res<<"\n";
        }
    }


    return 0;
}