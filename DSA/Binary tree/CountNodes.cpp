#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

     Node(int val)
    {
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};


int countNodes(Node* root)
{
    if(root==NULL){
        return 0;
    }

    return countNodes(root->left) + countNodes(root->right) + 1;
}
int main()
{
    struct Node* node = new Node(1);
    node->left = new Node(2);
    node->right = new Node(3);
    node->left->left = new Node(4);
    node->left->right = new Node(5);
    node->right->left = new Node(6);
    node->right->right = new Node(7);
    cout<< countNodes(node);
    return 0;
}