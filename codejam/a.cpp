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
    int t,u,ts=1;
    cin>>t;
    while(t--){
        int n,k,r,c;
        cin>>n;
        int a[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        k=0;
        r=0;
        c=0;
        for(int i=0;i<n;i++){
            map <int,int> m;
            for(int j=0;j<n;j++){ 
                u=a[i][j];
                if(m.find(u)==m.end()) m[u]=1;
                else{
                     r++;
                     break;
                }
            }
        }
        for(int i=0;i<n;i++){
            map <int,int> m;
            for(int j=0;j<n;j++){
                u=a[j][i]; 
                if(m.find(u)==m.end()) m[u]=1;
                else{
                     c++;
                     break;
                }
            }
        }
        for(int i=0;i<n;i++) k+=a[i][i];
        cout<<"Case #"<<ts<<": "<<k<<" "<<r<<" "<<c<<"\n";   
        ts++;     
    }
    return 0;
}