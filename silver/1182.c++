#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
vector <int>arr;
vector <bool>visited;
vector <int> save;
int cnt=0;
void dfs(int index,int sum,int s,int n)
{
    if (index==n)
    {
        if (!save.empty()&&s==sum)
            cnt++;
    }
    else
    {
        save.push_back(arr[index]);
        dfs(index+1,arr[index]+sum,s,n);
        save.pop_back();
        dfs(index+1,sum,s,n);
    }
}
int main(void)
{
    int n,s;
    cin>>n>>s;
    cin.ignore();
    arr.assign(n,0);
    visited.assign(n,false);
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    dfs(0,0,s,n);
    cout<<cnt<<'\n';
    return 0;
}
