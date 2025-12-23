#include<bits/stdc++.h>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer=0;
    int s=0,e=9;   
    while(e<discount.size())
    {
        if (!s)
        {
            for(int i=s;i<e+1;i++)
            {
                for(int k=0;k<want.size();k++)
                {
                    if (discount[i]==want[k])
                    {
                        number[k]--;
                        break;
                    }
                }
            }
        }
        else
        {
            for(int k=0;k<want.size();k++)
            {
                if (discount[s-1]==want[k])
                {
                    number[k]++;
                    break;
                }
            }
            for(int k=0;k<want.size();k++)
            {
                if (discount[e]==want[k])
                {
                    number[k]--;
                    break;
                }
            }
        }
        int ch=0;
        for(int i=0;i<want.size();i++)
        {

            if (number[i]<=0)ch++;
        }
        if (ch==want.size())answer++;
        s++,e++;
    }
    return answer;
}
