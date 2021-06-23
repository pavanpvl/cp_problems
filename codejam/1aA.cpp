#include <bits/stdc++.h>

using namespace std;

bool match(string str, string pattern) 
{ 
    // empty pattern can only match with 
    // empty string 
    int n=str.size();
    int m=pattern.size();
    int i,j;
    for(i=0,j=0;i<n&&j<m;){
        
        if(str[i]==pattern[j])
    } 
} 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n;
        vector<string> v;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            v.push_back(s);
        }
        int flag{};
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if(!match(v[i],v[j])){
                    flag=1;
                    break;
                }  
            }
        }
        if(flag) cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}