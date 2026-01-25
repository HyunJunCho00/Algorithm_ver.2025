#include<bits/stdc++.h>
using namespace std;
int dx[]={1,0,-1};
int dy[]={0,1,-1};
vector<int> solution(int n) 
{
    vector<int>ans;
    vector<vector<int>>arr(n,vector<int>(n,0));
    
    int x=0,y=0;
    int dir=0;
    int n1=2;
    arr[0][0]=1;
    while(n1<=n*(n+1)/2)
    {
        int x1=x+dx[dir],y1=y+dy[dir];
        if (x1>=0&&x1<n&&y1>=0&&y1<n&&!arr[x1][y1])
        {
            arr[x1][y1]=n1++;
            x=x+dx[dir],y=y+dy[dir];
        }
        else
        {
            dir=(dir+1)%3;
        }
    }
    n1=0;
    for(int i=0;i<n;i++)
    {
        for(int k=0;k<=i;k++)
        {
            ans.push_back(arr[i][k]);
        }
    }
    return ans;
}
