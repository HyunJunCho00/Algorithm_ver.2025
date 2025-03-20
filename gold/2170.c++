#include<bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pii pair<int,int>
using namespace std;
int main(void)
{
    fastIO;
    int n;cin>>n;
    vector<pii>a(n);
    for(int i=0;i<n;i++)
        cin>>a[i].first>>a[i].second;
    sort(a.begin(),a.end());
    int s=a[0].first,e=a[0].second,max_len=e-s;
    for(int i=1;i<n;i++)
    {
        int x=a[i].first,y=a[i].second;
        if (x>=s&&y<=e)continue;
        if (x>e)
        {
            max_len+=(y-x);s=x;e=y;
        }
        else
        {
            max_len+=(y-e);e=y;
        }

    }
    cout<<max_len;
    return 0;
}
