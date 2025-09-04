#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        string s;cin>>s;
        int ch=s[s.length()-1]-'0';
        if (!(ch%2)) cout<<"even\n";
        else cout<<"odd\n";
    }
    return 0;
}
