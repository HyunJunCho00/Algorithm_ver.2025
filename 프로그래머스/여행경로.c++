#include<bits/stdc++.h>
using namespace std;
vector<string> answer;
vector<string> save;
bool found=false;
void dfs(string start,int size,map<string,vector<string>>m,map<pair<string,string>,int>cnt)
{
    if (size==save.size())
    {
        if (!found)
        {
            found=true;
            for(string ss:save)
                answer.push_back(ss);
        }
        return;
    }
    for(string str:m[start])
    {
        if (cnt[{start,str}]>0)
        {
            save.push_back(str);
            cnt[{start,str}]--;
            dfs(str,size,m,cnt);      
            save.pop_back();
            cnt[{start,str}]++;
        }
    }
}
vector<string> solution(vector<vector<string>> tickets) {
    map<string,vector<string>>m;
    map<pair<string,string>,int>count;
    for(int i=0;i<tickets.size();i++)
    {
        m[tickets[i][0]].push_back(tickets[i][1]);
        count[{tickets[i][0],tickets[i][1]}]++;
    }

    for(auto&mm:m)
    {
        sort(mm.second.begin(),mm.second.end());
    }
    save.push_back("ICN");
    dfs("ICN",tickets.size()+1,m,count);
    return answer;
}
