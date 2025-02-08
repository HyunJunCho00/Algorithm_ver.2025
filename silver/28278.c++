#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int main(void)
{
    fastIO;int n;cin>>n;
    stack<int>st;
    for (int i=0;i<n;i++)
    {
        int a;cin>>a;
        if (a==1)
        {
            int x;cin>>x;
            st.push(x);
        }
        else if (a==2)
        {
            if (st.empty())
                cout<<-1<<'\n';
            else
            {
                cout<<st.top()<<'\n';st.pop();
            }
        }
        else if (a==3)
            cout<<st.size()<<'\n';
        else if (a==4)
            cout<<(st.empty()?1:0)<<'\n';
        else
            cout<<(st.empty()?-1:st.top())<<'\n';
    }
    return 0;
}
