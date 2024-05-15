#include <bits/stdc++.h>
using namespace std;

int emoM, emoP;
vector<int> permu;

vector<vector<int>> user;
vector<int> emo;

map<int, double> sales = {
    {10, 0.9}, {20, 0.8}, 
    {30, 0.7}, {40, 0.6}
};

// 이모티콘 플러스 가장 많이 가입이면서, 가장 많은 판매액
void dfs(int depth) {
    if(depth == emo.size()) {
        int cnt = 0, price = 0;
        
        for(int i = 0; i < user.size(); i++) {
            int uprice = 0;
            for(int j = 0; j < emo.size(); j++) {
                if(permu[j] >= user[i][0])
                    uprice += emo[j] * sales[permu[j]];
            }
            
            if(user[i][1] <= uprice) cnt++;
            else price += uprice;            
        }
        
        if(cnt >= emoM) {
            emoP = (cnt == emoM) ? max(emoP, price) : price;
            emoM = cnt;
        }
        
        return;
    }
    
    for(int i = 10; i <= 40; i += 10) {
        permu.push_back(i);
        dfs(depth + 1);
        permu.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    user = users;
    emo = emoticons;
    
    dfs(0);
    
    return {emoM, emoP};
}