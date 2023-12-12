#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *right,*left;
    Node(int value){
        data=value;
        right=NULL;
        left=NULL;
    }
};

Node* insertinBST(Node* root,int key)
{

}

int main()
{
    //    2
    //   /\ 
    //  1 3

    Node* root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);
}

