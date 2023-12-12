#include <iostream>
#include <algorithm>
using namespace std;
class AVLNode {
public:
    int key;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int k)  {
        this->key = key;
        left=NULL;
        right=NULL;
        height=1;
    }
};

class AVLTree {
private:
    AVLNode* root;

    int height(AVLNode* node) {
        return (node != nullptr) ? node->height : 0;
    }

    int balanceFactor(AVLNode* node) {
        return (node != nullptr) ? height(node->left) - height(node->right) : 0;
    }

    void updateHeight(AVLNode* node) {
        if (node != NULL) {
            node->height = 1 + max(height(node->left), height(node->right));
        }
    }

    AVLNode* rotateRight(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;//null

        // Update heights
        updateHeight(y);
        updateHeight(x);

        // Return new root
        return x;
    }

    AVLNode* rotateLeft(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        updateHeight(x);
        updateHeight(y);

        // Return new root
        return y;
    }

    AVLNode* insertNode(AVLNode* node, int key) {
        // Perform standard BST insertion
        if (node == NULL) 
            return new AVLNode(key);
        if (key < node->key) {
            node->left = insertNode(node->left, key);
        } else if (key > node->key) {
            node->right = insertNode(node->right, key);
        } else {
            // Duplicate keys are not allowed in this example
            return node;
        }

        // Update height of the current node
        updateHeight(node);

        // Get the balance factor to check if the node became unbalanced
        int balance = balanceFactor(node);

        // Perform rotations if necessary
        // Left Heavy
        if (balance > 1) {
            // Left-Left case
            if (key < node->left->key) {
                return rotateRight(node);
            }
            // Left-Right case
            else if (key > node->left->key) {
                node->left = rotateLeft(node->left);
                return rotateRight(node);
            }
        }
        // Right Heavy
        else if (balance < -1) {
            // Right-Right case
            if (key > node->right->key) {
                return rotateLeft(node);
            }
            // Right-Left case
            else if (key < node->right->key) {
                node->right = rotateRight(node->right);
                return rotateLeft(node);
            }
        }

        return node;
    }

public:
    AVLTree()  {
        root=NULL;
    }

    void insert(int key) {
        root = insertNode(root, key);
    }

    // For simplicity, perform an in-order traversal to display the tree
    void inOrderTraversal(AVLNode* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            std::cout << node->key << " ";
            inOrderTraversal(node->right);
        }
    }

    void display() {
        inOrderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    AVLTree avlTree;

    // Insert nodes into the AVL tree
    avlTree.insert(10);
    avlTree.insert(20);
    avlTree.insert(30);
    avlTree.insert(40);
    avlTree.insert(50);
    avlTree.insert(25);

    // Display the AVL tree
    std::cout << "In-order traversal of the AVL tree: ";
    avlTree.display();

    return 0;
}
