#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pii pair<int,int>
using namespace std;
int s[1000001];
int N=1000000;
int main(void)
{
    fastIO;
    int n=1;
    for (int i=2;i<=N;i++)s[i]=1;
    for(int i=2;i<int(sqrt(N))+1;i++)
    {
        for (int j=i;j<int(N/i)+1;j++) (i!=j)?s[i*j]+=i+j:s[i*j]+=i;
    }
    while(cin>>n)
    {
        if (n==0)break;
        cout<<"\nAmicable numbers between 1 and "<<n<<'\n';
        set<pii> p;
        for (int i=2;i<=n;i++)
        {
            if (i<s[i]&&s[i]<=n&&i==s[s[i]])p.insert({i,s[i]});
        }
        if (p.empty()) cout<<"None\n";
        else
            for (pii pair:p)cout<<pair.first<<' '<<pair.second<<'\n';
    }
    return 0;
}
