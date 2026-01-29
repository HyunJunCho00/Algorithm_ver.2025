#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> gems) 
{
    vector<int>answer(2,0);
    set<string>s(gems.begin(),gems.end());
    int total_len=s.size(),start=0,min_len=gems.size()+1;
    map<string,int>m;
    for(int i=0;i<gems.size();i++)
    {
        m[gems[i]]++;
        if (m.size()==total_len)
        {
            while(start<=i&&m.size()==total_len)
            {
                if (i-start<min_len)
                {
                    min_len=i-start;
                    answer[1]=i+1;
                    answer[0]=start+1;
                }
                m[gems[start]]--;
                if (m[gems[start]]==0)
                    m.erase(gems[start]);
                start++;
            }
        }
    }
    return answer;
}
