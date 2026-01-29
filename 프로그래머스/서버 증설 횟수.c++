#include<bits/stdc++.h>
#define pp pair<int,int>
using namespace std;

int solution(vector<int> players, int m, int k) 
{
    
    int answer = 0;
    vector<pp>dq;
    int cur=0;
    int need=0;
    int idx=0;
    for(int i=0;i<players.size();i++)
    {
        need=players[i]/m;
        if (dq.empty())
        {
            dq.push_back({i,need});
            answer+=need;
            cur=need;
        }
        else
        {
            if (idx<dq.size()&&dq[idx].first+k==i)
            {
                cur-=dq[idx++].second;
            }
            if (need>cur)
            {
                dq.push_back({i,need-cur});
                answer+=(need-cur);
                cur=need;
                
            }
        }
        //cout<<i<<' '<<cur<<' '<<idx<<' '<<need<<' '<<answer<<'\n';
    }
    return answer;
}
