#include<bits/stdc++.h>
#define pp pair<int,int>
using namespace std;

int solution(int k, vector<int> tangerine) 
{
    map<int,int>m;
    priority_queue<pp>pq;
    for(int i=0;i<tangerine.size();i++)
    {
        m[tangerine[i]]++;
    }
    for(auto&mm:m)
    {
        pq.push({mm.second,mm.first});
    }
    int cnt=0;
    while(!pq.empty())
    {
        pp p=pq.top();
        pq.pop();
        cnt++;
        k-=p.first;
        if (k<=0)break;
    }
    return cnt;
}
