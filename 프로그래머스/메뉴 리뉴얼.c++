#include<bits/stdc++.h>

using namespace std;
unordered_map<string,int>um;
void dfs(vector<char>c,int d,int k,string order,vector<int>&count)
{
    if (c.size()==k)
    {
        string s="";
        sort(c.begin(),c.end());
        for(char cc:c)
        {
            s+=cc;
        }
        um[s]++;
        count[k]=max(count[k],um[s]);
    }
    for(int i=d;i<order.length();i++)
    {
        c.push_back(order[i]);
        dfs(c,i+1,k,order,count);
        c.pop_back();
    }
}
vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;
    int n=course[course.size()-1];
    vector<int>count(n+1,0);
    for(int i=0;i<orders.size();i++)
    {
        for(int k=2;k<=course[course.size()-1];k++)
        {
            vector<char>c;
            dfs(c,0,k,orders[i],count);            
        }

    }
    for(auto&m:um)
    {
        for(int i=0;i<course.size();i++)
        {
            if (course[i]==m.first.length()&&m.second>=count[course[i]]&&count[course[i]]>=2)
            {
                answer.push_back(m.first);
                break;
            } 
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}
