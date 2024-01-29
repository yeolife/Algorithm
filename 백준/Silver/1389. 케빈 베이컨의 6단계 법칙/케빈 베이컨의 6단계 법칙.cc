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

int n, m;
int kevin[101];
vector<int> frie[101];

void bfs(int node) {
    int ret = 0;

    int visited[101] = {0,};
    queue<pair<int, int> > q;
    q.push({node, 0});

    visited[node] = true;

    while(!q.empty()) {
        int cur, dist;
        tie(cur, dist) = q.front();
        q.pop();

        for(int i = 0; i < frie[cur].size(); i++) {
            int next = frie[cur][i];

            if(visited[next]) continue;
            else
                ret += dist;

            visited[next] = true;
            q.push({next, dist + 1});
        }
    }

    kevin[node] = ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m;

    int a, b;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;

        frie[a].push_back(b);
        frie[b].push_back(a);
    }

    for(int i = 1; i <= n; i++)
        bfs(i);
    
    int tmp = 1e9, ans = 0;
    for(int i = 1; i <= n; i++) {
        if(tmp > kevin[i]) {
            ans = i;
            tmp = kevin[i];
        }
    }

    cout << ans;

    return 0;
}