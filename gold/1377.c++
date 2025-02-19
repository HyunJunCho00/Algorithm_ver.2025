#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pii pair<int,int>
using namespace std;
int main(void)
{
    fastIO; int n,move=0; cin>>n; 
    vector<pii> A(n);
    for (int i=0;i<n;i++)
    {
        cin>>A[i].first;A[i].second=i;
    }
    sort(A.begin(),A.end());
    for (int i=0;i<n;i++) move=max(move,A[i].second-i);
    cout<<move+1<<'\n';
    return 0;
}
