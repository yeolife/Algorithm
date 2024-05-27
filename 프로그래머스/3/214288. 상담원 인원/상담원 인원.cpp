#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>; 

int k, ans = 1e9, mento[5];
vector<pii> req[5];

int oper_time(int n) {
    int ret = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    int i = 0;
    for(; i < mento[n] && i < req[n].size(); i++)
        pq.push(req[n][i].first + req[n][i].second);
        
    
    while(i < req[n].size() && !pq.empty()) {
        // 도착시간, 상담시간
        int dt, st;
        tie(dt, st) = req[n][i++];
        
        int cur = pq.top();
        pq.pop();
        
        if(dt < cur) {
            ret += cur - dt;
            pq.push(cur + st);
        }
        else 
            pq.push(dt + st);
    }
        
    return ret;
}

void dfs(int depth, int remain) {
    if(remain == 0) {
        int ret = 0;
        for(int i = 0; i < k; i++) {
            if(!req[i].empty())
                ret += oper_time(i);
        }
        
        ans = min(ans, ret);
        
        return;
    }
    if(depth >= k) return;
    
    // (n-k)명의 멘토를 조합
    for(int i = 0; i <= remain; i++) {
        mento[depth] += i;
        dfs(depth + 1, remain - i);
        mento[depth] -= i;
    }
}

// 가장 적게 기다린 총 시간
int solution(int kk, int n, vector<vector<int>> reqs) {
    k = kk;
    
    for(int i = 0; i < reqs.size(); i++)
        req[reqs[i][2] - 1].push_back({reqs[i][0], reqs[i][1]});
    
    fill(mento, mento + k, 1);
    
    dfs(0, n - k);
    
    return ans;
}