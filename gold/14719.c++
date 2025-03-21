#include<bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int main(void)
{
    fastIO;
    int h,w,res=0;cin>>h>>w;
    vector<vector<bool>>box(h,vector<bool>(w,false));
    for(int i=0;i<w;i++)
    {
        int b;cin>>b;
        for(int k=0;k<b;k++) box[k][i]=true; 
    }
    for(int i=0;i<h;i++)
    {
        bool black=false; int k=0;
        while(k<w)
        {
            if (box[i][k]) black=true;
            else
            {
                if (black)
                {
                    black=false; int cnt=0;
                    while(1)
                    {
                        if (k==w) break;
                        if (box[i][k])
                        {
                            black=true;break;
                        }
                        else cnt++;
                        k++;
                    }
                    if(black)res+=cnt;       
                }
            }
            k++;
        }
    }
    cout<<res;
    return 0;
}
