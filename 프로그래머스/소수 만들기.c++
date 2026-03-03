#include<bits/stdc++.h>
using namespace std;
int answer=0;
void dfs(vector<int>nums,vector<int>&num,vector<bool>v,int s)
{
    if (num.size()==3)
    {
        int n=0;
        for(int k:num)
        {
            n+=k;
        }
        if (!v[n])
        {
            answer++;
        }        
        return;
    }
    for(int i=s;i<nums.size();i++)
    {
        num.push_back(nums[i]);
        dfs(nums,num,v,i+1);
        num.pop_back();
    }
}
int solution(vector<int> nums) 
{
    vector<int>num;
    vector<bool>v(3001,false);
    for(int i=4;i<=3000;i+=2)
        v[i]=true;
    int i=3;
    while(i*i<=3000)
    {
        for(int k=i*2;k<=3000;k+=i)
            v[k]=true;
        i+=2;
    }
    dfs(nums,num,v,0);
    return answer;
}
