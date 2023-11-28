#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

Node* searchInBST(Node* root,int key)
{
    if(root==NULL)
    {
        return NULL;//0(n)
    }

    if(root->data==key)
    {
        return root;//0(n)
    }

    if(root->data>key)
    {
        return searchInBST(root->left,key);//0(logn)
    }
        return searchInBST(root->right,key);//0(logn)
}
int main()
{
    struct Node* node = new Node(4);
    node->left = new Node(2);
    node->right = new Node(4);
    node->left->left = new Node(1);
    node->left->right = new Node(3);
    node->right->left = new Node(6);

    if(searchInBST(node,3)==NULL)
    {
        cout << "Key doesn't exist";
    }else{
        cout<< "Key exists";
    }
    return 0;
}