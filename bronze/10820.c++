#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    string s;
    while(getline(cin,s))
    {
        vector<int>a(4,0);
        for(char ss:s)
        {
            if (96<=ss&&ss<=122)a[0]++;
            else if (65<=ss&&ss<=90)a[1]++;
            else if (48<=ss&&ss<=57)a[2]++;
            else if (32==ss)a[3]++;
        }
        for(int i:a)cout<<i<<' ';
        cout<<'\n';
    }
    return 0;
}
