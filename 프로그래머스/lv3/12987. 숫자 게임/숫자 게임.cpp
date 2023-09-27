#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 0;
    
    priority_queue<int> q1;
    priority_queue<int> q2;
    
    for(int i = 0; i < a.size(); i++) {
        q1.push(a[i]);
        q2.push(b[i]);
    }
    
    while(!q1.empty()) {
        if(q1.top() < q2.top())
            q2.pop();
        
        q1.pop();
    }
    
    return b.size() - q2.size();
}