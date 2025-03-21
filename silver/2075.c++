#include<bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int main(void)
{
    fastIO;
    int n;cin>>n;
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<n;i++)
    {
        for (int k=0;k<n;k++)
        {
            int c;cin>>c;
            int size=pq.size();
            if (size<n)pq.push(c);
            else
            {
                if(pq.top()<=c)
                {
                    pq.pop();pq.push(c);   
                }
            }
        }     
    }
    cout<<pq.top();
    return 0;
}
