#include <iostream>
using namespace std;
class BinaryTrees
{
public:
    int data;
    BinaryTrees *left;
    BinaryTrees *right;
    BinaryTrees(int val)
    {
        data = val;
        this->left = nullptr;
        this->right = nullptr;
    }
    void preOrder(BinaryTrees *root)
    {
        if (root == nullptr)
        {
            return;
        }
        cout << root->data << "";
        preOrder(root->left);
        preOrder(root->right);
    }
    void postOrder(BinaryTrees *root)
    {
        if (root == nullptr)
        {
            return;
        }
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << "";
    }
    void inOrder(BinaryTrees *root)
    {
        if (root == nullptr)
        {
            return;
        }
        inOrder(root->left);
        cout << root->data << "";
        inOrder(root->right);
    }
};
int main()
{

    return 0;
}