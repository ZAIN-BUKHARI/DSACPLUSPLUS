#include <iostream>
using namespace std;


// program 1
int main()
{
    int n,a=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        a=a+1;
    }

    // linear ∝ n
}

// program 2
int main()
{
    int n,a=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            a=a+1;
        }
    }
//             n x n     
    // quadratic ∝ n power 2
}


// program 3
int main()
{
    int n,m,a=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
            a=a+1;
    }
    for(int j=1;j<=m;j++)
    {
            a=a+1;
    }
//             n + m     
    //      O(n+m) Omega
}

// PROGRAM 4 
int main()
{
    int n,a=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            a=a+1;
        }
    }
//             n x n     
    // O(nm)
}

// PROGRAM 5
int main()
{
    int n,a=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            a=a+1;
        }
    }
    for(int z=1;z<=n;z++)
    {
            a=a+1;   
    }
//             n x n + n   
    // O(n x m + n)
}

int main()
{
    int n,i;
    cin>>n;
    int a=0; 
    i=n;
    while(i >= 1)
    {
        a = a+1;
        i/2;
    }
    //O(logn)
}