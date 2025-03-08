#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    vector<vector<string>>a(10,vector<string>(10));
    for(int i=0;i<10;i++)for(int k=0;k<10;k++)cin>>a[i][k];
    for(int i=0;i<10;i++)
    {
        bool c=true;
        for(int k=1;k<10;k++)
        {
            if (a[i][0]!=a[i][k])c=false;
        }
        if(c)
        {
            cout<<1<<'\n';exit(0);
        }
        c=true;
        for(int k=1;k<10;k++)
        {
            if (a[0][i]!=a[k][i])c=false;
        }
        if (c)
        {
            cout<<1<<'\n';exit(0);
        }
    }
    cout<<0<<'\n';
    return 0;
}
