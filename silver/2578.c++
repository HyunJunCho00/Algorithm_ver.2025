#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef struct node
{
    int x,y;
}node;
bool check(vector<vector<bool>>&bingo)
{
    bool ch=true;
    int count=0;
    for (int i=0;i<5;i++)
    {
        for(int k=0;k<5;k++)
        {
            if (!bingo[i][k])
            {
                ch=false;break;
            }
        }
        if (ch) count++;
        ch=true;
        for(int k=0;k<5;k++)
        {
            if (!bingo[k][i])
            {
                ch=false;break;
            }
        }
        if (ch) count++;
        ch=true;
    }
    for(int i=0;i<5;i++)
    {
        if (!bingo[i][i])
        {
            ch=false;break;
        }
    }
    if (ch) count++;
    ch=true;
    for(int i=0;i<5;i++)
    {
        if (!bingo[i][4-i])
        {
            ch=false;break;
        }
    }
    if (ch) count++;

    if (count>=3) return true;
    return false;
}
int main(void)
{
    IOS;
    vector<vector<int>> arr(5,vector<int>(5,0));
    vector<vector<bool>>bingo(5,vector<bool>(5,false));
    node corr[26];
    for(int i=0;i<5;i++)
    {
        for(int k=0;k<5;k++)
        {
            cin>>arr[i][k];
            corr[arr[i][k]].x=i,corr[arr[i][k]].y=k;
        }
    }
    int count=1;
    while(1)
    {
        int num;
        cin>>num;
        bingo[corr[num].x][corr[num].y]=true;
        if (check(bingo)) break;
        count++;
    }
    cout<<count;
    return 0;
}
