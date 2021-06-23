#include <bits/stdc++.h>

using namespace std;
void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int mpartition(vector<int> &v, int p, int q)
{
    int i = p - 1;
    int r = (rand() % (q - p + 1)) + p;
    swap(v[r], v[q]);
    int x = v[q];
    for (int j = p; j < q; j++)
    {
        if (v[j] <= x)
        {
            i = i + 1;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[q]);
    return i + 1;
}
void quicksort(vector<int> &v, int p, int q)
{
    if (q - p + 1 <= 1)
        return;
    int r;
    r = mpartition(v, p, q);
    quicksort(v, p, r - 1);
    quicksort(v, r + 1, q);
}

int main()
{
    clock_t start, end;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(0));

#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = n - 1; i > 0; i--)
    {
        v[i] = rand()%n;
    }
    //time(&start);
    start=clock();
    quicksort(v, 0, n - 1);
    //for(auto e:v) cout<<e<<' ';
    //cout<<'\n';
    //time(&end);
    end=clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
    cout << "Time taken by program is : " << fixed  
         << time_taken << setprecision(5); 
    cout << " sec " << endl;
    return 0;
}