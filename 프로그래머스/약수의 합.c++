#include<bits/stdc++.h>
using namespace std;

int solution(int n) 
{
    int answer = 0;
    for(int i=1;i<=n;i++)
    {
        (n%i)?answer:answer+=i;
    }
    return answer;
}
