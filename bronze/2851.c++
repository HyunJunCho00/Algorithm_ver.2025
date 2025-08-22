#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int ans=0;
    for(int i=1;i<=10;i++)
    {
        int a;cin>>a;
        if(ans+a<=100)
        {
            ans+=a;
        }
        else
        {
            if (abs(100-ans)>=abs(ans+a-100)) ans+=a;
            break;
        }
    }
    cout<<ans;
    return 0;
}
