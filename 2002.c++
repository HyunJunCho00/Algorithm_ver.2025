#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;cin>>n;
    deque<string>st;
    for(int i=0;i<n;i++)
    {
        string s;cin>>s;
        st.push_back(s);
    }
    int count=0;
    deque<string>save;
    for(int i=0;i<n;i++)
    {
        string s;cin>>s;
        if (!s.compare(st.front()))
        {
            st.pop_front();
        }
        else
        {
            while(s.compare(st.back()))
            {
                save.push_back(st.back());
                st.pop_back();
            }
            st.pop_back();
            count++;
            while(!save.empty())
            {
                st.push_back(save.back());
                save.pop_back();
            }
        }
    }
    cout<<count;
    return 0;
}
