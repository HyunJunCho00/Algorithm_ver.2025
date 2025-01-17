#include <bits/stdc++.h>
using namespace std;
vector <int> arr;
vector <bool>visited;
vector <int>save;
void dfs(int depth,int start,int m,int n)
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
        for (int i=start;i<n;i++)
        {
            if (!visited[i])
            {
                visited[i]=true;
                save.push_back(arr[i]);
                dfs(depth+1,i,m,n);
                save.pop_back();
                visited[i]=false;

            }
        }
    }
}
int main(void)
{
    int n;

    while(1)
    {
        cin>>n;
        if (n==0)
            break;
        arr.clear();
        visited.clear();
        save.clear();
        visited.assign(n,false);
        arr.assign(n,0);
        for (int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        dfs(0,0,6,n);
        cout<<'\n';
    }
    return 0;
}
