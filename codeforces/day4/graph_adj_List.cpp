#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> v[], int a, int b)
{
    v[a].push_back(b);
    v[b].push_back(a);
}
void printgraph(vector<int> v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for(auto j:v[i]) cout<<j<<" ";
        cout<<"\n";
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
    int n;
    cin >> n;
    vector<int> graph[n];
    for (int i = 0; i < n; i++)
    {
        int a, b;
        std::cin >> a >> b;
        addEdge(graph, a, b);
    }
    printgraph(graph, n);
}