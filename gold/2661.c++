#include<bits/stdc++.h>
using namespace std;
bool check(string s,int i)
{
    string ss=s+to_string(i);
    for(int i=1;i<=ss.length()/2;i++)
    {
        int idx=ss.length()-1,cnt=0;
        for(int k=0;k<i;k++) if (ss[idx-k]==ss[idx-i-k])cnt++; 
        if (cnt==i)return false;
    }
    return true;
}
void dfs(int m,int n,string s)
{
    if (m==n)
    {
        cout<<s<<'\n';exit(0);
    }
    else
    {
        for(int i=1;i<=3;i++)
        {
            if (check(s,i)) dfs(m+1,n,s+to_string(i)); 
        }
    }
}
int main(void)
{
    int n;cin>>n;
    dfs(1,n,"1");
    return 0;
}
