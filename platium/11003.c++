#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pii pair<int,int>
using namespace std;
int main(void)
{
    fastIO;int n,l;cin>>n>>l;
    vector<int>arr(n+1,0); deque<pii>dq; stringstream ss;
    for (int i=1;i<=n;i++)
    {
        cin>>arr[i];
        while (!dq.empty()&&dq.back().first>arr[i])
            dq.pop_back();
        dq.push_back({arr[i],i});
        if (dq.front().second<=i-l)
            dq.pop_front();
        ss<<dq.front().first<<' ';
    }
    cout<<ss.str()<<'\n';
    return 0;
}
