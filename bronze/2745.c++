#include<bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int main(void)
{
    string line;
    int n;
    cin>>line>>n;
    int result=0;
    int idx=1;
    int re;
    for (int i=line.length()-1;i>=0;i--)
    {
        if (line[i]>='A'&&line[i]<='Z')
        {
            re=line[i]-55;
        }
        else
        {
            re=line[i]-'0';
        }
        result+=re*idx;
        idx*=n;
    }
    cout<<result<<'\n';
    return 0;
}
