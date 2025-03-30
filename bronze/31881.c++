#include<bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int main(void)
{
    fastIO;
    int n,q;
    cin>>n>>q;
    vector<bool>a(n+1,true);
    int cnt=n;
    for(int i=0;i<q;i++)
    {
        int x;cin>>x;
        if (x==3)cout<<cnt<<'\n';
        else
        {
            int y;cin>>y;
            if (x==1)
            {
                if (a[y])cnt--;
                a[y]=false;
            }
            else
            {
                if (!a[y])cnt++;
                a[y]=true;
            }
        }
    }
    return 0;
}
