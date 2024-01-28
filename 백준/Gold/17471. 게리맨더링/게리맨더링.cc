#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
#define x first
#define y second
const int MOD = 1e9+7;
ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;}
ll mp(ll a, ll b) {ll ret = 1; while(b) {if(b & 1) ret = ret * a % MOD; a = a * a % MOD; b >>= 1;} return ret;}

int ans = 1e9, n;
int peo[11];
vector<int> conn[11];
bool visited[11];
bool city[11];

void bfs(int node, bool team) {
    queue<int> q;
    q.push(node);
    city[node] = true;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int i = 0; i < conn[cur].size(); i++) {
            int next = conn[cur][i];

            if(city[next]) continue;

            if(visited[next] != team) continue;
            
            city[next] = true;
            q.push(next);
        }
    }
}

int check() {
    int a = 0, b = 0;
    for(int i = 0; i < n; i++) {
        if(visited[i]) a += peo[i];
        else b += peo[i];
    }

    int c = abs(a - b);

    if(c >= ans) return -1;

    memset(city, 0, 11);

    int tmp = 0;
    for(int i = 0; i < n; i++) {
        if(!city[i]) {
            tmp++;
            bfs(i, visited[i]);
        }
    }

    if(tmp == 2) return c;

    return -1;
}

void dfs(int depth, int idx) {
    if(depth <= n) {
        int cur = check();

        if(cur != -1)
            ans = min(ans, cur);
    }

    for(int i = idx; i < n; i++) {
        if(visited[i]) continue;

        visited[i] = true;
        dfs(depth + 1, i);
        visited[i] = false;
    }
}

// 선거구가 1개 이상
// 같은 선거구가 연결되지 않으면 안됨..


int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    
    for(int i = 0; i < n; i++)
        cin >> peo[i];

    int a;
    for(int i = 0; i < n; i++) {
        cin >> a;

        int b;
        for(int j = 0; j < a; j++) {
            cin >> b;
            conn[i].push_back(b-1);
        }
    }    

    dfs(0, 0);

    if(ans == 1e9) ans = -1;

    cout << ans;
    
    return 0;
}