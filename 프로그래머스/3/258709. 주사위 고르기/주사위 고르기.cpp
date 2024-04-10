#include <bits/stdc++.h>
using namespace std;

int n, per, win, lose;
vector<int> A = {0}, B, ans;
vector<vector<int> > dices;

// 뽑은 주사위에서 하나씩 뽑기
// A 순열과 B 순열 비교
void permu(vector<int>& team, vector<int>& sums, int depth, int sum) {
    if(depth == n) {
        sums.push_back(sum);
        
        return;
    }
    
    for(int i = 0; i < dices[team[depth]].size(); i++)
        permu(team, sums, depth + 1, sum + dices[team[depth]][i]);
}

// 주사위 나눠 가지기
void dfs(int depth, int idx) {
    if(depth == n) {
        B.clear();
        for(int i = 0, j = 0; i < dices.size(); i++) {          
            if(A[j] != i) B.push_back(i);
            else j++;
        }
        
        vector<int> sumA, sumB;
        permu(A, sumA, 0, 0);
        permu(B, sumB, 0, 0);
        
        sort(sumA.begin(), sumA.end());
        sort(sumB.begin(), sumB.end());
        
        int maxiA = 0;
        for(int i = 0; i < sumA.size(); i++)
            maxiA += lower_bound(sumB.begin(), sumB.end(), sumA[i]) - sumB.begin();
            
        int maxiB = 0;
        for(int i = 0; i < sumB.size(); i++)
            maxiB += lower_bound(sumA.begin(), sumA.end(), sumB[i]) - sumA.begin();
                
        if(maxiA > per || maxiB > per) {
            ans = (maxiA > maxiB) ? A : B;
            per = max(maxiA, maxiB);
        }
                 
        return;
    }
    
    for(int i = idx; i < dices.size(); i++) {
        A.push_back(i);        
        dfs(depth + 1, i + 1);
        A.pop_back();
    }
}

vector<int> solution(vector<vector<int>> dice) {
    n = dice.size() / 2;
        
    dices = dice;
    
    dfs(1, 1);
    
    for(auto& it: ans) it++;
    
    return ans;
}