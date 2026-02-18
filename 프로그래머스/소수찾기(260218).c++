#include<bits/stdc++.h>
using namespace std;

int solution(int n) 
{
    int answer = 0;
    vector<bool>prime(1000001,false);
    prime[1]=true;
    int i=2;
    for(int k=2*i;k<=1000000;k+=i)
    {
        prime[k]=true;
    }
    i++;
    while(i*i<=1000000)
    {
        for(int k=i*2;k<=1000000;k+=i)
        {
            prime[k]=true;
        }
        i+=2;
    }
    for(int i=2;i<=n;i++)
    {
        if (!prime[i])answer++;
    }
    return answer;
}
