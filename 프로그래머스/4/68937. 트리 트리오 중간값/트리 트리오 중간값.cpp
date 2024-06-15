#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

bool visited[250001];
vector<int> nodes[250001];

pii bfs(int st, bool state) {
    int mx1 = 0, mx2 = 0, ret;
    memset(visited, 0, sizeof(visited));
        
    queue<pii> q;
    q.push({0, st});
    visited[st] = true;
 
    while(!q.empty()) {
        int cur, cdist;
        tie(cdist, cur) = q.front();
        q.pop();
        
        if(mx2 <= cdist) {
            mx2 = cdist;
            ret = cur;
        }
        if(mx2 > mx1)
            swap(mx1, mx2);
        
        for(int i = 0; i < nodes[cur].size(); i++) {
            int next = nodes[cur][i];
            
            if(visited[next]) continue;
            
            visited[next] = true;
            q.push({cdist+1, next});
        }
    }
    
    if(mx1 == mx2 && state) return {mx1, 0};
        
    return {mx1, ret};
}

int solution(int n, vector<vector<int>> edges) {    
    for(int i = 0; i < edges.size(); i++) {
        int a = edges[i][0];
        int b = edges[i][1];
        
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }
    
    // 임의의 정점에서 가장 먼점 찾기
    pii ret1 = bfs(1, false);
    
    // 트리의 지름 찾기
    pii ret2 = bfs(ret1.second, true);
    if(ret2.second == 0) return ret2.first;
    
    // 역으로 뒤집어서 재확인
    pii ret3 = bfs(ret2.second, true);
    if(ret3.second == 0) return ret3.first;

    return ret2.first - 1;
}