#include<bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
vector<vector<int>>mapp,dice;
void build(int move,int x,int y)
{
    vector<int>save(4,0);
    if (move<=2)
    {
        if (move==1)
        {
            mapp[x][y]==0?(mapp[x][y]=dice[1][2]):(dice[1][2]=mapp[x][y],mapp[x][y]=0); 
            for(int i=0;i<3;i++)save[i]=dice[1][i];
            save[3]=dice[3][1];
            dice[1][0]=save[3];dice[1][1]=save[0];dice[1][2]=save[1];dice[3][1]=save[2];
        }
        else
        {
            mapp[x][y]==0?(mapp[x][y]=dice[1][0]):(dice[1][0]=mapp[x][y],mapp[x][y]=0); 
            for(int i=0;i<3;i++)save[i]=dice[1][i];
            save[3]=dice[3][1];
            dice[1][0]=save[1];dice[1][1]=save[2];dice[1][2]=save[3];dice[3][1]=save[0];
        } 
    }
    else
    {
        if (move==3)
        {
            mapp[x][y]==0?(mapp[x][y]=dice[0][1]):(dice[0][1]=mapp[x][y],mapp[x][y]=0); 
            for(int i=0;i<4;i++)save[i]=dice[i][1];        
            for(int i=2;i>=0;i--)dice[i][1]=save[i+1];
            dice[3][1]=save[0];
        }
        else
        {
            mapp[x][y]==0?(mapp[x][y]=dice[2][1]):(dice[2][1]=mapp[x][y],mapp[x][y]=0);
            for(int i=0;i<4;i++)save[i]=dice[i][1];        
            for(int i=0;i<3;i++)dice[i+1][1]=save[i];
            dice[0][1]=save[3];
        }   
    }
    cout<<dice[1][1]<<'\n';
}
int main(void)
{
    fastIO;
    int n,m,x,y,k;
    cin>>n>>m>>x>>y>>k;
    dice.assign(4,vector<int>(3,0));
    mapp.assign(n,vector<int>(m,0));
    for(int i=0;i<n;i++)for(int k=0;k<m;k++)cin>>mapp[i][k];
    for(int i=0;i<k;i++)
    {
        int cur;cin>>cur;
        if (cur>=3)
        {
            int next=cur%2?next=-1:next=1;
            if (0<=x+next&&x+next<n)
            {
                build(cur,x+next,y); x+=next;
            }
            else continue;
        }
        else
        {
            int next=cur%2?next=1:next=-1;
            if (0<=y+next&&y+next<m)
            {
                build(cur,x,y+next);y+=next;
            }
            else continue;
        }
    }
    return 0;
}
