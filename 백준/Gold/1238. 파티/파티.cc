#include <bits/stdc++.h>
using namespace std;

int ans = -1;
vector<int> node[1001];
int root[1001][1001];
int dp[1001];
int ret[1001];

struct cmp {
    bool operator()(tuple<int, int>& a, tuple<int, int>& b) {
        return get<0>(a) > get<0>(b);
    }
};

void dijkstra(int n, int k) {
    fill(&dp[0], &dp[1001], 1e9);
    dp[n]= 0;

    priority_queue<tuple<int, int>, vector<tuple<int, int>>, cmp> pq;

    pq.push({0, n});

    while(!pq.empty()) {
        int dist, cur;
        tie(dist, cur) = pq.top();
        pq.pop();

        if(n != k && cur == k) break;

        for (int i = 0; i < node[cur].size(); i++) {
            int next = node[cur][i];
            
            if(dp[next] > dist + root[cur][next]) {
                dp[next] = dist + root[cur][next];
                pq.push({dp[next], next});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        node[a].push_back(b);
        root[a][b] = c;
    }

    for (int i = 1; i <= n; i++) {
        dijkstra(i, k);

        if(i != k)
            ret[i] += dp[k];
        else {
            for(int j = 1; j <= n; j++)
                ret[j] += dp[j];
        }
    }

    for(int i = 1; i <= n; i++)
        ans = max(ans, ret[i]);

    cout << ans;

    return 0;
}