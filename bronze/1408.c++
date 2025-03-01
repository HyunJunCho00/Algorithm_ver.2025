#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n,m,s,q,w,h;char d,z='0';
    cin>>n>>d>>m>>d>>s;q=n*3600+m*60+s;
    cin>>n>>d>>m>>d>>s;w=n*3600+m*60+s;
    q>w?w=3600*24+w-q:w-=q;
    h=w/3600,m=(w%3600)/60,s=w%60;
    cout<<setw(2)<<setfill(z)<<h<<d<<setw(2)<<setfill(z)<<m<<d<<setw(2)<<setfill(z)<<s;
    return 0;
}
