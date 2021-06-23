#include <bits/stdc++.h>

using namespace std;

void max_heapify(vector<int> &v, const int &i, const int &n)
{
    int left, right, maxindex;
    left = 2 * i + 1;
    right = left + 1;
    if (left < n && v[left] > v[i])
        maxindex = left;
    else
        maxindex = i;
    if (right < n && v[right] > v[maxindex])
        maxindex = right;
    if (maxindex != i)
    {
        swap(v[i], v[maxindex]);
        max_heapify(v, maxindex, n);
    }
}

void buildmaxHeap(vector<int> &v, const int &heapsize)
{
    int n = heapsize;
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        max_heapify(v, i, n);
    }
}
void heapsort(vector<int> &v, const int &heapsize)
{
    buildmaxHeap(v, heapsize);
    for (int i = heapsize - 1; i >= 1; i--)
    {
        swap(v[i], v[0]);
        max_heapify(v, 0, i);
    }
}

int main()
{
    clock_t start,end;
    time(&start);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    int n;
    cin>>n;
    vector<int> v(n,0);
    for (int i = n-1; i >0; i--)
    {
        v[i]=rand()%n;
    }
    //time(&start);
    start=clock();
    heapsort(v, n);
    //for(auto const &i:v) cout<<i<<' ';
    //cout<<'\n';
    //time(&end);
    end=clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
    cout << "Time taken by program is : " << fixed  
         << time_taken << setprecision(5); 
    cout << " sec " << endl;
    return 0;
}