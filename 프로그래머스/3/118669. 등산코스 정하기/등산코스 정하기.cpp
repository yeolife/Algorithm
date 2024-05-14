#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

bool goal[50001];
bool mountain[50001];
int dist[50001]; // 등산로
vector<pii> edge[50001];

struct cmp {
    bool operator()(pii& a, pii& b) {
        if(a.first == b.first)
            return a.second > b.second;
        return a.first > b.first;
    }
};

int dijkstra(int st) {
    fill(dist, dist + 50001, 1e9);
    dist[st] = 0;

    priority_queue<pii, vector<pii>, cmp> pq;
    pq.push({0, st});

    while(!pq.empty()) {
        int cd, cur;
        tie(cd, cur) = pq.top();
        pq.pop();

        if(goal[cur])
            return cd;

        for(int i = 0; i < edge[cur].size(); i++) {
            int next = edge[cur][i].first;
            int nd = edge[cur][i].second;

            if(dist[next] <= nd) continue;
            if(mountain[next]) continue;

            dist[next] = nd;

            pq.push({max(nd, cd), next});
        }
    }

    return 1e9;
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> ans(2, 1e9);

    for(int i = 0; i < gates.size(); i++)
        goal[gates[i]] = true;
    
    for(int i = 0; i < summits.size(); i++)
        mountain[summits[i]] = true;

    for(int i = 0; i < paths.size(); i++) {
        int a = paths[i][0], b = paths[i][1], c = paths[i][2];

        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }
    
    sort(summits.begin(), summits.end());

    for(int i = 0; i < summits.size(); i++) {
        int ret = dijkstra(summits[i]);

        if(ret < ans[1]) {
            ans[0] = summits[i];
            ans[1] = ret;
        }
    }

    return ans;
}