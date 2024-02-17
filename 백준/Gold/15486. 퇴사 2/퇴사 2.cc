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

pair<int,int> v[1500002]; 
int dp[1500002]={0,};

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);

    int n;
    cin >> n;

    for(int i=1; i<=n; i++)
        cin >> v[i].first >> v[i].second;

    int cur=0;
    for(int i=1; i<=n+1; i++) {
        cur=max(cur, dp[i]);
        if(i+v[i].first <= n+1)
            dp[i+v[i].first] = max(dp[i+v[i].first], cur+v[i].second);
    }

    int ans=0;

    for(int i=1; i<=n+1; i++)
        ans = max(ans, dp[i]);

    cout << ans;

    return 0;
}