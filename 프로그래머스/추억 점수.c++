#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string,int>m;
    for(int i=0;i<name.size();i++)
    {
        m[name[i]]=yearning[i];
    }
    
    for(int i=0;i<photo.size();i++)
    {
        int ans=0;
        for(int k=0;k<photo[i].size();k++)
        {
            if (m.find(photo[i][k])!=m.end())
            {
                ans+=m[photo[i][k]];
            }
        }
        answer.push_back(ans);
    }
    
    return answer;
}
