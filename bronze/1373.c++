#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    string str;cin>>str;
    int cnt=0,b=1,sum=0; vector<int>save;
    for (int i=str.size()-1;i>=0;i--)
    {
        int c=str[i]-'0';
        sum+=c*b;b=b<<1;cnt++;
        if (cnt==3||i==0)
        {
            cnt=0;b=1;save.push_back(sum);sum=0;
        }
    }
    for (int i=save.size()-1;i>=0;i--)
        cout<<save[i];
    cout<<'\n';
    return 0;
}
