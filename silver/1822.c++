#include<bits/stdc++.h>
#define fastIO ios:: sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int main(void)
{
    fastIO;
    int a,b,c;
    cin>>a>>b;
    set<int>st;
    for(int i=0;i<a;i++)
    {
        cin>>c;
        st.insert(c);
    }
    for(int i=0;i<b;i++)
    {
        cin>>c;
        st.erase(c);
    }
    cout<<st.size()<<'\n';
    
    for(int ss:st) cout<<ss<<' ';
    return 0;
}
