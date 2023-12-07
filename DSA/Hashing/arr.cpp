#include <iostream>
using namespace std;
#define MAX 10000

int main()
{
    int arr[MAX];
    for(int i=0;i<MAX;i++)
    {
        arr[i]=i;
        cout<<arr[i];
    }
    
    return 0;
}