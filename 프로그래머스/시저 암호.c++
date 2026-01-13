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


#include<bits/stdc++.h>
using namespace std;

string solution(string s, int n) 
{
    for(char&c:s)
    {
        if ('a'<=c&&c<='z')
        {
            c=(c-'a'+n)%26+'a';
        }
        else if ('A'<=c&&c<='Z')
        {
            c=(c-'A'+n)%26+'A';
        }
    }
    return s;
}
