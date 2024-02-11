#include <bits/stdc++.h>
using namespace std;

int n;
int board[501][501];
bool visited[501][501];
int finished[501][501];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool OOB(int x, int y) {
    if(x >= 0 && y >= 0 && x < n && y < n) return true;
    return false;
}

int dfs(int x, int y) {
    if(finished[x][y] != 0) return finished[x][y];

    if(!visited[x][y]) {
        visited[x][y] = true;

        int ret = 1;
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(!OOB(nx, ny) || board[x][y] >= board[nx][ny]) continue;

            ret = max(ret, dfs(nx, ny) + 1);
        }

        finished[x][y] = ret;
    }

    return finished[x][y];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ans = max(ans, dfs(i, j));
        }
    }

    cout << ans;

    return 0;
}