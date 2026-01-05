#include<bits/stdc++.h>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(string st : skill_trees)
    {
        int idx=0;
        bool ch=true;
        for (char stt: st)
        {
            for(int i=idx;i<skill.size();i++)
            {
                if (stt==skill[i])
                {
                    if (i!=idx)
                    {
                        ch=false;
                    }
                    idx++;
                    break;
                }
            }
            if (!ch)break;
        }
        if (ch)answer++;
    }
        
    return answer;
}
