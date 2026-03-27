#include<bits/stdc++.h>
using namespace std;
int dist[101][101];
int solution(int n, vector<vector<int>> results) {

    int answer=0;
    for(int i=0;i<results.size();i++)
    {
        int s=results[i][0],e=results[i][1];
        dist[s][e]=true;
    }
    for(int i=1;i<=n;i++)
    {
        for(int k=1;k<=n;k++)
        {
            for(int j=1;j<=n;j++)
            {
                if (dist[k][i]&&dist[i][j]) dist[k][j]=true;
            }
        }
    }
    
    
    for(int i=1;i<=n;i++)
    {
        int cnt=0;
        for(int j=1;j<=n;j++)
        {
            if (i==j)continue;
            if (dist[i][j]||dist[j][i])cnt++;
        }
        if (cnt==n-1)
            answer++;
    }
    
    return answer;
}
