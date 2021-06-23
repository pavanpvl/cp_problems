#include <bits/stdc++.h>

using namespace std;
int prec(char a)
{
    switch (a)
    {
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}

void solve(string &s)
{
    int n;
    string in{};
    stack<char> ops;
    cin >> n >> in;
    for (int i = 0; i < n; i++)
    {
        if (in[i] >= 'A' && in[i] <= 'Z')
        {
            s += in[i];
        }
        else
        {
            if (ops.empty())
            {
                ops.push(in[i]);
            }
            else if (ops.top() == '(' || in[i] == '(')
                ops.push(in[i]);
            else if (in[i] == ')')
            {
                while (ops.top() != '(' && (!ops.empty()))
                {
                    s += ops.top();
                    ops.pop();
                }
                if (!ops.empty())
                    ops.pop();
            }
            else
            {
                int prect,preci;
                preci=prec(in[i]);
                prect=prec(ops.top());
                if(preci==-1){ 
                    cout<<"error\n";
                    return;
                }
                while(preci<=prect&&(!ops.empty())){
                    s +=ops.top();
                    ops.pop();
                    if(!ops.empty())
                        prect=prec(ops.top());
                }
                ops.push(in[i]); 
            }
        }
    }
    while(!ops.empty()){
        s+=ops.top();
        ops.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("../../a.in", "r", stdin);
    freopen("../../a.out", "w", stdout);
#endif
    int t{};
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string s{};
        solve(s);
        cout<<s<<'\n';
    }

    return 0;
}