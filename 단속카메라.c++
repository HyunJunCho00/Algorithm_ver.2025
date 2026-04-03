#include<bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(),routes.end(),[](vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    });
    int minn=-30001;
    for(int i=0;i<routes.size();i++)
    {
        if(routes[i][0]>minn)
        {
            minn=routes[i][1];
            answer++;
        }
    }
    return answer;
}
