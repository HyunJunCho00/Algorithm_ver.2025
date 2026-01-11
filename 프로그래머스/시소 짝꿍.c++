#include<bits/stdc++.h>
using namespace std;
int dx[]={4,4,3};
int dy[]={2,3,2};
long long solution(vector<int> weights) {
    long long answer = 0;
    map<int,int>m;
    for(int wei:weights)
    {
        m[wei]++;
    }
    for(auto&mm:m)
    {
        long long w=mm.first,cnt=mm.second;
        if (mm.second>=2)
        {
            answer+=cnt*(cnt-1)/2;
        }
        for(int i=0;i<3;i++)
        {
            int nx=dx[i]*w/dy[i];
            if (m.count(nx)&&!(dx[i]*w%dy[i]))
            {
                answer+=cnt*m[nx];
            }
        }
    }
    return answer;
}
