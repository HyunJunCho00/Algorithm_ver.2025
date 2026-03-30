#include<bits/stdc++.h>
using namespace std;

vector<int> solution(long long begin, long long end) 
{
    vector<int>answer;
    for (long long i = begin; i <= end; i++) {
        if (i == 1) {
            answer.push_back(0);
            continue;
        }
        int max_div=1;
        for(int k=2;k*k<=i;k++)
        {
            if (i%k==0)
            {
                if (i/k<=10000000)
                {
                    max_div = (int)(i / k);
                    break;                        
                }
                max_div=(int)k;
            }
        }
        answer.push_back(max_div);

    }
    return answer;
}
