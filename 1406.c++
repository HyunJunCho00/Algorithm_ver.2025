#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    list<char> arr;
    string line;
    cin>>line;
    for (int i=0;i<line.length();i++)
    {
        arr.push_back(line[i]);
    }
    int n;
    cin>>n;
    cin.ignore();
    string move;
    auto it=arr.end();
    for (int i=0;i<n;i++)
    {
        getline(cin,move);
        if (move[0]=='L')
        {
            if (it!=arr.begin())
                it--;
        }
        else if (move[0]=='D')
        {
            if (it!=arr.end())
                it++;
        }
        else if (move[0]=='B')
        {
            if (it!=arr.begin())
            {
                it=arr.erase(--it);
            }
        }
        else
        {
            char token=move[2];
            arr.insert(it,token);
        }
    }
    for (char ch : arr) 
    {
        cout << ch;
    }
    cout<<'\n';
    return 0;
}
