#include <iostream>
using namespace std;

class BinaryTrees
{
public:
    BinaryTrees *parent;
    BinaryTrees *left, *right;
    int value;
    BinaryTrees(int v, BinaryTrees *parentNode = nullptr)
    {
        this->value = v;
        this->parent = parentNode;
        this->left = nullptr;
        this->right = nullptr;
    }
    void addNode(int v, BinaryTrees *n)
    {
        if (n->left != nullptr && n->right != nullptr)
        {
            cout << "No space for another child!" << endl;
            return;
        }
        else if (n->left == nullptr)
        {
            BinaryTrees *b = new BinaryTrees(v, this);
            this->left = b;
        }
        else
        {
            BinaryTrees *b = new BinaryTrees(v, this);
            this->right = b;
        }
        cout << "New child added successfully!" << endl;
    }

    void addValueAnywhere(int v)
    {
        // If the current node is empty, add the value here
        if (isEmpty())
        {
            this->value = v;
            return;
        }

        // If there is space in the left subtree, add the value there
        if (this->left == nullptr)
        {
            BinaryTrees *newNode = new BinaryTrees(v, this);
            this->left = newNode;
            cout << "New value added successfully!" << endl;
            return;
        }

        // If there is space in the right subtree, add the value there
        if (this->right == nullptr)
        {
            BinaryTrees *newNode = new BinaryTrees(v, this);
            this->right = newNode;
            cout << "New value added successfully!" << endl;
            return;
        }

        // If there is no space in the current node or its subtrees, recursively try the left and right subtrees
        this->left->addValueAnywhere(v);
        this->right->addValueAnywhere(v);
    }
    int retreiveElement(BinaryTrees *b)
    {
        return b->value;
    }

    BinaryTrees *getleft(BinaryTrees *b)
    {
        return b->left;
    }

    BinaryTrees *getright(BinaryTrees *b)
    {
        return b->right;
    }

    bool isEmpty()
    {
        return (this == nullptr);
    }

    bool isLeaf(BinaryTrees *b)
    {
        return (!isEmpty()) && b->left == nullptr && b->right == nullptr;
    }

    int size()
    {
        if (isEmpty())
        {
            return 0;
        }
        else
        {
            return 1 + this->left->size() + this->right->size();
        }
    }

    int height()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return 1 + std::max(this->left->height(), this->right->height());
        }
    }

    void Clear()
    {
        if (isEmpty())
            return;
        if (left != nullptr)
            left->Clear();
        if (right != nullptr)
            right->Clear();
        delete this;
    }
};

int main()
{

    return 0;
}