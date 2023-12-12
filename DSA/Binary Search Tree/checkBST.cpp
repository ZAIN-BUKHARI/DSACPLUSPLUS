#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* right;
    Node* left;
    Node(int data)
    {
        this->data=data;
        right=NULL;
        left=NULL;
    }
};

bool isBST(Node* root,Node* min,Node*max)
{
    if(root==NULL)
    {
        return true;
    }

    if(min!=NULL && min->data>=root->data)
    {
        return false;
    }
    if(max!=NULL && root->data>=max->data)
    {

        return false;
    }
    bool leftValid = isBST(root->left,min,root);
    bool rightValid = isBST(root->right,root,max);

    return leftValid and rightValid;
}

int main()
{
    Node* node = new Node(2);
    node->left= new Node(1);
    node->right= new Node(3);

    if(isBST(node,NULL,NULL)==false)
    {
        cout<<"false";
    }else{
        cout<<"true";
    }
    return 0;
}