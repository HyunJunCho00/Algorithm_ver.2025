#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int N,m,M,T,R,time=0,cnt=0;
    cin>>N>>m>>M>>T>>R;
    int now=m;
    if (now+T>M&&now-R<m)
    {
        cout<<-1;
    }
    else
    {
        while(cnt!=N)
        {
            now+T<=M?(now+=T,cnt++):now-R<m?(now=m):now-=R;
            time++;
        }
        cout<<time;
    }
    return 0;
}
