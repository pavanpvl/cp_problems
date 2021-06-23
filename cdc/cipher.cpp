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

    int n;
    string s,t;
    cin>>n>>s;
    unordered_map <char,char> mp;
    for(char i='a';i<='z';i++){
        mp[i]=s[(int)(i-'a')];
    }

    for(int i=0;i<n;i++)
    {
        cin>>t;
        vector<int> v(t.length(),0);
        for(int j=0;j<t.length();j++){
            if(t[j]>='A'&&t[j]<='Z'){
                t[j]=t[j]-'A'+'a';
                v[j]=1;
            }
        }
        for(int j=0;j<t.length();j++){
            if(t[j]=='_') t[j]=' ';
            if(t[j]>='a'&&t[j]<='z'){
                t[j]=mp[t[j]];
                if(v[j]==1) t[j]=t[j]-'a'+'A';
            }
        }
        cout<<t<<"\n";
    }
    


    return 0;
}