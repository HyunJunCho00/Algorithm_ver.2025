#include<bits/stdc++.h>
using namespace std;
int bfs(int st)
{
    int cnt=0;
    while(st)
    {
        int div=st%10;
        if (div>5)
        {
            st+=10;
            cnt+=(10-div);
        }
        else if (div<5)
        {
            cnt+=div;
        }
        else
        {
            cnt+=div;
            if ((st/10)%10>=5)
                st+=10;
        }
        st/=10;
    }
    return cnt;
}
int solution(int storey) 
{
    int answer = bfs(storey);

    return answer;
}
