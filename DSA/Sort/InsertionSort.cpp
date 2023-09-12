// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
    int n=5;
    int arr[5]={30,2,56,34,1};
    
    for(int i=1;i<n;i++)
    {
        int current = arr[i]; // 2    at index 1
        int j=i-1;           // 30    at index 0
        while(arr[j]>current && j>=0) // if 30>2
        {
            arr[j+1]=arr[j]; // set 2 = 30 now j set to current 
            j--;   // set j back to index 0
            
        }
        arr[j+1]=current; // set 2 2 
    }
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }

    return 0;
}