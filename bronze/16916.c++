#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s,v;cin>>s>>v;
    cout<<(strstr(s.c_str(),v.c_str())!=NULL?1:0);
    return 0;
}
