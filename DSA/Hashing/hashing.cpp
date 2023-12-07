#include <iostream>
using namespace std;
#define MAX 1000

bool hashTable[MAX+1][2];
void insert(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]>=0)
            hashTable[arr[i]][0]=true;
        else
            hashTable[arr[abs(i)]][1]=true;

        
    }
}
bool search(int key)
{
    if(key>=0)
    {
        if(hashTable[key][0]==1)
        {
            return true;
        }
        else{
            return false;
        }
    }else{
        if(hashTable[abs(key)][1]==1)
        {
            return true;
        }
        else{
            return false;
        }
    }
}
int main()
{
    int arr[]={-1,9,2,-5,3,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    insert(arr,size);
    
    if(search(9))
        cout<<"true"<<endl;
    else    
        cout<<"false"<<endl;
    
    return 0;
}