#include <iostream>
struct Node
{
    int data;
    struct Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insert(Node **head, int val)
{
    Node *n = new Node(val);
    n->next = *head;
    *head = n;
}

void printlist(Node *head)
{
    Node *cur = head;
    if (head == NULL)
        std::cout << "Empty\n";
    while (cur != NULL)
    {
        std::cout << cur->data << "\n";
        cur = cur->next;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("/home/pavan/cp_problems/a.in", "r", stdin);
    freopen("/home/pavan/cp_problems/a.out", "w", stdout);
#endif
    int n, val;
    std::cin >> n;
    Node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        std::cin >> val;
        insert(&head, val);
    }
    printlist(head);
    return 0;
}
