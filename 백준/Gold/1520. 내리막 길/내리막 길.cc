#include <bits/stdc++.h>
using namespace std;

int n, m;
long long ans;
int board[501][501];
bool visited[501][501];
int finished[501][501];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool OOB(int x, int y) {
    if(x >= 0 && y >= 0 && x < n && y < m) return true;
    return false;
}

long long dfs(int x, int y) {
    if(x == n-1 && y == m-1)
        return 1;

    if(finished[x][y]) return finished[x][y];

    if(!visited[x][y]) {
        visited[x][y] = true;

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(!OOB(nx, ny) || board[x][y] <= board[nx][ny]) 
                continue;

            finished[x][y] += dfs(nx, ny);
        }
    }

    return finished[x][y];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    }

    ans = dfs(0, 0);

    cout << ans;

    return 0;
}