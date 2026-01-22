#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
    string full;
    string head;
    int num;
    int ord;
}file;
bool compare(const file& a, const file& b)
{
    if (a.head != b.head)
        return a.head < b.head;
    if (a.num != b.num)
        return a.num < b.num;
    return a.ord < b.ord;
}

vector<string> solution(vector<string> files) 
{
    vector<file>ff(files.size());
    int idx=0;
    for(string f:files)
    {
        string s="";bool d=false;
        for(int i=0;i<f.length();i++)
        {
            if (isdigit((unsigned char)f[i]))
            {
                if (d)
                {
                    s+=f[i];
                }
                else
                {
                    string lower;
                    for(char c:s)
                    {
                        lower+=tolower(c);
                    }
                    ff[idx].head=lower;
                    s=f[i];d=true;
                }
            }
            else
            {
                if (d)
                {
                    ff[idx].num=stoi(s);
                    s="";
                    break;
                }
                else
                {
                    s+=f[i];
                }
            }
        }
        if (s.length())
        {
            ff[idx].num=stoi(s);
        }
        ff[idx].ord=idx;
        ff[idx].full=f;
        idx++;
    }
    sort(ff.begin(),ff.end(),compare);
    vector<string>ans;
    for(auto&f:ff)
    {
        ans.push_back(f.full);
    }
    return ans;
}
