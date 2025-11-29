#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;cin>>n;
    int minn=100000;
    for(int i=n/5;i>=0;i--)
    {
        int c=n-5*i;
        if (!(c%2))
            minn=min(minn,i+c/2);
    }
    if (minn==100000)
        cout<<-1;
    else
        cout<<minn;
    return 0;
}
