#include<bits/stdc++.h>
#define pp pair<int,int>
using namespace std;

int bfs(int n)
{
    int ans=0;
    while(n)
    {
        if (n%2)
            ans++;
        n/=2;
    }
    return ans;
}
int solution(int n)
{
    int ans = bfs(n);
    return ans;
}
