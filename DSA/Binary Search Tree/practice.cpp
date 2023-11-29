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



Node* inorderSucc(Node* root)
{
    Node* curr = root;
    while(curr && curr!=NULL)
    {
        curr = curr->right;
    }
    return curr;
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

    

    
    return 0;
}