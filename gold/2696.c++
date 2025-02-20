#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int main(void)
{
    fastIO;int t;cin>>t;
    for (int i=0;i<t;i++)
    {
        int m,n;cin>>m;
        priority_queue<int,vector<int>,greater<int>>min_pq;
        priority_queue<int>max_pq; vector<int>save;
        for (int k=1;k<=m;k++)
        {
            cin>>n;
            if (max_pq.empty())
                max_pq.push(n);
            else
            {
                if (max_pq.top()>=n)
                {
                    max_pq.push(n);
                    if (min_pq.empty())
                    {
                        int tp=max_pq.top();
                        max_pq.pop();
                        min_pq.push(tp);
                    }
                    else
                    {
                        while(max_pq.size()>min_pq.size()+1)
                        {
                            int tp=max_pq.top();
                            max_pq.pop();
                            min_pq.push(tp);
                        }
                    }
                }
                else
                {
                    min_pq.push(n);
                    while(min_pq.size()>=max_pq.size()+1)
                    {
                        int tp=min_pq.top();
                        min_pq.pop();
                        max_pq.push(tp);
                    }
                }
            }
            if (k%2)
                save.push_back(max_pq.top());
        }
        cout<<(m+1)/2<<'\n';
        for (int k=1;k<=save.size();k++)
        {
            cout<<save[k-1]<<' ';
            if (k%10==0)cout<<'\n';
        }
        cout<<'\n';
    }
    return 0;
}
