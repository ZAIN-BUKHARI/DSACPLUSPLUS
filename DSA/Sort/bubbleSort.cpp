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
            if(arr[i]>arr[i+1]) //30 > 2 yes
            {
                int temp = arr[i]; //temp = 30
                arr[i] = arr[i+1]; // 30 = 2
                arr[i+1]=temp;    // 2 = temp which is euqal to 30
            }
        }
        count++;
    }
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }

    return 0;
}