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
    int t{};
    cin >> t;
    while (t--)
    {
        int a[10][10];
        

        for (int i = 1; i <= 9; i++)
        {
            string s;
            cin>>s;
           // cout<<s
            for (int j = 1; j <= 9; j++)
            {
                a[i][j]=static_cast<int>(s[j-1]-'0');
            } 
        }

        a[1][1] = (a[1][1]) % 9 + 1;
        a[2][4] = (a[2][4]) % 9 + 1;
        a[3][7] = (a[3][7]) % 9 + 1;
        a[4][2] = (a[4][2]) % 9 + 1;
        a[5][5] = (a[5][5]) % 9 + 1;
        a[6][8] = (a[6][8]) % 9 + 1;
        a[7][3] = (a[7][3]) % 9 + 1;
        a[8][6] = (a[8][6]) % 9 + 1;
        a[9][9] = (a[9][9]) % 9 + 1; 
        for (int i = 1; i <= 9; i++)
        {

            for (int j = 1; j <= 9; j++)
            {
                cout << a[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}