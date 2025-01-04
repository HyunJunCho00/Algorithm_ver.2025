#include <bits/stdc++.h>
using namespace std;
void solve(int x,int y,int n)
{
    if ((x/n)%3==1&&(y/n)%3==1)
    {
        cout<<' ';
    }
    else
    {
        if (n/3==0)
            cout<<'*';
        else solve(x,y,n/3);
    }
}
int main(void)
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        for (int k=0;k<n;k++)
        {
            solve(i,k,n);
        }
        cout<<'\n';
    }    
    return 0;
}
