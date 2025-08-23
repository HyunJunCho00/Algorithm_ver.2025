#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;cin>>n;
    vector<int>score(n+1,0);
    for(int i=1;i<=n;i++)
    {
        int s;cin>>s;
        s?(score[i]=score[i-1]+1):score[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        score[i]+=score[i-1];
    }
    cout<<score[n];
    return 0;
}
