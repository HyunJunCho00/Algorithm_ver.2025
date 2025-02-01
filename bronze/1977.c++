#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int m,n;
    cin>>m>>n;
    queue <int> a;
    int i=1;
    while (1)
    {
        int l=i*i;
        i++;
        if (m<=l&&l<=n)
            a.push(l);
        if (l>n)
            break;
    }
    int r=0,s=0;
    if (a.empty())
        cout<<-1<<'\n';
    else
    {
        r=a.front();
        while (!a.empty())
        {
            s+=a.front();
            a.pop();
        }
        cout<<s<<'\n'<<r<<'\n';
    }  
    return 0;
}
