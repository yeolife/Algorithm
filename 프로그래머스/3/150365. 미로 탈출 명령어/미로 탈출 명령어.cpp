#include <bits/stdc++.h>
using namespace std;
using tsii = tuple<string, int, int>;

int nn, mm, sx, sy, ex, ey, kk;

// d, r, l, u
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

map<int, char> dir = {
    {0, 'd'}, {1, 'r'},
    {2, 'l'}, {3, 'u'},
};

struct cmp {
    bool operator()(tsii& a, tsii& b) {
        if(get<0>(a) == get<0>(b))
            return get<0>(a).length() < get<0>(b).length();
        return get<0>(a) > get<0>(b);    
    }
};

bool OOB(int x, int y) {
    if(x >= 0 && y >= 0 && x < nn && y < mm) return false;
    return true;
}

// 남은 거리 > 갈 수 있는 거리(k - dp)
bool available(int x, int y, int d) {
    if(abs(ex - x) + abs(ey - y) > kk - d) return false;
    if((kk - d) & 1 && !((abs(ex - x) + abs(ey - y)) & 1)) return false;
    if(!((kk - d) & 1) && (abs(ex - x) + abs(ey - y)) & 1) return false;
    
    return true;
}

string dijkstra() {
    priority_queue<tsii, vector<tsii>, cmp> pq;
    pq.push({"", sx, sy});
        
    while(!pq.empty()) {
        string cur;
        int x, y;
        tie(cur, x, y) = pq.top();
        pq.pop();
                
        if(cur.length() == kk) {
            if(x == ex && y == ey)
                return cur;
            
            continue;
        }
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(OOB(nx, ny)) continue;
            if(!available(nx, ny, cur.length() + 1)) continue;
            if(cur.length() + 1 > kk) continue;
            
            pq.push({cur + dir[i], nx, ny});
        }
    }
    
    return "impossible";
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "impossible";
    nn = n; mm = m; sx = x - 1; sy = y - 1; ex = r - 1; ey = c - 1; kk = k;
    
    if(abs(ex - sx) + abs(ey - sy) <= k)
        answer = dijkstra();
    
    return answer;
}