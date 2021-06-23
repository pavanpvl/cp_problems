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
    int p[1001];
    memset(p,0,sizeof(p));
    p[0]=1;
    p[3]=1;
    p[5]=1;
    p[6]=1;
    p[7]=1;
    for(int i=8;i<=1000;i++){
        if(p[i-3]==1||p[i-5]==1||p[i-7]==1) p[i]=1;
        else p[i]=0;
    }
    // for(int i=0;i<=1000;i++){
    //     if(p[i]==1) cout<<i<<" ";
    // }
    //cout<<"\n";
    while(t--)
    {
        int x,c3{},c5{},c7{};
        cin>>x;
        if(p[x]==0) cout<<-1<<"\n";
        else{
            while(x>0){
                if(p[x-3]==1){
                    c3++;
                    x=x-3;
                }
                else if(p[x-5]==1){
                    c5++;
                    x-=5;
                }
                else{
                    c7++;
                    x-=7;
                }
            }
            cout<<c3<<" "<<c5<<" "<<c7<<"\n";
        }
    }


    return 0;
}