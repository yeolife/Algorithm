#include <bits/stdc++.h>
using namespace std;

struct edge {
    int dist;
    int v;
};

struct cmp {
    bool operator()(edge& a, edge& b) {
        return a.dist > b.dist;
    }
};

int dp[20001];
vector<edge> edges[20001];

void dijkstra(int st) {
    priority_queue<edge, vector<edge>, cmp> pq;
    dp[st] = 0;
    pq.push({0, st});

    while(!pq.empty()) {
        int dist = pq.top().dist;
        int cur = pq.top().v;
        pq.pop();

        for(int i = 0; i < edges[cur].size(); i++) {
            int ndist = edges[cur][i].dist;
            int next = edges[cur][i].v;

            if(dp[next] <= dist + ndist) continue;

            dp[next] = dist + ndist;
            pq.push({dp[next], next});
        }
    }
}

int main() {
   ios::sync_with_stdio(0); cin.tie(NULL);

    int n, m, st;
    cin >> n >> m >> st;

    int u, v, w;
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;

        edges[u].push_back({w, v});
    }

    fill(&dp[0], &dp[20001], 1e9);

    dijkstra(st);

    for(int i = 1; i <= n; i++) {
        if(dp[i] == 1e9) cout << "INF";
        else cout << dp[i];

        cout << '\n';
    }

   return 0;
}