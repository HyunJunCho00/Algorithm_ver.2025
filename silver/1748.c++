#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;
    cin>>n;
    if (n<10) cout<<n;
    else
    {
        int count=9;
        int i=10;
        int j=2;
        while(1)
        {
            if (n<i)break;
            i*=10;j++;
        }
        i=10;j-=1;
        for (int jj=2;jj<=j;jj++)
        {
            if (jj<j)count+=((i*10)-i)*jj;
            else count+=(n-i+1)*j;
            i*=10;
        }       
        cout<<count;
    }
    return 0;
}
