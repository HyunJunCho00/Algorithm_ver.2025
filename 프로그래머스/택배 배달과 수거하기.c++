#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
   int dist,cost; 
    bool operator>(const node&other) const{
        return dist<other.dist;
    };
}g;
long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    priority_queue<g,vector<g>,greater<g>>pq;
    priority_queue<g,vector<g>,greater<g>>pp;
    for(int i=0;i<n;i++)
    {
        int d=deliveries[i],p=pickups[i];
        if (d) pq.push({i+1,d});
        if (p) pp.push({i+1,p});
    }

    
    while(!pq.empty()||!pp.empty())
    {
        int max_dist=0;
        if (!pq.empty()) max_dist=max(max_dist,pq.top().dist);
        if (!pp.empty()) max_dist=max(max_dist,pp.top().dist);
        answer+=2*(long long)max_dist;
        int move=cap;
        while(!pq.empty()&&move>0)
        {
            g gg=pq.top();
            pq.pop();
            if (move-gg.cost<0)
            {
                pq.push({gg.dist,gg.cost-move});
            }
            move-=gg.cost;
        }
        move=cap;
        while(!pp.empty()&&move>0)
        {
            g gg=pp.top();
            pp.pop();
            if (move-gg.cost<0)
            {
                pp.push({gg.dist,gg.cost-move});
            }
            move-=gg.cost;
        }
    }
    return answer;
}
