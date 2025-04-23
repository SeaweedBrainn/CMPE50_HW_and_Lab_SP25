#include <iostream>
using namespace std;

class Node
{
public:
    Node();
    Node(int val);
    int getValue();
    Node *getLink();
    void setLink(Node &nd);
    friend void insert(Node* &head, Node *nd);
    friend ostream& operator << (ostream &ost, Node *head);
private:
    int value;
    Node *link;
};
Node::Node() : value(0), link(NULL)
{   }
Node::Node(int val) : value(val), link(NULL)
{   }
Node* Node::getLink()
{
    return this->link;
}
int Node::getValue()
{
    return this->value;
}
void Node::setLink(Node &nd)
{
    this->link = &nd;
}
void insert(Node* &head, Node *nd)
{
    if (head == NULL) {
        head = nd;
        nd -> link = NULL;
        return;
    }

    if (nd->value < head->value)
    {
        nd->link = head;
        head = nd;
        return;
    }

    Node *cur = head;
    while(cur->link != NULL && cur->link->value < nd->value)
    {
        cur = cur->link;
    }
    nd->link = cur->link;
    cur->link = nd;
    return;
}
ostream & operator << (ostream &ost, Node *head)
{
    Node *cur = head;
    while (cur != NULL)
    {
        ost << cur->value;
        cur = cur->link;
    }
    return ost;
}
int main() {
    int data[5] = {3, 1, 2, 0, 4};
    Node *nd;
    Node *head = NULL;
    for (int i = 0; i < 5; i++)
    {
        nd = new Node(data[i]);
        insert(head, nd);
    }
    cout << head << endl;
    return 0;
}
