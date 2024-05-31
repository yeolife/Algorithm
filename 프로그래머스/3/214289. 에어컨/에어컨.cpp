#include <bits/stdc++.h>
using namespace std;

int outt, t1, t2, spow, dpow, n;
vector<int> board;
int dp[1001][101];

int dfs(int ctime, int ctemp) {
    if(board[ctime] && (t1 > ctemp))
        return 1e9;
    if(ctime >= n)
        return 0;

    int& ret = dp[ctime][ctemp];
    if(ret != -1) return ret;
    ret = 1e9;

    if(ctemp == outt)
        ret = min(ret, dfs(ctime + 1, ctemp)); // 끔
    if(ctemp - 1 >= outt)
        ret = min(ret, dfs(ctime + 1, ctemp - 1)); // 끔

    if(ctemp <= t1)
        ret = min(ret, dfs(ctime + 1, ctemp + 1) + dpow); // 켬(up)
    ret = min(ret, dfs(ctime + 1, ctemp) + spow); // 켬(유지)
    
    return ret;
}

int solution(int temperature, int tt1, int tt2, int a, int b, vector<int> onboard) {
    n = onboard.size();
    outt = temperature + 10, t1 = tt1 + 10, t2 = tt2 + 10, dpow = a, spow = b, board = onboard;
    
    fill(&dp[0][0], &dp[1000][101], -1);
    
    dp[n-1][t1] = 0;
    dp[n-1][t1+1] = 0;

    if(outt >= t2) outt = t1 - (outt - t2);
    if(outt < 0) {
        t1 += (-outt);
        t2 += (-outt);
        outt = 0;
    }

    int ans = dfs(0, outt);

    return ans;
}