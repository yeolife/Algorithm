#include <bits/stdc++.h>

using namespace std;

vector<int> timestamp;

void StoI(vector<string> timetable) {
    // 편의상 시간을 정수로 변경
    
    for(int i = 0; i < timetable.size(); i++) {
        bool flag = false;
        stringstream ss;
        ss.str(timetable[i]);

        string token = "";
        while(getline(ss, token, ':')) {
            if(!flag) {
                timestamp.push_back(stoi(token)*60);
                flag = true;
            }
            else
                timestamp.back() += stoi(token);
        }
    }
}

string TtoS(int t) {
    string h = to_string(t / 60);
    string m = to_string(t % 60);
    
    if(h.length() == 1) {
        h += "0";
        reverse(h.begin(), h.end());
    }
    
    if(m.length() == 1) {
        m += "0";
        reverse(m.begin(), m.end());
    }
    
    
    string ret = h + ":" + m;
    
    return ret;
}

string solution(int n, int t, int m, vector<string> timetable) {
    int ans = 0;
    string answer = "";
    
    priority_queue<int, vector<int>, greater<int> > pq;
    
    StoI(timetable);
    
    for(auto& it: timestamp)
        pq.push(it);
    
    int cur = 9 * 60;
    for(int i = 0; i < n; i++) {
        int cnt = 0;
        
        if(pq.empty() || (!pq.empty() && pq.top() > 9 * 60 + t * (n-1))) {
            ans = cur + t*(n-1-i);
            break;
        }
        
        stack<int> st;
        while(!pq.empty() && cur >= pq.top() && cnt < m) {
            st.push(pq.top());
            pq.pop();
            cnt++;
        }
        
        if(cnt < m)
            ans = cur;
        else {
            if(!st.empty()) {
                int dup = st.top(); st.pop();
                while(!st.empty() && dup == st.top()) {
                    dup = st.top();
                    st.pop();
                }
                ans = dup - 1;
            }
        }
            
        cur += t;
    }
    
    answer = TtoS(ans);
    
    return answer;
}

// 최대한 늦게 도착하지만 꼭 타야함.
// 중복 예외를 처리해야함.


