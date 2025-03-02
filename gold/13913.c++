#include<bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int mov[3]={-1,1,2};
void bfs(int n,int k)
{
    vector<bool>visited(100001,false);
    vector<int>save,move(100001,-1);
    queue<int>q;
    q.push(n);
    visited[n]=true;
    while (!q.empty())
    {
        int cur=q.front(),next=0;q.pop();
        for(int i=0;i<3;i++)
        {
            i==2?next=cur*mov[i]:next=cur+mov[i];
            if (0<=next&&next<=100000&&!visited[next])
            {
                visited[next]=true;
                move[next]=cur;
                q.push(next);
            }
        }
        if (visited[k])
            break;
    }
    save.push_back(k);
    while (move[k]!=-1)
    {
        save.push_back(move[k]);
        k=move[k];
    }
    cout<<save.size()-1<<'\n';
    for(int i=save.size()-1;i>=0;i--)
        cout<<save[i]<<' ';
}
int main(void)
{
    fastIO;int n,k;cin>>n>>k;
    bfs(n,k);
    return 0;
}
