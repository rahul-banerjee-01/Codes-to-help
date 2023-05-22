#include <bits/stdc++.h>
using namespace std;

int check_occurence(string str, string pattern)
{
    int len = 0;
    int flag = 0;
    int match = 0;
    int str_len = str.length();
    int pat_len = pattern.length();
    for (int i = 0; i < str_len; i++)
    {
        if (len == pat_len)
        {
            cout << "\nMatch found at index : " << match;
            match = 0;
            len = 0;
            flag++;
        }
        if (str[i] == pattern[len])
        {
            if (len == 0)
            {
                match = i;
            }
            len += 1;
        }
        else
        {
            match = 0;
            len = 0;
        }
    }
    if (len == pat_len && pattern[pat_len - 1] == str[str_len - 1])
    {
        cout << "\nMatch found at index : " << str_len - pat_len;
        flag++;
    }

    return (flag);
}

int main()
{
    string str, pattern;
    cout << "\nEnter the string : " << endl;
    getline(cin, str);
    cout << "\nEnter the pattern to be searched :" << endl;
    cin >> pattern;
    int result = check_occurence(str, pattern);
    if (result != 0)
        cout << "\n\nOccurences found : " << result;
    if (result == 0)
        cout << "\n\nNo Occurences found!";
}

