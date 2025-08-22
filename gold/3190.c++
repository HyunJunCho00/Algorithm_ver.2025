#include<bits/stdc++.h>
using namespace std;
typedef struct point
{
    int x,y;
}point;
int arr[101][101];
int dirx[4]={-1,0,1,0};
int diry[4]={0,1,0,-1};

int main(void)
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<k;i++)
    {
        int r,c;
        cin>>r>>c;
        arr[r][c]=1;
    }
    int l;cin>>l;
    map<int,char>moves;
    for(int i=0;i<l;i++)
    {
        int t;char d;
        cin>>t>>d;
        moves[t]=d;
    }
    deque<point> snake;
    snake.push_back({1,1});
    arr[1][1]=2;
    int dir=1;
    int time=0;

    while(true)
    {
        time++;
        point head=snake.back();
        int next_x=head.x+dirx[dir];
        int next_y=head.y+diry[dir];
        if (next_x<1||next_x>n||next_y<1||next_y>n||arr[next_x][next_y]==2)
        {
            break;
        }

        if (arr[next_x][next_y]==1)
        {
            arr[next_x][next_y]=2;
            snake.push_back({next_x,next_y});
        }
        else
        {
            arr[next_x][next_y]=2;
            snake.push_back({next_x,next_y});
            point tail=snake.front();
            snake.pop_front();
            arr[tail.x][tail.y]=0;
        }

        if (moves.count(time))
        {
            moves[time]=='D'?(dir=(dir+1)%4):(dir=(dir+3)%4);
        }
    }
    cout<<time;
    return 0;
}
