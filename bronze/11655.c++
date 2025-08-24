#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    string s;
    getline(cin,s);
    for(int i=0;i<s.length();i++)
    {
        if (s[i]==' '||isdigit(s[i]))
            cout<<s[i];
        else if (isupper(s[i]))
        {
            char a=(s[i]+13-65)%26+'A';
            cout<<a;
        }
        else
        {
            char a=(s[i]+13-97)%26+'a';
            cout<<a;
        }
    }
    return 0;
}
