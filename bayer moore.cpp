
#include <bits/stdc++.h>
using namespace std;

void badCharInit(string str, int size, int badchar[256])
{
    int i;
    for (i = 0; i < 256; i++)
        badchar[i] = -1;

    for (i = 0; i < size; i++)
        badchar[(int)str[i]] = i;
}

int search(int found, string txt, string pat)
{
    int m = pat.size();
    int n = txt.size();

    int badchar[256];

    badCharInit(pat, m, badchar);

    int s = 0;
    while (s <= (n - m))
    {
        int j = m - 1;

        while (j >= 0 && pat[j] == txt[s + j])
            j--;

        if (j < 0)
        {
            cout << "\nPattern occurs at index = " << s << endl;
            found = 1;
            if ((s + m) < n)
                s += m - badchar[txt[s + m]];
            else
                s += 1;
        }

        else
            s += max(1, j - badchar[txt[s + j]]);
    }
    return found;
}

int main()
{
    string txt;
    string pat;

    cout << "Enter the text : ";
    getline(cin, txt);

    cout << "Enter the pattern : ";
    getline(cin, pat);

    int found = search(0, txt, pat);

    if (found == 0)
        cout << "\nNot Found!";
    return 0;
}

