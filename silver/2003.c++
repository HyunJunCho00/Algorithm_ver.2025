#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int main(void)
{
    int n,m;
    cin>>n>>m;
    vector <int> arr;
    vector <int> sum;
    arr.assign(n+1,0);
    sum.assign(n+1,0);
    for (int i=1;i<=n;i++)
    {
        cin>>arr[i];
        sum[i]=sum[i-1]+arr[i];
    }
    int start=1,end=1,count=0;
    while (1)
    {
        if (start>n)
            break;
        if (start==end)
        {
            if (sum[end]-sum[end-1]<=m)
            {
                if (sum[end]-sum[end-1]==m)
                    count++;
                if (end<n)
                    end++;
                else
                    start++;
            }
            else
            {
                if (end<n)
                    end++;
                start++;
            }

        }
        else
        {
            if (sum[end]-sum[start-1]<=m)
            {
                if (sum[end]-sum[start-1]==m)
                    count++;
                if (end<n)
                    end++;
                else
                    start++;
            }
            else
            {
                start++;
            }
        }
        //cout<<start<<' '<<end<<' '<<count<<'\n';
    }
    cout<<count<<'\n';
    return 0;
}
