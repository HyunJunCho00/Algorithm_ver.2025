#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
    int s,e;
}Schedule;
int solution(vector<vector<string>> book_time) 
{
    vector<Schedule>bt;
    for(int i=0;i<book_time.size();i++)
    {
        int s,e;
        for(int k=0;k<2;k++)
        {
            int h=stoi(book_time[i][k].substr(0,2));
            int m=stoi(book_time[i][k].substr(3,2));
            if (k)e=h*60+m+10;
            else s=h*60+m;
        }
        bt.push_back({s,e});
    }
    sort(bt.begin(),bt.end(),[](const Schedule&a,Schedule&b){
        return a.s<b.s;
    });
    priority_queue<int,vector<int>,greater<int>>pq;
    for(Schedule &sd:bt)
    {
        if(!pq.empty()&&pq.top()<=sd.s)
        {
            pq.pop();
        }
        pq.push(sd.e);
    }
    return pq.size();
}
