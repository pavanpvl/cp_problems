#include <bits/stdc++.h>

#define DEBUG

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("/home/pavan/cp_problems/a.in", "r", stdin);
    freopen("/home/pavan/cp_problems/a.out", "w", stdout);
#endif

    int n{}, m{};
    cin >> n >> m;
    map<string, int> namcnt;
    map<string, string> namnat;
    map<string, int> natcnt;
    for (int i = 0; i < n; i++)
    {
        string s, x;
        cin >> s >> x;
        namnat[s] = x;
        namcnt[s] = 0;
        natcnt[x] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        namcnt[s] += 1;
        natcnt[namnat[s]] += 1;
    }
    int mx={INT_MIN};
    string mnat{};
    for (auto i = natcnt.begin(); i != natcnt.end(); i++)
    {
        int curv;
        string curs;
        curv=(*i).second;
        curs=(*i).first;
        if(mx==curv){
            mnat=(mnat<curs)?mnat:curs;
        }
        else if(mx<curv){
            mnat=curs;
            mx=curv;
        }        
    }
    cout<<mnat<<"\n";
    mnat={};
    mx=INT_MIN;
    for (auto i = namcnt.begin(); i != namcnt.end(); i++)
    {
        int curv;
        string curs;
        curv=(*i).second;
        curs=(*i).first;
        if(mx==curv){
            mnat=(mnat<curs)?mnat:curs;
        }
        else if(mx<curv){
            mnat=curs;
            mx=curv;
        }        
    }
    cout<<mnat<<"\n";
}