#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int t;
    cin>>t;
    cin.ignore();
    for (int i=0;i<t;i++)
    {
        string str;
        vector<string>tokens;
        getline(cin,str);
        istringstream iss(str);
        string token;
        while(iss>>token)
            tokens.push_back(token);
        int check=0;
        double res = stod(tokens[0]);  

        for (size_t j = 1; j < tokens.size(); j++) 
        {  
            if (tokens[j] == "@")
                res *= 3;
            else if (tokens[j] == "#")
                res -= 7;
            else if (tokens[j] == "%")
                res += 5;
        }
        cout<<fixed<<setprecision(2)<<res<<'\n';
    }
    return 0;
}
