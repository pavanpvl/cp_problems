#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("../a.in", "r", stdin);
    freopen("../a.out", "w", stdout);
#endif
    int t{},ts{1};
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> str(n);
        vector<string> pre(n);
        vector<string> suf(n);
        for (int i = 0; i < n; i++)
            cin >> str[i];
        for (int i = 0; i < n; i++)
        {
            for (auto j = str[i].begin(); *j != '*';)
            {
                pre[i] += *j;
                j = str[i].erase(j);
            }

            for (auto j = str[i].end() - 1; *j != '*'; j--)
            {
                suf[i] += *j;
                j = str[i].erase(j);
            }
            str[i].erase(str[i].find_first_of('*'), 1);
            if (str[i].find_last_of('*') != string::npos)
            {
                str[i].erase(str[i].find_last_of('*'), 1);
            }
            // cout << str[i] << '\n';
        }

        /* for(int i=0;i<n;i++){
            cout<<pre[i]<<' '<<suf[i]<<'\n';
        } */
        int lpre{}, lsuf{}, flag{};
        //cout<<'a';
        for (int i = 1; i < n; i++)
        {
            int spre, a, b;
            spre = lpre;
            a = pre[lpre].length();
            b = pre[i].length();
            if (a > b)
                spre = i;
            else
                lpre = i;
            if (pre[lpre].substr(0, pre[spre].length()) != pre[spre])
            {
                cout << "*";
                flag = 1;
                break;
            }

            /* {
                lpre = > pre[i].length() ? lpre : i;
                spre = pre[lpre].length() <= pre[i].length() ? lpre : i;

                for (int k = 0; k < pre[spre].length(); k++)
                {
                    if (pre[lpre][k] != pre[spre][k])
                    {
                        cout << "*pre";
                        return 0;
                    }
                }
            } */
        }
        if (flag)
            continue;
        for (int i = 1; i < n; i++)
        {
            int ssuf, a, b;
            ssuf = lsuf;
            a = suf[lsuf].length();
            b = suf[i].length();
            if (a > b)
                ssuf = i;
            else
            {
                lsuf = i;
                b = a;
            }
            if (suf[lsuf].substr(0, b) != suf[ssuf])
            {
                cout << "*";
                flag = 1;
                break;
            }

            /* {
                int ssuf;
                ssuf = suf[lsuf].length() <= suf[i].length() ? lsuf : i;
                lsuf = suf[lsuf].length() > suf[i].length() ? lsuf : i;
                //cout << lsuf << ' ' << ssuf << '\n';
                for (int k = 0; k < suf[ssuf].length(); k++)
                {
                    if (suf[lsuf][k] != suf[ssuf][k])
                    {
                        cout << "*suf";
                        flag = 1;
                        break;
                    }
                }
            } */
        }
        if (flag)
            continue;
        string res{},rsuf{};
        for (int i = 0; i < n; i++)
        {
            while(str[i].find('*')!=string::npos)
            {
                 str[i].erase(str[i].find('*'), 1);
            }
            res += str[i];
        }
        for(int i=suf[lsuf].length()-1;i>=0;i--){
            if(suf[lsuf][i]=='*') continue;
            rsuf+=suf[lsuf][i];
        }
        //cout << res << '\n';
        cout <<"Case #"<<ts<<": "<< pre[lpre] << res << rsuf << '\n';
        ts++;
    }
    return 0;
}