#include<bits/stdc++.h>
using namespace std;
int dx[]={0, 1, 0, -1}; 
int dy[]={-1, 0, 1, 0}; 

int arr[1001][1001];

int main(void)
{
    int n,c;cin>>n>>c;
    int ww=n/2+1,hh=n/2+1,s_w=1,s_h=1,m=1,move=1,i=0;
    
    arr[ww][hh]=m;
    if (m == c) 
    {
        s_w=ww,s_h=hh;
    }
    m++;
    
    bool done = false; 

    while(m<=n*n)
    {
        for(int k=0;k<move;k++)
        {
            ww+=dy[i],hh+=dx[i];
            
            if (m > n*n)
            {
                done = true;
                break;
            }

            if (m==c)
            {
                s_w=ww,s_h=hh;
            }
            arr[ww][hh]=m++;
        }
        
        if (done) break;

        i=(i+1)%4;
        if (i==0 || i==2) move++;
    }
    
    for(int y=1;y<=n;y++)
    {
        for(int x=1;x<=n;x++)
        {
            cout<<arr[y][x]<<(x == n ? "" : " ");
        }
        cout<<'\n';
    }
    cout<<s_w<<' '<<s_h;
    
    return 0;
}
