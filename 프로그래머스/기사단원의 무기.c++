#include<bits/stdc++.h>
using namespace std;

int solution(int number, int limit, int power) 
{
    int answer = 0;
    vector<int>prime(number+1,1);
    for(int i=2;i<=number;i++)
    {
        for(int k=i;k<=number;k+=i)
        {
            prime[k]++;
        }
    }
    for(int i=1;i<=number;i++)
    {
        answer=answer+((prime[i]<=limit)?prime[i]:power);
    }
    return answer;
}
