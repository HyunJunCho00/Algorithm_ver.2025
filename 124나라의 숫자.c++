#include<bits/stdc++.h>
using namespace std;

string solution(int n) 
{
    string answer="";
    while(n)
    {
        int cur=n%3;
        n/=3;
        if (cur==2)
        {
            answer+="2";
        }
        else if (cur==1)
        {
            answer+="1";
        }
        else
        {
            answer+="4";
            n-=1;
        }
    }
    reverse(answer.begin(),answer.end());
    return answer;
}
