#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        string s;cin>>s;
        for(int i=0;i<s.length();i++)
        {
            if (i!=n-1)cout<<s[i];
        }
        cout<<'\n';
    }
    return 0;
}
