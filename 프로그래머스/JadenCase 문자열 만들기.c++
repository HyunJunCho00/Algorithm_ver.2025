#include<bits/stdc++.h>
using namespace std;

string solution(string s) 
{
    int idx=0;
    for(char&ss:s)
    {
        if (isalpha(ss))
        {
            if (isupper(ss))
            {
                if (idx)
                {
                    ss=tolower(ss);
                }
            }
            else
            {
                if (!idx)
                {
                    ss=toupper(ss);
                }
            }
            idx++;
        }
        else if (isdigit(ss))
        {
            idx++;
        }
        else
        {
            idx=0;
        }
    }
    return s;
}
