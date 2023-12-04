#include <iostream>
#include <list>

class TreeNode {
public:
    TreeNode *parent;
    int value;
    std::list<TreeNode *> children;

    TreeNode(int val, TreeNode *parentnode = nullptr) {
        value = val;
        parent = parentnode;
    }

    void addChild(TreeNode *child) {
        child->parent = this;
        children.push_back(child);
    }

    // Function to retrieve a node with a specific value
    TreeNode *getNodeWithValue(int val) {
        return getNodeWithValueHelper(this, val);
    }

    // Function to get the size of the tree
    int getSize() {
        return getSizeHelper(this);
    }

    // Function to get the height of the tree
    int getHeight() {
        return getHeightHelper(this);
    }

    // Function to get the degree of a node
    int getNodeDegree() {
        if (this == nullptr) {
            return 0;
        }
        return children.size();
    }

    // Function to insert a new node with a specific value under a parent node
    void insertNode(int val) {
        TreeNode *newNode = new TreeNode(val, this);
        addChild(newNode);
    }

    // Function to detach a subtree rooted at a specific node
    void detachSubtree() {
        if (this == nullptr || parent == nullptr) {
            return; // Cannot detach root or nullptr
        }

        parent->children.remove(this);
        delete this; // Don't forget to free the memory
    }

    // Function to print the tree structure
    void printTree(int depth = 0) {
        if (this == nullptr) {
            return;
        }

        for (int i = 0; i < depth; ++i) {
            std::cout << "  "; // Indentation based on depth
        }

        std::cout << "|_" << value << std::endl;

        for (TreeNode *child : children) {
            child->printTree(depth + 1);
        }
    }
    int getDegree(TreeNode* n)
    {
        return n->children.size();
    }
    bool isRoot(TreeNode*n)
    {
        return n->parent==NULL;
    }
    bool isLeaf(TreeNode* n)
    {
        return n->children.size()==0;
    }

    int retreive(TreeNode *n)
    {
        return n->value;
    }
private:
    // Helper function to retrieve a node with a specific value
    TreeNode *getNodeWithValueHelper(TreeNode *node, int val) {
        if (node == nullptr) {
            return nullptr;
        }
        if (node->value == val) {
            return node;
        }
        for (TreeNode *child : node->children) {
            TreeNode *result = getNodeWithValueHelper(child, val);
            if (result != nullptr) {
                return result;
            }
        }
        return nullptr;
    }

    // Helper function to get the size of the tree
    int getSizeHelper(TreeNode *node) {
        if (node == nullptr) {
            return 0;
        }
        int size = 1; // Count the current node
        for (TreeNode *child : node->children) {
            size += getSizeHelper(child);
        }
        return size;
    }

    // Helper function to get the height of the tree
    int getHeightHelper(TreeNode *node) {
        if (node == nullptr) {
            return 0;
        }
        int maxHeight = 0;
        for (TreeNode *child : node->children) {
            int childHeight = getHeightHelper(child);
            if (childHeight > maxHeight) {
                maxHeight = childHeight;
            }
        }
        return maxHeight + 1; // Add 1 for the current node
    }
};

int main() {
    // Creating nodes
    TreeNode *node1 = new TreeNode(1);

    // Creating tree and setting the root
    TreeNode *root = node1;

    // Adding children to nodes
    node1->addChild(new TreeNode(2));
    node1->addChild(new TreeNode(3));

    // Printing the tree
    std::cout << "Tree Structure:" << std::endl;
    root->printTree();

    // Example usage of new functions
    std::cout << "Size of the tree: " << root->getSize() << std::endl;
    std::cout << "Height of the tree: " << root->getHeight() << std::endl;

    TreeNode *foundNode = root->getNodeWithValue(3);
    if (foundNode != nullptr) {
        std::cout << "Node with value 3 found!" << std::endl;
    } else {
        std::cout << "Node with value 3 not found." << std::endl;
    }

    std::cout << "Degree of the root node: " << root->getNodeDegree() << std::endl;

    root->insertNode(4);
    std::cout << "Tree after inserting a new node:" << std::endl;
    root->printTree();

    root->getChild(2)->detachSubtree();
    std::cout << "Tree after detaching subtree rooted at node 2:" << std::endl;
    root->printTree();

    // Don't forget to free allocated memory
    delete root;

    return 0;
}
