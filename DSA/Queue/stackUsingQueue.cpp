#include <iostream>
#include <queue>
using namespace std;

class Stack{
    queue<int> q1;
    queue<int> q2;
    public:
    int n;
    Stack()
    {
        n=0;
    }

    void push(int x)
    {
        q2.push(x);
        n++;
        while(!s1.empty())
        {
            q2.push(q1.top());
            q1.pop();
        }
        queue<int> temp = q1;
        q1=q2;
        q2=temp;
    }
    void pop()
    {
        q1.pop();
        n--;
    }
    int top()
    {
        return q1.front();
    }
    
}

int main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);

    return 0;
}