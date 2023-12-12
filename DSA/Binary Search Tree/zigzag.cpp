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
Node* zigzag(Node* root)
{
    if(root==NULL)
    {
        return root;
    }
    vector<Node*> ans;
    stack<Node*> currLevel;
    stack<Node*> nextLevel;

    bool leftToRight= true;

    currLevel.push(root);
    while(!currLevel.empty())
    {
        Node* temp = currLevel.top();
        currLevel.pop();
        if(temp)
        {

        cout<< temp->data<< " ";

        if(leftToRight)
        {
            if(temp->left)
            {
                currLevel.push(temp->left);
            }
            if(temp->right)
            {
                currLevel.push(temp->right);
            }
        }else{
            if(temp->right)
            {
                currLevel.push(temp->right);
            }
            if(temp->left)
            {
                currLevel.push(temp->left);
            }
        }
        }
        if(currLevel.empty())
        {
            leftToRight=!leftToRight;
            swap(currLevel,nextLevel);

        }
    }
    return root;

}
int main()
{
    Node* root= new Node(12);
    root->left=new Node(9);
    root->right=new Node(15);
    root->left->left=new Node(5);
    root->left->right=new Node(10);

    zigzag(root);
    

    return 0;
}