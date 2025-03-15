#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int m=0,a,b,c=0;
    for(int i=0;i<10;i++)
    {
        cin>>a>>b;
        c+=b-a;
        m=max(m,c);
    }
    cout<<m;
    return 0;
}
