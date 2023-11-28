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

Node* inorderSuccess(Node* root)
{
    Node* curr = root;

    while(curr && curr->left!=NULL)
    {
        curr=curr->left;
    }
    return curr;
}

Node* deleteInBST(Node* root,int key)
{
    if(key<root->data)
    {
        root->left = deleteInBST(root->left,key);
    }
    else if(key>root->data)
    {
        root->right = deleteInBST(root->right,key);
    }else{
        //now key== root->data
        if(root->left==NULL) //case 1 
        {
            Node* temp = root->right;
            // free(root);
            delete root;
            return temp;
        }
        else if(root->right==NULL) //case 2
        {
            Node* temp = root->left;
            // free(root);
            delete root;
            return temp;
        }
            Node* temp = inorderSuccess(root->right);
            root->data = temp->data;
            root->right = deleteInBST(root->right,temp->data);
        
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
    struct Node* node = new Node(4);
    node->left = new Node(2);
    node->right = new Node(5);
    node->left->left = new Node(1);
    node->left->right = new Node(3);
    node->right->right = new Node(6);

    inorder(node);cout<<endl;
    node = deleteInBST(node,4);
    inorder(node);

    
    return 0;
}