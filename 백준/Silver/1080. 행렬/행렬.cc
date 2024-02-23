#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int ans = 0;
bool src[51][51], dest[51][51];

void switchON(int x, int y) {
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++)
			src[i][j] = !src[i][j];
	}
    ans++;
}

void solve(int n, int m) {
	for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(src[i][j] != dest[i][j])
                switchON(i, j);
        }
    }
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < m; j++)
			src[i][j] = str[j] - '0';
	}

	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < m; j++)
			dest[i][j] = str[j] - '0';
	}

	solve(n - 2, m - 2);

	bool flag = true;
	for (int i = 0; i < n; i++) {
		if (!flag) break;
		for (int j = 0; j < m; j++) {
			if (src[i][j] != dest[i][j])
				flag = false;
		}
	}
	ans = (flag) ? ans : -1;

	cout << ans;

	return 0;
}
