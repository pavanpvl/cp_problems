#include <iostream>

using namespace std;

struct Node
{
    int d;
    struct Node *l = NULL;
    struct Node *r = NULL;
};

void traversal(Node *root)
{
    if (root == NULL)
        return;
    //cout << root->d << "\n";
    traversal(root->l);
    //cout << root->d << "\n";
    traversal(root->r);
    cout << root->d << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/home/pavan/cp_problems/a.in", "r", stdin);
    freopen("/home/pavan/cp_problems/a.out", "w", stdout);
#endif
    Node *root=new Node;
    root->d = 10;
    root->l = new Node;
    root->l->d = 20;
    root->r = new Node;
    root->r->d = 30;
    root->l->l=new Node;
    root->l->l->d=40;
    root->l->r=new Node;
    root->l->r->d=50;
    root->r->l=new Node;
    root->r->l->d=60;
    root->l->l->r=new Node;
    root->l->l->r->d=70;
    traversal(root);
    return 0;
}