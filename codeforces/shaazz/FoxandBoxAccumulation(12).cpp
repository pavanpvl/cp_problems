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

    int n{};
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    //for(int i=0;i<n;i++) cout<<a[i]<<" ";
    vector<vector<int>> v;
    vector<int> temp;
    temp.push_back(a[0]);
    for (int i = 0; i < n; i++)
    {
        int f{0};
        for (int j = 0; j < v.size(); j++)
        {
            if (v[j].size() > a[i])
                continue;
            else
            {
                f = 1;
                v[j].push_back(a[i]);
                break;
            }
        }
        if (f == 0)
        {
            vector<int> t;
            t.push_back(a[i]);
            v.push_back(t);
        }
    }
    /*
    for (int j = 0; j < v.size(); j++)
    {
        for (int i = 0; i < v[j].size(); i++)
        {
            cout<<v[j][i]<<" ";
        }
        cout<<"\n";
    }
    */
    cout << v.size();
    return 0;
}