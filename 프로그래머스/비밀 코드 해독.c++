#include<bits/stdc++.h>

using namespace std;
int answer=0;
vector<int>save_number;
void dfs(int n,vector<vector<int>>q,vector<int>ans,int s)
{
    if (save_number.size()==5)
    {
        for(int i=0;i<q.size();i++)
        {
            int count=ans[i];
            int match_count=0;
            for(int num:save_number)
            {
                for(int qq:q[i])
                {
                    if (num==qq)match_count++; 
                }
            }
            if (match_count!=count)return;
        }
        answer++;
    }
    
    for(int i=s;i<=n;i++)
    {
        save_number.push_back(i);
        dfs(n,q,ans,i+1);
        save_number.pop_back();
    }
}
int solution(int n, vector<vector<int>> q, vector<int> ans) {
    dfs(n,q,ans,1);
    return answer;
}
