#include<bits/stdc++.h>
using namespace std;
vector <int>arr;
vector <bool>visited;
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
        for (int i=0;i<n;i++)
        {
            if (!visited[i])
            {
                if (i>0&&arr[i]==arr[i-1]&&!visited[i-1])
                {
                    continue;
                }
                save.push_back(arr[i]);
                visited[i]=true;
                dfs(depth+1,m,n);
                visited[i]=false;
                save.pop_back();
            }
        }
    }
}
int main(void)
{
    int n,m;
    cin>>n>>m;
    arr.assign(n,0);
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    visited.assign(n,false);
    sort(arr.begin(),arr.end());
    dfs(0,m,n);
    return 0;
}
