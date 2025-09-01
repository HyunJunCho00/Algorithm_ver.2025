#include<bits/stdc++.h>
#define pi pair<int,int>
using namespace std;
int main(void)
{
    deque<pi> dq;
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;cin>>a;
        dq.push_back({i,a});
    }
    for(int i=0;i<n;i++)
    {
        int next=dq.front().second;
        cout<<dq.front().first<<' ';
        dq.pop_front();
        if (dq.empty())break;
        if (next>0)
        {
            for(int k=0;k<next-1;k++)
            {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else
        {
            for(int k=0;k<abs(next);k++)
            {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
    return 0;
}
