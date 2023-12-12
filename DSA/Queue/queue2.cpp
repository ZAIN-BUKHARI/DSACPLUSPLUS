#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int data)
    {
        this->data=data;
        next=NULL;
    }
};

class queue{
     Node* front;
     Node* back;
     public:
     queue()
     {
        front=NULL;
        back=NULL;
     }

     void push(int x)
     {
        Node* node = new Node(x);

        if(front==NULL)
        {
            front=node;
            back=node;
            return;
        }
        back->next=node;
        back=node;
     }
     void pop()
     {
        if(front==NULL)
        {
            cout<<" no element in queue"<<endl;
            return;
        }
        Node* del = front;
        front=front->next;
        free(del);
//        delete del;
     }
     int peak()
     {
      //   if(front==NULL)
      //       return -1;
      //   return front->data;
      return front==NULL ? -1 : front->data;
     }  

     bool empty()
     {
        if(front==NULL)
            return true;
        return false;
     }
};

int main()
{
    queue q;
    q.push(1);
    cout<< q.peak();
}