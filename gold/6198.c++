#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0);
    int n,s,m=0;long long int res=0;cin>>n;
    stack<int>st;
    if (n==1)
    {
        cout<<0;
        exit(0);
    }
    for(int i=0;i<n;i++)
    {
        cin>>s;
        while(!st.empty()&&st.top()<=s)
        {
            st.pop();res+=st.size();
        }
        st.push(s);
    }
    while(!st.empty())
    {
        st.pop();
        res+=st.size();
    }
    cout<<res<<'\n';
    return 0;
}
