#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pii pair<int,int>
using namespace std;
void manage(stack<pii>&st,int t,vector<int>&tower,int i)
{
    while(!st.empty())
    {
        int top=st.top().first,idx=st.top().second;
        if (t<top)break;
        st.pop();
        if (st.empty())
        {
            tower[idx]=0;break;
        }
        int n_idx=st.top().second;
        tower[idx]=n_idx;
    }
}
int main(void)
{
    fastIO;int n,t;cin>>n;
    stack<pii>st;
    vector<int>tower(n+1,0);
    for (int i=1;i<=n;i++)
    {
        cin>>t; manage(st,t,tower,i); st.push({t,i});   
    }
    while(!st.empty())
    {
        int idx=st.top().second;st.pop();
        if (st.empty())
        {
            tower[idx]=0;break;
        }
        int n_idx=st.top().second;tower[idx]=n_idx;
    }
    for(int i=1;i<=n;i++)cout<<tower[i]<<' ';
    cout<<'\n';
    return 0;
}
