#include<bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> l, vector<int> res) {
    int ans=0;
    vector<int>c(n+1,1);
    vector<int>r;
    for(int i=0;i<l.size();i++)
    {
        c[l[i]]-=1;
    }
    for(int i=0;i<res.size();i++)
    {
        if (!c[res[i]])
        {
            c[res[i]]++;
        }
        else
            r.push_back(res[i]);
    }
    sort(r.begin(),r.end());
    for(int i=0;i<r.size();i++)
    {
        int cur=r[i];
        if (cur==n)
        {
            if (!c[cur-1])c[cur-1]++;
        }
        else
        {
            if (!c[cur-1])c[cur-1]++;
            else if (!c[cur+1])c[cur+1]++;
        }
    
    }
    for(int i=1;i<=n;i++)
        if(c[i])ans++;
    return ans;
}
