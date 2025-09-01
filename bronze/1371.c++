#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    string str;
    vector<int>a(26,0);
    int m=0;
    while(getline(cin,str))
    {
        for(int i=0;i<str.length();i++){
            if (str[i]!=' ')
            {
                int in=str[i]-'a';
                a[in]++;
                if (a[in]>m)m=a[in];
            }
        }
    }
    for(int i=0;i<26;i++)
    {
        if (m==a[i])
        {
            cout<<(char)('a'+i);
        }
    }
    return 0;
}
