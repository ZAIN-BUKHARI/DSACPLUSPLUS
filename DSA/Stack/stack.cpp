#include <iostream>
using namespace std;
#define n 5
class Stack
{   
    private:
    int *arr;
    int top;

    public:
        Stack(){
            arr = new int[n];
            top=-1;
        }
    void push(int x){
        if(top==n-1){
        cout<<"Stack is overloaded"<<endl;
            return;
        }
        top++;
        arr[top]=x;
    }
    void pop(){
        if(top==-1){
            cout<<"no element to pop"<<endl;
            return;
        }
        top--;
    }
    int Top(){
        if(top==-1){
            cout<<"no element in stack"<<endl;
            return -1;
        }
        return arr[top];
    }
     bool empty(){
        if(top==-1){
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.empty()<<endl;

}