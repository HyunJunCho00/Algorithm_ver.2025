#include <bits/stdc++.h>
using namespace std;
vector <int> arr;
vector <bool> visited;
vector <int> save;
void dfs(int depth,int m,int n)
{
    if (depth==m)
    {
        for (int num:save)
        {
            cout<<num<<' ';
        }
        cout<<'\n';
    }
    else
    {
        for (int i=1;i<=n;i++)
        {
            if (!visited[i])
            {
                visited[i]=true;
                save.push_back(arr[i]);
                dfs(depth+1,m,n);
                save.pop_back();
                visited[i]=false;
            }
            else
            {
                save.push_back(arr[i]);
                dfs(depth+1,m,n);
                save.pop_back();
            }
        }
    }
}
int main(void)
{
    int n,m;
    cin>>n>>m;
    arr.assign(n+1,0);
    for (int i=1;i<=n;i++)
        arr[i]=i;
    visited.assign(n+1,false);
    dfs(0,m,n);
    return 0;
}
