#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> sticker) {
    int answer = 0;
    int dp[100001] = {0,};
    
    if(sticker.size() == 1) return sticker.front();
            
    // 2부터 시작
    dp[0] = 0; 
    dp[1] = sticker[1];
    
    for(int i = 2; i < sticker.size(); i++) {
        dp[i] = max(dp[i-1], dp[i-2] + sticker[i]);
    }
    
    answer = dp[sticker.size()-1];
    
    // 1부터 시작
    sticker.pop_back();
    
    memset(dp, 0, 100001);
    dp[0] = sticker[0];
    dp[1] = sticker[0];
    
    for(int i = 2; i < sticker.size(); i++) {
        dp[i] = max(dp[i-1], dp[i-2] + sticker[i]);
    }
    
    answer = max(answer, dp[sticker.size()-1]);
    
    return answer;
}