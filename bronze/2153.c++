#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    vector<bool> prime(52*21,false);
    prime[0] = true;
    int p=2;
    while(p*p<52*21)
    {
        if(!prime[p])
        {
            for(int i=p*p;i<52*21;i+=p)
                prime[i] = true;
        }
        p++;
    }
    string s; cin >> s;
    int pri=0;
    for(int i=0;i<s.length();i++)
    {
        if (s[i]>='A'&&s[i]<='Z')
            pri+=s[i]-'A'+27;
        else
            pri+=s[i]-'a'+1;
    }
    string res=prime[pri]?"It is not a prime word.":"It is a prime word.";
    cout << res << '\n';
    return 0;
}
