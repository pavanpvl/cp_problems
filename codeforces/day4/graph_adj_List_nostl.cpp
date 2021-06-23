#include <iostream>

struct adjlistnode
{
    int val;
    struct adjlistnode *next;
    adjlistnode(int x)
    {
        val = x;
        next = NULL;
    }
};

struct adjlist
{
    struct adjlistnode *head;
};

struct graph
{
    int V;
    struct adjlist *array;
    graph(int n)
    {
        V = n;
        array = new adjlist[n];
    }
};

void printgraph(graph *g)
{
    int n = g->V;
    for (int i = 0; i < n; i++)
    {
        adjlistnode *cur = g->array[i].head;
        while (cur != NULL)
        {
            std::cout << cur->val << " ";
            cur = cur->next;
        }
        std::cout << "\n";
    }
}
void addEdge(graph *g,int a,int b)
{
    adjlistnode *nnode = new adjlistnode(a);
    nnode->next = g->array[b].head;
    g->array[b].head = nnode;
    adjlistnode *nnode1 = new adjlistnode(b);
    nnode1->next = g->array[a].head;
    g->array[a].head = nnode1;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/pavan/cp_problems/a.in", "r", stdin);
    freopen("/home/pavan/cp_problems/a.out", "w", stdout);
#endif
    int ne,nv;
    std::cin >> nv>>ne;
    struct graph *g = new graph(nv);
    for (int i = 0; i < nv; i++)
    {
        g->array[i].head = NULL;
    }
    /*
    adjlistnode *nnode = new adjlistnode(1);
    nnode->next = g->array[0].head;
    g->array[0].head = nnode;
    */
    for (int i = 0; i < ne; i++)
    {
        int a, b;
        std::cin >> a >> b;
        addEdge(g, a, b);
    }
    printgraph(g);
}