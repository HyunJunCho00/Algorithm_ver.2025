#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n; cin>>n;
    vector<int> x(n,0),y(n,0);
    for (int i=0;i<n;i++)
        cin>>x[i]>>y[i];
    sort(x.begin(),x.end()); sort(y.begin(),y.end());
    cout<<(x[n-1]-x[0])*(y[n-1]-y[0])<<'\n';
    return 0;
}
