#include <bits/stdc++.h>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = k;
    
    if(answer > enemy.size()) return enemy.size();
    
    priority_queue<int, vector<int>, greater<int> > pq;
    
    for(int i = 0; i < k ; i++)
        pq.push(enemy[i]);
    
    long long sum = 0;
    for(int i = k; i < enemy.size(); i++) {
        long long cur = pq.top();
        
        if(cur < enemy[i]) {
            pq.push(enemy[i]);
            pq.pop();
        } 
        else 
            cur = enemy[i];   
        
        sum += cur;
        
        if(sum > n) break;
        
        answer++;
    }

    return answer;
}