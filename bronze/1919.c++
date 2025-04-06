#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    string a,b;cin>>a>>b;
    vector<int>s(26),ss(26);
    for(int i=0;i<a.length();i++) s[a[i]-97]++;
    for(int i=0;i<b.length();i++) ss[b[i]-97]++;
    int res=0;
    for(int i=0;i<26;i++)
    {
        if ((s[i]||ss[i])&&s[i]!=ss[i])
        {
            if (!s[i]&&ss[i])res+=ss[i];
            else if (s[i]&&!ss[i])res+=s[i];
            else res+=abs(s[i]-ss[i]);
        }
    }
    cout<<res;
    return 0;
}
