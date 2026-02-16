#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;
    cin>>n;
    cout<<(int)(n/100)*78<<' '<<(int)(n/10*8+(n/1000)*156);
    return 0;
}
