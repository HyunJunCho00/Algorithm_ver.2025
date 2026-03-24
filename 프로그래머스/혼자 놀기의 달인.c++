#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> cards) 
{
    int answer = 0;
    vector<bool>vis(cards.size(),false);
    vector<int>score;
    for(int i=0;i<cards.size();i++)
    {
        int t=i,size=0;
        while(!vis[t])
        {
            vis[t]=true;
            size++;
            t=cards[t]-1;
        }
        if (size)
            score.push_back(size);
    }
    sort(score.begin(),score.end(),[](int a,int b){
        return a>b;    
    });
    if (score.size()>1)
        return score[0]*score[1];
    return 0;
}
