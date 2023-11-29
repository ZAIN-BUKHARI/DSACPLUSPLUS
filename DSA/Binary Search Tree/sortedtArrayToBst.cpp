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

Node* sortedArrayToBST(int arr[],int start,int end)
{
    if(start>end)
    {
        return NULL;
    }

    int mid = (start + end )/2;
    Node* root = new Node(arr[mid]);
    root->left = sortedArrayToBST(arr,start,mid-1);
    root->right = sortedArrayToBST(arr,mid+1,end);
    return root;
}

void preorder(Node* root)
{
    if(root==NULL){
        return ;
    }
    cout<< root->data<<"";
    preorder(root->left);
    preorder(root->right);

}
int main()
{
     //          4
    //         / \ 
    //        2   5
    //       /    
    //      1  
    int arr[]={1,2,3,4,5};
    Node* root=NULL;
    root = sortedArrayToBST(arr,0,4);
    preorder(root);


    

    
    return 0;
}