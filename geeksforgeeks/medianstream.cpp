#include <bits/stdc++.h>

using namespace std;

void median(priority_queue<int> &maxh, priority_queue<int, vector<int>, greater<int>> &minh, const int &x)
{
    if (maxh.empty() && minh.empty())
    {
        maxh.push(x);
        cout << x << '\n';
        return;
    }
    else if (maxh.empty())
    {
        int median = minh.top();
        if (median > x)
            maxh.push(x);
        else
        {
            maxh.push(minh.top());
            minh.pop();
            minh.push(x);
        }
        median = (maxh.top() + minh.top()) / 2;
        cout << median << '\n';
    }
    else if (minh.empty())
    {
        int median = maxh.top();
        if (median < x)
            minh.push(x);
        else
        {
            minh.push(maxh.top());
            maxh.pop();
            maxh.push(x);
        }
        median = (maxh.top() + minh.top()) / 2;
        cout << median << '\n';
    }
    else
    {
        int median, l, r;
        l = maxh.size();
        r = minh.size();
        switch (l - r)
        {
        case 0:
            median = (maxh.top() + minh.top()) / 2;
            if (x > median)
            {
                minh.push(x);
                cout << minh.top() << '\n';
            }
            else
            {
                maxh.push(x);
                cout << maxh.top() << '\n';
            }
            break;
        case 1:
            median = maxh.top();
            if (x < median)
            {
                minh.push(maxh.top());
                maxh.pop();
                maxh.push(x);
            }
            else
                minh.push(x);
            median = (maxh.top() + minh.top()) / 2;
            cout << median << '\n';
            break;
        case -1:
            median = minh.top();
            if (x > median)
            {
                maxh.push(minh.top());
                minh.pop();
                minh.push(x);
            }
            else
                maxh.push(x);
            median = (maxh.top() + minh.top()) / 2;
            cout << median << '\n';
            break;
        default:
            cout << "error" << '\n';
            break;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    int n, x;
    cin >> n;
    priority_queue<int, vector<int>> maxh;
    priority_queue<int, vector<int>, greater<int>> minh;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        median(maxh, minh, x);
    }
    return 0;
}