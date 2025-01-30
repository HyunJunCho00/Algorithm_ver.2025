#include <bits/stdc++.h>
using namespace std;
void solve(int n)
{
    if (n==1)
        cout<<'*'<<'\n';
    else
    {
        for (int i=0;i<n*2;i++)
        {
            for (int k=0;k<n;k++)
            {
                if (i%2==0)
                {
                    if (k%2==0)
                        cout<<'*';
                    else
                        cout<<' ';
                }
                else
                {
                    if (k%2==1)
                        cout<<'*';
                    else
                        cout<<' ';
                }
            }
            cout<<'\n';
        }
    }
}
int main(void)
{
    int n;
    cin>>n;
    solve(n);
    return 0;
}
