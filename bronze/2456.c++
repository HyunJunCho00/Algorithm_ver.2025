#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
struct Student
{
    int id,sum,num[3];
    bool operator<(const Student&other)const{
        if (sum!=other.sum)return sum>other.sum;
        if (num[2]!=other.num[2]) return num[2]>other.num[2];
        if (num[1]!=other.num[1]) return num[1]>other.num[1];
        return num[0]>other.num[0];
    }
};
vector <Student> st(3);
void check()
{
    int idx=0;
    if (st[0].sum==st[1].sum)
    {
        for (int i=0;i<3;i++)
        {
            if (st[0].num[i]>st[1].num[i])
            {
                cout<<st[0].id<<' '<<st[0].sum<<'\n';
                return;
            }
        }
        cout<<idx<<' '<<st[0].sum<<'\n';
    }
    else
        cout<<st[0].id<<' '<<st[0].sum<<'\n';
}
int main(void)
{
    fastIO;
    int n;
    cin>>n;
    for (int i=0;i<3;i++)
    {
        st[i]={i+1,0,{0,0,0}};
    }
    for (int i=0;i<n;i++)
    {
        for (int k=0;k<3;k++)
        {
            int a;
            cin>>a;
            st[k].num[a-1]++;
            st[k].sum+=a;
        }
    }
    sort(st.begin(), st.end());
    check();
    return 0;
}
