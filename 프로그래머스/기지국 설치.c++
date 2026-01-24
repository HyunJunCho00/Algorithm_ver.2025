#include<bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer=0;
    int cur=1;
    int idx=0;
    while(cur<=n)
    {
        if (idx<stations.size()&&cur>=stations[idx]-w)
        {
            cur=stations[idx]+w+1;
            idx++;
            
        }
        else
        {
            answer++;
            cur+=(w*2+1);
        }
    }
    return answer;
}
