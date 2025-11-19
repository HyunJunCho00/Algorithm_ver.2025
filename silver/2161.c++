#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;cin>>n;
    deque<int>dq;
    for(int i=1;i<=n;i++)
    {
        dq.push_back(i);
    }
    deque<int>dqq;
    while(!dq.empty())
    {
        int d=dq.front();
        dq.pop_front();
        dqq.push_back(d);
        if (dq.empty())break;
        d=dq.front();
        dq.pop_front();
        dq.push_back(d);
    }
    while(!dqq.empty())
    {
        cout<<dqq.front()<<' ';
        dqq.pop_front();
    }
    return 0;
}
