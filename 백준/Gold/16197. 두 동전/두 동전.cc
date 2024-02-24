#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 11;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
char board[21][21];
bool visited[21][21][21][21];

bool OOB(int x, int y) {
    if(x >= 0 && y >= 0 && x < n && y < m) return true;
    return false;
}

void dfs(int cnt, int x1, int y1, int x2, int y2) {
    if(cnt > 10) return;

    int result = OOB(x1, y1) + OOB(x2, y2);

    if(result <= 1) {
        if(result == 1)
            ans = min(ans, cnt);
        return;
    }

    for(int i = 0; i < 4; i++) {
        int nx1 = x1, ny1 = y1;
        int nx2 = x2, ny2 = y2;

        if(board[x1 + dx[i]][y1 + dy[i]] != '#') {
            nx1 += dx[i];
            ny1 += dy[i];
        }
        if(board[x2 + dx[i]][y2 + dy[i]] != '#') {
            nx2 += dx[i];
            ny2 += dy[i];
        }

        dfs(cnt + 1, nx1, ny1, nx2, ny2);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    
    
    cin >> n >> m;

    pair<int, int> st[2];

    int idx = 0;
    string str;
    for(int i = 0; i < n; i++) {
        cin >> str;
        for(int j = 0; j < m; j++) {
            board[i][j] = str[j];

            if(board[i][j] == 'o') {
                st[idx] = {i, j};
                idx++;
            }
        }
    }

    int x1, y1, x2, y2;
    tie(x1, y1) = st[0];
    tie(x2, y2) = st[1];

    dfs(0, x1, y1, x2, y2);

    ans = (ans > 10) ? -1 : ans;

    cout << ans;

    return 0;
}