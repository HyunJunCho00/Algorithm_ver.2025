#include<bits/stdc++.h>
using namespace std;

vector<int> solution(int n, int s) {
    
    vector<int> answer;
    int d=s/n;
    int v=s%n;
    if (!d)
    {
        answer.push_back(-1);
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            answer.push_back(d);
        }
        if (v)
        {
            for(int i=0;i<v;i++)
            {
                answer[i]+=1;
            }
        }     
    }
    sort(answer.begin(),answer.end());
    return answer;
}
