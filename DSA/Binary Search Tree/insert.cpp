#include <iostream>
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
//     6
//    /\ 
// NULL NULL 
Node* Insert(Node* root,int val)//val=1
{ 
    //---
    if(root==NULL)
        return new Node(val); //put the value 
    if(val>root->data)
        root->right = Insert(root->right,val); //traverse in right subtree until found a place where he put value
    else if(val<root->data)
        root->left = Insert(root->left,val); //traverse in left subtree until found a place where he put value
    return root;
}

void inorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<< root->data << "";
    inorder(root->right);
}

int main(){
    //           3   
    //         /  \ 
    //        2    7
    //       /    /\ 
    //      1    5  8
    //          /\ 
    //         4  6
  
    Node* root = new Node(3);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->right = new Node(7);
    root->right->right = new Node(8);
    root->right->left = new Node(5);
    root->right->left->left = new Node(4);
    root = Insert(root,6);
    inorder(root);
    return 0;
}
