#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int e,s,m;
    cin>>e>>s>>m;
    int e1,s1,m1;
    int i=1;
    while (1)
    {
        e1=i%15;s1=i%28;m1=i%19;
        if (e1==0)
            e1=15;
        if (s1==0)
            s1=28;
        if (m1==0)
            m1=19;
        if (e1==e&&s1==s&&m1==m)
        {
            cout<<i<<'\n';
            break;
        }
        i++;
    }
    return 0;
}
