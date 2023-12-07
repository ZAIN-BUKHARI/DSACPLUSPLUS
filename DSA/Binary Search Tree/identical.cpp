#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

bool isIdentical(Node* root1,Node* root2)
{
    if(root1==NULL and root2==NULL)
    {
        return true;
    }
    else if(root1==NULL or root2==NULL)
    {
        return false;
    }
    else{

        bool condition1 = root1->data==root2->data;
        bool condition2 = isIdentical(root1->left,root2->left);
        bool condition3 = isIdentical(root1->right,root2->right);

        if(condition1 and condition2 and condition3)
        {
            return true;
        }
        return false;
    }
}

int main()
{
    Node* root1= new Node(2);
    root1->left=new Node(1);
    root1->right=new Node(3);

    Node* root2= new Node(2);
    root2->left=new Node(1);
    root2->right=new Node(3);

   if(isIdentical(root1,root2)){
    cout<<"true";
   }
   else{
    cout<<"false";
   }

    

    return 0;
}