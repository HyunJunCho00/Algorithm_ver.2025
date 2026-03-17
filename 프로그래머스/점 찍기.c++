#include<bits/stdc++.h>
using namespace std;

long long solution(int k, int d) 
{
    long long answer = 0;
    for(int i=0;i<=d;i+=k)
    {
        long long y=(long long)sqrt(1LL*d*d-1LL*i*i);
        answer+=(y/k)+1;
    }
    return answer;
}
