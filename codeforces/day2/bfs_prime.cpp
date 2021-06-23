#include <iostream>
#include <cstring>
class queue
{
private:
    int a[5000];
    int n = 5000;
    int start = 0;
    int end = 0;

public:
    bool isempty()
    {
        if (start == end)
            return true;
        else
            return false;
    }
    bool isfull()
    {
        if ((end + 1) % n == start)
            return true;
        else
            return false;
    }
    void pushback(int value)
    {
        if (isfull())
        {
            std::cout << "Queue Full\n";
            return;
        }
        a[end] = value;
        end = (end + 1) % n;
    }
    int popfront()
    {
        if (isempty())
        {
            std::cout << "Queue empty\n";
            return -1;
        }
        int value = a[start];
        start = (start + 1) % n;
        return value;
    }
    int front()
    {
        if (isempty())
        {
            std::cout << "Queue empty\n";
            return -1;
        }
        int value = a[start];
        return value;
    }
};

int bfs(int x, int y, bool *a)
{
    queue q;
    q.pushback(x);
    q.pushback(-1);
    int l = 0;
    int vis[10000];
    memset(vis, 0, sizeof(vis));
    vis[x] = 1;
    while ((!q.isempty()) && l<10)
    {
        if (q.front() == -1)
        {
            q.popfront();
            q.pushback(-1);
            l++;
            continue;
        }
        if (q.front() == y)
            return l;
        else
        {
            int val = q.popfront();
            int num[4], temp, ten[4], tn = 1;
            temp = val;
            for (int i = 0; i < 4; i++)
            {
                ten[i] = tn;
                tn *= 10;
                num[i] = (temp % 10);
                temp /= 10;
            }
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    if (i == 3 && j == 0)
                        continue;
                    int nval = val - (num[i] - j) * ten[i];
                    if (a[nval] && (!vis[nval]))
                    {
                        vis[nval] = 1;
                        q.pushback(nval);
                    }
                }
            }
        }
    }
    return -4;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/pavan/cp_problems/a.in", "r", stdin);
    freopen("/home/pavan/cp_problems/a.out", "w", stdout);
#endif
    bool a[10000];
    int n = 9999;
    memset(a, true, sizeof(a));
    a[0] = false;
    a[1] = false;
    for (int p = 2; p * p <= n; p++)
    {
        if (a[p])
        {
            for (int i = p * p; i <= n; i = i + p)
            {
                a[i] = false;
            }
        }
    }
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        int x, y;
        std::cin >> x >> y;
        if (x == y)
        {
            std::cout << 0 << "\n";
            continue;
        }
        std::cout << bfs(x, y, a)<<"\n";
    }
}