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

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);

    int n,m;
    long long dist[501];
    vector<pair<int,int> > edge[501];

    cin >> n >> m;

    int a, b, c;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        edge[a].push_back({b,c});
    }

    fill(&dist[0], &dist[501], 1e18);
    dist[1] = 0;

    bool is_cycle = false;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            for(auto it: edge[j]) {
                int next = it.first;
                int cost = it.second;
                if(dist[j] != 1e18 && dist[next] > dist[j] + cost) {
                    dist[next] = dist[j] + cost;
                    if(i == n) 
                        is_cycle = true;
                }
            }
        }
    }

    if(is_cycle) cout << -1;
    else {
        for(int i = 2; i <= n; i++) {
            if(dist[i] == 1e18)
                cout << -1 << '\n';
            else
                cout << dist[i] << '\n';
        }
    }
    return 0;
}