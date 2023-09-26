#include <iostream>
using namespace std;
class node
{
public:
    string data;
    node *next; // pointer that points to the next node
    node(string value)
    {
        this->data = value;
        this->next = NULL;
    }
};
// &head is the reference to the pointer head, indicating that it is reference to a pointer
void insertAtTail(node *&head, string val) // node* is a pointer referencing to an abject of type node which is usually a class or a struct
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

void insertAtHead(node* &head, string val)
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

bool searchNode(node* head, string key)
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
void deleteNode(node* &head, string key)
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

void insertAtPosition(node* &head, string val, int pos)
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


void insertAlphabetically(node* &myList, string val)
{
    node *n = new node(val);
    
    if (myList == nullptr || val < myList->data)
    {
        insertAtHead(myList, val);
        delete n;
        return;
    }

    node* temp = myList;

    while (temp->next != NULL && val > temp->next->data)
    {
        temp = temp->next;
    }

    n->next = temp->next;
    temp->next = n;
}


int main()
{
    node *head = NULL;
    string names[7] = {"Ahmed","Ayesha","Bilal","Fatima","Hira","Nabeel","Usman"};
    for(int i = 0; i<(sizeof(names)/sizeof(names[0]))-1; i++)
    {
        for (int j = 0; j < sizeof(names)/sizeof(names[0])-i-1;j++)
        {
        if(names[j]>names[j+1])
        {
            string temp = names[j];
            names[j]= names[j+1];
            names[j+1] = temp;
        }
        }

    }
    // for(int i = 0; i<sizeof(names)/sizeof(names[0]); i++)
    // {
    //     cout<<names[i]<<endl;
    // }
    // displayNode(head);
    node* myList = NULL;
    for(int i = 0; i < sizeof(names)/sizeof(names[0]); i++)
    {
        insertAtTail(myList, names[i]);
    }
    insertAlphabetically(myList, "Awais");
    insertAlphabetically(myList, "Zaheer");
    insertAlphabetically(myList, "Aamaan");
    deleteAtPosition(myList,2);
    displayNode(myList);
    return 0;
}