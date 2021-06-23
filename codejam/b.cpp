#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    #endif
    int t,ts;
    cin>>t;
    ts=1;
    while(t--){
        string x,s;
        int n,d,r;
        cin>>s;
        n=s.size();
        int a[n];
        for(int i=0;i<n;i++){
            a[i]=s[i]-'0';
        }
        d=0;
        for(int i=0;i<n;i++){
            r=a[i];
            if(r==d) x.append(s,i,1);
            else if(r>d){
                string temp(r-d,'(');
                temp.append(s,i,1);
                x.append(temp);
                d=r;
            } 
            else{
                string temp(d-r,')');
                temp.append(s,i,1);
                x.append(temp);
                d=r;
            }
        }
        if(d>0){
            string temp(d,')');
            x.append(temp);
        }
        cout<<"Case #"<<ts<<": "<<x<<"\n"; 
        ts++;
    }
    return 0;
}