#include <iostream>
#include <stack>
using namespace std;

class queue{
    stack<int> s1;
    stack<int> s2;
    public:

    void push(int x)
    {
        s1.push(x);
    }
    //approch 1 2 stacks
    int pop()
    {
        if(s1.empty() and s2.empty())
        {
            cout<<"empty";
            return-1;
        }
        if(s2.empty())
        {

        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        }
        int topele = s2.top();
        s2.pop();
        return topele;
    }
    //approch 2 recurive using call stack
    int pop()
    {
        if(s1.empty())
        {
            cout<< " empty" << " ";
            return -1;
        }
        int x = s1.top(); // 5        4     3    2   1
        s1.pop(); //       1 2 3 4  1 2 3  1 2   1   return -1 
        if(s1.empty())
        {
            return x;
        }
        int item = pop();
        s1.push(item); // 1  2  3  4  5
        return item;

    }
    bool empty()
    {
        if(s1.empty() and s2.empty())
        {
            return true;
        }
        return false;
    }
};

int main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout<< q.pop()<< " ";
    cout<< q.pop()<< " ";
    cout<< q.pop()<< " ";
    cout<<endl;
    cout<<q.empty();
    return 0;
}