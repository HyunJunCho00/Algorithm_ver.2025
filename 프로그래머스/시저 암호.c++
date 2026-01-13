#include<bits/stdc++.h>
using namespace std;

string solution(string s, int n) 
{
    string answer = "";
    for(char ss:s)
    {
        if ('a'<=ss&&ss<='z')
            if (ss+n<=122)
                answer+=ss+n%26;
            else
                answer+='a'+(ss+n-97)%26;
        else if ('A'<=ss&&ss<='Z')
            if (ss+n<=90)
                answer+=ss+n%26;
            else
                answer+='A'+(ss+n-65)%26;
        else
            answer+=ss;
    }
    return answer;
}
