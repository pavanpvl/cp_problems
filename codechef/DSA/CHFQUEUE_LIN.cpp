#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int g_m = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("/home/pavan/cp_problems/a.in", "r", stdin);
    freopen("/home/pavan/cp_problems/a.out", "w", stdout);
#endif

    int n{}, k{};
    long long  res{1};
    cin >> n >> k;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    stack<pair<int, int>> st;
    st.push(make_pair(-1, -1));
    for (int i = 0; i < n; i++)
    {
        int temp = st.top().first;
        if (temp == -1 || temp <= v[i])
            st.push(make_pair(v[i], i));
        else
        {
            while (temp > v[i] && temp != -1)
            {
                res=(res*(i-st.top().second+1))%g_m;
                st.pop();
                temp=st.top().first;
            }
            st.push(make_pair(v[i],i));
        }
    }
    cout << res << "\n";

    return 0;
}