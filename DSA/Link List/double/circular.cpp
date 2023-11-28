#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data=data;
        next=NULL;
    }
};

void insertAtHead(Node* &head,int data)
{
    Node* node = new Node(data);
    if(head==NULL)
    {
        node->next=node;
        head=node;
        return;
    }
    Node* temp = head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=node;
    node->next=head;
    head=node;

    
}
void insert(Node* &head,int data)
{
    if(head==NULL)
    {
        insertAtHead(head,data);
        return;
    }
    Node* node = new Node(data);

    Node* temp = head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=node;
    node->next=head;

}

void display(Node* head)
{
    Node* temp=head;
    
    do
    {
        cout<<temp->data;
        temp=temp->next;
    } while (temp!=head);
    
}

int main()
{
    Node* head=NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    display(head);
    // del(head,1);
    // cout<<endl;
    // display(head);
    return 0;
}