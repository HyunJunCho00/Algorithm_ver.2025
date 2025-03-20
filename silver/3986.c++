#include<bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
void sol(int n,vector<string>&s)
{
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        int len=s[i].length();
        stack<char>st;
        for(int k=0;k<len;k++)
        {
            char comp=s[i][k];
            if (st.empty())
            {
                st.push(comp);
            }
            else
            {
                if (st.top()==comp)
                    st.pop();
                else
                    st.push(comp);
            }
        }
        (!st.empty())?cnt=cnt:cnt++;
    }
    cout<<cnt;
}
int main(void)
{
    fastIO;
    int n;cin>>n;
    vector<string>s(n);
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    sol(n,s);
    return 0;
}
