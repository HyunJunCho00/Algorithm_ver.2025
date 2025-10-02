#include<bits/stdc++.h>
using namespace std;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int check(vector<vector<char>>&a,int ox,int oy,int x,int y,int n)
{
    vector<vector<char>>b=a;
    b[ox][oy]=a[x][y];
    b[x][y]=a[ox][oy];
    int max_res=0;
    for (int i=0;i<n;i++)
    {
        int k=0,len=1;char s=b[i][k];
        while(k<n)
        {
            while(k<n-1&&b[i][k]==b[i][k+1])
            {
                len++;k++;
            }
            max_res=max(max_res,len);
            len=1;k++;
        }
        k=0,len=1,s=b[k][i];
        while(k<n)
        {
            while(k<n-1&&b[k][i]==b[k+1][i]) 
            {
                len++;k++;
            }
            max_res=max(max_res,len);
            len=1;k++;
        }
    }
    return max_res;
}
int main(void)
{
    int n,res=0;cin>>n;
    vector<vector<char>>a(n,vector<char>(n));
    for(int i=0;i<n;i++)
    {
        string s;cin>>s;
        for(int k=0;k<n;k++)
        {
            a[i][k]=s[k];
        }
    }
    for(int i=0;i<n;i++)
    {
        for (int k=0;k<n;k++)
        {
            for(int z=0;z<4;z++)
            {
                int nx=i+dx[z],ny=k+dy[z];
                if (nx>=0&&nx<n&&ny>=0&&ny<n)
                {
                    res=max(res,check(a,i,k,nx,ny,n));
                }
            }
        }
    }
    cout<<res;
    return 0;
}
