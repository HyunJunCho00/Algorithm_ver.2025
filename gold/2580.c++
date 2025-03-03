#include<bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pii pair<int,int>
using namespace std;
int arr[9][9];
bool row[9][10],col[10][9],box[10][10];
vector<pii>save;
int get_xy(int x,int y)
{
    return (x/3)*3+(y/3);
}
void dfs(int m,int d)
{
    if(d==m)
    {
        for(int i=0;i<9;i++)
        {
            for(int k=0;k<9;k++)
            {
                cout<<arr[i][k]<<' ';
            }
            cout<<'\n';
        }
        exit(0);
    }
    int x=save[d].first,y=save[d].second;
    int b=get_xy(x,y);
    for(int i=1;i<=9;i++)
    {
        if (!row[x][i]&&!col[y][i]&&!box[b][i])
        {
            arr[x][y]=i;
            row[x][i]=col[y][i]=box[b][i]=true;
            dfs(m,d+1);
            row[x][i]=col[y][i]=box[b][i]=false;
            arr[x][y]=0;
        }
    }
}
int main(void)
{
    fastIO;
    for(int i=0;i<9;i++)
    {
        for(int k=0;k<9;k++)
        {
            cin>>arr[i][k];
            if (!arr[i][k])
                save.push_back({i,k});
            else
            {
                int num=arr[i][k];
                row[i][num]=col[k][num]=box[get_xy(i,k)][num]=true;
            }
        }
    }
    dfs(save.size(),0);
    return 0;
}
