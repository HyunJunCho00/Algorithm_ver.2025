#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    string str;int h=0;cin>>str;
    for (int i=0;i<str.length();i++)
    {
        if (i==0||str[i]!=str[i-1])
            h+=10;
        else
            h+=5;
    }
    cout<<h<<'\n';
    return 0;
}
