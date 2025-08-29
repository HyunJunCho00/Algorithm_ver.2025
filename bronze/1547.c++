#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int m;cin>>m;
    vector<bool>ball(4,false);
    ball[1]=true;
    for(int i=0;i<m;i++)
    {
        int x,y;cin>>x>>y;
        if (ball[x])
        {
            ball[x]=false;ball[y]=true;
        }
        else if (ball[y])
        {
            ball[x]=true;ball[y]=false;
        }
    }
    for(int i=1;i<=3;i++)
    {
        if (ball[i])
        {
            cout<<i;
            return 0;
        }
    }
}
