#include<bits/stdc++.h>

using namespace std;
int outdegree[1000001];
int indegree[1000001];
vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4,0);

    int max_node=0;
    for(int i=0;i<edges.size();i++)
    {
        int a=edges[i][0],b=edges[i][1];
        outdegree[a]++;
        indegree[b]++;
        max_node=max(max_node,a);
        max_node=max(max_node,b);
    }
    int graph=0;
    for(int i=1;i<=max_node;i++)
    {
        if(outdegree[i]>=2&&indegree[i]==0)
        {
             answer[0]=i;    
            graph=outdegree[i];
        }
        if(outdegree[i]==0&&indegree[i]>=1)
            answer[2]++;
        if(outdegree[i]>=2&&indegree[i]>=2)
            answer[3]++;
    }
    answer[1]=graph-answer[2]-answer[3];
    return answer;
}
