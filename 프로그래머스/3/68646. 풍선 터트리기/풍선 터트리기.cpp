#include <bits/stdc++.h>
using namespace std;

// 나보다 작은애가 양쪽에 있어서는 안됨
int solution(vector<int> a) {
    stack<int> st;
    
    int prev = 1e9;
    for(int i = 0; i < a.size(); i++) {
        while(!st.empty() && (st.top() > a[i] && st.top() > prev))
            st.pop();
        
        st.push(a[i]);
        prev = min(prev, a[i]);
    }
    
    return st.size();
}