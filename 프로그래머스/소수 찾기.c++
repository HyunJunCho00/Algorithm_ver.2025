#include<bits/stdc++.h>
#define INF 10000000
using namespace std;
int answer = 0;
set<int>se;
void dfs(vector<bool>&arr,string numbers,string s,vector<bool>&vis)
{
    if (s!=""&&arr[stoi(s)])
    {
        if (!se.count(stoi(s)))
        {
            answer++;
            se.insert(stoi(s));
        }
    }
    if (s.length()==numbers.length())
    {
        return;
    }
    else
    {
        for(int i=0;i<numbers.length();i++)
        {
            if (!vis[i])
            {
                vis[i]=true;
                dfs(arr,numbers,s+numbers[i],vis);
                vis[i]=false;
            }

        }
    }
}
int solution(string numbers) 
{
    vector<bool>arr(INF,true);
    vector<bool>vis(10,false);
    arr[1]=false,arr[0]=false;
    int i=2;
    while(i*i<=INF)
    {
        if (arr[i])
        {
            for(int k=2*i;k<=INF;k+=i)
            {
                arr[k]=false;
            }
        }
        i+=1;
    }
    dfs(arr,numbers,"",vis);
    return answer;
}
