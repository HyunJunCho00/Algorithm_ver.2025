#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
unordered_set<char>vo={'a','e','i','o','u'};
int main(void)
{
    fastIO;
    string str;
    while (cin>>str&&str.compare("end"))
    {
        bool t=true;
        int in=0,mo=0,ja=0;
        for (int i=0;i<str.length();i++)
        {
            if (str[i]==str[i-1]) (str[i]=='e'||str[i]=='o')?(in++,mo++):(t=false);
            else vo.count(str[i])?(in++,mo++,ja=0):(mo=0,ja++);
            if (mo==3||ja==3) t=false;
        }
        cout<<"<"<<str<<"> "<<"is "<<((t&&in)?"":"not ")<<"acceptable.\n";
    }
    return 0;
}
