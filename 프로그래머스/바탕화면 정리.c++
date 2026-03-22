#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer(4,0);
    answer[0]=51;
    answer[1]=51;
    for(int i=0;i<wallpaper.size();i++)
    {
        for(int k=0;k<wallpaper[i].size();k++)
        {
            if (wallpaper[i][k]=='#')
            {
                answer[0]=min(answer[0],i);
                answer[1]=min(answer[1],k);
                answer[2]=max(answer[2],i+1);
                answer[3]=max(answer[3],k+1);
            }
        }
    }
    return answer;
}
