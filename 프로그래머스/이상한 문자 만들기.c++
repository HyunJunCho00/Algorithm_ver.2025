#include<bits/stdc++.h>
using namespace std;

string solution(string s) 
{
    int idx=0;
    for(char &ss:s)
    {
        if (!(idx%2))
        {
  
            if ('a'<=ss&&ss<='z')
            {
                ss='A'+(ss-97);
            }
        }
        else
        {

            if ('A'<=ss&&ss<='Z')
            {
                ss='a'+(ss-65);
            }   
        }
        if (ss!=' ')
            idx++;
        else
            idx=0;
    }
    return s;
}
