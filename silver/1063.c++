#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
bool valid(int r,int c)
{
    if (0<=r&&r<8&&0<=c&&c<8)return false;
    return true;
}
string convert_s(pii p)
{
    string s="";
    s+=(char)('A'+p.first);
    s+=(char)('1'+p.second);
    return s;
}
int main(void)
{
    string king,rock;
    int n;
    cin>>king>>rock>>n;
    vector<string>move(n);
    for(int i=0;i<n;i++)cin>>move[i];
    pii k={king[0]-'A',king[1]-'1'}; pii r={rock[0]-'A',rock[1]-'1'};
    map<string,pii>mm;
    mm["R"]={1,0};
    mm["L"]={-1,0};
    mm["B"]={0,-1};
    mm["T"]={0,1};
    mm["RT"]={1,1};
    mm["LT"]={-1,1};
    mm["RB"]={1,-1};
    mm["LB"]={-1,-1};
    for(const string&mov:move)
    {
        pii dir=mm[mov];
        pii next={k.first+dir.first,k.second+dir.second};
        if (valid(next.first,next.second))continue;
        if (next==r)
        {
            pii next_r={r.first+dir.first,r.second+dir.second};
            if (valid(next_r.first,next_r.second))continue;
            k=next;r=next_r;
        }
        else k=next;
    }
    cout<<convert_s(k)<<'\n'<<convert_s(r);
    return 0;
}
