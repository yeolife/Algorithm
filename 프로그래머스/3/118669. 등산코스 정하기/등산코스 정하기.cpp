#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

bool gate[50001], summit[50001];
int dist[50001];
vector<pii> edge[50001];

int dijkstra(int st) {
    fill(dist, dist + 50001, 1e9);
    dist[st] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, st});

    while(!pq.empty()) {
        int cd, cur;
        tie(cd, cur) = pq.top();
        pq.pop();

        if(gate[cur])
            return cd;
        // if(dist[cur] < cd) continue; // 이거 왜 빼야함?

        for(int i = 0; i < edge[cur].size(); i++) {
            int next = edge[cur][i].first;
            int nd = edge[cur][i].second;

            if(dist[next] <= nd || summit[next]) continue;

            dist[next] = nd;
            pq.push({max(nd, cd), next});
        }
    }

    return 1e9;
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> ans(2, 1e9);

    for(int i = 0; i < gates.size(); i++)
        gate[gates[i]] = true;
    
    for(int i = 0; i < summits.size(); i++)
        summit[summits[i]] = true;

    for(int i = 0; i < paths.size(); i++) {
        int a = paths[i][0], b = paths[i][1], c = paths[i][2];

        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }
    
    for(int i = 0; i < summits.size(); i++) {
        int ret = dijkstra(summits[i]);

        if(ret <= ans[1]) {                        
            if(ret == ans[1])
                ans[0] = min(ans[0], summits[i]);
            else
                ans[0] = summits[i];
            
            ans[1] = ret;
        }
    }

    return ans;
}