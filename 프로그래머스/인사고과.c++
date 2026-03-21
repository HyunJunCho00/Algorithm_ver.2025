#include<bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> scores) 
{
    vector<int>wonho;
    wonho.push_back(scores[0][0]);wonho.push_back(scores[0][1]);
    int won=wonho[0]+wonho[1];
    sort(scores.begin(),scores.end(),[](vector<int>&a,vector<int>&b){
        if (a[0]!=b[0]) return a[0]>b[0];
        return a[1]<b[1];
    });
    int rank=1;
    int max_peer=0;
    for(vector<int>&s:scores)
    {
        if (s[1]<max_peer)
        {
            if (s[0]==wonho[0]&&s[1]==wonho[1])
                return -1;
            continue;
        }
        
        max_peer=max(max_peer,s[1]);
        if (s[0]+s[1]>won)
            rank+=1;
    }
    return rank;
}
