#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using till = tuple<int, long long, long long>;

int n, m = -1;
ll st, en, money, ans;
vector<pii> nodes[100001];
ll dist[100001];

struct cmp {
    bool operator()(till& a, till& b) {
        if(get<1>(a) == get<1>(b))
            return get<2>(a) > get<2>(b);
        return get<1>(a) > get<1>(b);
    }
};

long long dijkstra() {
    priority_queue<till, vector<till>, cmp> pq;
    pq.push({st, 0, 0});
    dist[st] = 0;

    while(!pq.empty()) {
        int cur, su, d;
        tie(cur, su, d) = pq.top();
        pq.pop();

        if(cur == en) return su;

        for(int i = 0; i < nodes[cur].size(); i++) {
            int next = nodes[cur][i].first;
            int nd = nodes[cur][i].second;
            int nsu = max(su, nd);

            if(dist[next] <= nsu) continue;
            if(money < d + nd) continue;

            dist[next] = nsu;
            pq.push({next, nsu, d + nd});
        }
    }

    return -1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m >> st >> en >> money;

    st--, en--;

    for(int i = 0; i < m; i++) {
        int x, y, d;
        cin >> x >> y >> d;

        nodes[x - 1].push_back({y - 1, d});
        nodes[y - 1].push_back({x - 1, d});
    }

    fill(dist, dist+100001, 0x7f7f7f7f7f7f);

    ans = dijkstra();

    cout << ans;

	return 0;
}