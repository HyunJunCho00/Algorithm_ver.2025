#include<bits/stdc++.h>

using namespace std;

int solution(string s) 
{
    int answer = 0;
    int count=0,count_oth=0;
    char st;
    for(char ss:s)
    {
        if (count||count_oth)
        {
            if (st==ss)
            {
                count++;
            }
            else
            {
                count_oth++;
                if (count==count_oth)
                {
                    answer++;
                    count=0,count_oth=0;
                }
            }
        }
        else
        {
            count++;
            st=ss;
        }
    }
    if (count||count_oth)
        answer++;
    return answer;
}
