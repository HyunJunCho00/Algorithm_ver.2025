#include<bits/stdc++.h>
using namespace std;
int mm[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool yoon(int c_y,int i)
{
    return (c_y%4==0&&(c_y%100||c_y%400==0)&&i==2);
}
int main(void)
{
    int y,m,d;cin>>y>>m>>d;
    int cy,cm,cd;cin>>cy>>cm>>cd;
    int day=0,c_y=y,m_m=m;
    while(c_y<=cy)
    {
        if (c_y<cy)
        {
            if (y==c_y)day+=mm[m]-d;
            y==c_y?m=m:m=0;
            for(int i=m+1;i<=12;i++)
            {
                yoon(c_y,i)?day+=mm[i]+1:day+=mm[i];
            }
        }
        else
        {
            if (y==c_y)yoon(c_y,m)?day+=mm[m]-d+1:day+=mm[m]-d;
            y==c_y?m=m:m=0;
            for(int i=m+1;i<cm;i++)
            {
                yoon(c_y,i)?day+=mm[i]+1:day+=mm[i];
            }
            day+=cd;
        }
        c_y++;
    }
    if (y+1000<cy||(y+1000==cy&&(m_m<cm||(m_m==cm&&d<=cd))))cout<<"gg";
    else cout<<"D-"<<day;
    return 0;
}
