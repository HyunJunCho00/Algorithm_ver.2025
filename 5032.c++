#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int e,f,c,cnt=0;
    cin>>e>>f>>c;
    e=e+f;
    while(e>=c)
    {
        cnt++;
        e=e-c+1;
    }
    cout<<cnt;
    return 0;
}
