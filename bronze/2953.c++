#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int r=1,s=0;
    for(int i=1;i<=5;i++)
    {
        int c=0,b;
        for(int k=0;k<4;k++){
            cin>>b;c+=b;
        }
        if(s<c){
            r=i;s=c;
        }
    }
    cout<<r<<" "<<s;
    return 0;
}
