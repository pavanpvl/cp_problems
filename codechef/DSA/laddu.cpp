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
    while(t--)
    {
        int nact{},ind{};
        int cwon{},tcon{};
        int cnhst{},bf{};
        int res{};
        string s;
        cin>>nact>>s;
        if(s=="INDIAN") ind=1;
        for(int o=0;o<nact;o++){
            cin>>s;
            if(s=="CONTEST_WON"){
                int rank;
                cin>>rank;
                if(rank>20) rank=20;
                cwon+=300+(20-rank);
            }
            else if(s=="TOP_CONTRIBUTOR") tcon++;
            else if(s=="BUG_FOUND") {
                int bval;
                cin>>bval;
                bf+=bval;
            }
            else if(s=="CONTEST_HOSTED") cnhst++;
            else cout<<"error"<<'\n';
        }
        res=cwon+(tcon*300)+bf+(cnhst*50);
        if(ind) cout<<(res/200)<<'\n';
        else cout<<(res/400)<<'\n';
    }
    return 0;
}