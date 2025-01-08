#include <bits/stdc++.h>
using namespace std;
vector <int> visited;
vector <int> order;
int main(void)
{
    int n;
    cin>>n;
    visited.assign(1000001,0);
    order.assign(1000001,0);
    for (int i=0;i<n;i++)
    {
        cin>>order[i];
        visited[order[i]]=i;
    }
    int x;
    cin>>x;
    int count=0;
    for (int i=0;i<n-1;i++)
    {
        int diff=x-order[i];
        if (diff>=1&&diff<=1000000)
        {
            if (visited[diff]>i)
                count++;
        }
    }
    cout<<count<<'\n';
    return 0;
}
