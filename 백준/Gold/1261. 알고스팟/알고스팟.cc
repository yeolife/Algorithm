#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[101][101], dp[101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool OOB(int x, int y) {
    if(x >= 0 && y >= 0 && x < n && y < m) return false;
    return true;
}

struct node {
    int dist;
    int x;
    int y;
};

struct cmp {
    bool operator()(node& a, node& b) {
        return a.dist > b.dist;
    }
};

int dijkstra(int sx, int sy) {
    int ret = -1;

    priority_queue<node, vector<node>, cmp> pq;
    pq.push({0, sx, sy});
    dp[sx][sy] = 0;

    while(!pq.empty()) {
        node cur = pq.top();
        pq.pop();

        if(cur.x == n - 1 && cur.y == m - 1) {
            ret = cur.dist;
            break;
        }

        for(int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            int wall = board[nx][ny];

            if(OOB(nx, ny)) continue;

            if(dp[nx][ny] > dp[cur.x][cur.y] + wall) {
                dp[nx][ny] = dp[cur.x][cur.y] + wall;
                pq.push({dp[nx][ny], nx, ny});
            }
        }
    }

    return ret;
}

int main() {
    fill(&dp[0][0], &dp[100][101], 1e9);

    cin >> m >> n;

    string str;
    for(int i = 0; i < n; i++) {
        cin >> str;
        for(int j = 0; j < m; j++)
            board[i][j] = str[j] - '0';
    }

    int ans = dijkstra(0, 0);

    cout << ans;

    return 0;
}