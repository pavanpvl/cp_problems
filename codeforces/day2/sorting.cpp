#include <iostream>

using namespace std;

/*
void sort(int *a, int s, int e)
{
    int mn, pos, tmp;
    for (int i = s; i < e - 1; i++)
    {
        mn = a[i];
        pos = i;
        for (int j = i + 1; j < e; j++)
        {
            if (mn > a[j])
            {
                mn = a[j];
                pos = j;
            }
        }
        tmp = a[i];
        a[i] = a[pos];
        a[pos] = tmp;
    }
}
*/
void swap(int *a,int i,int j)
{
    int t;
    t=a[i];
    a[i]=a[j];
    a[j]=t;
}
int partition(int *a,int s,int e)
{
    int i,j,k;
    i=s;
    j=s+1;
    k=e-1;
    while(j<=k)
    {
        if(a[j]==a[i]) j++;
        else if(a[j]<a[i]){
            swap(a,i,j);
            i++;
            j++;
        }
        else {
            swap(a,j,k);
            k--;
        }
    }
    return i;
}

void sort(int *a,int s,int e)
{
    if(e-s<=1) return;
    int p;
    p=partition(a,s,e);
    sort(a,s,p);
    sort(a,p+1,e);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/pavan/cp_problems/a.in", "r", stdin);
    freopen("/home/pavan/cp_problems/a.out", "w", stdout);
#endif
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, 0, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << "\n";
}