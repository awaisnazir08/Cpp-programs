#include<iostream>
using namespace std;

// Structure to represent a node in a Binary Search Tree (BST)
struct BinarySearchTrees {
    int data;
    BinarySearchTrees* left, * right;

    // Constructor to initialize a node with a given value
    BinarySearchTrees(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to insert a value into a Binary Search Tree
BinarySearchTrees* insertInBinarySearchTree(BinarySearchTrees* root, int val)
{
    if (root == nullptr)
    {
        return new BinarySearchTrees(val);
    }
    if (val < root->data)
    {
        root->left = insertInBinarySearchTree(root->left, val);
    }
    else
    {
        root->right = insertInBinarySearchTree(root->right, val);
    }
    return root;
}

// In-order traversal of a Binary Search Tree, printing values in sorted order
void inOrderTraversal(BinarySearchTrees* root)
{
    if (root == nullptr)
    {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

// Pre-order traversal of a Binary Search Tree
void preOrderTraversal(BinarySearchTrees* root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// Post-order traversal of a Binary Search Tree
void postOrderTraversal(BinarySearchTrees* root)
{
    if (root == nullptr)
    {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

// Function to search for a key in a Binary Search Tree
BinarySearchTrees* searchInBinarySearchTree(BinarySearchTrees* root, int key)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->data == key)
    {
        return root;
    }
    if (key > root->data)
    {
        return searchInBinarySearchTree(root->right, key);
    }
    else
    {
        return searchInBinarySearchTree(root->left, key);
    }
}

// Function to find the in-order successor of a node in a Binary Search Tree
//it will find the next inorder successor of the node that has to be deleted
BinarySearchTrees* inorderSuccessor(BinarySearchTrees* root)
{
    BinarySearchTrees* curr = root;
    while (curr != nullptr && curr->left != nullptr)
    {
        curr = curr->left;
    }
    return curr;
}

// Function to delete a node with a given key in a Binary Search Tree
BinarySearchTrees* deleteInBinarySearchTree(BinarySearchTrees* root, int key)
{
    if (key < root->data)
    {
        root->left = deleteInBinarySearchTree(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteInBinarySearchTree(root->right, key);
    }
    else
    {
        if (root->left == nullptr)
        {
            BinarySearchTrees* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            BinarySearchTrees* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Node with two children
        // the logic is that we will find the next bigger element, and replace it with the node that has to be deleted
        BinarySearchTrees* temp = inorderSuccessor(root->right);
        root->data = temp->data;
        root->right = deleteInBinarySearchTree(root->right, temp->data);
    }
}



int main() {
    // Creating an empty Binary Search Tree
    BinarySearchTrees* root = nullptr;

    // Inserting values into the Binary Search Tree
    int values[] = { 5, 3, 7, 2, 4, 8, 1, 6, 9, 10, 12, 14, 25, 27,32, 21, 40, 55, 60, 18, 99, 17 };

    // Inserting values into the Binary Search Tree
    for (int i = 0; i < sizeof(values) / sizeof(values[0]); ++i) {
        root = insertInBinarySearchTree(root, values[i]);
    }

    // Displaying the tree after insertions
    cout << "Binary Search Tree after insertions: ";
    inOrderTraversal(root);
    cout << endl;

    // Performing in-order traversal
    cout << "In-Order Traversal: ";
    inOrderTraversal(root);
    cout << endl;

    // Performing pre-order traversal
    cout << "Pre-Order Traversal: ";
    preOrderTraversal(root);
    cout << endl;

    // Performing post-order traversal
    cout << "Post-Order Traversal: ";
    postOrderTraversal(root);
    cout << endl;

    // Deleting a node from the Binary Search Tree
    int deleteKey = 5;
    root = deleteInBinarySearchTree(root, deleteKey);

    // Displaying the tree after deletion
    cout << "Node to be deleted with value: " << deleteKey << endl;
    deleteKey = 21;
    root = deleteInBinarySearchTree(root, deleteKey);

    deleteKey = 60;
    cout << "Node to be deleted with value: " << deleteKey << endl;
    root = deleteInBinarySearchTree(root, deleteKey);

    deleteKey = 1;
    cout << "Node to be deleted with value: " << deleteKey << endl;
    root = deleteInBinarySearchTree(root, deleteKey);

    cout << "Binary Search Tree after deletion: ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}
// Function to display the menu
//void displayMenu() {
//    cout << "Binary Search Tree Operations:" << endl;
//    cout << "a) Insert new data" << endl;
//    cout << "b) In-Order Traversal" << endl;
//    cout << "c) Pre-Order Traversal" << endl;
//    cout << "d) Post-Order Traversal" << endl;
//    cout << "e) Delete an item" << endl;
//    cout << "f) Exit" << endl;
//}
//int main() {
//    BinarySearchTrees* root = nullptr;
//    char choice;
//
//    do {
//        displayMenu();
//        cout << "Enter your choice: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 'a':
//            int value;
//            cout << "Enter value to insert: ";
//            cin >> value;
//            root = insertInBinarySearchTree(root, value);
//            break;
//        case 'b':
//            cout << "In-Order Traversal: ";
//            inOrderTraversal(root);
//            cout << endl;
//            break;
//        case 'c':
//            cout << "Pre-Order Traversal: ";
//            preOrderTraversal(root);
//            cout << endl;
//            break;
//        case 'd':
//            cout << "Post-Order Traversal: ";
//            postOrderTraversal(root);
//            cout << endl;
//            break;
//        case 'e':
//            int deleteValue;
//            cout << "Enter value to delete: ";
//            cin >> deleteValue;
//            root = deleteInBinarySearchTree(root, deleteValue);
//            break;
//        case 'f':
//            // Exit the program
//            break;
//        default:
//            cout << "Invalid choice. Please try again." << endl;
//        }
//    } while (choice != 'f');
//
//    return 0;
//}
