#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    vector<string>st;
    string ss;cin>>ss;st.push_back(ss);
    int n,idx=0;cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>ss;st.push_back(ss);
    }
    while (idx<=25)
    {
        ss=st[0];
        for (int i=0;i<ss.length();i++) ss[i]='a'+(ss[i]-'a'+idx)%26;
        for (int i=1;i<=n;i++)
        {
            if (ss.find(st[i])!=string::npos)
            {
                cout<<ss<<'\n';exit(0);
            }
        }
        idx++;
    }
    return 0;
}
