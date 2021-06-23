    #include <bits/stdc++.h>

    using namespace std;

    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("a.in", "r", stdin);
        freopen("a.out", "w", stdout);
    #endif
        int t{};
        cin >> t;
        while (t--)
        {
            int n;
            vector<int> v;
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                int k;
                cin >> k;
                if (k & 1)
                {
                    v.push_back(0);
                }
                else if ((k >> 1) & 1)
                {
                    v.push_back(1);
                }
                else
                    v.push_back(2);
            }

            /* for(int i=1;i<n;i++){
                v[i]+=v[i-1];
                //if(v[i]>2) v[i]=2;
            } */
            vector<tuple<int, int, int>> d;
            int prev = v[0];
            int cnt{}, i;
            long long res{}, temp{};
            for (i = 0; i < n; i++)
            {
                if (v[i] == prev)
                    cnt++;
                else
                {
                    d.push_back(make_tuple(prev, cnt, i - cnt));
                    cnt = 1;
                    prev = v[i];
                }
            }
            d.push_back(make_tuple(prev, cnt, i - cnt));
            for (i = 0; i < d.size(); i++)
            {
                int val;
                temp = get<1>(d[i]);
                val = get<0>(d[i]);
                if (val != 1)
                    temp *= (temp + 1);
                else
                    temp *= temp - 1;
                temp = temp / 2;
                res += temp;
            }
            //cout << res << '\n';
            int s, j;
            for (i = 0; i < d.size() - 1; i++)
            {
                int ccnt{}, cval{}, cpos{}, ncnt{}, nval{}, npos{};
                ccnt = get<1>(d[i]);
                cval = get<0>(d[i]);
                cpos = get<2>(d[i]);
                ncnt = get<1>(d[i + 1]);
                nval = get<0>(d[i + 1]);
                npos = get<2>(d[i + 1]);
                switch (cval)
                {
                case 2:
                    res += (n - npos) * ccnt;
                    break;
                case 0:
                    j = i + 2;
                    s = 1;
                    if (nval == 1 && ncnt < 2)
                    {
                        while (j < d.size() && s < 2)
                        {
                            s += (get<0>(d[j])) * (get<1>(d[j]));
                            j++;
                        }
                        j--;
                        if (s >= 2)
                            res += (n - get<2>(d[j]))*ccnt;
                    }
                    else if (nval == 1)
                    {
                        res += (n - (npos + 1)) * ccnt;
                    }
                    else
                        res += (n - npos) * ccnt;
                    break;
                case 1:
                    //int end = i + ccnt - 1;
                    res += (n - npos) * (ccnt - 1);
                    j = i + 1;
                    s = 1;
                    while (j < d.size() && s < 2)
                    {
                        s += (get<0>(d[j])) * (get<1>(d[j]));
                        j++;
                    }
                    j--;
                    if (s >= 2)
                    {
                        res += n - get<2>(d[j]);
                        //cout<<get<0>(d[j]) << 'y' << res << '\n';
                    }
                    break;
                default:
                    cout << "error";
                    break;
                }
            }
            cout << res << '\n';
            /*  for (auto e : d)
            {
                cout << get<0>(e) << ' ' << get<1>(e) << ' ' << get<2>(e) << '\n';
            } */
        }
        return 0;
    }