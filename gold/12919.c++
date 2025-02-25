#include <bits/stdc++.h>
using namespace std;
queue<string>q;
set<string>visited;
void bfs(string s,string t)
{
    bool ch=false;
    q.push(t);
    visited.insert(t);
    while (!q.empty())
    {
        string cur=q.front();
        q.pop();
        if (cur==s)
        {
            ch=true;break;
        }
        if (cur.length()<s.length())continue;
        string next;
        if (cur.back()=='A')
        {
            next=cur.substr(0,cur.length()-1);
            if (visited.find(next)==visited.end())
            {
                q.push(next);visited.insert(next);
            }
        }    
        if (cur.front()=='B')
        {
            reverse(cur.begin(),cur.end());
            next=cur.substr(0,cur.length()-1);
            if (visited.find(next)==visited.end())
            {
                q.push(next);visited.insert(next);
            }
        }
    }
    cout<<(ch?1:0)<<'\n';
}
int main(void)
{
    string s;cin>>s;
    string t;cin>>t;
    bfs(s,t);
    return 0;
}
