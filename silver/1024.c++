#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n,l;cin>>n>>l;
    while(l<=100)
    {
        int s=(l-1)*l/2;
        if (n-s<0)break;
        if ((n-s)%l==0)
        {
            int res=(n-s)/l;
            for(int i=0;i<l;i++)
                cout<<res+i<<' ';
            exit(0);
        }
        l++;
    }
    cout<<-1;
    return 0;
}
