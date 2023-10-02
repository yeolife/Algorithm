#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int visited[26][26][4];

struct cmp{
    bool operator()(tuple<int, int, int, int>& a, tuple<int, int, int, int>& b){
        return get<0>(a) > get<0>(b);
    }
};

bool OOB(int x, int y, int sz) {
    if(x >= 0 && y >= 0 && x <= sz && y <= sz) return true;
    
    return false;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    
    fill_n(&visited[0][0][0], 26 * 26 * 4, 1e9);
    
    int sz = board.size()-1; 
    
    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, cmp > pq;
    pq.push({0, 0, 0, -1});
    
    while(!pq.empty()) {
        int cnt, x, y, dist;
        tie(cnt, x, y, dist) = pq.top();
                
        pq.pop();
        
        if(x == sz && y == sz) {
            answer = cnt;
                        
            break;
        }
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(!OOB(nx, ny, sz) || board[nx][ny] == 1) continue;
            
            int ret = cnt;
            
            if(dist != i && dist != -1) ret += 600;
            else ret += 100;
            
            if(visited[nx][ny][i] <= ret) continue;
                
            visited[nx][ny][i] = ret;
            
            pq.push({ret, nx, ny, i});
        }
    }
    
    return answer;
}