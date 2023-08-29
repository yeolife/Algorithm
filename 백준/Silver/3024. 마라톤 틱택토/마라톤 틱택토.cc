#include <bits/stdc++.h>

using namespace std;

int n;
string ans = "ongoing";
char board[31][31];
int dx[4] = {0,1,1,1};
int dy[4] = {1,0,1,-1};

bool OOB(int x, int y) {
    if(x >= 0 && y >= 0 && x < n && y < n) return true;

    return false;
}

void dfs(int x, int y, int preDir) {
    int cnt = 0;
    
    int curCH = board[x][y];

    for(int k = 0; k < 3; k++) {
        int nx = x + dx[preDir]*k;
        int ny = y + dy[preDir]*k;

        if(!OOB(nx, ny)) return;
        if(board[nx][ny] == '.' || board[nx][ny] != curCH) return;

        cnt++;
    }

    if(cnt == 3) ans = curCH;
}

int main() {
    cin >> n;

    string tmp;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        for(int j = 0; j < tmp.length(); j++)
            board[i][j] = tmp[j];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == '.') continue;
            for(int k = 0; k < 4; k++) {
                dfs(i, j, k);
            }
        }
    }

    cout << ans;
}