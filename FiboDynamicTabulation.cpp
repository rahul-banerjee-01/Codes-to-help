#include<bits/stdc++.h>
using namespace std;

int fibo(int fibarr[], int n)
{
    if(fibarr[n]==0)
    {
        if(n==0 || n==1)
        {
            fibarr[n] = n;
            return n;
        }
        else
        {
            fibarr[n] = fibo(fibarr,n-1)+fibo(fibarr,n-2);
        }
    }
    
    return fibarr[n];

    
}

main()
{
    int n;
    cin>>n;
    int fibarr[n+1] = {0};

    for(int i=0; i<n; i++)
        cout<<fibo(fibarr,i)<<" ";

}