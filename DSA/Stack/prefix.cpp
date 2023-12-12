#include<iostream>
#include<stack>
using namespace std;

int prefixEvalutation(string s){
    stack<int> st;
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0'); }//parsing string to number 
        else{
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();
            switch(s[i]){
                case '+':
                    st.push(op1+op2);
                    break;
                case '-':
                    st.push(op1+op2);
                    break;
                case '/':
                    st.push(op1/op2);
                    break;
                case '*':
                    st.push(op1*op2);
                    break;
            }
        }
    }
    return st.top();
}
int main(){

    cout<<prefixEvalutation("-+7*45+20")<<endl;
    
    return 0;
}

// 1+2/3 infix
// +/123