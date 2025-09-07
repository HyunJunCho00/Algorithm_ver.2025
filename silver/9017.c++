#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        vector<vector<int>>team(201);
        vector<int>cnt(201);
        vector<int>choose;
        vector<int>a(n+1,0);
        vector<bool>vis(201,false);
        vector<int>save(201,0);
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            cnt[a[i]]++;
            if (cnt[a[i]]==6)
            {
                choose.push_back(a[i]);
                vis[a[i]]=true;
            }
        }
        int first=1;
        for(int i=1;i<=n;i++)
        {
            if (vis[a[i]])
            {
                team[a[i]].push_back(first);
                first++;
            }
        }
 
        int winner=0,score=10000;
        for(int & c:choose)
        {
            for(int i=0;i<=3;i++)
            {
                save[c]+=team[c][i];
            }
            if (score>save[c])
            {
                winner=c;score=save[c];
            }
            else if (score==save[c]&&team[c][4]<team[winner][4])
            {
                winner=c;
            }
        }
        cout<<winner<<'\n';
    }
    return 0;
}
