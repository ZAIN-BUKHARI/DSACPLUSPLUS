#include <iostream>
using namespace std;


struct Node {
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int k)  {
        this->key = key;
        left=NULL;
        right=NULL;
        height=1;
    }
};

 int height(Node* root) {
        return (root != NULL) ? root->height : 0;
    }

 int balanceFactor(Node* root) {
        return (root != NULL) ? height(root->left) - height(root->right) : 0;
    }

 void updateHeight(Node* root) {
        if (root != NULL) {
            root->height = 1 + max(height(root->left), height(root->right));
        }
    }

 Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;//null

        // Update heights
        updateHeight(y);
        updateHeight(x);

        // Return new root
        return x;
    }

 Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        updateHeight(x);
        updateHeight(y);

        // Return new root
        return y;
    }

 void inOrderTraversal(Node* root) {
        if (root == NULL) {
            return NULL;
        }
            inOrderTraversal(root->left);
            cout << root->key << " ";
            inOrderTraversal(root->right);
    }

root* insertBST(Node* root,int key)
{
    // Perform standard BST insertion
        if (root == NULL) 
            return new root(key);
        if (key < root->key) {
            root->left = insertBST(root->left, key);
        } else if (key > root->key) {
            root->right = insertBST(root->right, key);
        } else {
            // Duplicate keys are not allowed in this example
            return root;
        }

        // Update height of the current root
        updateHeight(root);

        // Get the balance factor to check if the root became unbalanced
        int balance = balanceFactor(root);

        // Perform rotations if necessary
        // Left Heavy
        if (balance > 1) {
            // Left-Left case
            if (key < root->left->key) {
                return rotateRight(root);
            }
            // Left-Right case
            else if (key > root->left->key) {
                root->left = rotateLeft(root->left);
                return rotateRight(root);
            }
        }
        // Right Heavy
        else if (balance < -1) {
            // Right-Right case
            if (key > root->right->key) {
                return rotateLeft(root);
            }
            // Right-Left case
            else if (key < root->right->key) {
                root->right = rotateRight(root->right);
                return rotateLeft(root);
            }
        }

        return root;
}

int main()
{
    //       3
    //      /\ 
    //     2 NULL
    //    /  
    //   1  
    //     2
    //    /\ 
    //   1  3
    //ans 2 1 3
    root* root = new root(3);    
    root->left = new root(2);    
    root->left->left = new root(1); 

    std::cout << "In-order traversal of the AVL tree: ";
    avlTree.inOrderTraversal();   
    return 0;
}