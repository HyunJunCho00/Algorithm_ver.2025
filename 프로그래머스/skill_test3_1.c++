#include<bits/stdc++.h>
using namespace std;
int check(int s,int e,int cover)
{
    int div=(e-s+1)%cover;
    if (div)
    {
        div=1;
    }
    return (e-s+1)/cover+div;
}
int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int cover=2*w+1;
    int s=1,e=1;
    for(int i=0;i<stations.size();i++)
    {
        if (i)
        {
            s=stations[i-1]+w+1;
        }
        e=stations[i]-w-1;
        if (e>=s)
        {
            answer+=check(s,e,cover);
        }
    }
    if (stations[stations.size()-1]+w+1<=n)
    {
        s=stations[stations.size()-1]+w+1;
        e=n;
        answer+=check(s,e,cover);
    }
    return answer;
}
