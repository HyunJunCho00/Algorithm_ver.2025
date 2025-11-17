#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;cin>>n;
    int s=0,e,cnt=0;
    priority_queue<int> pq;
    cin>>s;
    for(int i=1;i<n;i++)
    {
        cin>>e;
        pq.push(e);
    }
    while(1)
    {
        if (pq.empty())
            break;
        int com=pq.top();
        if (com<s)
            break;
        com-=1;
        s+=1;
        cnt++;
        pq.pop();
        pq.push(com);
    }
    cout<<cnt;
    return 0;
}
