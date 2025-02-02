#include <bits/stdc++.h>
using namespace std;
vector <int> n;
vector <int> v;
vector <bool> visited;
void dfs(int depth,int s,int sum,int t,int m)
{
    if (depth==t)
    {
        if (sum==100)
        {
            for(int num:v)
                cout<<num<<'\n';  
            return;
        }
    }
    else
    {
        for (int i=s;i<m;i++)
        {
            if (!visited[i])
            {
                visited[i]=true;
                v.push_back(n[i]);
                dfs(depth+1,i,sum+n[i],t,m);
                v.pop_back();
                visited[i]=false;
            }
        }
    }
}
int main(void)
{
    n.assign(9,0);
    visited.assign(9,false);
    for (int i=0;i<9;i++)
        cin>>n[i];
    dfs(0,0,0,7,9);
    return 0;
}
