#include <bits/stdc++.h>
using namespace std;

// k개만큼의 범위에서 가장 큰 값 중에 가장 작은 값 + 슬라이딩 윈도우

int solution(vector<int> stones, int k) {
    int ans = 0;
    priority_queue<int> pq, dummy;
            
    for(int i = 0; i < k; i++) 
        pq.push(stones[i]);
    
    dummy.push(0);
    
    ans = pq.top();
        
    for(int i = k; i < stones.size(); i++) {
        pq.push(stones[i]);
        dummy.push(stones[i-k]);
                
        while(pq.top() <= dummy.top()) {
            pq.pop();
            dummy.pop();
        }
        
        if(ans > pq.top()) ans = pq.top();
    }

    return ans;
}