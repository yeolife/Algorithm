#include <iostream>
#include <algorithm>
using namespace std;

int n, m, ans;
int board[1001][1001];
int dp[1001][1001][3];
bool visited[1001][1001];
int dx[3] = { 1, 0, 0 };
int dy[3] = { 0, -1, 1 };

bool OOB(int x, int y) {
	if (x >= 0 && y >= 0 && x < n && y < m) return false;
	return true;
}

int dfs(int x, int y, int dir) {
	if (x == n - 1 && y == m - 1) return board[x][y];

	int& ret = dp[x][y][dir];

	if (ret != -1e9) return ret;

	ret = -1e9;

	visited[x][y] = true;

	for (int i = 0; i < 3; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (OOB(nx, ny) || visited[nx][ny]) continue;

		ret = max(ret, dfs(nx, ny, i) + board[x][y]);
	}

	visited[x][y] = false;

	return ret;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 3; k++)
				dp[i][j][k] = -1e9;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	}

	cout << dfs(0, 0, 0);
}