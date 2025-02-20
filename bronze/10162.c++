#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int t;cin>>t;cout<<(t%10?"-1":to_string(t/300)+" "+to_string(t%300/60)+" "+to_string(t%300% 60/10))<<'\n';return 0;
}
