#include<bits/stdc++.h>
using namespace std;
int arr[1002][1002];
int ans[101];
int main(void)
{
    int n;cin>>n;
    int a,b,c,d,m_c=0,m_d=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b>>c>>d;
        m_c=max(a+c,m_c);
        m_d=max(b+d,m_d);
        for(int k=a;k<a+c;k++)for(int l=b;l<b+d;l++)arr[k][l]=i;
    }
    for(int i=0;i<=m_c;i++)for(int k=0;k<=m_d;k++)ans[arr[i][k]]++;
    for(int i=1;i<=n;i++)cout<<ans[i]<<'\n';
    return 0;
}
