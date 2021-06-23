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
    int t{};
    cin>>t;
    while(t--){
        long long n{},x{};
        cin>>n>>x;
        long long a[n];
        //long long temp;
        for(long long i=0;i<n;i++) cin>>a[i];
        sort(a,a+n,greater<int>());
        int pos=-1;
        for(int i=0;i<n;i++){
            if(i!=0) a[i]+=a[i-1];
            //cout<<a[i]<<' '<<x*(i+1)<<'\n';
            if(a[i] < x*(i+1) ){ 
                pos=i;
                break;
            }
        }
        if(pos==-1) cout<<n<<'\n';
        else cout<<pos<<'\n';


    }
    return 0;
}