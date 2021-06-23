#include <iostream>
#define DEBUG

struct node
{
    int s;
    int f;
    int ind;
};

bool greater(node a, node b)
{
    if (a.f > b.f)
        return 1;
    else if ((a.f == b.f) && (a.s > b.s))
        return 1;
    else
        return 0;
}

int partition(node *arr, int start, int end)
{
    int i, j, k;
    node temp = arr[start];
    node temp1;
    i = start;
    j = start + 1;
    k = end - 1;
    while (j <= k)
    {
        if (greater(arr[j], temp))
        {
            temp1 = arr[j];
            arr[j] = arr[k];
            arr[k] = temp1;
            k--;
        }
        else
        {
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j++;
        }
    }
    return i;
}

void sort(node *arr, int start, int end)
{
    if (start + 1 >= end)
        return;
    int pos;
    pos = partition(arr, start, end);
    //std::cout<<pos<<"\n";
    sort(arr, start, pos);
    sort(arr, pos + 1, end);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("/home/pavan/cp_problems/a.in", "r", stdin);
    freopen("/home/pavan/cp_problems/a.out", "w", stdout);
#endif
    int t{};
    std::cin >> t;
    while (t--)
    {
        int n;
        std::cin >> n;
        node *arr = new node[n];
        for (int i = 0; i < n; i++)
        {
            std::cin >> arr[i].s;
            arr[i].ind = i + 1;
        }
        for (int i = 0; i < n; i++)
        {
            std::cin >> arr[i].f;
        }
        sort(arr, 0, n);
        /*
        for (int i = 0; i < n; i++)
        {
            std::cout << arr[i].s << " " << arr[i].f << "\n";
        }
        */
        int lf = arr[0].f;
        std::cout << arr[0].ind<<" ";
        for (int i = 1; i < n; i++)
        {
            if (arr[i].s >= lf)
            {
                std::cout<<arr[i].ind<<" ";
                lf=arr[i].f;
            }
        }
        std::cout<<"\n";
    }

    return 0;
}