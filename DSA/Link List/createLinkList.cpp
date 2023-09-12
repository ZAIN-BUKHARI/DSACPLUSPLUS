#include <iostream>
using namespace std;
class Node
{
    public:
        int data;
        Node* next;
        Node(int data)
        {
            this->data=data;
            next = NULL;
        }
};
void insertAtTail(Node* &head,int data)
{
    Node* node = new Node(data);
    if(head==NULL) // 1st attemp if work
    {
        head=node;
        return;
    }

    Node* temp=head;
    while(temp->next!=NULL)  // 3rd attempt this while work
    {
        temp=temp->next;
    }
    temp->next=node;  // 2nd attemp this line call
}
void displayNode(Node* head)



{
    Node* temp = head;
    cout<<"Head->";
    while(temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|-->";
        temp=temp->next;
    }
    cout<<"NULL";
        
}
void insertAtHead(Node* &head,int data)
{
    Node* node = new Node(data);
    node->next=head;
    head=node;
    
}
bool searchInList(Node* head,int key){
    while(head!=NULL)
    {
        if(head->data==key)
        {
            return true;
        }
        head=head->next;
    }
    return false;
}
void delElement(Node* &head,int data)
{
    if(head==NULL)
    {
        return;
    }
    if(head->next==NULL)
    {
        // deleteAtHead(head);
        return;
    }

    Node* node = head;

    while(node->next->data!=data)
    {
        node=node->next;
    }
    Node* todel = node->next;
    node->next=node->next->next;

    delete todel;
}
void deleteAtHead(Node* &head)
{
    Node* toelete = head;
    head=head->next;

    delete toelete;
}
Node* reverse(Node* &head)  //iterative reverse 
{
    Node* previous=NULL;
    Node* current=head;
    Node* next;

    while(current!=NULL)
    {
        next=current->next;
        current->next=previous;

        previous=current;
        current=next;
    }

    return previous;


}
Node* reverseRecursive(Node* &head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    Node* newhead = reverseRecursive(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}
bool detectionCycle(Node* &head)
{
    Node* slow=head;
    Node* fast=head;

    while(fast!=NULL && fast->next!=NULL)
    {
        
        slow=head->next;
        fast=head->next->next;

        if(slow==fast)
        {
            return true;
        }
    }
    return false;
}
void removeCycle(Node* &head)
{
    Node* fast=head;
    Node* slow=head;

    do
    {
        slow=slow->next;
        fast=fast->next->next;
    } while (slow!=fast);

    fast=head;
    while(slow->next!=fast->next)
    {
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;
    
}
int main()
{
    Node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    // insertAtHead(head,4);
    // displayNode(head);
    // cout<<endl<<endl;
    // cout<<searchInList(head,3);
    // delElement(head,2);
    // deleteAtHead(head);
    // displayNode(head);
    Node* newhead = reverse(head);
    displayNode(newhead);

}