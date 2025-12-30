#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> elements) 
{
    set<int>s;
    int n=elements.size();
    vector<vector<int>>sum(n+1,vector<int>(n,0));
    int sm=0;
    for(int i=0;i<n;i++) 
    {
        sm+=elements[i];
        if (s.find(elements[i])==s.end())
        {
            s.insert(elements[i]);
        }
        sum[1][i]=elements[i];
    }
    if (s.find(sm)==s.end())
    {
        s.insert(sm);
    }
    for (int len=2;len<n;len++)
    {
        for(int i=0;i<n;i++)
        {
            int d=i-len+1>=0?i-len+1:n-len+i+1;
            //cout<<i<<' '<<"d "<<d<<'\n';
            sm=sum[len-1][i]+elements[d];
            sum[len][i]=sm;
            if (s.find(sm)==s.end())
            {
                s.insert(sm);
            }
        }
    }
    return s.size();
}
