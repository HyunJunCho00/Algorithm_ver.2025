#include<bits/stdc++.h>
using namespace std;
int arr[2200][2200];
int cnt[3];
bool check(int x,int y,int r)
{
    int ch1=arr[x][y];
    for(int i=x;i<x+r;i++)
    {
        for(int k=y;k<y+r;k++)
        {
            if (ch1!=arr[i][k]) return false;
        }
    }
    return true;
}
void recur(int x,int y,int r,int n)
{
    if (x>n||y>n)return;
    if (check(x,y,r))
    {
        cnt[1-arr[x][y]]++;
        return;
    }
    if (r==3)
    {
        for(int i=x;i<x+r;i++)
        {
            for(int k=y;k<y+r;k++)
            {
                cnt[1-arr[i][k]]++;
            }
        }
        return;
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            recur(x+i*r/3,y+j*r/3,r/3,n);
        }
    }
}
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int k=0;k<n;k++)
        {
            cin>>arr[i][k];
        }
    }
    recur(0,0,n,n);
    for(int i=2;i>=0;i--)
        cout<<cnt[i]<<'\n';
    return 0;
}
