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

int n, k;
int arr[200001];
int visited[100001];

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);

	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	int ans = 0, cnt = 0;
	int st = 0, en = 0;
	while(en < n) {
		visited[arr[en]]++;

		while(visited[arr[en]] > k)
			visited[arr[st++]]--;

		en++;
		
		ans = max(ans, en - st);
	}

	cout << ans;

	return 0;
}