#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0);
    int n;cin>>n;
    stack<int>st;
    for(int i=0;i<n;i++)
    {
        int s;cin>>s;
        if (st.empty())st.push(s);
        else
        {
            while(!st.empty()&&st.top()<=s)st.pop();
            st.push(s);
        }
    }
    cout<<st.size();
    return 0;
}
