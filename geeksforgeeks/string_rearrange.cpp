#include <bits/stdc++.h>

using namespace std;
class Compare
{
public:
    bool operator() (const pair<char,int> &a,const pair<char,int> &b)
    {
        return a.second<b.second;
    }
};
/*
bool Compare(const pair<char, int> &a, const pair<char, int> &b)
{
    return a.second < b.second;
}
*/
int main()
{
/*  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    */
/*     freopen("a.in", "r", stdin);
    freopen("a.txt", "w", stdout); */
    int t;
    cin >> t;
    while (t--)
    {
        string s,res;
        cin >> s;
        //priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(&Compare)> v(Compare);
        priority_queue<pair<char, int>, vector<pair<char, int>>,Compare> v;
        int a[26];
        for (int &i : a)
            i = 0;
        for (char c : s)
        {
            int k = c - 'a';
            //cout<<k<<' '<<c<<'\n';
            a[k]++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (a[i] > 0)
            {
                //cout<<a[i]<<' ';
                char q = static_cast<char>(97 + i);
                v.push(make_pair(q, a[i]));
            }
        }
        pair<char,int> prev,temp;
        prev.second=-1;
        prev.first='#';
        while(!v.empty())
        {
            temp=v.top();
            v.pop();
            if(prev.second>0){
                v.push(prev);
            }
            res+=temp.first;
            temp.second-=1;
            prev=temp;
        }
        cout<<(res.size()==s.size())<<'\n';
        //cout<<res<<'\n';
        /* while (!v.empty())
        {
            cout << '\t' << v.top().first << v.top().second;
            v.pop();
        }
        cout << '\n'; */
    }
    return 0;
}