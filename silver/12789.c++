#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n,idx=1;cin>>n;
    vector<int>m(n,0);
    stack<int>st;
    for (int i=0;i<n;i++)
    {
        cin>>m[i];
        if (m[i]==idx)
        {
            idx++;
            while(!st.empty()&&st.top()==idx)
            {
                idx++;st.pop();
            }
        }       
        else 
            st.push(m[i]);
    }
    while (!st.empty() && st.top() == idx) {
        st.pop();
        idx++;
    }
    cout<<(st.empty()?"Nice":"Sad")<<'\n';
    return 0;
}
