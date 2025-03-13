#include<bits/stdc++.h>
using namespace std;
int a[26];
int main(void)
{
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        string s;cin>>s;
        a[s[0]-97]++;
    }
    vector<char>s;
    for(int i=0;i<26;i++)
    {
        if(a[i]>=5)
        {
            char aa='a'+i; s.push_back(aa);
        }
    }
    if (s.size())for(int i=0;i<s.size();i++)cout<<s[i];
    else cout<<"PREDAJA";
    return 0;
}
