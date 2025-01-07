#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;
    cin>>n;
    cin.ignore();
    for (int i=0;i<n;i++)
    {
        string input;
        getline(cin,input);
        stringstream ss(input);
        string word;
        vector <string> sentence;
        while (ss>>word)
            sentence.push_back(word);
        for (auto&w:sentence)
        {
            for (int k=w.size()-1;k>=0;k--)
                cout<<w[k];
            cout<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
