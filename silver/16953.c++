#include <bits/stdc++.h>
#include <queue>
#include <string>
using namespace std;
queue<int> q;
vector <bool> graph;
void bfs(int a,int b)
{
    int cal=1;
    graph[a]=true;
    if (a*2<=b)
    {
        q.push(a*2);
        graph[a*2]=true;
    }
    string s1=to_string(a)+'1';
    long long int s2=stoll(s1);
    if (s2<=b)
    {
        q.push(s2);
        graph[s2]=true;
    }
    while (!q.empty())
    {
        int size=q.size();
        for (int i=0;i<size;i++)
        {
            long long int c=q.front();
            q.pop();
            if (b==c)
            {
                cout<<cal+1<<'\n';
                return;
            }
            long long int c1=c*2;
            s1=to_string(c)+'1';
            s2=stoll(s1);
            if (c1<=b)
            {
                if (!graph[c1])
                {
                    q.push(c1);
                    graph[c1]=true;
                }
            }
            if (s2<=b)
            {
                if (!graph[s2])
                {
                    q.push(s2);
                    graph[s2]=true;
                }
            }
        }
        cal++;
    }
    cout<<-1<<'\n';
}
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    graph.resize(b+1,false);
    if (a==b)
        cout<<1;
    else
        bfs(a,b);
    return 0;
}
