#include <bits/stdc++.h>

#define DEBUG

using namespace std;

struct Node
{
    int data;
    Node *l = NULL;
    Node *r = NULL;
};

class Tree
{
public:
    Tree();
    ~Tree();
    void insert(int val);
    Node *search(int val); //returns a pointer to the node if it exists otherwise Null
    void print();

private:
    void delTree(Node *leaf);
    Node *search(int val, Node *leaf);
    void print(Node *leaf);
    //void insert(int val, Node *leaf);
    Node *root;
};
Tree::Tree()
{
    root = NULL;
}
Tree::~Tree()
{
    delTree(root);
}
void Tree::print()
{
    cout<<"\n";
    print(root);
    cout<<"\n";
}
void Tree::print(Node *leaf)
{
    if(leaf==NULL) return;
    print(leaf->l);
    cout<<leaf->data<<" ";
    print(leaf->r);
}
void Tree::delTree(Node *leaf)
{
    if (leaf == NULL)
        return;
    delTree(leaf->l);
    delTree(leaf->r);
    delete (leaf);
}

/* void Tree::insert(int val)
{
    insert(val, root);
} */
Node *Tree::search(int val)
{
    return search(val, root);
}

Node *Tree::search(int val, Node *leaf)
{
    if (leaf == NULL)
        return NULL;
    if (leaf->data == val)
        return leaf;
    else if (val >= leaf->data)
        return search(val, leaf->r);
    else
        return search(val, leaf->l);
}

void Tree::insert(int val)
{
    Node *p, *c;
    p = NULL;
    c = root;
    if (c == NULL)
    {
        c = new Node;
        c->data = val;
        root = c;
        return;
    }
    while (c != NULL)
    {
        p = c;
        if (val >= c->data)
            c = c->r;
        else
            c = c->l;
    }
    c = new Node;
    c->data = val;
    if (p->data <= val)
        p->r = c;
    else
        p->l = c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("/home/pavan/cp_problems/a.in", "r", stdin);
    freopen("/home/pavan/cp_problems/a.out", "w", stdout);
#endif
    Tree t;
    Node *p;
    t.insert(1);
    t.insert(3);
    t.insert(2);
    t.insert(10);
    t.insert(5);
    p = t.search(3);
    t.print();
    if (p == NULL)
        cout << "NOT FOUND\n";
    else
        cout << "FOUND"
             << "\n";
    return 0;
}