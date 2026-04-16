#include <bits/stdc++.h>
using namespace std;

char c[] = {'*', '+', '-'};
bool vis[3];
long long answer = 0;

long long calculate(long long a, long long b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    return a * b;
}

void dfs(vector<string> save, int depth) {
    if (depth == 3) {
        answer = max(answer, abs(stoll(save[0])));
        return;
    }

    for (int i = 0; i < 3; i++) {
        if (!vis[i]) {
            vis[i] = true;
            vector<string> next_save = save; 
            
            for (int k = 0; k < next_save.size(); k++) {
                if (next_save[k] == string(1, c[i])) {
                    long long res = calculate(stoll(next_save[k - 1]), stoll(next_save[k + 1]), c[i]);
                    
                    next_save[k] = to_string(res);
                    next_save.erase(next_save.begin() + k + 1);
                    next_save.erase(next_save.begin() + k - 1);
                    
                    k--; 
                }
            }
            
            dfs(next_save, depth + 1);
            vis[i] = false;
        }
    }
}

long long solution(string expression) {
    vector<string> save;
    string num = "";
    for (char e : expression) {
        if (isdigit(e)) {
            num += e;
        } else {
            save.push_back(num);
            save.push_back(string(1, e));
            num = "";
        }
    }
    save.push_back(num);

    dfs(save, 0);
    return answer;
}
