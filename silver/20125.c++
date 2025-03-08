#include<bits/stdc++.h>
using namespace std;
void build(vector<vector<bool>>&cook,int x,int y,int n)
{
    int i=x,k=y,cnt=0;
    while(k>0&&cook[i][--k])cnt++;
    cout<<cnt<<' ';
    i=x,k=y,cnt=0;
    while(k<n-1&&cook[i][++k])cnt++;
    cout<<cnt<<' ';
    i=x,k=y,cnt=0;
    while(i<n-1&&cook[++i][k])cnt++;
    cout<<cnt<<' ';
    x=i,cnt=0;
    while(i<n&&cook[i++][k-1])cnt++;
    cout<<cnt<<' ';
    i=x,cnt=0;
    while(i<n&&cook[i++][k+1])cnt++;
    cout<<cnt<<' ';
}
int main(void)
{
    int n;cin>>n;
    vector<vector<bool>>cook(n,vector<bool>(n,false));
    int x=-1,y=-1;
    for(int i=0;i<n;i++)
    {
        for(int k=0;k<n;k++)
        {
            char c;cin>>c;
            c=='*'?(x==-1&&y==-1)?(x=i,y=k,cook[i][k]=true):cook[i][k]=true:0; 
        }
    }
    cout<<x+2<<' '<<y+1<<'\n';
    build(cook,x+1,y,n);
    return 0;
}
