#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int v;cin>>v;
    vector<int>a(2,0);
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        a[s[i]-'A']++;
    }
    if (a[0]>a[1]) cout<<'A';
    else if (a[0]<a[1])cout<<'B';
    else cout<<"Tie";
    return 0;
}
