#include<bits/stdc++.h>
using namespace std;
int dx[]={0,-1,0,1};
int dy[]={1,0,-1,0};
int main(void)
{
    int t;cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;cin>>s;
        int lx=0,rx=0,Uy=0,Dy=0,sx=0,sy=0,move=0;
        for(int k=0;k<s.length();k++)
        {
            if (s[k]=='L')
            {
                move=(move+1)%4;
            }
            else if (s[k]=='R')
            {
                move==0?move=3:move=(move-1);
            }
            else if (s[k]=='F')
            {
                sx+=dx[move],sy+=dy[move];
            }
            else
            {
                sx-=dx[move],sy-=dy[move];
            }
            lx=min(lx,sx);
            rx=max(rx,sx);
            Uy=max(Uy,sy);
            Dy=min(Dy,sy);  
        }
        cout<<(rx-lx)*(Uy-Dy)<<'\n';
    }
    return 0;
}
