#include <bits/stdc++.h>
#define fastIO ios:: sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
vector<bool>visited;
vector<vector<int>> arr;
vector<int>save;
vector<int>other;
int sum=99999999,ind=0;
void dfs(int depth,int s,int m,int n)
{
    if (depth==m)
    {
        other.assign(n/2,0);
        int idx=0;
        for (int i=1;i<=n;i++)
            if (!visited[i])
                other[idx++]=i;
        int origin=0,comp=0;
        for (int i=0;i<ind;i++)
        {
            for (int k=0;k<ind;k++)
            {
                if (i==k)
                    continue;
                origin+=arr[save[i]][save[k]]; comp+=arr[other[i]][other[k]];
            }
        }
        sum=min(sum,abs(origin-comp));
    }
    else
    {
        for (int i=s;i<=n;i++)
        {
            if (!visited[i])
            {
                visited[i]=true;
                save[ind++]=i;
                dfs(depth+1,i,m,n);
                visited[i]=false; 
                ind--;
            }
        }
    }
}
int main(void)
{
    fastIO;
    int n;
    cin>>n;
    save.assign(n/2,0);
    arr.assign(n+1,vector<int>(n+1,0));
    visited.assign(n+1,false);
    for (int i=1;i<=n;i++)
        for (int k=1;k<=n;k++)
            cin>>arr[i][k];
    dfs(0,1,n/2,n);
    cout<<sum<<'\n';
    return 0;
}
