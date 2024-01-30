#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
int board[1002][1002];
bool visited[1002][1002];
vector<pair<int, int > > fires;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool OOB(int x, int y) {
    if(x >= 0 && y >= 0 && x < n && y < m) return true;
    return false;
}

struct cmp {
    bool operator()(tuple<int ,int ,int, bool> a, tuple<int, int, int, bool> b) {
        if(get<2>(a) == get<2>(b))
            return get<3>(a) > get<3>(b);

        return get<2>(a) > get<2>(b);
    }
};

// 불 먼저 다 하고 상근이가 가봐야함.
bool bfs(int x, int y) {
    priority_queue<tuple<int, int, int, bool>, vector<tuple<int, int, int, bool> >, cmp > q;
    
    q.push({x, y, 0, 1});
    visited[x][y] = true;

    for(int i = 0; i < fires.size(); i++) {
        int fx, fy;
        tie(fx, fy) = fires[i];
        visited[fx][fy] = true;
        q.push({fx, fy, 0, 0});
    }

    while(!q.empty()) {
        int nx, ny, dist, flag;
        tie(nx, ny, dist, flag) = q.top();
        q.pop();

        if((nx == 0 || ny == 0 || nx == n-1 || ny == m-1) && flag) {
            ans = dist + 1;
            return true;
        }

        for(int i = 0; i < 4; i++) {
            int xx = nx + dx[i];
            int yy = ny + dy[i];

            if(!OOB(xx, yy)) continue;
            if(visited[xx][yy]) continue;
            if(board[xx][yy] == '#' || visited[xx][yy] == '*') continue;

            visited[xx][yy] = true;
            q.push({xx, yy, dist + 1, flag});
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);

    int tc;
    cin >> tc;

    for(int t = 0; t < tc; t++) {
        ans = 1e9;
        fill(&board[0][0], &board[1000][1001], 0);
        fill(&visited[0][0], &visited[1000][1001], 0);
        fires = vector<pair<int, int> >();
        
        cin >> m >> n;

        int sx, sy;

        string tmp;
        for(int i = 0; i < n; i++) {
            cin >> tmp;
            for(int j = 0; j < tmp.length(); j++) {
                if(tmp[j] == '@') {
                    sx = i;
                    sy = j;
                } else if(tmp[j] == '*')
                    fires.push_back({i, j});

                board[i][j] = tmp[j];
            }
        }

        if(bfs(sx, sy))
            cout << ans << '\n';
        else
            cout << "IMPOSSIBLE" << '\n';
    }

    return 0;
}