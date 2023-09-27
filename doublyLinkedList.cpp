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

void deleteAtHead(node *&list)
{
    if (list == NULL)
    {
        return;
    }
    else if ((list->next == NULL))
    {
        list = NULL;
        return;
    }
    else
    {
        node *toDelete = list;
        list->next->prev = NULL;
        list = list->next;
        delete toDelete;
    }
}

void deleteAtTail(node *&list)
{
    if (list == NULL)
    {
        return;
    }
    else if (list->prev == NULL && list->next == NULL)
    {
        list = NULL;
        return;
    }
    else
    {
        node *temp = list;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        node *toDelete = temp;
        temp->prev->next = NULL;
        delete toDelete;
    }
}

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
    cout << "NULL->>";
    while (temp != NULL)
    {
        cout << temp->data << "->>";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
void displayReverse(node *list)
{
    if (list == NULL)
    {
        cout << "NULL<<-NULL" << endl;
        return;
    }
    node *temp = list;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    cout << "NULL<<-";
    while (temp != NULL)
    {
        cout << temp->data << "<<-";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}

void deleteAtPosition(node *&list, int pos)
{
    try 
    {
        if(pos <= 0)
        {
            throw std::runtime_error("The position size must be greater than zero..!!");
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        exit(0);
    }
    if (list == NULL)
    {
        return;
    }
    else if (pos == 1)
    {
        deleteAtHead(list);
    }
    else
    {
        node *temp = list;
        int *counter = new int(1);
        while (*counter != pos)
        {
            (*counter)++;
            try
            {
                /* code */
                temp = temp->next;
                if (temp == NULL && *counter != pos)
                {
                    delete counter;
                    throw std::runtime_error("The position that you have entered is out of bounds!");
                }
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
            }
        }
        delete counter;
        if (temp->next != NULL && temp->next != NULL)
        {
            node *toDelete = temp;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete toDelete;
        }
        else if (temp->next == NULL)
        {
            deleteAtTail(list);
        }
    }
}

int main()
{
    node *list = NULL;
    insertAtTail(list, 43);
    insertAtHead(list, 2);
    insertAtHead(list, 4);
    insertAtHead(list, 7);
    displayNode(list);
    deleteAtPosition(list, 4);
    deleteAtPosition(list, 2);
    displayNode(list);
    return 0;
}