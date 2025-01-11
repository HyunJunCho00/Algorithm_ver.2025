#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main(void)
{
    int n;
    cin>>n;
    unordered_map<string,bool>h_map;
    vector <string> keys;
    string line;
    cin.ignore();
    for (int i=0;i<n;i++)
    {
        getline(cin,line);
        istringstream iss(line);
        string word;
        vector <string>words;
        while(iss>>word)
            words.push_back(word);
        if (h_map.find(words[0])!=h_map.end() &&h_map[words[0]])
            h_map[words[0]]=false;
        else
            h_map[words[0]]=true;
    }
    for (const auto&pair:h_map)
    {
        if (pair.second==true)
            keys.push_back(pair.first);
    }
    sort(keys.begin(),keys.end(),greater<string>());
    for (const auto&key:keys)
    {
        cout<<key<<'\n';
    }
    return 0;
}
