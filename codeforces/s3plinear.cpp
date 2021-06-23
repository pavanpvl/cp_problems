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
    int n;
    long long s,m,res;
    vector <int> a,cnt;
    cin>>n;
    a.assign(n,0);
    cnt.assign(n,0);
    s=0;
    for(int i=0;i<n;i++){
         cin>>a[i];
         s+=a[i];
    }
    if((s%3)!=0) {
        cout<<0;
        return 0;
    }
    else{
        m=s/3;
        s=0;
        for(int i=n-1;i>=0;i--){
            s+=a[i];
            if(s==m) cnt[i]=1;
        }
        for(int i=n-2;i>=0;i--) cnt[i]+=cnt[i+1];
        s=0;
        res=0;
        for(int i=0;i<n-2;i++){
            s+=a[i];
            if(s==m) res+=cnt[i+2];
        }
        cout<<res;

    }
    return 0;
}