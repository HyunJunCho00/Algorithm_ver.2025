#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
unordered_map<int,int>inorder;
vector<int>pre;
void build(vector<int>&in,vector<int>&post,int is,int ie,int ps,int pe)
{
    if (is>ie||ps>pe) return;
    int root=post[pe], root_index=inorder[root],left=root_index-is;
    pre.push_back(root);
    build(in,post,is,root_index-1,ps,ps+left-1);
    build(in,post,root_index+1,ie,ps+left,pe-1);
}
int main(void)
{
    fastIO;
    int n;cin>>n;
    vector<int>inor(n),post(n);
    for (int i=0;i<n;i++)
    {
        cin>>inor[i]; inorder[inor[i]]=i;
    }
    for(int i=0;i<n;i++)cin>>post[i];
    build(inor,post,0,n-1,0,n-1);
    for (int pr:pre) cout<<pr<<' ';
    return 0;
}
