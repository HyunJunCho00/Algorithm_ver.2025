#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;char a;cin>>n>>a;
    set<string>s;
    for(int i=0;i<n;i++)
    {
        string ss;cin>>ss;
        s.insert(ss);
    }
    cout<<(a=='Y'?s.size():a=='F'?s.size()/2:s.size()/3);
    return 0;
}
