#include<bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int main(void)
{
    fastIO;int n,s,p,t=1,i=1;cin>>n>>s>>p;
    vector<int>arr(n+1,0),top(n+1,0);
    for(int i=1;i<=n;i++)cin>>arr[i];
    while(i<=n)
    {
        if (s>arr[i])break;
        else
        {
            int idx=i;
            while(i<n&&arr[i+1]==arr[i])i++;
            if (s==arr[i])
            {
                i+1>p?t=-1:t=idx; break;
            }
            else i+1>p?t=-1:t=i+1;
            i++;
        }
    }
    cout<<t<<'\n';
    return 0;
}
