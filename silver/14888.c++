#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define INF 1111111111
using namespace std;
vector<int>arr,save,cal;
vector<bool>visited;
int max_c=-INF,min_c=INF;
void dfs(int d,int m,int n)
{
    if (d==m)
    {
        int res=arr[0];
        for (int i=0;i<save.size();i++)
        {
            if (save[i]==1) res=res+arr[i+1];
            else if (save[i]==2) res=res-arr[i+1];
            else if (save[i]==3) res=res*arr[i+1];
            else res=res/arr[i+1];
        }
        max_c=max(max_c,res);
        min_c=min(min_c,res);
    }
    else
    {
        for (int i=0;i<n-1;i++)
        {
            if (!visited[i])
            {
                visited[i]=true,save.push_back(cal[i]);
                dfs(d+1,m,n);
                save.pop_back(),visited[i]=false;
            }
            
        }
    }
}
int main(void)
{
    fastIO;int n;cin>>n;
    arr.assign(n,0),cal.assign(n-1,0),visited.assign(n-1,false);
    int s_cal[4]={0},idx=0;
    for (int i=0;i<n;i++) cin>>arr[i];
    for (int i=0;i<4;i++) 
    {
        cin>>s_cal[i];
        for (int k=0;k<s_cal[i];k++) cal[idx++]=i+1;
    }
    dfs(0,n-1,n);
    cout<<max_c<<'\n'<<min_c<<'\n';
    return 0;
}
