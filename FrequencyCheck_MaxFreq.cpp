#include<bits/stdc++.h>
#include "conio.h"
#include<vector>
#include<set>
using namespace std;

void freqCheck(vector<int>& v)
{
  set<int> values;
  vector<int> freq;
  for(int i = 0;i<v.size();i++)
    values.insert(v[i]);
  for(auto i:values)
  {
    int count = 0;
      for(auto k:v)
        if(k==i)
          count++;
    freq.push_back(count);
  }
  vector<int> keys;
  for(auto i: values)
    keys.push_back(i);

  int max = freq.front();

  for(int i:freq)
    if(i>max)
      max = i;

  cout<<endl<<endl<<"Frequency Table: \n";
  for(int i = 0;i<freq.size();i++)
    cout<<keys[i]<<"->"<<freq[i]<<"\n";


  cout<<endl<<endl<<"Maximum frequency: \n";
  for(int i = 0;i<freq.size();i++)
    if(max==freq[i])
      cout<<keys[i]<<"->"<<freq[i]<<"\n";

  cout<<endl<<endl<<"Singular Elements: \n";
  for(int i = 0;i<freq.size();i++)
    if(1==freq[i])
      cout<<keys[i]<<"->"<<freq[i]<<"\n";
}

main()
{
  vector<int> v;
  int n;
  cin>>n;
  while(n--)
  {
    int inp;
    cin>>inp;
    v.push_back(inp);
  }
  
  freqCheck(v);
}

//1.palindrome check
//2. Linked List Link check
//3. Left view of Tree
//4. Find frequency of each number in a list, and max frequency
//5. Find number with no repetetion in list.