#include<bits/stdc++.h>
using namespace std;

string solution(vector<string> seoul) 
{
    string answer = "";
    int idx=0;
    for(string se:seoul)
    {
        if (se=="Kim")
        {
            break;
        }
        idx++;
    }
    answer="김서방은 ";
    answer+=to_string(idx);
    answer+="에 있다";
    return answer;
}
