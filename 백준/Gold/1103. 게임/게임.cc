#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using ll = long long;

bool cycle;
int n,m,ans=0;
char board[51][51];
bool visited[51][51];
int finished[51][51];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

bool OOB(int x, int y) {
    if(x >= 0 && y >= 0 && x < n && y < m) return true;
    return false;
}

int dfs(int x, int y) {
    // 보드 바깥으로 나가거나, 구멍에 빠질 경우
    if(!OOB(x,y) || board[x][y] == 'H' || cycle) {
        return 0;
    }
    
    // 사이클인 경우
    if(visited[x][y] && !finished[x][y]) {
        cycle=true;
        return 0;
    }
    
    int go = board[x][y]-'0';

    int cal=-1;
    if(!visited[x][y]) {
        visited[x][y]=true;
        for(int i=0; i<4; i++) {
            int nx=x+go*dx[i];
            int ny=y+go*dy[i];
            int sum=dfs(nx, ny)+1;
            cal=max(cal,sum);
        }
        finished[x][y]=cal;
        return cal;
    }
    return finished[x][y];
}

int main() {  
    ios::sync_with_stdio(0); cin.tie(NULL);
    
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        for(int j=0; j<m; j++)
            board[i][j]=s[j];
    }

    ans=dfs(0,0);

    if(cycle) ans = -1;

    cout << ans;
}