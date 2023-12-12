#include <iostream>
using namespace std;

class queue {
    int *arr;
    int front;
    int back;
    int size;

    public:
    queue(int size)
    {
        arr = new int[size];
        front=-1;
        back=-1;
        this->size=size;
    }

    void push(int x)
    {
        if(back==size-1)
        {
            cout<<"queue overflow"<<endl;
            return;
        }
        back++;
        arr[back]=x;

        if(front==-1)
            front++;
            
        
    }
    void pop()
    {
        if(front==-1 || front>back)
        {
            cout<<"no element in queue"<<endl;
            return;
        }
        front++;
    }
    int peak()
    {
        if(front==-1 || front>back)
        {
            cout<<"no element in queue"<<endl;
            return -1;
        }
        return arr[front]; 
    }
    bool empty()
    {
        if(front==-1 || front>back)
            return true;
        return false;
    }
};

int main()
{
    queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();
    while(!q.empty())
    {
        cout<<q.peak()<< " ";
        q.pop();
    }
    return 0;
}