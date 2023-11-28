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

Node* insertBTS(Node *root,int val)
{
    if(root==NULL)
    {
        return new Node(val);
    }

    if(val<root->data)
    {
        root->left = insertBTS(root->left,val);
    }else{
        root->right = insertBTS(root->right,val);
    }
    return root;

}
void inorder(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<< "";
    inorder(root->right);
}
int main()
{
    Node* root = NULL;
    root = insertBTS(root,5);
    insertBTS(root,1);
    insertBTS(root,3);
    insertBTS(root,4);
    insertBTS(root,2);
    insertBTS(root,7);
    inorder(root);
    return 0;
}