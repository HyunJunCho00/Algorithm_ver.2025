#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer(2,0);
    for(int i=0;i<park.size();i++)
    {
        for(int k=0;k<park[i].size();k++)
        {
            if (park[i][k]=='S')
            {
                answer[0]=i,answer[1]=k;
                park[i][k]='O';
            }
        }
    }
    for(int i=0;i<routes.size();i++)
    {
        char r=routes[i][0];int move=(routes[i][2])-'0';
        int sx=answer[0],sy=answer[1];
        int nx=r=='S'?sx+move:sx-move;
        int ny=r=='E'?sy+move:sy-move;
        if (r=='S')
        {
            for(int i=sx;i<=nx&&i<park.size();i++)
            {
                if (park[i][sy]=='X')
                    break;
                if (i==nx)
                    answer[0]=i;
            }
        }
        else if (r=='W')
        {
            for(int i=sy;i>=ny&&i>=0;i--)
            {
                if (park[sx][i]=='X')
                    break;
                if (i==ny)
                    answer[1]=i;
            }
        }
        else if (r=='N')
        {
            for(int i=sx;i>=nx&&i>=0;i--)
            {
                if (park[i][sy]=='X')
                    break;
                if (i==nx)
                    answer[0]=i;
            }
        }
        else
        {
            for(int i=sy;i<park[0].size()&&i<=ny;i++)
            {
                if (park[sx][i]=='X')
                    break;
                if (i==ny)
                    answer[1]=i;
            }
        }
    }
    return answer;
}
