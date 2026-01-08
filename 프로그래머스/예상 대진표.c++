#include<bits/stdc++.h>
using namespace std;
int solution(int n, int a, int b)
{
    int two=2;
    int answer=0;
    while(1)
    {
        bool ch=false;
        for(int i=1;i<=n/two;i++)
        {
            int left=two*(i-1)+1,right=two*(i);
            //cout<<i<<' '<<left<<' '<<right<<' '<<answer<<'\n';
            if (a>=left&&a<=right&&b>=left&&b<=right)
            {
                ch=true;break;
            }
        }
        answer++;
        two*=2;
        if (ch)break;
    }

    return answer;

}
