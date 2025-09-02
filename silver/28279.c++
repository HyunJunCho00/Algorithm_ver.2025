#include<bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int main(void)
{
    fastIO;
    int n;cin>>n;
    deque<int>dq;
    while(n--)
    {
        int i;cin>>i;
        if (i==1||i==2)
        {
            int x;cin>>x;
            if (i==1) dq.push_front(x);
            else dq.push_back(x);
        }
        else
        {
            if (dq.empty()&&i!=5&&i!=6)cout<<-1;
            else if (i==3)
            {
                cout<<dq.front();
                dq.pop_front();
            }
            else if (i==4)
            {
                cout<<dq.back();
                dq.pop_back();
            }
            else if (i==5)
            {
                cout<<dq.size();
            }
            else if (i==6)
            {
                if (dq.empty()) cout<<1;
                else cout<<0;
            }
            else if (i==7) cout<<dq.front();
            else cout<<dq.back();
            cout<<'\n';
        }
    }
    return 0;
}
