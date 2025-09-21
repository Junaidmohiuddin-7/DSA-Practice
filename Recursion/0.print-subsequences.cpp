#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void printsubsequences(string s, string output, int i)
{
    if (i == s.size())
    {
        cout << output << endl;
        return;
    }
    char ch = s[i];
    // include
    printsubsequences(s, output + ch, i + 1);
    // exclude
    printsubsequences(s, output, i + 1);
}

int main()
{
    string s = "abc";
    string output = "";
    int i = 0;
    printsubsequences(s, output, i);

    return 0;
}