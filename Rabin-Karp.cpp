// Rabin-Karp algorithm in C++

#include <string.h>
#include <vector>

#include <bits/stdc++.h>
using namespace std;

#define d 256

void rabinKarp(string pattern, string text, int q) 
{
    int m = pattern.size();
    int n = text.size();
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;
    vector<int> pos;

    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    for (i = 0; i < m; i++) 
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Find the match
    for (i = 0; i <= n - m; i++) 
    {
        if (p == t) 
        {
        for (j = 0; j < m; j++) 
        {
            if (text[i + j] != pattern[j])
            break;
        }

        if (j == m)
            pos.push_back(i);
        }

        if (i < n - m) 
        {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0)
                t = (t + q);
        }

        
    }
    if (!pos.empty())
    {
        cout << "\n\nPattern '"<<pattern<<"' is found at position: ";
        for(i = 0 ; i<pos.size()-1; i++)
            cout<< pos[i]+1 << ", ";
        cout<< pos[i]+1 << endl<< endl<< endl;
    }
    else
    {
        cout << "\n\nPattern '"<<pattern<<"' is not found in the string...\n\n\n\n";
    }
}

int main() 
{
    string txt,pat;
    fflush(stdin);
    cout<<"\n\nEnter Text...: \t\t";
    fflush(stdin);
    getline(cin,txt);
    cout<<"\nEnter Pattern...: \t";
    fflush(stdin);
    getline(cin,pat);
    fflush(stdin);
    int q = 41;

    cout << "\n\nText --> \t"<<txt;
    cout << "\n\nPattern --> \t"<<pat;
    rabinKarp(pat, txt, q);
}