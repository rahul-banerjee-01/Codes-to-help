
#include<iostream>
#include<vector>
using namespace std;

void selection_sort(vector<int> &arr)
{
    int temp;
    for(int i=0;i<arr.size();i++)
    {
      for(int j=i;j<arr.size();j++)
      {
        if(arr[j]<=arr[i])
        {
          temp=arr[i];
          arr[i]=arr[j];
          arr[j]=temp;
        }
      }
    }
}
void bubble_sort(vector<int> &arr)
{
  int temp;
  for(int i=0;i<arr.size();i++)
  {
    for(int j=0;j<arr.size()-i;j++)
    {
      if(arr[j]>arr[j+1])
      {
        temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
      }
    }
  }
}
void insertion_sort(vector<int> &arr)
{
  for(int i=1;i<arr.size();i++)
  {
    int current=arr[i];
    int j=i-1;
    while(arr[j]>current && j>=0)
    {
      arr[j+1]=arr[j];
      j--;
    }
    arr[j+1]=current;
  }
}

void quick_sort(vector<int> &arr)
{

}

int partition(vector<int> &A,int low, int high)
{
    int pivot = A[high]; 
    int i = (low - 1); 
    for (int j = low; j <= high - 1; j++)
    {
        
        if (A[j] < pivot)
        {
            i++; 
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[high]);
    return (i + 1);
}

void quick_sort(vector<int> &A, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(A, low, high);
        quick_sort(A, low, pivot - 1);
        quick_sort(A, pivot + 1, high);
    }
}


void merge(vector<int> &a,int low,int mid,int high)
{
    int n1=mid-low+1;
    int n2=high-mid;
    int left[n1];
    int right[n2];
    for(int i=0;i<n1;i++)
        left[i]=a[low+i];
    
    for(int i=0;i<n2;i++)
        right[i]=a[mid+i+1];
    

    int i=0,j=0,k=low;
    while(i<n1 && j<n2)
    {
        if(left[i]<=right[j])
        {
            a[k]=left[i];
            i++; 
            k++;
        }
        else
        {
            a[k]=right[j];
            k++;
            j++;
        }
    }
    while(i<n1)
    {
        a[k]=left[i];
        i++;
        k++;

    }
    while(j<n2)
    {
        a[k]=right[j];
        j++;
        k++;
    }
}
void merge_sort(vector<int> &arr,int l,int r)
{
    if(l<r){
        int m=l+(r-l)/2;
        merge_sort(arr,l,m);
        merge_sort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}


int getMax_fromList(vector<int> &array, int size) 
{
   int max = array[0];
   for(int i = 1; i<size; i++) {
      if(array[i] > max)
         max = array[i];
   }
   return max; 
}

void count_sort(vector<int> &array, int size) 
{
  int max = getMax_fromList(array, size);
  int count[max+1] = {0};     
  

  for(int i = 0; i <=size; i++)
    count[array[i]]++;     
  
  vector<int> result;
  for(int i=0;i<=max;i++)
    for(int j=1;j<=count[i];j++)
      result.push_back(i);
  
  array = result;
}





void display(vector<int> arr)
{
  for(int i=0;i<arr.size();i++)
  {
    cout<<arr[i]<<" ";
  }
}
int main()
{
  vector<int> arr1={5,4,8,1,3,100,59,6,99,4,0,54};
  vector<int> arr6=arr1,arr5=arr1,arr4=arr1,arr3=arr1,arr2=arr1;
  display(arr1);
  cout<<"\n\n";
  
  selection_sort(arr1);
  display(arr1);
  cout<<"\n\n";
  
  bubble_sort(arr2);
  display(arr2);
  cout<<"\n\n";
  
  insertion_sort(arr3);
  display(arr3);
  cout<<"\n\n";
  
  quick_sort(arr4,0,arr4.size()-1);
  display(arr4);
  cout<<"\n\n";

  merge_sort(arr5,0,arr5.size()-1);
  display(arr5);
  cout<<"\n\n";

  count_sort(arr6,arr6.size()-1);
  display(arr6);
  cout<<"\n\n";
  
}
