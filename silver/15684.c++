#include <bits/stdc++.h>
using namespace std;
vector <int>arr;
vector <int>sequence;
vector <bool>visited;
void dfs(int depth,int m,int n)
{
    if (depth==m)
    {
        for (int num:sequence)
            cout<<num<<' ';
        cout<<'\n';
    }
    else
    {
        for (int i=0;i<n;i++)
        {
            if (!visited[i])
            {
                visited[i]=true;
                sequence.push_back(arr[i]);
                dfs(depth+1,m,n);
                visited[i]=false;
                sequence.pop_back();
            }

        }
    }
}
int main(void)
{
    int n,m;
    cin>>n>>m;
    arr.assign(n,0);
    visited.assign(n,false);
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    dfs(0,m,n);
    return 0;
}
