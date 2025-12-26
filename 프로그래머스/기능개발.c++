#include<bits/stdc++.h>
#define pp pair<int,int>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> save;
    int size=speeds.size();
    for(int i=0;i<size;i++)
    {
        int d=(100-progresses[i])%speeds[i];
        int s=(100-progresses[i])/speeds[i];
        if (d) s+=1;
        save.push_back(s);
    }
    int cnt=1,max_top=save[0];
    for(int i=1;i<save.size();i++)
    {
        if (max_top>=save[i])
            cnt++;
        else
        {
            max_top=save[i];
            answer.push_back(cnt);
            cnt=1;
        }
    }
    answer.push_back(cnt);
    return answer;
    
}
