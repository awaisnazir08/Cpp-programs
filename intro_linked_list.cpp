#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next; // pointer that points to the next node
    node(int value)
    {
        this->data = value;
        this->next = NULL;
    }
};
// &head is the reference to the pointer head, indicating that it is reference to a pointer
void insertAtTail(node *&head, int val) // node* is a pointer referencing to an abject of type node which is usually a class or a struct
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void insertAtHead(node* &head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

void displayNode(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

bool searchNode(node* head, int key)
{
    node *temp = head;
    while(temp!=NULL)
    {
        if(key == temp->data)
        {
            return true;
        }
        else
        {
            temp = temp->next;
        }
    }
    return false;
}

int main()
{
    node *head = NULL;
    // insertAtHead(head, 7);
    insertAtTail(head, 86);
    // insertAtHead(head,5);
    displayNode(head);
    return 0;
}