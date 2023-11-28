#include <iostream>
#include <queue>
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

void printLevelOrder(Node* root)
{
    
    if(root==NULL)
    {
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* node = q.front();
        q.pop();
        if(node!=NULL)
        {
          cout<<node->data<<" ";
          if(node->left)
             q.push(node->left);
          if(node->right)
             q.push(node->right);

        }
        else if(!q.empty())
        {
            q.push(NULL);
        }
    }
}
int levelKSum(Node* root, int K)
{
    
    if(root==NULL)
    {
        return -1;
    }
    queue<Node*> q;
    int sum=0;
    int count=0;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* node = q.front();
        q.pop();
        if(node!=NULL)
        {
            
            sum+=node->data;
            count++;
            
          if(node->left)
             q.push(node->left);
          if(node->right)
             q.push(node->right);

        }
        else if(!q.empty())
        {
            q.push(NULL);
        }
    }
    cout << count;
    return sum;
}
int32_t main()
{
    struct Node* node = new Node(1);
    node->left = new Node(2);
    node->right = new Node(3);
    node->left->left = new Node(4);
    node->left->right = new Node(5);
    node->right->left = new Node(6);
    node->right->right = new Node(7);
    cout<<levelKSum(node,0);
    return 0;
}