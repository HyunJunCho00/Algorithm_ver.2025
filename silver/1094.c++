#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;cin>>n;
    int res=0,s=64,m=0;
    while(1)
    {
        if (m+s/2>n)
        {
            s/=2;
        }
        else if (n==64||m+s/2==n)
        {
            res++;break;
        }
        else
        {
            m+=s/2;
            s/=2;res++;
        }
    }
    cout<<res;
    return 0;
}
