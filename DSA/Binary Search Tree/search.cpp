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

Node* search(Node* root,int key)
{
    if(root==NULL)
        return NULL; // KEY NOT FOUND 

    if(root->data==key)
        return root;// KEY FOUND

    if(root->data>key)
        return search(root->left,key);
    return search(root->right,key);
    
}
int main()
{
    //          4
    //         / \ 
    //        2   5
    //       /\   \ 
    //      1 3    6
    struct Node* node = new Node(4);
    node->left = new Node(2);
    node->right = new Node(5);
    node->left->left = new Node(1);
    node->left->right = new Node(3);
    node->right->left = new Node(6);

    node = search(node,10);
    if(node==NULL)
    {
        cout << "Key doesn't exist";
    }else{
        cout<< "Key exists "<<node->data;
    }
    return 0;
}