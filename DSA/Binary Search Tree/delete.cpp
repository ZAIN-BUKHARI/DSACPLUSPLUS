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

Node* inorderSucc(Node* root)
{
    Node* curr = root;
    while(curr && curr!=NULL)
    {
        curr = curr->right;
    }
    return curr;
}

Node* delBST(Node* root,int key)
{
    if(root->data>key)
        return delBST(root->left,key);
    else if(root->data<key)
        return delBST(root->right,key);
    else{
        if(root->left==NULL)
        {
            Node* right = root->right;
            free(root);
            return right;
        }
        else if(root->right==NULL)
        {
            Node* left = root->left;
            free(root);
            return left;

        }
        else
        {
            Node* temp = inorderSucc(root->right);
            root->data=temp->data;
            root->right = delBST(root->right,temp->data);
        }
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
     //          4
    //         / \ 
    //        2   5
    //       /    
    //      1     
    struct Node* node = new Node(4);
    node->left = new Node(2);
    node->right = new Node(5);
    node->left->left = new Node(1);

    inorder(node);cout<<endl;
    node = delBST(node,1);
    inorder(node);

    
    return 0;
}