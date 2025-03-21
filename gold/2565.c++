#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;cin>>n;
    vector<vector<int>>a(n,vector<int>(2,0));
    for(int i=0;i<n;i++) cin>>a[i][0]>>a[i][1];
    sort(a.begin(),a.end());
    vector<int>save;
    for(int i=0;i<n;i++)
    {
        int idx=lower_bound(save.begin(),save.end(),a[i][1])-save.begin();
        if (idx==save.size())
            save.push_back(a[i][1]);
        else
            save[idx]=a[i][1];
    }
    cout<<n-save.size();
    return 0;
}
