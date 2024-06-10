#include <bits/stdc++.h>
using namespace std;

// 각도를 꺾을 때마다 -1

int dx[4] = {1, 0, -1};
int dy[4] = {0, 1, -1};
int board[1001][1001];

void dfs(int x, int y, int dir, int cur, int cnt, int n) {
    board[x][y] = cur;
    if(n == 1) return;
    
    if(cnt == 1) {
        n -= 1;
        cnt = n;
        dir = (dir + 1) % 3;
    }
    else
        cnt--;
    
    dfs(x + dx[dir], y + dy[dir], dir, cur + 1, cnt, n);
}

vector<int> solution(int n) {
    vector<int> answer;
    
    dfs(0, 0, 0, 1, n, n);
    
    for(int i = 0; i <= 1000; i++) {
        for(int j = 0; j <= 1000; j++) {
            if(board[i][j] != 0)
                answer.push_back(board[i][j]);
        }
    }
    
    return answer;
}