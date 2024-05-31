#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int st, en;
int dist[1001], path[1001];
vector<pii> node[1001];

void dijkstra() {
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, st});
    dist[st] = 0;

    while(!pq.empty()) {
        int d, cur;
        tie(d, cur) = pq.top();
        pq.pop();

        if(dist[cur] < d && cur != st) continue;

        if(cur == en) return;

        for(int i = 0; i < node[cur].size(); i++) {
            int next = node[cur][i].first;
            int nd = node[cur][i].second;

            if(dist[next] <= dist[cur] + nd) continue;

            dist[next] = dist[cur] + nd;
            pq.push({dist[next], next});
            path[next] = cur;
        }
    }
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int a, b, c;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        node[a].push_back({b, c});
    }

    fill(dist, dist + n + 1, 1e9);

    cin >> st >> en;

    dijkstra();

    cout << dist[en] << '\n';

    stack<int> s;

    int cur = en;
    while(path[cur] != 0) {
        s.push(cur);
        cur = path[cur];
    }
    s.push(st);

    cout << s.size() << '\n';

    while(!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }

	return 0;
}