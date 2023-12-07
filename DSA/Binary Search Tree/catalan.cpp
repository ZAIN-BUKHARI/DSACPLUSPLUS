#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node* right;
    Node* left;
    Node(int data)
    {
        this->data=data;
        right=NULL;
        left=NULL;
    }

};

vector<Node*> catalan(int start,int end)
{
    vector<Node*> trees;
    if(start>end)
    {
        trees.push_back(NULL);
        return trees;
    }
    for(int i=start; i<=end;i++)
    {
    vector<Node*> leftSubtree = catalan(start,i-1);
    vector<Node*> rightSubtree = catalan(i+1,end);

        for(int j=0;j<leftSubtree.size();j++)
        {
            Node* left = leftSubtree[j];
            for(int k=0;k<rightSubtree.size();k++)
            {
            Node* right = rightSubtree[i];
            Node* node = new Node(i);
            node->left = left;
            node->right = right;
            trees.push_back(node);
            }
        }

    }
    return trees;
}

void preorderPrint(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<< root->data<<" ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

int main()
{
    vector<Node*> tree = catalan(1,3);
    for(int i=0; i<tree.size();i++)
    {
        cout<< (i+1) << " : ";
        preorderPrint(tree[i]);
        cout<<endl;
    }
    return 0;
}