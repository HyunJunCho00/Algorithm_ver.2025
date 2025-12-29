#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> sequence, int k) 
{
    vector<int>ans(2,0);
    int n=sequence.size();
    int sum=0,s=0;
    int mLen=100000000;
    for(int e=0;e<n;e++)
    {
        sum+=sequence[e];
        while(sum>k&&s<=e)
        {
            sum-=sequence[s];
            s++;
        }
        if (sum==k)
        {
            int cur=e-s;
            if (mLen>cur)
            {
                ans[0]=s,ans[1]=e;
                mLen=cur;
            }
        }
    }
    return ans;
}
