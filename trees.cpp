#include <iostream>
#include <list>

class TreeNode{
    public:
    TreeNode * parent;
    int value;
    std::list<TreeNode*> children;
    TreeNode(int val, TreeNode* parentnode = nullptr)
    {
        value = val;
        parent = parentnode;
    }
    void addChild(TreeNode* child)
    {
        child->parent = this;
        children.push_back(child);
    }
};


class Tree {
public:
    TreeNode* root;

    Tree() : root(nullptr) {}

    void setRoot(TreeNode* node) {
        root = node;
    }

    // Function to retrieve a node with a specific value
    TreeNode* getNodeWithValue(int val) {

        return getNodeWithValueHelper(root, val);
    }

    // Function to get the size of the tree
    int getSize() {
        return getSizeHelper(root);
    }

    // Function to get the height of the tree
    int getHeight() {
        return getHeightHelper(root);
    }

    // Function to get the degree of a node
    int getNodeDegree(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        return node->children.size();
    }

    // Function to insert a new node with a specific value under a parent node
    void insertNode(TreeNode* parent, int val) {
        TreeNode* newNode = new TreeNode(val, parent);
        parent->addChild(newNode);
    }

    // Function to detach a subtree rooted at a specific node
    void detachSubtree(TreeNode* node) {
        if (node == nullptr || node->parent == nullptr) {
            return;  // Cannot detach root or nullptr
        }

        TreeNode* parent = node->parent;
        parent->children.remove(node);
        delete node;  // Don't forget to free the memory
    }

    // Function to print the tree structure
    void printTree(TreeNode* node, int depth = 0) {
        if (node == nullptr) {
            return;
        }

        for (int i = 0; i < depth; ++i) {
            std::cout << "  "; // Indentation based on depth
        }

        std::cout << "|_" << node->value << std::endl;

        for (TreeNode* child : node->children) {
            printTree(child, depth + 1);
        }
    }

    /**
    * The function `getChild` returns the nth child of a given node, or `nullptr` if the index is out
    * of bounds.
    * 
    * @param node A pointer to the TreeNode whose child is to be retrieved.
    * @param n The parameter `n` represents the index of the child node that we want to retrieve.
    * 
    * @return a pointer to a TreeNode object.
    */
    TreeNode* getChild(TreeNode* node, int n)
    {
        if(n < 0 || n >=getNodeDegree(node))
        {
            return nullptr;
        }
        std::list<TreeNode*> temp = node->children;
        int count = 0;
        for(TreeNode* child: node->children)
        {
            count++;
            if(count == n)
            {
                return child;
            }
        }
    }

private:
    // Helper function to retrieve a node with a specific value
    TreeNode* getNodeWithValueHelper(TreeNode* node, int val) {
        if (node == nullptr) {
            return nullptr;
        }
        if (node->value == val) {
            return node;
        }
        for (TreeNode* child : node->children) {
            TreeNode* result = getNodeWithValueHelper(child, val);
            if (result != nullptr) {
                return result;
            }
        }
        return nullptr;
    }

    // Helper function to get the size of the tree
    int Size(TreeNode* n)
    {
        if(n == nullptr)
        {
            return 0;
        }
        int s = 1;
        for(TreeNode* child: n->children)
        {
            s+=Size(child);
        }
        return s;
    }
    int getSizeHelper(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        int size = 1;  // Count the current node
        for (TreeNode* child : node->children) {
            size += getSizeHelper(child);
        }
        return size;
    }

    // Helper function to get the height of the tree
    int Height(TreeNode* n)
    {
        int h = 0;
        if(n == nullptr)
        {
            return 0;
        }
        for(TreeNode* child: n->children)
        {
        h = std::max(h, 1 + Height(child));
        }
        return h;
    }
    int getHeightHelper(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        int maxHeight = 0;
        for (TreeNode* child : node->children) {
            int childHeight = getHeightHelper(child);
            if (childHeight > maxHeight) {
                maxHeight = childHeight;
            }
        }
        return maxHeight + 1;  // Add 1 for the current node
    }
};

int main() {
    // Creating nodes
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);

    // Creating tree and setting the root
    Tree myTree;
    myTree.setRoot(node1);

    // Adding children to nodes
    node1->addChild(node2);
    node1->addChild(node3);
    node2->addChild(node4);
    node2->addChild(node5);

    // Printing the tree
    std::cout << "Tree Structure:" << std::endl;
    myTree.printTree(myTree.root);

    // Example usage of new functions
    std::cout << "Size of the tree: " << myTree.getSize() << std::endl;
    std::cout << "Height of the tree: " << myTree.getHeight() << std::endl;

    TreeNode* foundNode = myTree.getNodeWithValue(4);
    if (foundNode != nullptr) {
        std::cout << "Node with value 4 found!" << std::endl;
    } else {
        std::cout << "Node with value 4 not found." << std::endl;
    }

    std::cout << "Degree of node 2: " << myTree.getNodeDegree(node2) << std::endl;

    myTree.insertNode(node3, 6);
    std::cout << "Tree after inserting a new node:" << std::endl;
    myTree.printTree(myTree.root);

    myTree.detachSubtree(node2);
    std::cout << "Tree after detaching subtree rooted at node 2:" << std::endl;
    myTree.printTree(myTree.root);

    // Don't forget to free allocated memory
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;

    return 0;
}