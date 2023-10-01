#include <bits/stdc++.h>

using namespace std;

int dist[20001] = {0,};
vector<vector<int> > nodes(20001);

void bfs() {
    queue<pair<int,int> > q;
    
    for(int i = 0; i < nodes[1].size(); i++)
        q.push({nodes[1][i], 1});
    
    while(!q.empty()) {
        int node, cnt;
        tie(node, cnt) = q.front();
        q.pop();
        
        if(dist[node] != 1e9) continue;
        
        dist[node] = cnt;
        
        for(int i = 0; i < nodes[node].size(); i++)
            q.push({nodes[node][i], cnt+1});
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 1;
    
    fill(dist, dist+20001, 1e9);
    
    for(int i = 0; i < edge.size(); i++) {
        int x = edge[i][0];
        int y = edge[i][1];
        
        nodes[x].push_back(y);
        nodes[y].push_back(x);
    }
    
    bfs();
    
    int max = -1;
    for(int i = 2; i <= n; i++) {
        if(dist[i] == 1e9) continue;
        
        if(dist[i] == max)
            answer++;
        else if(dist[i] > max) {
            max = dist[i];
            answer = 1;
        }
    }
    
    return answer;
}

// 정점 1에서의 모든 최단 거리를 구한다.
// 최단거리에서 가장 큰 값을 구한다.