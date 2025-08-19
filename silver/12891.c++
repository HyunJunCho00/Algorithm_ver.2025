#include<bits/stdc++.h>
using namespace std;
int cnt[4];
int main(void)
{
    int s,p,a,c,g,t,res=0;
    cin>>s>>p;
    string dna;
    cin>>dna;
    cin>>a>>c>>g>>t;

    for(int i=0;i<p;i++)
    {
        dna[i]=='A'?cnt[0]++:dna[i]=='C'?cnt[1]++:dna[i]=='G'?cnt[2]++:cnt[3]++;
    }
    if (cnt[0]>=a&&cnt[1]>=c&&cnt[2]>=g&&cnt[3]>=t)
        res++;
    for(int i=p;i<s;i++)
    {
        dna[i]=='A'?cnt[0]++:dna[i]=='C'?cnt[1]++:dna[i]=='G'?cnt[2]++:cnt[3]++;
        dna[i-p]=='A'?cnt[0]--:dna[i-p]=='C'?cnt[1]--:dna[i-p]=='G'?cnt[2]--:cnt[3]--;
        if (cnt[0]>=a&&cnt[1]>=c&&cnt[2]>=g&&cnt[3]>=t)
            res++;

    }
    cout<<res;
    return 0;
}
