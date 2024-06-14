#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int ans = 0;
vector<pii> nodes[10001];

int dfs(int cur) {
    if(nodes[cur].empty())
        return 0;

    int mx1 = 0, mx2 = 0;
    for(int i = 0; i < nodes[cur].size(); i++) {
        int tmp = dfs(nodes[cur][i].first) + nodes[cur][i].second;

        if(mx1 < tmp) {
            if(mx1 > mx2) mx2 = mx1;

            mx1 = tmp;
        } else {
            if(mx2 < tmp) 
                mx2 = tmp;
        }
    }

    ans = max(ans, mx1 + mx2);

    return mx1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);

    int n;
    cin >> n;

    for(int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        nodes[a].push_back({b, c});
    }

    dfs(1);

    cout << ans;

	return 0;
}