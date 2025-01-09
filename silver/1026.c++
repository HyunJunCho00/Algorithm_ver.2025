#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main(void)
{
    vector <int> a;
    vector <int> b;
    vector <bool>visited;
    int n;
    cin>>n;
    a.assign(n,0);
    b.assign(n,0);
    visited.assign(n,false);
    for (int i=0;i<n;i++)
        cin>>a[i];
    for (int i=0;i<n;i++)
        cin>>b[i];
    sort(a.begin(),a.end(),std::greater<int>());
    int res=0;
    for (int i=0;i<n;i++)
    {
        int min_value=1000000;
        int idx;
        for (int j=0;j<n;j++)
        {
            if (!visited[j]&&min_value>a[i]+b[j])
            {
                idx=j;
                min_value=a[i]+b[j];
            }
        }
        res+=a[i]*b[idx];
        visited[idx]=true;
    }
    cout<<res<<'\n';
    return 0;
}
