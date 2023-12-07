#include <iostream>
#include <climits>
using namespace std;

struct Node{
    int data;
    Node *right,*left;
    Node(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

Node* constructBST(int preorder[],int *preorderIdx,int key,int min,int max,int n)
{
    if(*preorderIdx>=n)
    {
        return NULL;
    }

    Node* root = NULL;
    if(key>min && key<max)
    {
        root= new Node(key);
        *preorderIdx = *preorderIdx + 1;

        if(*preorderIdx<n)
        {
            root->left = constructBST(preorder,preorderIdx,preorder[*preorderIdx],min,key,n);
        }
        if(*preorderIdx<n)
        {
            root->left = constructBST(preorder,preorderIdx,preorder[*preorderIdx],min,key,n);
        }
    }
    return root;
}

void preorderPrint(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<< root->data << " ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

int main()
{
    int preorder[] = {10,2,1,13,11};
    int n = 5;
    int index = 0;
    Node* root = constructBST(preorder,&index,preorder[index],INT_MIN,INT_MAX,n);
    preorderPrint(root);
    return 0;
}