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
        
        // 앞에서부터 111이면 110 담음
        string ret = "";
        string ooz = "110";
        
        int idx = 0;
        
        for(int j = dq.size() - 1; j >= 0; j--) {
            if(dq[j] == '0') {
                idx = j + 1;
                break;
            }
        }
                
        for(int j = 0; j < idx; j++)
            ret += dq[j];
        
        while(cnt) {
            ret += ooz;
            cnt--;
        }
        
        for(int j = idx; j < dq.size(); j++)
            ret += dq[j];

        answer.push_back(ret);
    }
    
    return answer;
}