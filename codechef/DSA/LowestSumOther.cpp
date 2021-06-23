    #include <bits/stdc++.h>

    #define DEBUG

    using namespace std;

    void solve()
    {
        int k, q, s;
        cin >> k >> q;
        cout<<k<<" "<<q<<"\n";
        vector<long long> a(k, 0);
        vector<long long> b(k, 0);
        for (int i = 0; i < k; i++)
            cin >> a[i];
        for (int i = 0; i < k; i++)
            cin >> b[i];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        priority_queue<long long> pq;
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                if (pq.size() < 10000)
                {
                    pq.push(a[i] + b[j]);
                }
                else if (a[i] + b[j] < pq.top())
                {
                    pq.pop();
                    pq.push(a[i] + b[i]);
                }
                else
                    break;
            }
        }
        vector<long long> res(10000, 0);
        int n = pq.size();
        for (int i = 0; i < n; i++)
        {
            res[i] = pq.top();
            pq.pop();
        }
        reverse(res.begin(), res.begin()+n);
        for (int i = 0; i < q; i++)
        {
            int Q;
            cin>>Q;
            cout<<res[Q-1]<<"\n";
        }
    }

    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("/home/pavan/cp_problems/a.in", "r", stdin);
        freopen("/home/pavan/cp_problems/a.out", "w", stdout);
    #endif

        int t{};
        cin >> t;

        while (t--)
        {
            solve();
        }

        return 0;
    }