#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int h,w,n,m;cin>>h>>w>>n>>m;
    cout<<(h/(n+1)+(h%(n+1)?1:0))*(w/(m+1)+(w%(m+1)?1:0))<<'\n';
    return 0;
}
