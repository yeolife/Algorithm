#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int n, m, ans;
int root[7];
bool tmp[11][11];
int board[11][11];
bool visited[11][11];
vector<tiii> edges;
vector<tiii> island;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool OOB(int x, int y) {
    if(x >= 0 && y >= 0 && x < n && y < m) return false;
    return true;
}

void painting(int sx, int sy, int color) {
    queue<pii> q;
    q.push({sx, sy});
    visited[sx][sy] = true;
    board[sx][sy] = color;

    while(!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(OOB(nx, ny) || visited[nx][ny]) continue;
            if(!tmp[nx][ny]) {
                island.push_back({x, y, i});
                continue;
            }

            visited[nx][ny] = true;
            q.push({nx ,ny});
            board[nx][ny] = color;
        }
    }
}

void bridge(tiii st) {
    int x, y, dir;
    tie(x, y, dir) = st;
    int color = board[x][y];

    int cnt = 0;
    while(true) {
        x += dx[dir];
        y += dy[dir];

        if(OOB(x, y)) return;

        if(board[x][y]) {
            if(board[x][y] != color && cnt >= 2)
                edges.push_back({cnt, color, board[x][y]});

            return;
        }

        cnt++;
    }
}

int find(int x) {
    if(root[x] == -1) return x;

    return root[x] = find(root[x]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);

    if(a > b) swap(a, b);

    root[b] = a;
}

bool cycle(int a, int b) {
    a = find(a);
    b = find(b);

    if(a == b) return true;
    return false;
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cin >> tmp[i][j];
    }

    int cnt = -1, color = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!visited[i][j] && tmp[i][j]) {
                painting(i, j, color++);
                cnt++;
            }
        }
    }

    for(auto& it: island)
        bridge(it);

    sort(edges.begin(), edges.end());

    memset(root, -1, sizeof(root));

    for(int i = 0; i < edges.size(); i++) {
        int dist, x, y;
        tie(dist, x , y) = edges[i];

        if(!cycle(x, y)) {
            merge(x, y);
            ans += dist;
            cnt--;
        }
    }

    if(cnt != 0) ans = -1;

    cout << ans << '\n';

    return 0;
}