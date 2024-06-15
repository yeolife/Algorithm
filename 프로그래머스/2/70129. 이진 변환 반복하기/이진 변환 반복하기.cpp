#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2, 0);
    
    while(s != "1") {
        // 1의 갯수를 셈
        int zero = 0, one = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '1') one++;
            else zero++;
        }
        
        s = "";
        
        while(one) {
            s += (one%2) + '0';
            one /= 2;
        }
        
        answer[0]++;
        answer[1] += zero;
    }
    
    return answer;
}