#include<bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
void search(vector<int>&x,int base,int s,int e,int c)
{
    int max_size=0;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        int cnt=1,b=base;
        for(int xx:x)
        {
            if (xx-b>=mid)
            {
                cnt++;
                b=xx;
            }
        }
        if (cnt>=c)
        {
            max_size=max(max_size,mid);
            s=mid+1;
        }
        else e=mid-1;
    }
    cout<<max_size<<'\n';
}
int main(void)
{
    fastIO;
    int n,c;
    cin>>n>>c;
    vector<int>x(n,0);
    for (int i=0;i<n;i++)cin>>x[i];
    sort(x.begin(),x.end());
    int s=1,e=x[n-1]-x[0];
    search(x,x[0],s,e,c);
    return 0;
}
