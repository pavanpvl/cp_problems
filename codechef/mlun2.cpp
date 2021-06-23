#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        string s;
        int a[26],K,X,i,y,cnt=0;
        cin>>s;
        cin>>K>>X;
        for(i=0;i<26;i++) a[i]=0;
        for(i=0;i<s.size();i++){
            y=s[i]-'a';
            a[y]+=1;
            cnt++;
            if(a[y]>X&&(K==0)){
                cnt--;
                break;
            }
            else if(a[y]>X&&(K>0)){
                K--;
                cnt--;
                a[y]--;
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}