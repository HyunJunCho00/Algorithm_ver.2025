#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int t;
    cin>>t;
    for (int i=0;i<t;i++)
    {
        int m;
        cin>>m;
        cout<<m/25<<' '<<(m%25)/10<<' '<<(m%25%10)/5<<' '<<(m%25%10%5)/1<<'\n';
    }
    return 0;
}
