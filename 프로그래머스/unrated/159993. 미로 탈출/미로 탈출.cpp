#include <bits/stdc++.h>

using namespace std;

pair<int,int> st;

int sizeX, sizeY;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int visited[101][101][2];

bool OOB(int x, int y) {
    if(x >= 0 && y >= 0 && x < sizeX && y < sizeY)
        return true;
    
    return false;
}

int bfs(vector<string> map) {
    queue<tuple<int, int, bool, int> > q;
    q.push({st.first, st.second, 0, 0});
    visited[st.first][st.second][0] = true;
    
    while(!q.empty()) {
        int nx, ny, flag, cnt;
        tie(nx, ny, flag, cnt) = q.front();
        q.pop();

        if(map[nx][ny] == 'E' && flag)
            return cnt;
        if(map[nx][ny] == 'L' && !flag)
            flag = true;
        
        for(int i = 0; i < 4; i++) {
            int xx = nx+dx[i];
            int yy = ny+dy[i];
            
            if(!OOB(xx, yy)) continue;
            if(visited[xx][yy][flag]) continue;
            if(map[xx][yy] == 'X') continue;
             
            visited[xx][yy][flag] = true;
            
            q.push({xx, yy, flag, cnt+1});
        }
    }
    
    return -1;
}

int solution(vector<string> maps) {
    int ans = 0;
    
    sizeX = maps.size();
    sizeY = maps[0].size();
    
    // 위치 탐색
    for(int i = 0; i < maps.size(); i++) {
        for(int j = 0; j < maps[i].length(); j++) {
            if(maps[i][j] == 'S')
                st = {i, j};
        }
    }
    
    // 최적 경로 탐색
    ans = bfs(maps);
    
    return ans;
}