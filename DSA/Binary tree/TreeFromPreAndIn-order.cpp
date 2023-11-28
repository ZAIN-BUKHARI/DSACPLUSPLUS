//BUILDING A TREE FROM PREORDER AND POSTODER RULE VALUES

#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

     Node(int val)
    {
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};

int search (int inorder[],int start,int end,int curr)
{
    for(int i=start;i<=end;i++)
    {
        if(inorder[i]==curr)
        {
            return i;
        }
    }
    return -1;
}

Node* BuilTree(int preorder[],int inorder[],int start,int end)
{
    static int idx=0;
    if(start>end)
    {
        return NULL;
    }
    int curr = preorder[idx];//1
    idx++;                                 // 1
    Node* node = new Node(curr); //node ---  / 
    if(start==end){return node;}
    int pos = search(inorder,start,end,curr);
    node->left=BuilTree(preorder,inorder,start,pos-1);
    node->right=BuilTree(preorder,inorder,pos+1,end);

    return node;
}

void inorderPrint(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorderPrint(root->left);
    cout<<root->data;
    inorderPrint(root->right);
}

int main()
{
    int preorder[]={1,2,4,3,5};
    int inorder[]={4,2,1,5,3};

    Node* root = BuilTree(preorder,inorder,0,4);
    inorderPrint(root);

    return 0;
}