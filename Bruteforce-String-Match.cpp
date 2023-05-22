/*
Input String
Input Pattern

find pattern in string
*/


#include<bits/stdc++.h>
using namespace std;


void string_matcher(string str, string ptrn)
{
    bool match_found = false;
    for(int i=0;i<str.length()-ptrn.length()+1;i++)
    {
        bool flag = true;
        for(int j=0, k=i; j<ptrn.length();j++,k++)
        {
            if(str[k]!=ptrn[j])
            {
                flag = false;
                break;
            }
        }
        if(flag == true)
            match_found = true;
    }

    if(match_found)
    {
        cout<<"Match Found!\n\n";
    }
    else
        cout<<"Match not found!\n\n";
}

main()
{
    string str, ptrn;
    cin>>str>>ptrn;
    string_matcher(str,ptrn);
}