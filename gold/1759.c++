#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
vector<char>str,save;
unordered_set<char>vo={'a','e','i','o','u'};
vector<bool>visited;
void dfs(int d,int s,int m,int n)
{
    if (d==m)
    {
        int ch=0;
        for (char c:save)
            if (vo.count(c))
                ch++;
        if (m-ch>=2&&ch>=1)
        {
            for (char c:save)
                cout<<c;
            cout<<'\n';
        }
    }
    else
    {
        for (int i=s;i<n;i++)
        {
            if (!visited[i]&&(i==0||(i>0&&str[i]!=str[i-1])))
            {
                visited[i]=true;
                save.push_back(str[i]);
                dfs(d+1,i,m,n);
                save.pop_back();
                visited[i]=false;
            }
        }
    }
}
int main(void)
{
    fastIO;int l,c;cin>>l>>c;
    visited.assign(c,false);
    for (int i=0;i<c;i++)
    {
        char ch;cin>>ch;str.push_back(ch);
    }
    sort(str.begin(),str.end());
    dfs(0,0,l,c);
    return 0;
}
