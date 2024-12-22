#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int sunsu[1001][1001] = { 0, };

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);

	int n, m, ans = 1e9 + 7;
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> sunsu[i][j];

		sort(sunsu[i], sunsu[i] + m);
	}

	vector<int> pointer(n, 0);

	while (true) {
		int lo = 1e9 + 7, hi = -1, idx;
		for (int i = 0; i < n; i++) {
			if (lo > sunsu[i][pointer[i]]) {
				lo = sunsu[i][pointer[i]];
				idx = i;
			}
			if (hi < sunsu[i][pointer[i]])
				hi = sunsu[i][pointer[i]];
		}

		ans = min(ans, hi - lo);
		
		if (++pointer[idx] == m)
			break;
	}
	
	cout << ans;

	return 0;
}