#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int main(void)
{
    fastIO;int p,t,c;cin>>p;
    for (int i=0;i<p;i++)
    {
        cin>>t; c=0; vector<int>save(20);
        for (int k=0;k<20;k++)cin>>save[k];
        for (int k=1;k<20;k++)
        {
            int idx=0,st=save[k];
            while (idx<k&&save[idx]<save[k])idx++;
            for (int j=k;j>idx;j--)
            {
                c++;save[j]=save[j-1];
            } 
            save[idx]=st;
        }
        cout<<t<<' '<<c<<'\n';
    }
    return 0;
}
