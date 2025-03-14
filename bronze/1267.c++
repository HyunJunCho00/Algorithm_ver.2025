#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n,a,y=0,m=0;cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        y+=(a/30+1)*10;m+=(a/60+1)*15;
    }
    if (y==m)cout<<"Y M "<<y;
    else if (y<m)cout<<"Y "<<y;
    else cout<<"M "<<m;
    return 0;
}
