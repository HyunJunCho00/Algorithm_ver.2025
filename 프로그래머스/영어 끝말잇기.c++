#include<bits/stdc++.h>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2,0);
    int idx=1;
    char end=words[0][words[0].size()-1];
    set<string>word;
    word.insert(words[0]);
    while(idx<words.size())
    {
        char start=words[idx][0];
        
        if (end==start)
        {
            if (word.find(words[idx])==word.end())
            {
                word.insert(words[idx]);
                end=words[idx][words[idx].size()-1];
                idx++;
            }
            else
            {
                answer[0]=(idx%n)+1;
                answer[1]=(idx/n)+1;
                break;
            }

        }
        else
        {
            answer[0]=(idx%n)+1;
            answer[1]=(idx/n)+1;
            break;
        }

    }

    return answer;
}
