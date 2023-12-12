#include <iostream>
#include <algorithm>

class AVLNode {
public:
    int key;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
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
        if (node != nullptr) {
            node->height = 1 + std::max(height(node->left), height(node->right));
        }
    }

    AVLNode* rotateRight(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

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

    AVLNode* minValueNode(AVLNode* node) {
        AVLNode* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    AVLNode* deleteNode(AVLNode* node, int key) {
        // Perform standard BST deletion
        if (node == nullptr) {
            return node;
        }

        if (key < node->key) {
            node->left = deleteNode(node->left, key);
        } else if (key > node->key) {
            node->right = deleteNode(node->right, key);
        } else {
            // Node with only one child or no child
            if ((node->left == nullptr) || (node->right == nullptr)) {
                AVLNode* temp = (node->left != nullptr) ? node->left : node->right;

                // No child case
                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                } else { // One child case
                    *node = *temp; // Copy the contents of the non-empty child
                }

                delete temp;
            } else {
                // Node with two children, get the inorder successor
                AVLNode* temp = minValueNode(node->right);

                // Copy the inorder successor's data to this node
                node->key = temp->key;

                // Delete the inorder successor
                node->right = deleteNode(node->right, temp->key);
            }
        }

        // If the tree had only one node, then return
        if (node == nullptr) {
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
            if (balanceFactor(node->left) >= 0) {
                return rotateRight(node);
            }
            // Left-Right case
            else {
                node->left = rotateLeft(node->left);
                return rotateRight(node);
            }
        }
        // Right Heavy
        else if (balance < -1) {
            // Right-Right case
            if (balanceFactor(node->right) <= 0) {
                return rotateLeft(node);
            }
            // Right-Left case
            else {
                node->right = rotateRight(node->right);
                return rotateLeft(node);
            }
        }

        return node;
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(int key) {
        root = insertNode(root, key);
    }

    void remove(int key) {
        root = deleteNode(root, key);
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
    avlTree.insert(9);
    avlTree.insert(5);
    avlTree.insert(10);
    avlTree.insert(0);
    avlTree.insert(6);
    avlTree.insert(11);
    avlTree.insert(-1);
    avlTree.insert(1);
    avlTree.insert(2);

    // Display the AVL tree
    std::cout << "In-order traversal of the AVL tree: ";
    avlTree.display();

    // Remove
