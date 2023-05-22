#include <iostream>
using namespace std;
int bin_Search(int arr[], int search, int low, int high)
{
    if (high >= low) 
    {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == search)
            return mid;
  
        if (arr[mid] > search)
            return bin_Search(arr, search, low, mid-1);
  
        return bin_Search(arr, search, mid+1, high);
    }
    return -1;
}

int main()
{
    int n;
    cout <<"\n\nEnter number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"\nEnter array elements in ascending order: ";
    for (int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    int search;
    cout<<"\n\nEnter Value to Search: ";
    cin>>search;

    int result=bin_Search(arr,search,0,n-1);

    if(result == -1)
        cout <<"\n"<<search<<" is not present in array";
    else
        cout <<"\n"<<search<<" is present at index " << result;
    
    return 0;
}