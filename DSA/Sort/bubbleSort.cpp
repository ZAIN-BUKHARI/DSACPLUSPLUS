// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
    int n=5;
    int arr[5]={30,2,56,34,1};
    int count=1;

    while(count<n)
    {
        for(int i=0;i<n-count;i++)
        {
            if(arr[i]>arr[i+1])
            {
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1]=temp;
            }
        }
        count++;
    }
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }

    return 0;
}