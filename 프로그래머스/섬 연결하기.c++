#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
    int n,cost;
}node;
int parent(vector<int>&par,int p)
{
    if (par[p]==p)
        return p;
    return par[p]= parent(par,par[p]);
}
int solution(int n, vector<vector<int>> cost) {
    int answer = 0;
    sort(cost.begin(), cost.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2]<b[2];
    });
    vector<int>par(n+1,0);
    for(int i=1;i<=n;i++)
        par[i]=i;
    for(int i=0;i<cost.size();i++)
    {
        int a=parent(par,cost[i][0]);
        int b=parent(par,cost[i][1]);
        if (a!=b)
        {
            if (a<b)
                par[b]=a;
            else
                par[a]=b;
            answer+=cost[i][2];
        }
    }
    
    return answer;
}
