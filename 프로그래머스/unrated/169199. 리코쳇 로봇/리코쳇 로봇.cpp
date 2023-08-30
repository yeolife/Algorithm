#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
vector<string> boards;
bool visited[101][101];

bool OOB(int x, int y) {
    if(x >= 0 && y >= 0 && x < boards.size() && y < boards[0].size()) return true;
    
    return false;
}

pair<int, int> go (int x, int y, int dir) {
    while(1) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(!OOB(nx, ny) || boards[nx][ny] == 'D') return {x, y};
        
        x = nx;
        y = ny;
    }
        
    return {-1, -1};
}

int bfs(int sx, int sy) {
    queue<tuple<int, int, int> > q;
    
    q.push({sx, sy, 0});
    visited[sx][sy] = true;
    
    while(!q.empty()) {
        int nx, ny, cnt;
        tie(nx,ny,cnt) = q.front();
        q.pop();
        
        if(boards[nx][ny] == 'G')
            return cnt;

        for(int i = 0; i < 4; i++) {
            pair<int,int> xy = go(nx, ny, i);
            int xx, yy;
            tie(xx, yy) = xy;
            
            if(!OOB(xx, yy) || visited[xx][yy]) continue;
            
            visited[xx][yy] = true;
            q.push({xx, yy, cnt+1});
        }
    }
    
    return -1;
}

int solution(vector<string> board) {
    int answer = 0;
    
    boards = board;
    
    // 시작점 찾기
    int sx, sy;
    for(int i = 0; i < board.size(); i++) {
        bool flag = false;
        for(int j = 0; j < board[i].size(); j++) {
            if(board[i][j] == 'R') {
                sx = i;
                sy = j;
                break;
            }
        }
        
        if(flag) break; 
    }
    
    answer = bfs(sx, sy);
    
    return answer;
}