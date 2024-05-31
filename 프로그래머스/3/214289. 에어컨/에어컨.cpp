#include <bits/stdc++.h>
using namespace std;

int outt, t1, t2, a, b, n;
vector<int> board;
int dp[1001][51];

int dfs(int ctime, int ctemp) {
    if(board[ctime] && (t1 > ctemp || t2 < ctemp))
        return 1e9;
    if(ctime > n - 2)
        return 0;

    int& ret = dp[ctime][ctemp];
    if(ret != -1) return ret;
    ret = 1e9;

    if(ctemp == outt)
        ret = min(ret, dfs(ctime + 1, ctemp)); // 끔
    if(ctemp > outt)
        ret = min(ret, dfs(ctime + 1, ctemp - 1)); // 끔

    if(ctemp <= t1)
        ret = min(ret, dfs(ctime + 1, ctemp + 1) + a); // 켬(up)
    ret = min(ret, dfs(ctime + 1, ctemp) + b); // 켬(유지)
    
    return ret;
}

int solution(int temperature, int T1, int T2, int A, int B, vector<int> onboard) {
    n = onboard.size();
    outt = temperature + 10, t1 = T1 + 10, t2 = T2 + 10, a = A, b = B, board = onboard;
    
    fill(&dp[0][0], &dp[1000][51], -1);
    
    if(outt > t2) outt = t1 - (outt - t2);
    if(outt < 0) {
        t1 += (-outt);
        t2 += (-outt);
        outt = 0;
    }

    int ans = dfs(0, outt);

    return ans;
}