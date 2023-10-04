#include <bits/stdc++.h>

using namespace std;

vector<int> timestamp;

// 편의상 시간을 정수로 변환
void StoI(vector<string> timetable) {
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

// 시간을 문자열로 재변환
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
    int ans = 540;
    string answer = "";
    
    stack<int> st;
    priority_queue<int, vector<int>, greater<int> > pq;
    
    StoI(timetable);
    
    for(auto& it: timestamp)
        pq.push(it);

    for(int i = 0, cur = 9 * 60; i < n; i++, cur += t) {
        // 크루원 신경 안 쓰고 제일 늦게 가도 널널함
        if(pq.empty() || (pq.top() > 9 * 60 + t * (n-1))) {
            ans = cur + t * (n-1-i);
            break;
        }
        
        // 현재 셔틀에 최대한 태움
        int cnt = 0;
        while(!pq.empty() && cur >= pq.top() && cnt < m) {
            if(i == n-1)
                st.push(pq.top());
            
            cnt++;
            pq.pop();
        }
        
        if(cnt < m) ans = cur;
    }
    
    // 현재 셔틀이 꽉 차면 
    if(m == st.size()) {
        // 가장 늦은 시각을 중복을 확인하며 내리게 함
        int dup = st.top(); st.pop();
        while(!st.empty() && dup == st.top()) {
            dup = st.top();
            st.pop();
        }
        ans = dup - 1;
    }
    
    answer = TtoS(ans);
    
    return answer;
}

// 최대한 늦게 도착하지만 꼭 타야함.
// 중복 예외를 처리해야함.