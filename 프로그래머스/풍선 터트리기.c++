#include<bits/stdc++.h>
#define inf 1e9
using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    vector<int>left_min(a.size(),0);
    vector<int>right_min(a.size(),0);
    int cur=inf;
    for(int i=0;i<a.size();i++)
    {
        if (a[i]<=cur)
            cur=a[i];
        left_min[i]=cur;
    }
    cur=inf;
    for(int i=a.size()-1;i>=0;i--)
    {
        if (a[i]<=cur)
            cur=a[i];
        right_min[i]=cur;
    }
    
    for(int i=0;i<a.size();i++)
    {
        if (a[i]<=left_min[i]||a[i]<=right_min[i])
            answer++;
    }
    return answer;
}
