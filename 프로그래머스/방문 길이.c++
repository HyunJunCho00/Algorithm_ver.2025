#include<bits/stdc++.h>

using namespace std;

int solution(string dirs) {
    int x=0,y=0;
    vector<vector<bool>>vis(11,vector<bool>(11,false));
    set<pair<pair<int,int>,pair<int,int>>>s;
    for (int i=0;i<dirs.length();i++)
    {
        int nx=x,ny=y;
        if (dirs[i]=='L')nx-=1;
        else if (dirs[i]=='R')nx+=1;
        else if (dirs[i]=='U')ny+=1;
        else ny-=1;
        
        if (nx<-5||nx>5||ny<-5||ny>5)
            continue;
        s.insert({{x,y},{nx,ny}});
        s.insert({{nx,ny},{x,y}});
        x=nx,y=ny;
    }
    return s.size()/2;
}
