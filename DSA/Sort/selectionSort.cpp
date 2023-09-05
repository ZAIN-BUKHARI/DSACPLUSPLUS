// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
    int n=5;
    int arr[5]={30,2,56,34,1};
    
    for(int i =0;i<n;i++){
        for(int j =i+1;j<n;j++){
            if(arr[j]<arr[i]){
                int temp = arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }

    return 0;
}