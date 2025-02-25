#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    string s;cin>>s;
    int len=s.length();
    int n=atoi(s.c_str());
    vector<int>dp(len+1,0);
    bool ch=true;
    (s[0]-'0')%10?dp[1]=1:ch=false;
    for (int i=1;i<len;i++)
    {
        int b=s[i-1]-'0',c=s[i]-'0',t=b*10+c;
        (b>=1&&b<=2&&ch&&t<=26)?(dp[i+1]=i>1?dp[i-1]:dp[i]):0;
        (ch&&c>=1&&c<=9)?dp[i+1]=(dp[i+1]+dp[i])%1000000:!dp[i+1]?ch=false:0;
    }
    cout<<dp[len]<<'\n';
    return 0;
}
