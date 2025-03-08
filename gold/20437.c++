#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int t;cin>>t;
    for(int i=0;i<t;i++)
    {
        string ss;cin>>ss;int k;cin>>k;
        vector<int>a[26];
        int f=10001,s=0;
        for(int i=0;i<ss.length();i++)
        {
            int l=ss[i]-97;
            a[l].push_back(i);
            int size=a[l].size();
            if (size>=k)
            {
                f=min(f,a[l][size-1]-a[l][size-k]+1);
                s=max(s,a[l][size-1]-a[l][size-k]+1);
            }
        }
        if(!f||!s)cout<<-1<<'\n';
        else cout<<f<<' '<<s<<'\n';
    }
    return 0;
}
