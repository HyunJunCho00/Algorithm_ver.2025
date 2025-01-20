#include <bits/stdc++.h>
using namespace std;
vector <int>arr;
vector <int>save;
void dfs(int depth,int start,int m,int n)
{
    if (depth==m)
    {
        for (int num:save)
            cout<<num<<' ';
        cout<<'\n';
    }
    else
    {
        for (int i=start;i<n;i++)
        {
            if (i>0&&arr[i]==arr[i-1])
                continue;
            save.push_back(arr[i]);
            dfs(depth+1,i,m,n);
            save.pop_back();
        }
    }
}
int main(void)
{
    int n,m;
    cin>>n>>m;
    arr.assign(n,0);
    for (int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr.begin(),arr.end());
    dfs(0,0,m,n);
    return 0;
}
