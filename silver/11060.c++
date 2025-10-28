#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
    int start,move,t;
}jump;
void bfs(vector<int>&arr,int n)
{
    queue<jump>q;
    q.push({1,arr[1],1});
    vector<bool>vis(n+1,false);
    vis[1]=true;
    while(!q.empty())
    {
        jump j=q.front();
        q.pop();
        if (j.start==n){
            cout<<j.t-1;return;
        }
        for(int i=1;i<=j.move;i++)
        {
            if (j.start+i<=n&&!vis[j.start+i])
            {
                vis[j.start+i]=true;
                q.push({j.start+i,arr[j.start+i],j.t+1});
            }
        }
    }
    cout<<-1;
}
int main(void)
{
    int n;cin>>n;
    vector<int> arr(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    bfs(arr,n);
    return 0;
}
