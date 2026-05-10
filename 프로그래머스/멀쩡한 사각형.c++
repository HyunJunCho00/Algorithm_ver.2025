#include<bits/stdc++.h>
using namespace std;

long long solution(int w,int h) {
    long long answer = 1;
    answer=(long long)w*h-w-h+gcd(w,h);
    return answer;
}
