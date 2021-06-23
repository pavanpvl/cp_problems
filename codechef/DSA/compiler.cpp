#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("../../a.in","r",stdin);
    freopen("../../a.out","w",stdout);
    #endif
    int t{};
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        stack <char> st;
        int pos{},i{},flag{};
        for(i=0;i<s.size();i++){
            if(st.empty()){ 
                pos=i;
                if(s[i]=='<') st.push(s[i]);
                else if(s[i]=='>'){
                    flag=1;
                    break;
                }
            }
            else if(s[i]=='>') st.pop();
            else st.push(s[i]);
        }
        if(st.empty()&&(!flag)) pos=i;
        cout<<pos<<'\n';
    }
    return 0;
}