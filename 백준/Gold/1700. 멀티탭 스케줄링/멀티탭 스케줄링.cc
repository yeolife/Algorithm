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

    int n, k;
    int arr[101] = {0,};
    int plug[101] = {0,};
    bool visited[101] = {0,};

    cin >> n >> k;

    for(int i = 0; i < k; i++) {
        cin >> arr[i];
        plug[arr[i]]++;
    }

    int ans = 0, cnt = 0;
    for(int i = 0; i < k; i++) {
        // 이미 꽂혀있음
        if(visited[arr[i]])
            plug[arr[i]]--;
        // 꽂혀있지 않지만 빈 곳이 존재
        else if(cnt < n) {
            visited[arr[i]] = true;
            plug[arr[i]]--;
            cnt++;
        }
        // 빈 곳이 없으므로 다른 것을 뽑음
        else {
            int last = -1, last_idx = -1;

            // 가장 늦게 사용할 것을 뽑음
            for(int j = 1; j <= k; j++) {
                if(!visited[j]) continue;
                int tmp_idx = 0;
                for(int jj = i+1; jj < k; jj++) {
                    if(j == arr[jj])
                        break;
                    tmp_idx++;
                }
                if(last_idx < tmp_idx) {
                    last = j;
                    last_idx = tmp_idx;
                }
            }

            visited[arr[i]] = true;
            visited[last] = false;
            plug[last]--;
            ans++;
        }
    }

    cout << ans;

    return 0;
}