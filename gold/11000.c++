#include <bits/stdc++.h>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct node
{
    int s,e;
}Room;
bool compare(const Room& p1,const Room& p2)
{
    if (p1.s==p2.s)
    {
        return p1.e<p2.e;
    }
    return p1.s<p2.s;
}
int main(void)
{
    int n;
    cin>>n;
    int s,e;
    priority_queue<int,vector<int>,greater<int>> pq;
    vector <Room> t;
    Room room;
    for (int i=0;i<n;i++)
    {
        scanf("%d %d",&room.s,&room.e);
        t.push_back(room);
    }
    sort(t.begin(),t.end(),compare);
    pq.push(t[0].e);
    for (int i=1;i<n;i++)
    {
        if (pq.top()>t[i].s)
        {
            pq.push(t[i].e);
        }
        else
        {
            pq.pop();
            pq.push(t[i].e);
        }
    }
    cout<< pq.size();
    return 0;
}

