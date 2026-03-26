#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
    int s,e;
}graph;
int solution(vector<vector<int>> targets) {
    int answer = 0;
    if (targets.size()==1)
        return 1;
    queue<graph>q;
    sort(targets.begin(),targets.end(),[](const vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    });
    q.push({targets[0][0],targets[0][1]});
    int i=1;
    while(i<targets.size())
    {
        while(i<targets.size()&&q.front().e>targets[i][0])
        {
            q.push({targets[i][0],targets[i][1]});
            i++;
        }
        while(!q.empty())
        {
            q.pop();
        }
        answer++;
        if (i==targets.size())break;
        q.push({targets[i][0],targets[i][1]});

    }
    return answer;
}
