#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("../../a.in", "r", stdin);
    freopen("../../a.out", "w", stdout);
#endif
    int n{};
    string s;
    cin >> n;
    s.assign(n, '1');
    for (int i = 0; i < n; i++)
        cin >> s[i];
    stack<char> stk;
    int md{}, mdpos{}, ml{}, mlpos{};
    int cd{}, cl{}, cpos{};
    for (int i = 0; i <= n; i++)
    {
        if (stk.empty())
        {
            mlpos = (ml >= cl) ? mlpos : cpos;
            ml = max(ml, cl);
            cd = 0;
            cl = 0;
            cpos = i + 1;
            if (i == n)
                break;
        }
        if (s[i] == '1')
        {
            stk.push(s[i]);
            cd++;
            cl++;
            mdpos = (md >= cd) ? mdpos : i + 1;
            md = max(md, cd);
        }
        else if (s[i] == '2')
        {
            stk.pop();
            cd--;
            cl++;
        }
    }
    cout << md << " " << mdpos << " " << ml << " " << mlpos << "\n";
    return 0;
}