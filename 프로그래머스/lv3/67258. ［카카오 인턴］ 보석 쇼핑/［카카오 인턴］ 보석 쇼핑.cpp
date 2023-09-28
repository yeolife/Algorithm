#include <bits/stdc++.h>

using namespace std;

set<string> s;
vector<int> answer(2, 0);

void f(vector<string> gems) {
    deque<string> dq;
    
    map<string, int> mp;
    
    int st = 0, en = 1e9;
    
    for(int i = 0; i < gems.size(); i++) {
        dq.push_back(gems[i]);
        
        mp[gems[i]]++;
                
        int sst = st;
        int een = i;
        if(s.size() == mp.size()) {
            while(mp[dq.front()] > 1) {
                mp[dq.front()]--;
                                
                dq.pop_front();
                
                sst++;
            }
            
            if(answer[1] - answer[0] >= een - sst) {
                if(answer[1] - answer[0] > een - sst) {
                    answer[0] = sst + 1;
                    answer[1] = een + 1;
                }
                
                en = een;
            }
            
            st = sst;
        }
    }
}

vector<int> solution(vector<string> gems) {   
    answer[1] = 1e9;
    
    for(auto& it: gems) s.insert(it);
    
    f(gems);
    
    return answer;
}