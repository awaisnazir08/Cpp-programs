#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int v)
    {
        this->data = v;
        this->next = NULL;
        this->prev = nullptr;
    }
};

void insertAtHead(node *&list, int val)
{
    node *n = new node(val);
    if (list == nullptr)
    {
        list = n;
        return;
    }
    list->prev = n;
    n->next = list;
    list = n;
}

void insertAtTail(node *&list, int val)
{
    node *n = new node(val);
    if (list == nullptr)
    {
        list = n;
        return;
    }
    node *temp = list;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    n->prev = temp;
    temp->next = n;
}

void displayNode(node *list)
{
    node *temp = list;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
}

int main()
{
    node *list = NULL;
    insertAtTail(list, 43);
    insertAtHead(list, 2);
    insertAtHead(list, 4);
    displayNode(list);
    return 0;
}