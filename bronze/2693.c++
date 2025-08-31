#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int t;cin>>t;
    for(int i=0;i<t;i++)
    {
        vector<int>n(10);
        for(int k=0;k<10;k++)
        {
            cin>>n[k];
        }
        sort(n.begin(),n.end());
        cout<<n[7]<<'\n';
    }
    return 0;
}
