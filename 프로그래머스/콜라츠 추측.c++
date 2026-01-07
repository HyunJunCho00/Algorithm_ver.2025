#include<bits/stdc++.h>
using namespace std;

int solution(int num) 
{
    int cnt=0;
    long long numm=num;
    while(1)
    {
        if (cnt>500)
            return -1;
        if (numm==1)
            break;
        if (numm%2)
        {
            numm=numm*3+1;
        }
        else
        {
            numm/=2;
        }
        cnt++;
    }
    return cnt;
}
