#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data)
    {
        this->data=data;
        next=NULL;
        prev=NULL;
    }
};
void insertAtHead(Node* &head,int data)
{
    Node* node = new Node(data);
    // 1 2 3
    //new node 4
    //we want 4 1 2 3
    //before
    // null-> 1 -> 2 -> 3
    //        |
    //      head
    // after
    // null ->1 ->2 ->3
    //    4  |
    //      head
    //first step---------------------
    // null -> 1 -> 2 ->3
//            |
//4->next = head  now 4 is pointing t 1st node which i 1

// step 2
///// null ->  1 -> 2 ->3
//          / |
//        /  |
//      4  <-prev<-head and 4 node prev already null
//step3
// NULL -> 4 -> 1 -> 2 -> 3 ->
//         |
//        ^
//      head
           
    node->next=head;
    if(head!=NULL)
    {
    head->prev=node;
    }
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
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=node;
    node->prev=temp;

}
void display(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data;
        head=head->next;
    }
}
void deletAtHead(Node* &head)
{
    Node* todelete = head;
    head=head->next;
    head->prev=NULL;
    delete todelete;
}
void del(Node* &head,int position)
{
    if(position==1)
    {
        deletAtHead(head);
        return;
    }
   int count=1;
   Node* temp = head;
   while(temp!=NULL && count!=position)
   {
        count++;
        temp=temp->next;
   }

    temp->prev->next=temp->next;
    if(temp->next!=NULL)
    {
    temp->next->prev=temp->prev;
    }

    delete temp;



}

int main()
{
    Node* head=NULL;
    insert(head,4);
    insert(head,1);
    insert(head,2);
    insert(head,3);
    display(head);
    del(head,1);
    cout<<endl;
    display(head);
    return 0;
}