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

  for(int q=1;q<=t;q++)
    {
        int n,a,b,c;
        cin>>n>>a>>b>>c;
        if(a+b-c>n)
        {
            cout<<"Case #"<<q<<": IMPOSSIBLE\n";    
        }
        else
        {
            if(a+b-c<n)
            {
                if(a==c&&b==c&&c<2){ cout<<"Case #"<<q<<": IMPOSSIBLE\n";
                continue;
                }
            }
            int r=n-(a+b-c);
            cout<<"Case #"<<q<<": ";
            for(int i=0;i<a-c;i++) cout<<n-1<<" ";
            if(c<2&&((a-c)>0))
            {
                for(int k=0;k<r;k++) cout<<n-2<<" ";
            }

            for(int i=0;i<c;i++){
                if(i==1){
                    for(int k=0;k<r;k++) cout<<n-2<<" ";
                }
                cout<<n<<" ";
            }
            if(c<2&&((a-c)==0))
            {
                for(int k=0;k<r;k++) cout<<n-2<<" ";
            }
            for(int i=0;i<b-c;i++) cout<<n-1<<" ";
            cout<<"\n";
        }
    }

    return 0;
}