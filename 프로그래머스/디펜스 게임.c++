#include<bits/stdc++.h>
using namespace std;

int solution(int n, int k, vector<int> enemy) 
{
    int ans = 0;
    priority_queue<int,vector<int>,greater<int>>pq;
    while(ans<enemy.size())
    {
        int cur=enemy[ans];
        pq.push(cur);
        if (k>0)
        {
            k--;
        }
        else
        {
            int top=pq.top();
            pq.pop();
            n-=top;
            if (n<0)
                break;
        }
        ans++;
    }
    return ans;
}
