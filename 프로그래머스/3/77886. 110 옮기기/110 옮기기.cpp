#include <bits/stdc++.h>
using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;

    for(int i = 0; i < s.size(); i++) {
        // 110 갯수 + parsing
        int cnt = 0;
        deque<char> dq;
        for(int j = 0; j < s[i].length(); j++) {
            dq.push_back(s[i][j]);
                        
            while(dq.size() >= 3 && dq.back() == '0' && *(dq.end() - 2) == '1' && *(dq.end() - 3) == '1') {
                int three = 3;
                while(three--) dq.pop_back();
                cnt++;
            }            
        }
        
        // 앞에서부터 11이면 110 담음
        string ret = "";
        string ooz = "110";
        
        int j = 0;
        for(; j < dq.size(); j++) {
            if(j == dq.size() - 1 && dq[j] == '1') break;
            if(dq[j] == '1' && dq[j + 1] == '1') break;
            
            ret += dq[j];
        }
        
        while(cnt) {
            ret += ooz;
            cnt--;
        }
        
        while(j < dq.size()) {
            ret += dq[j];
            j++;
        }
        
        answer.push_back(ret);
    }
    
    return answer;
}