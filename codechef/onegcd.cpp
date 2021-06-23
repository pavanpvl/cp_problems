#include <bits/stdc++.h>

using namespace std;

/* 
int gcd(int a, int b)
{
    if (a == b)
        return a;

    // GCD(0, b) == b; GCD(a, 0) == a,
    // GCD(0, 0) == 0
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    // look for factors of 2
    if (~a & 1) // a is even
    {
        if (b & 1) // b is odd
            return gcd(a >> 1, b);
        else // both a and b are even
            return gcd(a >> 1, b >> 1) << 1;
    }

    if (~b & 1) // a is odd, b is even
        return gcd(a, b >> 1);

    // reduce larger number
    if (a > b)
        return gcd((a - b) >> 1, b);

    return gcd((b - a) >> 1, a);
} */
#define MAXN 1000001
int spf[MAXN];

void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)

        // Marking smallest prime factor for every
        // number to be itself
        spf[i] = i;

    // Separately marking spf for every even
    // number as 2
    for (int i = 4; i < MAXN; i += 2)
        spf[i] = 2;

    // Checking if i is prime
    for (int i = 3; i * i < MAXN; i++)
    {

        // Marking SPF for all numbers divisible by i
        if (spf[i] == i)
        {
            for (int j = i * i; j < MAXN; j += i)

                // Marking spf[j] if it is not
                // previously marked
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

void primefact(vector<int> &p, int x)
{
    int temp;
    while (x != 1)
    {
        temp = spf[x];
        if (x % temp == 0)
        {
            p.push_back(spf[x]);
            x = x / spf[x];
        }
        while (x % temp == 0)
            x = x / temp;
    }
}
void printres(vector<vector<int>> &v)
{
    cout << v.size() << '\n';
    for (unsigned i = 0; i < v.size(); i++)
    {
        cout << v[i].size() << ' ';
        for (unsigned j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
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
    sieve();
    int t{};
    cin >> t;
    while (t--)
    {
        int n{};
        cin >> n;
        vector<unordered_set<int>> hash;
        vector<vector<int>> res;
        vector<int> temp;
        temp.push_back(1);
        for (int i = 2; i <= n; i += 2)
        {
            vector<int> prime;
            primefact(prime, i);
            unordered_set<int> mid;
            for (auto e : prime)
            {
                if (mid.find(e) != mid.end())
                {
                    mid.insert(e);
                }
            }
            hash.push_back(mid);
            temp.push_back(i);
            res.push_back(temp);
            temp.clear();
        }
        for (int i = 3; i <= n; i+=2)
        {
            vector<int> prime;
            primefact(prime, i);
            int cnt = 0;
            for (unsigned j = 0; j < hash.size(); j++)
            {
                int flag = 0;
                for (auto e : prime)
                {
                    if (hash[j].find(e) != hash[j].end())
                    {
                        flag = 1;
                        cnt++;
                        break;
                    }
                }
                if (flag)
                {
                    continue;
                }
                else
                {
                    for (auto e : prime)
                    {
                        if (hash[j].find(e) == hash[j].end())
                            hash[j].insert(e);
                    }
                    res[j].push_back(i);
                    break;
                }
            }
            if (cnt == hash.size())
            {
                unordered_set<int> mid;
                for (auto e : prime)
                {
                    if (mid.find(e) != mid.end())
                    {
                        mid.insert(e);
                    }
                }
                hash.push_back(mid);
                temp.clear();
                temp.push_back(i);
                res.push_back(temp);
            }
        }
        printres(res);
    }

    return 0;
}
/*
{
    int time{};
        set<int> v;
        for (int i = 1; i <= n; i++)
            v.insert(i);
        //int hash[n+1][n+1];
        vector <vector<int>> r;
        while (v.size() != 0 )
        {
            vector <int> res;
            for (auto i = v.begin(); i != v.end(); i++)
            {
                int cnt=0;
                for(int j=0;j<res.size();j++){
                    if(gcd(res[j],*i)!=1) break;
                    else cnt++;
                }
                if(cnt==res.size()) {
                    res.push_back(*i);
                    v.erase(*i);
                }
            }
            r.push_back(res);
        }
        cout<<r.size()<<'\n';
        for(unsigned int i=0;i<r.size();i++){
            cout<<r[i].size()<<' ';
            for(unsigned int j=0;j<r[i].size();j++){
                cout<<r[i][j]<<' ';
            }
            cout<<'\n';
        }
}
*/