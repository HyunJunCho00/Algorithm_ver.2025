#include<bits/stdc++.h>

using namespace std;

bool solution(int x) 
{
    
    bool answer = true;
    int div=0;
    int xx=x;
    while(1)
    {
        div+=(xx%10);
        xx/=10;
        if (!xx)
            break;
    }
    if (x%div) answer=false;
    return answer;
}
