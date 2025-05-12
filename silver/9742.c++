#include<bits/stdc++.h>
using namespace std;
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int cnt=0;
vector<char>save;
vector<char>ss;
vector<bool>vis;
void dfs(int l,int d,int t,string s)
{
    if (l==d)
    {
        cnt++;
        if (cnt==t)
        {
            cout<<s<<' '<<t<<" = ";
            for(char ch:save)
            {
                cout<<ch;
            }
        }
        return;
    }
    for(int i=0;i<l;i++)
    {
        if (!vis[i])
        {
            vis[i]=true;
            save.push_back(s[i]);
            dfs(l,d+1,t,s);
            vis[i]=false;
            save.pop_back();
        }
    }
}
int facto(int n)
{
    if (n==1)
        return 1;
    return n*facto(n-1);
}
int main(void)
{
    fastIO;
    string s;int t;
    while(cin>>s>>t)
    {
        cnt=0;
        vis.assign(10,false);
        ss.clear();
        save.clear();
        for(int i=0;i<s.length();i++)
            ss.push_back(s[i]);
        if (t>facto(s.length()))
            cout<<s<<' '<<t<<" = "<<"No permutation";
        else
            dfs(s.length(),0,t,s);
        cout<<'\n';
    }
    return 0;
}
