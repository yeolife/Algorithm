#include <bits/stdc++.h>
using namespace std;

map<char, char> mp = {
    {']', '['}, {'}', '{'}, {')', '('}
};

int solution(string s) {
    int ans = 0 ;
    deque<char> dq(s.begin(), s.end());
    int sz = dq.size();
    
    while(sz--) {
        stack<char> st;
        
        bool flag = false;
        for(auto& it: dq) {
            if(it == '[' || it == '(' || it =='{') st.push(it);
            else {
                if(st.empty()) {
                    flag = true;
                    break;
                }
                if(!st.empty() && mp[it] == st.top()) st.pop();
            }
        }
        
        if(!flag && st.empty()) ans++;
        
        dq.push_back(dq.front());
        dq.pop_front();
    }
    
    return ans;
}