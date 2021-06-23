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
        int a,b,x[2],y[2],i,s=0,t;
        cin>>a>>b;
        s=a+b;
        for(i=0;i<2;i++){
            x[i]=a%10;
            y[i]=b%10;
            a=a/10;
            b=b/10;
        }
        
        if( ((x[1]+x[0])*10+y[0]+y[1]) > s && (y[1]!=0) ) s=((x[1]+x[0])*10+y[0]+y[1]);
        if( ((y[1]+y[0])*10+x[0]+x[1]) > s && (x[1]!=0)) s=((y[1]+y[0])*10+x[0]+x[1]);
       /* t=((x[1]+y[0])*10+x[0]+y[1]);
        if(t>s) s=t;
        t=((y[1]+x[0])*10+y[0]+x[1]);
        if(t>s) s=t;
        t=((y[0]+x[0])*10+y[1]+x[1]);
        */
        cout<<s<<'\n';
    }
	return 0;
}