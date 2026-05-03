#include<bits/stdc++.h>
using namespace std;
struct Pos
{
    int x,y;
    bool operator<(const Pos&other) const {
      if(other.x!=x)
          return x<other.x;
        return y<other.y;
    };
};
int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    //time, {coordinate,count}
    map<int,map<Pos,int>>m;
    for(int i=0;i<routes.size();i++)
    {
        int time=0;
        int cur_x=points[routes[i][0]-1][0];
        int cur_y=points[routes[i][0]-1][1];
        m[time][{cur_x,cur_y}]++;
        for(int k=1;k<=routes[i].size()-1;k++)
        {
            int next_x=points[routes[i][k]-1][0];
            int next_y=points[routes[i][k]-1][1];
            while(cur_x!=next_x)
            {
                if (cur_x<next_x)cur_x++;
                else cur_x--;
                time++;
                m[time][{cur_x,cur_y}]++;
            }
            while(cur_y!=next_y)
            {
                if (cur_y<next_y)cur_y++;
                else cur_y--;
                time++;
                m[time][{cur_x,cur_y}]++;
            }
        }
    }
    
    for(auto&mm:m)
    {
        for(auto&coordinate:mm.second)
        {
            if(coordinate.second>1)
                answer++;
        }
    }
    return answer;
}
