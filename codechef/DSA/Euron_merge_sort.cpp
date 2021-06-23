#include <bits/stdc++.h>

#define DEBUG

using namespace std;

long long mergetry(vector<int> &a, int f, int l, int mid);

long long mergesort(vector<int> &a, int f, int l)
{
    if (l == f)
        return 0;
    int mid = f + (l - f) / 2; //floor (l+f)/2
    long long fv{}, lv{}, mv{};
    fv = mergesort(a, f, mid);
    lv = mergesort(a, mid + 1, l);
    mv = mergetry(a, f, l, mid);
    //cout<<fv<<" "<<lv<<" "<<mv<<" "<<l<<" "<<f<<" "<<mid<<"\n";
    return fv + lv + mv;
}

long long mergetry(vector<int> &a, int f, int l, int mid)
{
    int left = mid - f + 1;
    int right = l - mid;
    int k;
    long long res{};
    int lf[left], rg[right];
    for (int i = 0; i < left; i++)
        lf[i] = a[i + f];
    for (int i = 0; i < right; i++)
        rg[i] = a[i + mid + 1];
        
    int i=left;
    int j=right;
    left = 0;
    right = 0;
    k = f;
    while ((left <i) && (right <j))
    {
        if (lf[left] <= rg[right])
            a[k++] = lf[left++];
        else
        {
            res += i-left;
            a[k++] = rg[right++];
        }
    }
    while (left != i)
    {
        a[k++] = lf[left++];
    }
    while (right != j)
    {
        a[k++] = rg[right++];
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("/home/pavan/cp_problems/a.in", "r", stdin);
    freopen("/home/pavan/cp_problems/a.out", "w", stdout);
#endif

    int n{};
    cin >> n;
    vector<int> a(n, 0);
    long long res{};
    for (int i = 0; i < n; i++)
        cin >> a[i];
    res = mergesort(a, 0, n - 1);
    cout << res << "\n";
    return 0;
}