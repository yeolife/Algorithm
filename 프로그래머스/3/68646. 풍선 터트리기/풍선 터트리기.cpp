#include <bits/stdc++.h>
using namespace std;

// 나보다 작은애가 양쪽에 있어서는 안됨
int solution(vector<int> a) {
    stack<int> st;
    
    int cur = a[0];
    st.push(a[0]);
    
    for(int i = 1; i < a.size(); i++) {
        while(!st.empty() && (st.top() > a[i] && st.top() > cur))
            st.pop();
        
        st.push(a[i]);
        cur = min(cur, a[i]);
    }
    
    return st.size();
}