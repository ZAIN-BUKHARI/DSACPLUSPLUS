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

void preorder(struct Node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct Node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
}
void postorder(struct Node* root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data;
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
    cout<<"Preorder"<<endl;
    preorder(node);cout<<endl;
    cout<<"Inorder"<<endl;
    inorder(node);cout<<endl;
    cout<<"Postorder"<<endl;
    postorder(node);cout<<endl;

    return 0;
}