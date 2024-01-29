#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
#define x first
#define y second
const int MOD = 1e9+7;
ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;}
ll mp(ll a, ll b) {ll ret = 1; while(b) {if(b & 1) ret = ret * a % MOD; a = a * a % MOD; b >>= 1;} return ret;}

int n, m, k;
bool board[101][101];
bool visited[101][101];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool OOB(int x, int y) {
    if(x >= 0 && y >= 0 && x < n && y < m) return true;

    return false;
}

int bfs(int x, int y) {
    int ret = 1;

    queue<pair<int, int> > q;
    q.push({x, y});
    visited[x][y] = true;

    while(!q.empty()) {
        int nx, ny;
        tie(nx, ny) = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int xx = nx + dx[i];
            int yy = ny + dy[i];

            if(!OOB(xx, yy)) continue;
            if(visited[xx][yy]) continue;
            if(board[xx][yy]) continue;

            visited[xx][yy] = true;

            q.push({xx, yy});
            ret++;
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m >> k;

    int x1, y1, x2, y2;
    for(int i = 0; i < k; i++) {
        cin >> x1 >> y1 >> x2 >> y2;

        for(int x = y1; x < y2; x++) {
            for(int y = x1; y < x2; y++)
                board[x][y] = true;
        }
    }

    int cnt = 0;
    vector<int> ans;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(visited[i][j] || board[i][j]) continue;

            cnt++;
            ans.push_back(bfs(i, j));
        }
    }

    sort(ans.begin(), ans.end());

    cout << cnt << '\n';

    for(auto& it: ans)
        cout << it << ' ';

    return 0;
}