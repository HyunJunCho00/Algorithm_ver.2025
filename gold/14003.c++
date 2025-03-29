#include<bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int main(void)
{
    fastIO;
    int n;cin>>n;
    vector<int>lis(n);
    for(int i=0;i<n;i++)cin>>lis[i];
    vector<int>save,pred(n,-1),res(n);
    for(int i=0;i<n;i++)
    {
        auto it=lower_bound(save.begin(),save.end(),lis[i]);
        int dist=it-save.begin();
        if (it==save.end())
        {
            if (!save.empty())
            {
                pred[i]=res[dist-1];
            }
            save.push_back(lis[i]);
            res[dist]=i;
        }
        else
        {
            if (dist>0)
            {
                pred[i]=res[dist-1];
            }
            save[dist]=lis[i];
            res[dist]=i;
        }
    }
    int cur=res[save.size()-1];
    vector<int>long_subseq;
    while(cur!=-1)
    {
        long_subseq.push_back(lis[cur]);
        cur=pred[cur];
    }
    cout<<save.size()<<'\n';
    for(int i=long_subseq.size()-1;i>=0;i--)cout<<long_subseq[i]<<' ';
    return 0;
}
