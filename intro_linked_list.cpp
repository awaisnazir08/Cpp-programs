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

void deleteAtHead(node* &head)
{
    node* temp = head;
    if(head->next!= NULL)
    {
        head=head->next;
    }
    else 
    {
        head = NULL;
    }
    delete temp;
}
void deleteNode(node* &head, int key)
{
    if(head == NULL)
    {
        return;
    }
    if(head->data == key)
        {
            deleteAtHead(head);
            return;
        }
    node* temp = head;
    while(temp->next != NULL)
    {
        if(key==temp->next->data)
        {
            if(temp->next->next == NULL)
            {
                temp->next = NULL;
            }
            else
            {       
                node* toDelete = temp->next;    
                temp->next = temp->next->next;
                delete toDelete;
            }
            return;
        }
        temp = temp->next;
    }
}

void reverseList(node* &head)
{
    if(head == NULL || head->next == NULL)
    {
        return;
    }
    node* previous = NULL;
    node* current = head; 
    node* temp = NULL;
    while(current != NULL)
    {
        temp = current ->next;
        current->next = previous;
        previous = current;
        current = temp;       
    }
    head = previous;     
}

void insertAtPosition(node* &head, int val, int pos)
{
    if (pos!=1 && head==NULL)
    {
        return;
    }

    if(pos==1)
    {
        insertAtHead(head,val);
        return;
    }
    else
    {
        node *n = new node(val);
        node *temp = head;
        for(int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        n->next = temp->next;
        temp->next = n;
    }
}
void deleteAtPosition(node* &head, int pos)
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        node* temp = head;
        for(int i=1;i<pos-1; i++)
        {
            temp = temp -> next;
        }
        node *toDelete = temp->next;
        if(temp->next->next == NULL)
        {
            temp->next = NULL;
        }
        else
        {
            temp -> next = temp ->next->next;
        }
        delete toDelete;
    }
}

int main()
{
    node *head = NULL;
    insertAtHead(head, 9);
    // insertAtHead(head, 9);
    // deleteNode(head,9);
    insertAtHead(head,63);
    insertAtTail(head,453);
    // deleteAtHead(head);
    // insertAtTail(head, 86);
    insertAtHead(head,5);
    displayNode(head);
    // reverseList(head);
    // reverseList(head);
    // insertAtPosition(head, 100, 3);
    // insertAtPosition(head, 689, 20);
    // deleteNode(head,63);
    // deleteAtPosition(head,3);
    deleteNode(head,453);
    // deleteNode(head, 334);
    displayNode(head);
    return 0;
}