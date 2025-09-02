#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;cin>>n;
    map<string,int>m;
    int max_cnt=0;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        m[s]++;
        if (max_cnt<m[s])max_cnt=m[s];
    }
    for(auto&mm:m)
    {
        if (mm.second==max_cnt)
        {
            cout<<mm.first;break;
        }
    }
    return 0;
}
